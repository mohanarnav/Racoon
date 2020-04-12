/*
 * gpio_config.c
 *
 *  Created on: Mar 11, 2020
 *      Author: arnav
 */

#include "gpio_config.h"

void init_GPIO(void){

	/* Initializing for GPIOA Pins */
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOD, ENABLE);
	GPIO_InitTypeDef gpio_init_struct;
	gpio_init_struct.GPIO_Pin = GPIO_Pin_4 |
						GPIO_Pin_5 |
						GPIO_Pin_6 |
						GPIO_Pin_7 |
						GPIO_Pin_8 |
						GPIO_Pin_9 |
						GPIO_Pin_10;
	gpio_init_struct.GPIO_Mode = GPIO_Mode_OUT;
	gpio_init_struct.GPIO_Speed = GPIO_Speed_50MHz;
	gpio_init_struct.GPIO_OType = GPIO_OType_PP;
	gpio_init_struct.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_Init(GPIOD, &gpio_init_struct);

}

void GPIO_ToggleBits(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin)
{
	GPIOx->ODR ^= GPIO_Pin;
}
