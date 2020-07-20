#include <limits.h>
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include "xbee/serial.h"

#include "usart_xbee.h"

#define XBEE_SER_CHECK(ptr) \
    do { if (xbee_ser_invalid(ptr)) return -EINVAL; } while (0)


int xbee_ser_invalid( xbee_serial_t *serial)
{
    if (serial && serial->fd >= 0)
    {
        return 0;
    }

    #ifdef XBEE_SERIAL_VERBOSE
        if (serial == NULL)
        {
            printf( "%s: serial=NULL\n", __FUNCTION__);
        }
        else
        {
            printf( "%s: serial=%p, serial->fd=%d (invalid)\n", __FUNCTION__,
                serial, serial->fd);
        }
    #endif

    return 1;
}


const char *xbee_ser_portname( xbee_serial_t *serial)
{
    if (serial == NULL)
    {
        return "(invalid)";
    }

    return serial->device;
}


int xbee_ser_write( xbee_serial_t *serial, const void FAR *buffer,
    int length)
{
    int result;

    XBEE_SER_CHECK( serial);
    if (length < 0)
    {
        return -EINVAL;
    }

    /* Arnav made changes here */
    /* result = write( serial->fd, buffer, length); */
    // task_delay(10);

    taskENTER_CRITICAL();
    result = xbee_send(buffer, length);
    taskEXIT_CRITICAL();
    /****************************/

    if (result < 0)
    {
        #ifdef XBEE_SERIAL_VERBOSE
            printf( "%s: error %d trying to write %d bytes\n", __FUNCTION__,
                errno, length);
        #endif
        return -errno;
    }

    #ifdef XBEE_SERIAL_VERBOSE
        printf( "%s: wrote %d of %d bytes\n", __FUNCTION__, result, length);
        hex_dump( buffer, result, HEX_DUMP_FLAG_TAB);
    #endif

//    u_printf("length: ");
//    u_printf32(length);
//    u_printf(", result: ");
//    u_printf32(result);
//    u_printf("\n\r");

    return result;
}


int xbee_ser_read( xbee_serial_t *serial, void FAR *buffer, int bufsize)
{
    int result;

    XBEE_SER_CHECK( serial);

    if (! buffer || bufsize < 0)
    {
        #ifdef XBEE_SERIAL_VERBOSE
            printf( "%s: buffer=%p, bufsize=%d; return -EINVAL\n", __FUNCTION__,
                buffer, bufsize);
        #endif
        return -EINVAL;
    }

    result = xbee_read(buffer, bufsize); // result = bufsize if successful

    if (result == -1)
    {
    	/* Not dealing with system errors in case of porting it to a bare metal/RTOS software on STM. */
        #ifdef XBEE_SERIAL_VERBOSE
            printf( "%s: error %d trying to read %d bytes\n", __FUNCTION__,
                errno, bufsize);
        #endif
        return 0;
    }

    #ifdef XBEE_SERIAL_VERBOSE
        printf( "%s: read %d bytes\n", __FUNCTION__, result);
        hex_dump( buffer, result, HEX_DUMP_FLAG_TAB);
    #endif

    return result;
}


int xbee_ser_putchar( xbee_serial_t *serial, uint8_t ch)
{
    int retval;

    retval = xbee_ser_write( serial, &ch, 1);
    if (retval == 1)
    {
        return 0;
    }
    else if (retval == 0)
    {
        return -ENOSPC;
    }
    else
    {
        return retval;
    }
}


int xbee_ser_getchar( xbee_serial_t *serial)
{
    uint8_t ch = 0;
    int retval;

    retval = xbee_ser_read( serial, &ch, 1);
    if (retval != 1)
    {
        return retval ? retval : -ENODATA;
    }

    return ch;
}


int xbee_ser_tx_free( xbee_serial_t *serial)
{
    return INT_MAX;
}


int xbee_ser_tx_used( xbee_serial_t *serial)
{
    return 0;
}


int xbee_ser_tx_flush( xbee_serial_t *serial)
{


    return 0;
}


int xbee_ser_rx_free( xbee_serial_t *serial)
{
   return INT_MAX;
}


int xbee_ser_rx_used( xbee_serial_t *serial)
{
	return 0;
}


int xbee_ser_rx_flush( xbee_serial_t *serial)
{


    return 0;
}


#define _BAUDCASE(b)        case b: baud = B ## b; break
int xbee_ser_baudrate( xbee_serial_t *serial, uint32_t baudrate)
{
	usart_xbee_config(baudrate);
	serial->baudrate = baudrate;
    return 0;
}


int xbee_ser_open( xbee_serial_t *serial, uint32_t baudrate)
{
 return 0;
}


int xbee_ser_close( xbee_serial_t *serial)
{

    return 0;
}


int xbee_ser_break( xbee_serial_t *serial, int enabled)
{


    return 0;
}


int xbee_ser_flowcontrol( xbee_serial_t *serial, int enabled)
{


    return 0;
}


int xbee_ser_set_rts( xbee_serial_t *serial, int asserted)
{

    return 0;
}


int xbee_ser_get_cts( xbee_serial_t *serial)
{
	return 1;
}

///@}
