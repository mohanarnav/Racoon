/*
 * task_test.c
 *
 *  Created on: May 24, 2020
 *      Author: arnav
 */


#include "rtos_tasks.h"
#include "usart_printf.h"
#include "usart_xbee.h"
#include "xbee/platform.h"

xbee_serial_t xbee_serial;

void test_task(void *pvParameters)
{
	TickType_t xLastTick;
	xLastTick = xTaskGetTickCount();
	uint32_t t0 = xbee_millisecond_timer();
	uint32_t tf;

	for(;;)
	{
		char *msg = "Hello Arnav\r\n";
		GPIO_ToggleBits(GPIOD, GPIO_Pin_10);
		xbee_ser_write(&xbee_serial, msg, 13);
		GPIO_ToggleBits(GPIOD, GPIO_Pin_10);
		vTaskDelayUntil(&xLastTick, pdMS_TO_TICKS(100));

		/* Testing xbee_millisecond_timer; should return 100 ms */
		tf = xbee_millisecond_timer();
		uint32_t dt = tf - t0;
		t0 = tf;
		configASSERT(dt >= 90); // Check out the hook for config assert


	}

	vTaskDelete(NULL);

}
