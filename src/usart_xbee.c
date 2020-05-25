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

/* Remember USARTx is defined in usart_printf.h */

void xbee_send_byte(uint8_t ch)
{
//  while(!(USARTx->SR & USART_IT_TXE)); // THIS MIGHT MOST DEFINITELY BE WRONG
  while( !(USARTx_XBEE->ISR & USART_ISR_TC) );
  USARTx_XBEE->TDR = (ch & (uint16_t)0x01FF);
}


void xbee_send(uint8_t * str, uint8_t cmd_length)
{
  while(cmd_length > 0)
  {
//	u_printf32(*str);
//	u_printf(" ");
    xbee_send_byte(*str);
    str++;
    cmd_length--;
  }
}


void reset_rec_buffer(void)
{
	rec_buffer_length = 0;
}

#if 1
volatile uint8_t buffer_overflow_flag = 0;

// this is the interrupt request handler (IRQ) for ALL USARTx interrupts
void USARTx_XBEE_IRQHANDLER(void){
	// check if the USART1 receive interrupt flag was set
	if( USART_GetITStatus(USARTx_XBEE, USARTx_XBEE_IT_FLAG) ){

		BaseType_t ret;
		UBaseType_t status;

		BaseType_t xHigherPriorityTaskWoken = pdFALSE;

		while(USART_GetFlagStatus(USARTx_XBEE, USART_FLAG_RXNE))
		{

			status = taskENTER_CRITICAL_FROM_ISR();
			char rx_data = (char) USARTx_XBEE->RDR;
			// UU_PutChar(rx_data);
			status = xQueueSendToBackFromISR(xbee_rx_queue, &rx_data, &xHigherPriorityTaskWoken);
			taskEXIT_CRITICAL_FROM_ISR(status);
		}

		portYIELD_FROM_ISR( xHigherPriorityTaskWoken );
	}
}
#endif

#if 1
volatile int packet_ctr = 0, packet_itr = 0, packet_error = 0;
volatile int16_t packet_length = 0;
volatile uint8_t in_read = 0;
int rc;

void read_fn(char c)
{

}

#if 0
extern volatile uint8_t queue_flag;

void USARTx_XBEE_IRQHANDLER(void){

	if( USART_GetITStatus(USARTx_XBEE, USARTx_XBEE_IT_FLAG) ){
		// queue_flag = 1;
		// GPIO_ToggleBits(GPIOD, GPIO_Pin_9);
		char c = USARTx_XBEE->RDR;
		read_fn(c);
	}
}
#endif

int no_of_bits_captured = 0;
/* Make sure that interrupt control is off */
void xbee_read(void)
{
	while(USART_GetFlagStatus(USARTx_XBEE, USART_FLAG_RXNE))
	{
		char c = USARTx_XBEE->RDR;
		// u_printf32((uint8_t) c);
		no_of_bits_captured++;
		read_fn(c);
	}
}
#endif
