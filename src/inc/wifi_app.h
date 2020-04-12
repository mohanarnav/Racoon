/*
 * wifi_app.h
 *
 *  Created on: Apr 3, 2020
 *      Author: arnavm89
 */

#ifndef INC_WIFI_APP_H_
#define INC_WIFI_APP_H_


#include <xbee/platform.h>
#include <xbee/device.h>
#include <xbee/atcmd.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <userdef.h>

typedef struct{
	char* first;
	char* command;
	char* third;
	char* fourth;
	char* fifth;
}AT_Command;

#ifdef RACOON_POSIX
#define BYTE_SIZE 8
#else
#define BYTE_SIZE 4
#endif

extern xbee_dev_t racoon_xbee;


void connect_to_wifi(void);
uint8_t check_frame(char *cmd);
void print_frame_payload(void); // Perfroms receive frame too.

extern AT_Command at_command;
#endif /* INC_WIFI_APP_H_ */
