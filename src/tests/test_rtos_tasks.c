/*
 * rtos_tasks.c
 *
 *  Created on: Mar 31, 2020
 *      Author: arnav
 */

#include "rtos_tasks.h"

TaskHandle_t task0Handle = NULL;
TaskHandle_t task1Handle = NULL;
TaskHandle_t task2Handle = NULL;

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

/* Implementing a blocking Queue */
QueueHandle_t xQueue;

void vSenderTask(void *pvParameters)
{
	int32_t lValueToSend;
	BaseType_t xStatus;

	lValueToSend = (int32_t) pvParameters;

	for(;;){

		GPIO_ToggleBits(GPIOD, GPIO_Pin_8);
		xStatus = xQueueSendToBack(xQueue, &lValueToSend, 0);
		GPIO_ToggleBits(GPIOD, GPIO_Pin_8);

		if(xStatus != pdPASS)
		{
			u_printf("Could not send to the queue. \r\n");
		}
	}
}

void vReceiverTask(void *pvParameters)
{
	int32_t lReceivedValue;
	BaseType_t xStatus;
	const TickType_t xTicksToWait = pdMS_TO_TICKS(100);

	for(;;){

		if(uxQueueMessagesWaiting(xQueue) != 0){
			u_printf("Queue should have been empty!\r\n");
		}

		GPIO_ToggleBits(GPIOD, GPIO_Pin_10);
		xStatus = xQueueReceive(xQueue, &lReceivedValue, xTicksToWait);
		GPIO_ToggleBits(GPIOD, GPIO_Pin_10);

		if(xStatus == pdPASS)
		{
			u_printf("received: ");
			u_printf32(lReceivedValue);
			u_printf("\r\n");
		}else{
			u_printf("Couldn't receive from the queue. \r\n");
		}
	}
}

void test_queue(void)
{
	xQueue = xQueueCreate(5, sizeof(int32_t));

	if(xQueue != NULL){
		xTaskCreate(vReceiverTask, "Receiver", 400, NULL, 2, NULL);
		xTaskCreate(vSenderTask, "Sender1", 400, (void *) 100, 1, NULL);
		xTaskCreate(vSenderTask, "Sender2", 400, (void *) 200, 1, NULL);
	}
}
