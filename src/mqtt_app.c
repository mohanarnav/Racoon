/*
 * mqtt_app.c
 *
 *  Created on: May 13, 2020
 *      Author: arnavm89
 */

#include <mqtt_app.h>
#include <stddef.h>
#include <MQTTClient.h>
#include <pthread.h>
#include <wifi_app.h>
#include <unistd.h>

extern
struct opts_struct
{
	char* clientid;
	int nodelimiter;
	char* delimiter;
	enum QoS qos;
	char* username;
	char* password;
	char* host;
	int port;
	int showtopics;
} opts = {
	(char*)"DIGI", 0, (char*)"\n", QOS1, NULL, NULL, (char*)MOSQUITTO_SERVER, MOSQUITTO_PORT, 0
};

#define MAX_BUF_SIZE 1400
unsigned char buf[MAX_BUF_SIZE];
unsigned char readbuf[MAX_BUF_SIZE];

int mqtt_app(void){

/********** Testing Paho MQTT application ***********/
	printf("TESTING PAHO MQTT APPLICATION\n");

	char* topic = "test_topic";

	int rc = 0;

	MessageData message_data;
	Network n;
	MQTTClient c;

#if 0
	signal(SIGINT, cfinish);
	signal(SIGTERM, cfinish);

#endif

	int network_connect_status;
	NetworkInit(&n);
	network_connect_status = NetworkConnect(&n, opts.host, opts.port);
	MQTTClientInit(&c, &n, 100, buf, MAX_BUF_SIZE, readbuf, MAX_BUF_SIZE);
	printf("Network Connection Status: %d\n", network_connect_status);

	MQTTPacket_connectData data = MQTTPacket_connectData_initializer;
	data.willFlag = 0;
	data.MQTTVersion = 4;
	data.clientID.cstring = opts.clientid;
	data.username.cstring = opts.username;
	data.password.cstring = opts.password;

	data.keepAliveInterval = 60;
	data.cleansession = 0;
	printf("Connecting to %s %d\n", opts.host, opts.port);

	rc = MQTTConnect(&c, &data);
	printf("MQTT Connection Status %d\n", rc);


	//    printf("Subscribing to %s\n", topic);
	//	rc = MQTTSubscribe(&c, topic, opts.qos, messageArrived);
	//	printf("Subscribed %d\n", rc);

	/* settting payload */
#if 1
#define MAX_LOAD (MAX_BUF_SIZE - 20)
#define CHAR_SIZE 256
int val = 0;
volatile unsigned char max_payload[MAX_LOAD];

	for(int i = 0; i < MAX_LOAD; i++)
	{
		max_payload[i] = (char) ((val++)%CHAR_SIZE);
	}
#endif

	/* Publishing */
	int count = 0;
	printf("Publishing to %s\n", topic);
	MQTTMessage msg;
	char payload[50] = "Hello Mr. Mohan. Como Esta?";


	msg.qos = 1;
	msg.retained = 0;
	msg.payload = max_payload;
	msg.payloadlen = MAX_LOAD;

	volatile int success = 0;
	volatile int reps = 10;

	uint32_t t0, tf, t0_0, t0_f;
	t0 = xbee_millisecond_timer();

	for(int i = 0; i < reps; i++)
	{
		t0_0 = xbee_millisecond_timer();
		if ((rc = MQTTPublish(&c, "test_topic", &msg)) == 0)
		{
			success++;
		}
		t0_f = xbee_millisecond_timer();
		printf("Time taken for %dst publish: %d ms\n", i, (t0_f - t0_0));
		// usleep(100000);
	}

	tf = xbee_millisecond_timer();

	if(success == reps){
		printf("Published\n");
		float data_rate = (msg.payloadlen * reps)*1000/((float)tf - (float)t0);
		printf("Time taken for 10 publish commands: %d ms\n", (tf - t0));
		printf("Time taken for 1 byte: %f ms\n", 1000/data_rate);
		printf("Data rate: %f bytes/s\n", data_rate);
	}

	printf("Stopping\n");
	MQTTDisconnect(&c);
	NetworkDisconnect(&n);
	printf("Stopped\n");


	return 0;
}
