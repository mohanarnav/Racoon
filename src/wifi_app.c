/*
 * wifi_app.c
 *
 *  Created on: Apr 3, 2020
 *      Author: arnavm89
 */

#include "wifi_app.h"
#include "xbee/device.h"
#include "xbee/firmware.h"
#include "xbee/atcmd.h"         // for XBEE_FRAME_HANDLE_LOCAL_AT
#include <string.h>
#include <unistd.h>

xbee_dev_t racoon_xbee;
volatile uint8_t read_xbee = 0;
volatile uint8_t ack_status = 0;

const xbee_dispatch_table_entry_t xbee_frame_handlers[] =
{
    XBEE_FRAME_HANDLE_LOCAL_AT,
    XBEE_FRAME_TABLE_END
};

/* AT command Specifications for connecting to wireless router */

typedef struct{
		char *id;
		char *pass;
		char *dl;
		char *de;

} credentials;

char tcp[] = {0x1};
char port[] = {0x23, 0x2A};
credentials cred = {"Wi So Fi", "allmenmustfi123", "52.43.121.77", (char *) &port};

/* IP4 initializations for Recieve and Transmit envelops */
xbee_ipv4_envelope_t tx_envelope;

typedef enum{
	ID = 0,
	PK,
	DL,
	DE,
	NO_OF_STEPS
}connect_to_wifi_state;

uint8_t wifi_state = ID;
char cmds[5][3] = {"ID", "PK", "DL", "DE"};
volatile char at_cmd_str[3];

uint8_t send_ack(char* cmd)
{
	read_xbee++;
	strcpy(at_cmd_str, cmd);
	pthread_cond_signal(&c_read);

	pthread_mutex_lock(&m);
		while(read_xbee > 0)
			pthread_cond_wait(&c_write, &m);
	pthread_mutex_unlock(&m);

	// printf("Cmd executed: %s with status: %d\n", cmd, ack_status);
	uint8_t ret = ack_status;
	ack_status = 0;
	return ret;
}

uint8_t connect_to_wifi(void)
{
	int length = 0;
	char** ptr = (char **) &cred;

	for(int i = 0; i < sizeof(cred)/BYTE_SIZE; i++)
	{
#ifdef USER_VERBOSE
		printf("\n");
#endif
		if(!strcmp(cmds[i], "IP"))
		{
			length = 1;
		}else if(!strcmp(cmds[i], "DE")){
			length = 2;
		}else{
			length = strlen(*ptr);
		}
		uint8_t ret = 1;
		xbee_cmd_execute((xbee_dev_t *) &racoon_xbee, cmds[i], (const void FAR *) *ptr, length);
		ret &= send_ack(cmds[i]);
		ptr++;
		sleep(0.01);

		xbee_cmd_execute((xbee_dev_t *) &racoon_xbee, "WR", (const void FAR *) NULL, 0);
		ret &= send_ack("WR");
		sleep(0.01);


		xbee_cmd_execute((xbee_dev_t *) &racoon_xbee, "AC", (const void FAR *) NULL, 0);
		ret &= send_ack("AC");
		sleep(0.01);

		if(!ret){
#ifdef USER_VERBOSE
			printf("%s cmd failed\n", cmds[i]);
#endif
		}else{
#ifdef USER_VERBOSE
			printf("%s cmd successfully implemented\n", cmds[i]);
#endif
			wifi_state++;
		}
	}
	if(wifi_state == NO_OF_STEPS){
		return WIFI_STATE_COMPLETE;
	}else
	{
		return 0;
	}
}


uint8_t check_frame(char *cmd)
{
	uint8_t ret = 0;
	uint8_t timeout = 0;

	if((uint8_t) racoon_xbee.rx.frame_data[0] == 0x8A)
	{
#ifdef USER_VERBOSE
			printf("Modem Activity Detected\n");
			printf("Status: %0.2x\n", (uint8_t) racoon_xbee.rx.frame_data[0]);
#endif
			ret = MODEM_ACTIVITY;
	}

	if((uint8_t) racoon_xbee.rx.frame_data[0] == 0x88 &&
			   *((uint16_t *) &racoon_xbee.rx.frame_data[2]) == *((uint16_t *) cmd)){

			ret = MATCH;
	}


	if((uint8_t) racoon_xbee.rx.frame_data[4] == 0){
		return ret;

	}else{
		return NO_MATCH;
	}
}

uint8_t get_RxIpv4_payload(void)
{
	/* Make this blocking in STM */
	int t0 = xbee_millisecond_timer();
	int dt = t0;
	volatile int rx_found = 0;
	do{
		uint8_t ret = _xbee_frame_load(&racoon_xbee);
		dt = xbee_millisecond_timer() - t0;
		/* Checking for Tx Status messages */
		if(racoon_xbee.rx.frame_data[0]==0x89 && ret != 0)
		{
			printf("Tx Status: %0.2x\n", racoon_xbee.rx.frame_data[2]);
		}
		/* Checking of Rx */
		if(racoon_xbee.rx.frame_data[0]==0xB0 && ret != 0){
#ifdef USER_VERBOSE
			printf("RxIPv4 found\n");
			print_rxipv4_frame_payload();

#endif
			rx_found++;
		}
	}while(dt < 2000);

	if(dt > 2000)
	{
		printf("RxIPv4 Timeout\n");
	}
	return 0;
}

/* IPV4 frame API functionalities */
#define RXIPV4_OFFSET 11
void print_rxipv4_frame_payload(void)
{
	printf("\nASCIIdata: \n");
	for(int i = RXIPV4_OFFSET; i < racoon_xbee.rx.bytes_in_frame; i++)
	{
		printf("%c", racoon_xbee.rx.frame_data[i]);
	}
	printf("\nHex Data:\n");

	for(int i = RXIPV4_OFFSET; i < racoon_xbee.rx.bytes_in_frame; i++)
	{
		printf("%x ", racoon_xbee.rx.frame_data[i]);
	}
	printf("\n");
}

void init_ipv4_tx_test(void)
{
	char payload[] = {0x0D};
	tx_envelope.xbee = &racoon_xbee;
	tx_envelope.remote_addr_be = 0x4D792B34;            		//< remote device's IP address
	tx_envelope.remote_port = 0x232A;               			//< port on remote device
	tx_envelope.protocol = 0x1;                  				//< protocol for message
	tx_envelope.payload = (const void FAR *) &payload;          //< contents of message
	tx_envelope.length = 1;

	int ret = xbee_ipv4_envelope_send(&tx_envelope);

	get_RxIpv4_payload();

}

/* Socket API functionalities */
xbee_sock_t xbee_sock;
uint16_t local_port = 0;

void init_socket_api(void){

	xbee_sock = xbee_sock_create(&racoon_xbee,
			XBEE_SOCK_PROTOCOL_TCP,
			notify_callback);

	xbee_sock_connect(xbee_sock, 0x232A,
						0x342B794D, "52.43.121.77",
						 	 receive_callback);

	// xbee_sock_listen(xbee_sock, local_port,
		//				ip4_callback);

	char payload[] = {0x0D};

	xbee_sock_send(xbee_sock, 0,
	                   (const void *) &payload, 1);


}



// Callbacks
void notify_callback(xbee_sock_t socket,
					uint8_t frame_type,
					uint8_t message)
{
	printf("Notify Callback\n");
}

void ip4_callback(xbee_sock_t listening_socket,
                                xbee_sock_t client_socket,
                                uint32_t remote_addr,
                                uint16_t remote_port)
{
	printf("Ipv4 Callback\n");
}

void receive_callback(xbee_sock_t socket,
        uint8_t status,
        const void *payload,
        size_t payload_len)
{
	printf("Receive Callback\n");
}

