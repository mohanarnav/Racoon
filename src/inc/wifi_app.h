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
#include <xbee/ipv4.h>
#include <xbee/socket.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <userdef.h>
#include <pthread.h>


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
// Callbacks
void notify_callback(xbee_sock_t socket,
					uint8_t frame_type,
					uint8_t message);

void ip4_callback(xbee_sock_t listening_socket,
                                xbee_sock_t client_socket,
                                uint32_t remote_addr,
                                uint16_t remote_port);

void receive_callback(xbee_sock_t socket,
        uint8_t status,
        const void *payload,
        size_t payload_len);


#endif /* INC_WIFI_APP_H_ */
