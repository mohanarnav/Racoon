/*
 * MQTTstm32.c
 *
 *  Created on: Aug 28, 2019
 *      Author: arnavm89
 */


#include "MQTTstm.h"
// #include "usart_layer.h"

static xbee_ipv4_envelope_t tx_envelope;


char expired(Timer* timer) {
	long left = timer->end_time - xbee_millisecond_timer();
	return (left < 0);
}


void countdown_ms(Timer* timer, unsigned int timeout) {
	timer->end_time = xbee_millisecond_timer() + timeout;
}


void countdown(Timer* timer, unsigned int timeout) {
	timer->end_time = xbee_millisecond_timer() + (timeout * 1000);
}


int left_ms(Timer* timer) {
	long left = timer->end_time - xbee_millisecond_timer();
	return (left < 0) ? 0 : left;
}


void InitTimer(Timer* timer) {
	timer->end_time = 0;
}


int stm_read(Network* n, unsigned char* buffer, int len, int timeout_ms) {

	int rc = 0;
	int recvLen = 0;

	/* Create Time Out Operation */

	/* USART Operation */
	int bytes = 0;
	while (bytes < len)
	{
		int rc = get_mqtt_payload(&buffer[bytes], (len - bytes));
		if (rc == -1)
		{
			// if (errno != EAGAIN && errno != EWOULDBLOCK)
			/* Error state not possible */
			  bytes = -1;
			break;
		}
		else if (rc == 0)
		{
			bytes = 0;
			break;
		}
		else
			bytes += rc;
	}
	return bytes;
}


int stm_write(Network* n, unsigned char* buffer, int len, int timeout_ms) {
	int retval = 0, rc = 0;

	/* Create Time Out Operation */

	tx_envelope.payload = (const void FAR *) buffer;          //< contents of message
	tx_envelope.length = len;

	retval = xbee_ipv4_envelope_send(&tx_envelope);

	if(retval == 0){
		rc = tx_envelope.length;
	}
	return rc;
}


void stm_disconnect(Network* n) {
//	sl_Close(n->my_socket);
}


void NewNetwork(Network* n) {
	n->my_socket = 0;
	n->mqttread = stm_read;
	n->mqttwrite = stm_write;
	n->disconnect = stm_disconnect;
}


int ConnectNetwork(Network* n, char* addr, int port)
{
	uint32_t remort_addr_be;

	xbee_ipv4_aton(addr, &remort_addr_be);
	tx_envelope.xbee = &racoon_xbee;
	tx_envelope.remote_addr_be = remort_addr_be;            		//< remote device's IP address
	tx_envelope.remote_port = (uint16_t) port;               			//< port on remote device
	tx_envelope.protocol = 0x1;                  				//< protocol for message

	return 0;
}

int MQTTConnect_xbee(void)
{
	int rc;
	return 0;
}
