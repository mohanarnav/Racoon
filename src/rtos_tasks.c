/*
 * rtos_tasks.c
 *
 *  Created on: Mar 31, 2020
 *      Author: arnav
 */

#include "rtos_tasks.h"

TaskHandle_t task0Handle = NULL;
TaskHandle_t task1Handle = NULL;

void task0(void *pvParameters)
{
	TickType_t xLastTick;
	xLastTick = xTaskGetTickCount();

	for(;;)
	{
		GPIO_ToggleBits(GPIOD, GPIO_Pin_8);
		u_printf((uint8_t *) pvParameters);
		//vTaskDelay(pdMS_TO_TICKS(10));
		GPIO_ToggleBits(GPIOD, GPIO_Pin_8);
		vTaskDelayUntil(&xLastTick, pdMS_TO_TICKS(100));
	}

	vTaskDelete(task0Handle);

}

void task1(void *pvParameters)
{
	TickType_t xLastTick;
	xLastTick = xTaskGetTickCount();
	for(;;)
	{
		GPIO_ToggleBits(GPIOD, GPIO_Pin_10);
		u_printf((uint8_t *) pvParameters);
		GPIO_ToggleBits(GPIOD, GPIO_Pin_10);
		vTaskDelayUntil(&xLastTick, pdMS_TO_TICKS(50));
	}

	vTaskDelete(task1Handle);

}
