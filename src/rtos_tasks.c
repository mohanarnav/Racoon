/*
 * rtos_tasks.c
 *
 *  Created on: May 21, 2020
 *      Author: arnav
 */


#include "rtos_tasks.h"
#include "usart_printf.h"
#include "usart_xbee.h"

TaskHandle_t mqtt_task_handle = NULL;

/* There is stack limit of 400/task it seems */
void queue_tasks(void)
{
	xQueue = xQueueCreate(5, sizeof(int32_t));

	if(xQueue != NULL){
		xTaskCreate(mqtt_task, "MQTT_Task", 400, "MQTT_TASK\n\r", 1, NULL);
		xTaskCreate(test_task, "TEST_Task", 400, "TEST_TASK\r\n", 1, NULL);
	}
}

void mqtt_task(void *pvParameters)
{
	TickType_t xLastTick;
	xLastTick = xTaskGetTickCount();

	for(;;)
	{
		GPIO_ToggleBits(GPIOD, GPIO_Pin_8);
		u_printf((uint8_t *) pvParameters);

		BaseType_t ret;

		taskENTER_CRITICAL();
		while(uxQueueMessagesWaiting(xbee_rx_queue) != 0){
			char c;
			ret = xQueueReceive(xbee_rx_queue, &c, 0);
			UU_PutChar(c);
		}
		taskEXIT_CRITICAL();
		u_printf("\n\r");
		GPIO_ToggleBits(GPIOD, GPIO_Pin_8);
		vTaskDelayUntil(&xLastTick, pdMS_TO_TICKS(100));
	}

	vTaskDelete(NULL);
}


void test_task(void *pvParameters)
{
	TickType_t xLastTick;
	xLastTick = xTaskGetTickCount();
	for(;;)
	{
		char *msg = "Hello Arnav\r\n";
		GPIO_ToggleBits(GPIOD, GPIO_Pin_10);
		xbee_send(msg, strlen(msg));
		GPIO_ToggleBits(GPIOD, GPIO_Pin_10);
		vTaskDelayUntil(&xLastTick, pdMS_TO_TICKS(500));
	}

	vTaskDelete(NULL);

}
