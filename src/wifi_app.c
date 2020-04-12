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

const xbee_dispatch_table_entry_t xbee_frame_handlers[] =
{
    XBEE_FRAME_HANDLE_LOCAL_AT,
    XBEE_FRAME_TABLE_END
};


AT_Command at_command = {.first = "+++", .third = "ATWR", .fourth = "ATAC", .fifth = "ATCN"};

typedef struct{
		char *id;
		char *pass;
		char *dl;
		char *de;

} credentials;

char tcp[] = {0x1};
char port[] = {0x23, 0x2A};
credentials cred = {"Wi So Fi", "allmenmustfi123", "52.43.121.77", (char *) &port};


void connect_to_wifi(void)
{
	int frames;
	int length = 0;

	char** ptr = (char **) &cred;
	char cmds[5][3] = {"ID", "PK", "DL", "DE"};

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
		ret &= check_frame(cmds[i]);
		ptr++;
		sleep(0.01);

		xbee_cmd_execute((xbee_dev_t *) &racoon_xbee, "WR", (const void FAR *) NULL, 0);
		ret &= check_frame("WR");
		sleep(0.01);


		xbee_cmd_execute((xbee_dev_t *) &racoon_xbee, "AC", (const void FAR *) NULL, 0);
		ret &= check_frame("AC");
		sleep(0.01);

#ifdef USER_VERBOSE
		if(!ret){
			printf("%s cmd failed\n", cmds[i]);
		}else{
			printf("%s cmd successfully implemented\n", cmds[i]);
		}
#endif

	}
}

uint8_t check_frame(char *cmd)
{
	uint8_t ret = 0;
	uint8_t timeout = 0;
	do{
		/* Include a timeout here */
		ret = _xbee_frame_load(&racoon_xbee);
		/* Check for Modem status prompts (important) might want to put this is State Machine later */
		if((uint8_t) racoon_xbee.rx.frame_data[0] == 0x8A && (uint8_t) racoon_xbee.rx.frame_data[0] == 0x02)
		{
#ifdef USER_VERBOSE
			printf("Modem Connected\n");
#endif
		}

	}while(*((uint16_t *) &racoon_xbee.rx.frame_data[2]) != *((uint16_t *) cmd));

	if(!timeout && (uint8_t) racoon_xbee.rx.frame_data[4] == 0){
		return 1;
	}else{
		return 0;
	}
}

void print_frame_payload(void)
{
	/* Performs receive too */
	uint8_t ret = _xbee_frame_load(&racoon_xbee);
	printf("\n");
	for(int i = 0; i < racoon_xbee.rx.bytes_in_frame-2; i++)
	{
		printf("%c", racoon_xbee.rx.frame_data[2+i]);
	}
	printf("\nHex Data:\n");

	for(int i = 0; i < racoon_xbee.rx.bytes_in_frame-2; i++)
	{
		printf("%x ", racoon_xbee.rx.frame_data[2+i]);
	}
	printf("\n");
}
