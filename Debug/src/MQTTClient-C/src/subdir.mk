################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/MQTTClient-C/src/MQTTClient.c 

OBJS += \
./src/MQTTClient-C/src/MQTTClient.o 

C_DEPS += \
./src/MQTTClient-C/src/MQTTClient.d 


# Each subdirectory must supply rules for building sources it contributes
src/MQTTClient-C/src/%.o: ../src/MQTTClient-C/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -I"/home/arnavm89/cpp-workspace/XbeeS6B/src/inc" -I"/home/arnavm89/cpp-workspace/XbeeS6B/src/MQTTPacket/src" -I"/home/arnavm89/cpp-workspace/XbeeS6B/src/xbee_ansic_library/include" -I"/home/arnavm89/cpp-workspace/XbeeS6B/src/MQTTClient-C/src/stm32" -I"/home/arnavm89/cpp-workspace/XbeeS6B/src/MQTTClient-C/src" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


