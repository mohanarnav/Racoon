/*
 * usart_xbee.h
 *
 *  Created on: May 22, 2020
 *      Author: arnav
 */

#ifndef USART_XBEE_H_
#define USART_XBEE_H_


#include <stdint.h>
#include "stm32f30x_rcc.h"
#include "stm32f30x_usart.h"
#include "stm32f30x_gpio.h"
#include "xbee.h"
#include "rtos_tasks.h"

#define RCC_USART_XBEE_GPIOx RCC_AHBPeriph_GPIOC
#define RCC_USARTx_XBEE RCC_APB1Periph_USART3
#define GPIO_AF_USARTx_XBEE GPIO_AF_7
#define USARTx_XBEE USART3
#define USARTx_XBEE_IRQn USART3_IRQn
#define USARTx_XBEE_IRQHANDLER USART3_IRQHandler
#define UGPIOx_XBEE GPIOC
#define USART_GPIO_Pin_XBEE GPIO_Pin_10 | GPIO_Pin_11 | GPIO_Pin_12
#define GPIO_PinSource_Tx_XBEE GPIO_PinSource10
#define GPIO_PinSource_Rx_XBEE GPIO_PinSource11
#define GPIO_PinSource_Ck_XBEE GPIO_PinSource12
#define BAUD_115200 115200
#define BAUD_921600 921600
#define BAUDRATE BAUD_921600
#define MAX_BUFFER_LENGTH 100
#define USARTx_XBEE_IT_FLAG USART_IT_RXNE
#define RX_QUEUE_MAX_SIZE 100

extern char rec_buffer[MAX_BUFFER_LENGTH];
extern uint32_t rec_buffer_length;
extern QueueHandle_t xbee_rx_queue;

void usart_xbee_config(void);
void xbee_send_byte(uint8_t ch);
void xbee_send(uint8_t * str, uint8_t cmd_length);
void reset_rec_buffer(void);
void xbee_read(void);

#endif /* USART_XBEE_H_ */
