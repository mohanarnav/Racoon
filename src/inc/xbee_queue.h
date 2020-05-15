/*
 * xbee_queue.h
 *
 *  Created on: May 13, 2020
 *      Author: arnavm89
 */

#ifndef INC_XBEE_QUEUE_H_
#define INC_XBEE_QUEUE_H_

#include <stdint.h>

typedef uint8_t byte;

typedef struct
{
    // Initialize front and rear
    int rear, front;

    // Circular Queue
    int size;
    byte *arr;
}Queue;

extern Queue payload_queue;

#define INT_MIN 0xFF
#define QUEUE_SIZE 100

void enQueue(Queue* q, byte value);
byte deQueue(Queue* q);
void displayQueue(Queue* q);
uint8_t isEmpty(Queue* q);
void flushQueue(Queue* q);

#endif /* INC_XBEE_QUEUE_H_ */
