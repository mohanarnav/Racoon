/*
 * rtos_tasks.c
 *
 *  Created on: May 21, 2020
 *      Author: arnav
 */

/* REMEMBER TO FLUSH THE QUEUE IF IT HAS REDUNDANT ITEMS, which are not dequeued */

#include "rtos_tasks.h"
#include "usart_printf.h"
#include "usart_xbee.h"
#include "racoon_test.h"
#include "mqtt_app.h"

TaskHandle_t mqtt_task_handle = NULL;
static volatile int count = 0;

/* There is stack limit of 400/task it seems */
void queue_tasks(void)
{
	xQueue = xQueueCreate(5, sizeof(int32_t));

	if(xQueue != NULL){
		xTaskCreate(mqtt_task, "MQTT_Task", 400, "MQTT_TASK\n\r", 2, NULL);
#ifdef TEST_TASK
		xTaskCreate(test_task, "TEST_Task", 400, "TEST_TASK\r\n", 1, NULL);
#endif
	}
}

void wait_startup( void)
{
    uint16_t t;

    u_printf( "waiting for XBee to start up...\n\r");
    t = XBEE_SET_TIMEOUT_MS( 3000);     		// 3 seconds
    while (! XBEE_CHECK_TIMEOUT_MS( t));		// Make this blocking in STM-FreeRTOS implementation.
}

void mqtt_task(void *pvParameters)
{
	char buff[50];

/* Intializations */
#if 1
	char cmdstr[80];
	int status;

	xbee_serial_t serport;
	serport.baudrate = RATE_115200;
	serport.fd = 0;

	if(xbee_dev_init(&racoon_xbee, &serport, NULL, NULL))
	{
		u_printf("Failed to initialize device. \n\r");
	}else
	{
		u_printf("Device successfully initialized. \n\r");
	}

	wait_startup();

    // Initialize the AT Command layer for this XBee device and have the
    // driver query it for basic information (hardware version, firmware version,
    // serial number, IEEE address, etc.)
	racoon_xbee.mode = XBEE_MODE_API;
	xbee_cmd_init_device(&racoon_xbee);
	u_printf("Waiting for driver to query the XBee Device.. \n\r");
	/*
	 * - Use Blocking when using STM32
	 * - Change to API Mode!! Currently in AT mode
	 *
	 * 	0           query completed
	 *	22 	 -EINVAL     \a xbee is NULL
	 *	16 	 -EBUSY      query underway
	 *	110  -ETIMEDOUT  query timed out  CMD_LIST_TIMEOUT
	 *	5	 -EIO        halted, but query may not have completed
	 */
#endif
#if 1

	do{
		xbee_dev_tick(&racoon_xbee);
		status = xbee_cmd_query_status(&racoon_xbee);
	}while(status == -EBUSY);

	if (status)
    {
        u_printf( "Error %d waiting for query to complete.\n\r");
    }else
	{
    	u_printf( "Query completed successfully\n\r");
	}
#endif
/*******************************************************/

#ifdef TEST_MQTT
	u_printf("TESTING MQTT\n\r");
	test_mqtt(NULL);
#endif

	task_delay(2000);

	TickType_t xLastTick;
	xLastTick = xTaskGetTickCount();

	for(;;)
	{
		GPIO_ToggleBits(GPIOD, GPIO_Pin_8);
#ifdef TEST_TASK
		int len = 8;
		int ret = xbee_ser_read(&xbee_serial, buff, len);

		for(int i = 0; i < len; i++){
			UU_PutChar(buff[i]);
		}
		u_printf("\n\r");
#endif

		if(count < 10){
			u_printf((uint8_t *) pvParameters);
			// mqtt_app();
			init_ipv4_tx_test();
			count++;
		}


		GPIO_ToggleBits(GPIOD, GPIO_Pin_8);
		task_delay(200);
	}

	vTaskDelete(NULL);
}

void task_delay(uint32_t time_in_ms){
	TickType_t xLastTick;
	xLastTick = xTaskGetTickCount();

	vTaskDelayUntil(&xLastTick, pdMS_TO_TICKS(time_in_ms));
}
