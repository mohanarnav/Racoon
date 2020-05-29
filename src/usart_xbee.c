/*
 * usart_xbee.c
 *
 *  Created on: May 21, 2020
 *      Author: arnav
 */

#include "usart_xbee.h"
#include "usart_printf.h"
#include "xbee.h"


char rec_buffer[MAX_BUFFER_LENGTH];
uint32_t rec_buffer_length;
QueueHandle_t xbee_rx_queue;

void usart_xbee_config(uint32_t baudrate)
{
		RCC_AHBPeriphClockCmd(RCC_USART_XBEE_GPIOx, ENABLE);
		RCC_APB1PeriphClockCmd(RCC_USARTx_XBEE, ENABLE);

		GPIO_InitTypeDef 		USART_GPIOx;
		USART_InitTypeDef 		USART_InitStruct;
		USART_ClockInitTypeDef 	USART_ClockInitStruct;
		NVIC_InitTypeDef 		NVIC_InitStructure;


		/* GPIO pin configuration */

		USART_GPIOx.GPIO_Pin    = USART_GPIO_Pin_XBEE;
		USART_GPIOx.GPIO_Mode	= GPIO_Mode_AF;
		USART_GPIOx.GPIO_OType 	= GPIO_OType_PP;
		USART_GPIOx.GPIO_Speed 	= GPIO_Speed_50MHz;
		USART_GPIOx.GPIO_PuPd 	= GPIO_PuPd_NOPULL;

		GPIO_Init(UGPIOx_XBEE, &USART_GPIOx);
	 	GPIO_PinAFConfig(UGPIOx_XBEE, GPIO_PinSource_Tx_XBEE, GPIO_AF_USARTx_XBEE);
	 	GPIO_PinAFConfig(UGPIOx_XBEE, GPIO_PinSource_Rx_XBEE, GPIO_AF_USARTx_XBEE);
	 	GPIO_PinAFConfig(UGPIOx_XBEE, GPIO_PinSource_Ck_XBEE, GPIO_AF_USARTx_XBEE);

	 	/* USART configuration */
	 	USART_InitStruct.USART_BaudRate = baudrate;
	 	USART_InitStruct.USART_WordLength = USART_WordLength_8b;
	 	USART_InitStruct.USART_StopBits = USART_StopBits_1;
	 	USART_InitStruct.USART_Parity = USART_Parity_No;
	 	USART_InitStruct.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	 	USART_InitStruct.USART_Mode = USART_Mode_Tx | USART_Mode_Rx;
	 	USART_Init(USARTx_XBEE, &USART_InitStruct);

	 	USART_ClockStructInit(&USART_ClockInitStruct);
	 	USART_ClockInit(USARTx_XBEE, &USART_ClockInitStruct);

		/* USART interrupt configuration */
		USART_ITConfig(USARTx_XBEE, USARTx_XBEE_IT_FLAG, ENABLE);

		NVIC_InitStructure.NVIC_IRQChannel = USARTx_XBEE_IRQn;
		NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
		NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
		NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
		NVIC_Init(&NVIC_InitStructure);


		/* Enable USART */
	 	USART_Cmd(USARTx_XBEE, ENABLE);

	 	/* Create the Recieve Queue */
	 	xbee_rx_queue = xQueueCreate(RX_QUEUE_MAX_SIZE, sizeof(char));
}

/* Send a Byte to XBee */
void xbee_send_byte(uint8_t ch)
{
  while( !(USARTx_XBEE->ISR & USART_ISR_TC) );
  USARTx_XBEE->TDR = (ch & (uint16_t)0x01FF);
}

/* Send a string to XBee */
int xbee_send(uint8_t * str, uint8_t cmd_length)
{
  int len = cmd_length;
  while(cmd_length > 0)
  {
    xbee_send_byte(*str);
    str++;
    cmd_length--;
  }

  return len; // return that send was successful
}


// this is the interrupt request handler (IRQ) for ALL USARTx interrupts
void USARTx_XBEE_IRQHANDLER(void){

	// check if the USARTx_XBEE receive interrupt flag was set
	if( USART_GetITStatus(USARTx_XBEE, USARTx_XBEE_IT_FLAG) ){

		BaseType_t ret;
		UBaseType_t status;

		BaseType_t xHigherPriorityTaskWoken = pdFALSE;

		while(USART_GetFlagStatus(USARTx_XBEE, USART_FLAG_RXNE))
		{

			status = taskENTER_CRITICAL_FROM_ISR();
			char rx_data = (char) USARTx_XBEE->RDR;
			status = xQueueSendToBackFromISR(xbee_rx_queue, &rx_data, &xHigherPriorityTaskWoken);
			taskEXIT_CRITICAL_FROM_ISR(status);
		}

		portYIELD_FROM_ISR( xHigherPriorityTaskWoken );
	}

}

/* This function is to be called from the Tasks and not from ISR */
int xbee_read(unsigned char* buffer, int len)
{
	/* Probably introduce a delay or predicate for reading */
	/* This is an extreme measure; since this is not blocking */
	/*
	 *	while(uxQueueMessagesWaiting(xQueue == 0);
	 */
	char *rptr = (char*) buffer;

	BaseType_t ret;

	for(int i = 0; i < len; i++){

		taskENTER_CRITICAL();
			char c = 0x00;
			ret = xQueueReceive(xbee_rx_queue, &c, pdMS_TO_TICKS(200)); // This should be blocking, Max time: 2 ms
			if(ret != 0){
				*rptr++ = c;
			}
		taskEXIT_CRITICAL();
	}

	if(rptr == (char *) buffer + len){
		return len;
	}else{
		return -1;
	}
}
