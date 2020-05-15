################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/main.c \
../src/mqtt_app.c \
../src/wifi_app.c \
../src/xbee_queue.c 

OBJS += \
./src/main.o \
./src/mqtt_app.o \
./src/wifi_app.o \
./src/xbee_queue.o 

C_DEPS += \
./src/main.d \
./src/mqtt_app.d \
./src/wifi_app.d \
./src/xbee_queue.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -I"/home/arnavm89/cpp-workspace/XbeeS6B/src/inc" -I"/home/arnavm89/cpp-workspace/XbeeS6B/src/MQTTPacket/src" -I"/home/arnavm89/cpp-workspace/XbeeS6B/src/xbee_ansic_library/include" -I"/home/arnavm89/cpp-workspace/XbeeS6B/src/MQTTClient-C/src/stm32" -I"/home/arnavm89/cpp-workspace/XbeeS6B/src/MQTTClient-C/src" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


