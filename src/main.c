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
#include <unistd.h>
#include "wifi_app.h"

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
	strcpy(serport.device,"/dev/ttyUSB0");

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

	connect_to_wifi();
	print_frame_payload();



	return EXIT_SUCCESS;
}
