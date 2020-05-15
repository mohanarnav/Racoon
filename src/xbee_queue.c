/*
 * xbee_queue.c
 *
 *  Created on: May 13, 2020
 *      Author: arnavm89
 */

#include <xbee_queue.h>
//#include "usart_printf.h"

byte payload_array[QUEUE_SIZE];
Queue payload_queue = {-1, -1, QUEUE_SIZE, &payload_array[0]};

void enQueue(Queue* q, byte value)
{
    if ((q->front == 0 && q->rear == q->size-1) ||
            (q->rear == (q->front-1)%(q->size-1)))
    {
        return;
    }

    else if (q->front == -1) /* Insert First Element */
    {
        q->front = q->rear = 0;
        q->arr[q->rear] = value;
    }

    else if (q->rear == q->size-1 && q->front != 0)
    {
        q->rear = 0;
        q->arr[q->rear] = value;
    }

    else
    {
        q->rear++;
        q->arr[q->rear] = value;
    }
}

byte deQueue(Queue* q)
{
	if (q->front == -1)
	{
		//printf("\nQueue is Empty");
	    return INT_MIN;
	}

	int data = q->arr[q->front];
	q->arr[q->front] = -1;
	if (q->front == q->rear)
	{
		q->front = -1;
	    q->rear = -1;
	}

	else if (q->front == q->size-1)
	        q->front = 0;
	else
	        q->front++;

	return data;
}

void displayQueue(Queue* q)
{
    if (q->front == -1)
    {
        printf("\nQueue is Empty");
    	// u_printf("\nQueue is Empty");
        return;
    }
    // printf("\nElements in Circular Queue are: ");
    if (q->rear >= q->front)
    {
        for (int i = q->front; i <= q->rear; i++)
        {
            printf("%c", q->arr[i]);
            printf(" ");
        }
        printf("\n\r");
    }
    else
    {
        for (int i = q->front; i < q->size; i++)
        {
            printf("%c", q->arr[i]);
            printf(" ");
        }

        for (int i = 0; i <= q->rear; i++)
        {
            printf("%c", q->arr[i]);
            printf(" ");
        }
    }
}

uint8_t isEmpty(Queue* q)
{
	if (q->front == -1)
	{
		// printf("\nQueue is Empty");
	    return 1;
	}else
	{
		return 0;
	}
}

void flushQueue(Queue* q){

	while(!isEmpty(q)){
		deQueue(q);
	}
}
