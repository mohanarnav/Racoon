/*
 * Copyright (c) 2010-2012 Digi International Inc.,
 * All rights not expressly granted are reserved.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 * Digi International Inc. 11001 Bren Road East, Minnetonka, MN 55343
 * =======================================================================
 */
/**
    @addtogroup hal_posix
    @{
    @file xbee_platform_posix.c
    Platform-specific functions for use by the XBee Driver on POSIX platform.

    @todo Create a platform unit test, one that can verify that the millisecond
            timer doesn't run backwards and that it matches up accurately with
            the seconds timer (base it on the HCS08 regression).
*/

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
