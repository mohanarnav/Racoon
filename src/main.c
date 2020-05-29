/**
  ******************************************************************************
  * @file    main.c
  * @author  Ac6
  * @version V1.0
  * @date    01-December-2013
  * @brief   Default main function.
  ******************************************************************************
*/


#include "stm32f30x.h"
#include "stm32f3_discovery.h"
#include "usart_printf.h"

#include "usart_xbee.h"
#include "rtos_tasks.h"

const char* task0_text = "Task0 Running: Arnav Mohan is Awesome\n\r";
const char* task1_text = "Task1 Running: Meh\n\r";
const char* task2_text = "Task2 Running: Meh Et Tu?\n\r";

int main(void)
{
	init_GPIO();
	uartConfig();
	usart_xbee_config(BAUD_115200);
	u_printf("Running...\n\r");
	/*	TaskFunction, Task Name, Stack Size, Pointer to parameters, task priority, handle to the task */
//	xTaskCreate(task1, "task1", 200, (void *) task1_text, 1, NULL);
//	xTaskCreate(task2, "task2", 200, (void *) task2_text, 1, &task2Handle);

//	xTaskCreate(task0, "task0", 200, (void *) task0_text, 2, NULL);

	queue_tasks();
	vTaskStartScheduler();
	for(;;);
}
