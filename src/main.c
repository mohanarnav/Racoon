/*
 ============================================================================
 Name        : main.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : IoT application through XBeeS6B wifi module.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <pthread.h>
#include "wifi_app.h"

pthread_t back_thread;
pthread_cond_t c_read = PTHREAD_COND_INITIALIZER;
pthread_cond_t c_write = PTHREAD_COND_INITIALIZER;
pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER;

volatile uint8_t connection_state = 0;

void *back_task(void * param);

void wait_startup( void)
{
    uint16_t t;

    printf( "waiting for XBee to start up...\n");
    t = XBEE_SET_TIMEOUT_MS( 3000);     		// 3 seconds
    while (! XBEE_CHECK_TIMEOUT_MS( t));		// Make this blocking in STM-FreeRTOS implementation.
}

void wait(uint16_t time)
{
	uint16_t t = XBEE_SET_TIMEOUT_MS(time);     		// in milliseconds
	while (! XBEE_CHECK_TIMEOUT_MS( t));				// Make this blocking in STM-FreeRTOS implementation.
}

int main(void) {

	char cmdstr[80];
	int status;

	xbee_serial_t serport;
	serport.baudrate = 115200;
	serport.fd = 0;
	strcpy(serport.device,"/dev/ttyUSB1");

	if(xbee_dev_init(&racoon_xbee, &serport, NULL, NULL))
	{
		printf("Failed to initialize device. \n\r");
		return 0;
	}else
	{
		printf("Device successfully initialized. \n\r");
	}

	wait_startup();

    // Initialize the AT Command layer for this XBee device and have the
    // driver query it for basic information (hardware version, firmware version,
    // serial number, IEEE address, etc.)
	racoon_xbee.mode = XBEE_MODE_API;
	xbee_cmd_init_device(&racoon_xbee);
	printf("Waiting for driver to query the XBee Device.. \n");
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


	do{
		xbee_dev_tick(&racoon_xbee);
		status = xbee_cmd_query_status(&racoon_xbee);
	}while(status == -EBUSY);

	if (status)
    {
        printf( "Error %d waiting for query to complete.\n", status);
    }else
	{
    	printf( "Query completed successfully: %d.\n", status);
	}

	// report on the settings
	/* Change the print function for STM32 */
	xbee_dev_dump_settings( &racoon_xbee, XBEE_DEV_DUMP_FLAG_DEFAULT);

/* Setting up background thread */

	if(pthread_create(&back_thread, NULL, back_task, NULL) != 0){
		printf("Error in creating a background thread");
		exit(1);
	}

	sleep(1);

/* Create a debug thread */
	printf("Connecting to Wifi\n");
	uint8_t ret = connect_to_wifi();
	if(ret == WIFI_STATE_COMPLETE){
		printf("Wifi state machine succeeded in process\n");
		connection_state++;
	}
	sleep(5);

//	init_ipv4_tx_test();
	pthread_join(back_thread, NULL);

	return EXIT_SUCCESS;
}

typedef enum{
	DISCONNECTED = 0,
	CONNECTED = 1,
	MQTT_CONNECTED = 2
}State;

void *back_task(void *param){
	printf("Running Background Thread\n\n");

	/* Create a continuous read scenario */
	for(;;){

		volatile bool_t timeout = false;

		/* Enter Critical Section */
		pthread_mutex_lock(&m);
			while(read_xbee == 0)
				pthread_cond_wait(&c_read, &m);

		pthread_mutex_unlock(&m);

		int dt = 0;
		int t0 = xbee_millisecond_timer();
		while(_xbee_frame_load(&racoon_xbee)==0 && dt <= TIMEOUT)
			dt = xbee_millisecond_timer() - t0;

		if(dt > TIMEOUT)
		{
			printf("frame_load TIMEOUT\n");
			timeout = true;
			read_xbee = 0; // No more frames to be loaded from receive.
			pthread_cond_signal(&c_write); // Wake up any thread waiting to send a cmd.
		}

		if(!timeout){

			uint8_t ret = 0;
			switch(connection_state){
				case DISCONNECTED:
					ret = check_frame((char* ) &at_cmd_str);
					if(ret == MATCH){
						ack_status = 0x1;
					}
					break;
				default:
					break;
			}
		}

	}


}