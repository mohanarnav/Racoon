/*
 * MQTTstm.h
 *
 *  Created on: Aug 28, 2019
 *      Author: arnavm89
 */

#ifndef SRC_STM32_MQTTSTM_H_
#define SRC_STM32_MQTTSTM_H_

#include <wifi_app.h>

typedef struct Timer Timer;

struct Timer {
	unsigned long period;
	unsigned long end_time;
};

typedef struct Network Network;

struct Network
{
	int my_socket;
	int (*mqttread) (Network*, unsigned char*, int, int);
	int (*mqttwrite) (Network*, unsigned char*, int, int);
	void (*disconnect) (Network*);
};

#define TimerInit InitTimer
#define TimerCountdownMS countdown_ms
#define TimerCountdown countdown
#define TimerLeftMS left_ms
#define TimerIsExpired expired
#define NetworkInit NewNetwork
#define NetworkDisconnect stm_disconnect
#define NetworkConnect ConnectNetwork

char expired(Timer*);
void countdown_ms(Timer*, unsigned int);
void countdown(Timer*, unsigned int);
int left_ms(Timer*);

void InitTimer(Timer*);

int stm_read(Network*, unsigned char*, int, int);
int stm_write(Network*, unsigned char*, int, int);
void stm_disconnect(Network*);
void NewNetwork(Network*);
int MQTTConnect_xbee(void);

int ConnectNetwork(Network*, char*, int);
// int TLSConnectNetwork(Network*, char*, int, SlSockSecureFiles_t*, unsigned char, unsigned int, char);


#endif /* SRC_STM32_MQTTSTM_H_ */
