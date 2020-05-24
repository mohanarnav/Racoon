/*
 * xbee.h
 *
 *  Created on: May 22, 2020
 *      Author: arnav
 */

#ifndef XBEE_H_
#define XBEE_H_


#include <xbee/platform.h>
#include <xbee/device.h>
#include <xbee/atcmd.h>
#include <xbee/ipv4.h>
#include <xbee/socket.h>
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

#define TIMEOUT 100

#define RATE_115200 115200
#define RATE_921600	921600

extern volatile uint8_t read_xbee;
extern pthread_cond_t c_read;
extern pthread_cond_t c_write;
extern pthread_mutex_t m;
extern volatile char at_cmd_str[3];


extern xbee_dev_t racoon_xbee;
extern AT_Command at_command;
extern volatile uint8_t ack_status;
extern volatile uint8_t modem_status;

typedef enum{
	NO_MATCH = 0,
	MATCH,
	MODEM_ACTIVITY,
	WIFI_STATE_COMPLETE,

}frame_return_values;

uint8_t connect_to_wifi(void);
uint8_t check_frame(char *cmd);
void process_rxipv4_frame_payload(void);
void init_ipv4_tx_test(void);
uint8_t get_RxIpv4_payload(void);
int get_mqtt_payload(unsigned char* buffer, int len);

void init_socket_api(void);

#endif /* XBEE_H_ */
