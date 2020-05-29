#include <stdint.h>

#include "stm32f30x.h"
#include "stm32f30x_usart.h"
#include "stm32f30x_rcc.h"
#include "stm32f30x_gpio.h"
//#include "iot_app.h"

#define RCC_USART_GPIOx RCC_AHBPeriph_GPIOA
#define RCC_USARTx RCC_APB1Periph_USART2
#define GPIO_AF_USARTx GPIO_AF_7
#define USARTx USART2
#define USARTx_IRQn USART2_IRQn
#define UGPIOx GPIOA
#define USART_GPIO_Pin GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_4
#define GPIO_PinSource_Tx GPIO_PinSource2
#define GPIO_PinSource_Rx GPIO_PinSource3
#define GPIO_PinSource_Ck GPIO_PinSource4
#define PRINT_BAUDRATE 115200

void uartConfig();
void UU_PutChar(uint8_t ch);
void u_printf(uint8_t * str);
void u_printf32(uint32_t n);
