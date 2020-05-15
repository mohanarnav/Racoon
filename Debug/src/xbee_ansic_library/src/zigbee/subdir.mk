################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/xbee_ansic_library/src/zigbee/zcl_types.c \
../src/xbee_ansic_library/src/zigbee/zigbee_zcl.c 

OBJS += \
./src/xbee_ansic_library/src/zigbee/zcl_types.o \
./src/xbee_ansic_library/src/zigbee/zigbee_zcl.o 

C_DEPS += \
./src/xbee_ansic_library/src/zigbee/zcl_types.d \
./src/xbee_ansic_library/src/zigbee/zigbee_zcl.d 


# Each subdirectory must supply rules for building sources it contributes
src/xbee_ansic_library/src/zigbee/%.o: ../src/xbee_ansic_library/src/zigbee/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -I"/home/arnavm89/cpp-workspace/XbeeS6B/src/inc" -I"/home/arnavm89/cpp-workspace/XbeeS6B/src/MQTTPacket/src" -I"/home/arnavm89/cpp-workspace/XbeeS6B/src/xbee_ansic_library/include" -I"/home/arnavm89/cpp-workspace/XbeeS6B/src/MQTTClient-C/src/stm32" -I"/home/arnavm89/cpp-workspace/XbeeS6B/src/MQTTClient-C/src" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


