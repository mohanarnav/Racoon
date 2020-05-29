/*
 * xbee.c
 *
 *  Created on: May 22, 2020
 *      Author: arnav
 */


#include "rtos_tasks.h"
#include "xbee.h"
#include "xbee/device.h"
#include "xbee/firmware.h"
#include "xbee/atcmd.h"         // for XBEE_FRAME_HANDLE_LOCAL_AT
#include <string.h>
#include <unistd.h>
#include <xbee_queue.h>

xbee_dev_t racoon_xbee;
volatile uint8_t read_xbee = 0;
volatile uint8_t ack_status = 0;
volatile uint8_t modem_status = 0;

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
		sleep(0.1);

		xbee_cmd_execute((xbee_dev_t *) &racoon_xbee, "WR", (const void FAR *) NULL, 0);
		ret &= send_ack("WR");
		sleep(0.1);


		xbee_cmd_execute((xbee_dev_t *) &racoon_xbee, "AC", (const void FAR *) NULL, 0);
		ret &= send_ack("AC");
		sleep(0.1);

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
		sleep(0.1);
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

	printf("API-ID: %0.2x\n", (uint8_t) racoon_xbee.rx.frame_data[0]);

	/* Modem Activity
	 * 0: Hardware reset or power up
	 * 1: Watchdog timer reset
	 * 2: Joined
	 * 3: No Longger joined to access point
	 * 0x0E: Remote manager connected
	 * 0x0F: Remote manager disconnected
	 * */
	if((uint8_t) racoon_xbee.rx.frame_data[0] == 0x8A)
	{
#ifdef USER_VERBOSE
/*			printf("Modem Detected\n");
			printf("Status: %0.2x\n", (uint8_t) racoon_xbee.rx.frame_data[1]); */
#endif
			modem_status = (uint8_t) racoon_xbee.rx.frame_data[1];
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

/* For stm put this in an interrupt; or improve resolution */
uint8_t get_RxIpv4_payload(void)
{
	volatile int rx_found = 0;
	/* Checking for Modem activity */
	if(racoon_xbee.rx.frame_data[0]==0x8A)
	{
		//printf("Modem Activity: %0.2x\n", racoon_xbee.rx.frame_data[1]);
	}

	/* Checking for AT Command Response */
	if(racoon_xbee.rx.frame_data[0]==0x88)
	{
		// printf("AT Command Response: %0.2x\n", racoon_xbee.rx.frame_data[2]);
	}

	/* Checking for Tx Status messages */
	if(racoon_xbee.rx.frame_data[0]==0x89)
	{
		//printf("Tx Status: %0.2x\n", racoon_xbee.rx.frame_data[2]);
	}
	/* Checking of Rx */
	if(racoon_xbee.rx.frame_data[0]==0xB0){
#ifdef USER_VERBOSE
		//printf("RxIPv4 found\n");
		process_rxipv4_frame_payload();
#endif
		rx_found++;
	}

	return 0;
}

/* IPV4 frame API functionalities */
#define RXIPV4_OFFSET 11
void process_rxipv4_frame_payload(void)
{
	for(int i = RXIPV4_OFFSET; i < racoon_xbee.rx.bytes_in_frame; i++)
	{
		enQueue(&payload_queue, racoon_xbee.rx.frame_data[i]);
		//UU_PutChar(racoon_xbee.rx.frame_data[i]);
	}
	//u_printf("\n\r");

#if 0
	printf("ASCIIdata: \n");
	for(int i = RXIPV4_OFFSET; i < racoon_xbee.rx.bytes_in_frame; i++)
	{
		printf("%c", racoon_xbee.rx.frame_data[i]);
	}
	printf("Hex Data:\n");

	for(int i = RXIPV4_OFFSET; i < racoon_xbee.rx.bytes_in_frame; i++)
	{
		printf("%x ", racoon_xbee.rx.frame_data[i]);
	}
	printf("\n");
#endif
}


int get_mqtt_payload(unsigned char* buffer, int len){

	int dt = 0;
	int rx_t0 = xbee_millisecond_timer();

	/* Replace with blocking queue */
	while(isEmpty(&payload_queue) && dt <= TIMEOUT){

		volatile int ret_xbee = 0;

		ret_xbee = _xbee_frame_load(&racoon_xbee);

		if(ret_xbee != 0){
			get_RxIpv4_payload();
		}

		dt = xbee_millisecond_timer() - rx_t0;
	}


	if(!isEmpty(&payload_queue)){
		char *rptr = (char *) buffer;

		for(int i = 0; i < len; i++){
			*rptr = deQueue(&payload_queue);
			UU_PutChar(*rptr);
			rptr++;
		}
		u_printf("\n\r");
		return len;
	}else{
		u_printf("TIMEOUT FOR MQTT READ\n\r");
		return -1;
	}


}


/* Not to be called from an ISR */
void init_ipv4_tx_test(void)
{
	char payload[] = {0x0D};
	tx_envelope.xbee = &racoon_xbee;
	tx_envelope.remote_addr_be = 0x4D792B34;            		//< remote device's IP address
	tx_envelope.remote_port = 0x232A;               			//< port on remote device
	tx_envelope.protocol = 0x1;                  				//< protocol for message
	tx_envelope.payload = (const void FAR *) &payload;          //< contents of message
	tx_envelope.length = 1;

	unsigned char buffer[100];
	uint32_t t0, tf;

	t0 = xbee_millisecond_timer();

	int ret = xbee_ipv4_envelope_send(&tx_envelope);

	get_mqtt_payload(&buffer[0],2);
	get_mqtt_payload(&buffer[2],4);

	flushQueue(&payload_queue);

/* Only to be used if delay is required.
	TickType_t xLastTick;
	xLastTick = xTaskGetTickCount();
	vTaskDelayUntil(&xLastTick, pdMS_TO_TICKS(100));
*/
#if 0
	volatile int ret_xbee = 0;

	int dt = 0;
	volatile int msg_rec = 0;
	int rx_t0 = xbee_millisecond_timer();
	while(ret_xbee == 0 && dt <= TIMEOUT){
		ret_xbee = _xbee_frame_load(&racoon_xbee);

		if(ret_xbee != 0){
			msg_rec++;
			get_RxIpv4_payload();
		}

		dt = xbee_millisecond_timer() - rx_t0;
	}

	tf = xbee_millisecond_timer();

	u_printf("No. of msgs: ");
	u_printf32(msg_rec);
	u_printf("\n\r");
	u_printf("Time taken for capture:");
	u_printf32(tf - t0);
	u_printf("\n\rEnd of ipv4 test \n\r\n\r");
#endif
}
