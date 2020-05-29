# Racoon
The project provides the stm port for xbee_ansic_library(https://github.com/digidotcom/xbee_ansic_library.git). It also has examples/tests on how to interface the library with an STM32 platform code (using STM32 Peripheral Device Library). The example also demonstrates the interfacing when FreeRTOS kernel is running on the platform.

The MQTTClient-C library contains the API which links eclipse Paho MQTT embedded C library (https://github.com/eclipse/paho.mqtt.embedded-c.git) with Digi XBee's Anci C library. 

After cloning xbee_ansic_library; the STM32 port can be used by placing the files in Racoon\src\xbee_port_stm to xbee_ansic_libary\ports\stm32.
