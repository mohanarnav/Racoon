#include <time.h>
#include <sys/time.h>
#include "xbee/platform.h"
#include "rtos_tasks.h"

uint32_t xbee_seconds_timer()
{
	TickType_t xLastTick;
	xLastTick = xTaskGetTickCount();

	return (xLastTick/configTICK_RATE_HZ);
}

uint32_t xbee_millisecond_timer()
{
	TickType_t xLastTick;
	xLastTick = xTaskGetTickCount();

    return (xLastTick*1000/configTICK_RATE_HZ);
}

///@}
