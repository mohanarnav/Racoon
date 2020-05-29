/*
 * gpio_config.h
 *
 *  Created on: Mar 11, 2020
 *      Author: arnav
 */

#ifndef GPIO_CONFIG_H_
#define GPIO_CONFIG_H_

#include "stm32f30x_gpio.h"

void init_GPIO(void);
void GPIO_ToggleBits(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);

#endif /* GPIO_CONFIG_H_ */
