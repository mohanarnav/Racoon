#include "usart_printf.h"
#include <stdlib.h>
#include <stdio.h>

#define MAX_STRLEN 50

volatile char rec_string[MAX_STRLEN+1];

void uartConfig(void)
{
		RCC_AHBPeriphClockCmd(RCC_USART_GPIOx, ENABLE);
		RCC_APB1PeriphClockCmd(RCC_USARTx, ENABLE);

		GPIO_InitTypeDef 		USART_GPIOx;
		USART_InitTypeDef 		USART_InitStruct;
		USART_ClockInitTypeDef 	USART_ClockInitStruct;
		NVIC_InitTypeDef 		NVIC_InitStructure;


		/* GPIO pin configuration */

		USART_GPIOx.GPIO_Pin    = USART_GPIO_Pin;
		USART_GPIOx.GPIO_Mode	= GPIO_Mode_AF;
		USART_GPIOx.GPIO_OType 	= GPIO_OType_PP;
		USART_GPIOx.GPIO_Speed 	= GPIO_Speed_50MHz;
		USART_GPIOx.GPIO_PuPd 	= GPIO_PuPd_NOPULL;

		GPIO_Init(UGPIOx, &USART_GPIOx);
	 	GPIO_PinAFConfig(UGPIOx, GPIO_PinSource_Tx, GPIO_AF_USARTx);
	 	GPIO_PinAFConfig(UGPIOx, GPIO_PinSource_Rx, GPIO_AF_USARTx);
	 	GPIO_PinAFConfig(UGPIOx, GPIO_PinSource_Ck, GPIO_AF_USARTx);

	 	/* USART configuration */
	 	USART_InitStruct.USART_BaudRate = BAUDRATE;
	 	USART_InitStruct.USART_WordLength = USART_WordLength_8b;
	 	USART_InitStruct.USART_StopBits = USART_StopBits_1;
	 	USART_InitStruct.USART_Parity = USART_Parity_No;
	 	USART_InitStruct.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	 	USART_InitStruct.USART_Mode = USART_Mode_Tx | USART_Mode_Rx;
	 	USART_Init(USARTx, &USART_InitStruct);

	 	USART_ClockStructInit(&USART_ClockInitStruct);
	 	USART_ClockInit(USARTx, &USART_ClockInitStruct);

		/* USART interrupt configuration */

		USART_ITConfig(USARTx, USART_IT_RXNE, ENABLE);

		NVIC_InitStructure.NVIC_IRQChannel = USARTx_IRQn;
		NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
		NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
		NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
		NVIC_Init(&NVIC_InitStructure);

		/* Enable USART */
	 	USART_Cmd(USARTx, ENABLE);
}

/* Remember USARTx is defined in usart_printf.h */

void UU_PutChar(uint8_t ch)
{
//  while(!(USARTx->SR & USART_IT_TXE)); // THIS MIGHT MOST DEFINITELY BE WRONG
  while( !(USARTx->ISR & USART_ISR_TC) );
  USARTx->TDR = (ch & (uint16_t)0x01FF);
}


void u_printf(uint8_t * str)
{
  while(*str != 0)
  {
    UU_PutChar(*str);
    str++;
  }
}

void u_printf32(uint32_t n)
{

	char c_buf[10] = {0};

	itoa((int32_t) n,c_buf,10);

	u_printf(c_buf);

}

/*
char num_to_hex(uint8_t num)
{
    // char array to store hexadecimal number
    char hexaDeciNum[100];

    // counter for hexadecimal number array
    int i = 0;
    while(n!=0)
    {
        // temporary variable to store remainder
        int temp  = 0;

        // storing remainder in temp variable.
        temp = n % 16;

        // check if temp < 10
        if(temp < 10)
        {
            hexaDeciNum[i] = temp + 48;
            i++;
        }
        else
        {
            hexaDeciNum[i] = temp + 55;
            i++;
        }

        n = n/16;
    }
}
*/

char rx_char;
// this is the interrupt request handler (IRQ) for ALL USARTx interrupts
void USART2_IRQHandler(void){
	// check if the USART1 receive interrupt flag was set
	if( USART_GetITStatus(USARTx, USART_IT_RXNE) ){

		static uint8_t cnt = 0; // this counter is used to determine the string length
		char t = USARTx->RDR; // the character from the USART1 data register is saved in t

#ifndef TEST_MODE
			UU_PutChar(t);
			rx_char = t;
#else
		/* check if the received character is not the LF character (used to determine end of string)
		 * or the if the maximum string length has been been reached
		 */
		if( (t != '\r') && (cnt < MAX_STRLEN) ){
			rec_string[cnt] = t;
			cnt++;
		}
		else{ // otherwise reset the character counter and print the received string
			rec_string[cnt] = '\n';
			cnt++;
			rec_string[cnt] = '\r';
			cnt = 0;
			u_printf(rec_string);
		}
#endif

	}
}



