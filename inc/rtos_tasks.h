/*
 * rtos_tasks.h
 *
 *  Created on: Mar 31, 2020
 *      Author: arnav
 */

#ifndef RTOS_TASKS_H_
#define RTOS_TASKS_H_

#include "gpio_config.h"
#include "FreeRTOS.h"
#include "task.h"
#include "usart_printf.h"

/* Task Notes
 * 	-Create an Idle hook for performance analysis
 * 	-Tasks can also change each other's or their own priorities
 * 	-If configIDLE_SHOULD_YIELD is set to 1 then the Idle task will yield (voluntarily give
up whatever remains of its allocated time slice) on each iteration of its loop if there are
other Idle priority tasks in the Ready state.
 *	-When the co-operative scheduler is used, a context switch will only occur when the Running
state task enters the Blocked state, or the Running state task explicitly yields (manually
requests a re-schedule) by calling taskYIELD(). Tasks are never pre-empted, so time slicing
cannot be used.
 * -Would probably want to see scheduling again
 */

extern TaskHandle_t task0Handle;
void task0(void *pvParameters);

extern TaskHandle_t task1Handle;
void task1(void *pvParameters);

extern TaskHandle_t task2Handle;
void task2(void *pvParameters);

#endif /* RTOS_TASKS_H_ */
