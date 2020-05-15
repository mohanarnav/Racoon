################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/MQTTPacket/src/MQTTConnectClient.c \
../src/MQTTPacket/src/MQTTConnectServer.c \
../src/MQTTPacket/src/MQTTDeserializePublish.c \
../src/MQTTPacket/src/MQTTFormat.c \
../src/MQTTPacket/src/MQTTPacket.c \
../src/MQTTPacket/src/MQTTSerializePublish.c \
../src/MQTTPacket/src/MQTTSubscribeClient.c \
../src/MQTTPacket/src/MQTTSubscribeServer.c \
../src/MQTTPacket/src/MQTTUnsubscribeClient.c \
../src/MQTTPacket/src/MQTTUnsubscribeServer.c 

OBJS += \
./src/MQTTPacket/src/MQTTConnectClient.o \
./src/MQTTPacket/src/MQTTConnectServer.o \
./src/MQTTPacket/src/MQTTDeserializePublish.o \
./src/MQTTPacket/src/MQTTFormat.o \
./src/MQTTPacket/src/MQTTPacket.o \
./src/MQTTPacket/src/MQTTSerializePublish.o \
./src/MQTTPacket/src/MQTTSubscribeClient.o \
./src/MQTTPacket/src/MQTTSubscribeServer.o \
./src/MQTTPacket/src/MQTTUnsubscribeClient.o \
./src/MQTTPacket/src/MQTTUnsubscribeServer.o 

C_DEPS += \
./src/MQTTPacket/src/MQTTConnectClient.d \
./src/MQTTPacket/src/MQTTConnectServer.d \
./src/MQTTPacket/src/MQTTDeserializePublish.d \
./src/MQTTPacket/src/MQTTFormat.d \
./src/MQTTPacket/src/MQTTPacket.d \
./src/MQTTPacket/src/MQTTSerializePublish.d \
./src/MQTTPacket/src/MQTTSubscribeClient.d \
./src/MQTTPacket/src/MQTTSubscribeServer.d \
./src/MQTTPacket/src/MQTTUnsubscribeClient.d \
./src/MQTTPacket/src/MQTTUnsubscribeServer.d 


# Each subdirectory must supply rules for building sources it contributes
src/MQTTPacket/src/%.o: ../src/MQTTPacket/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -I"/home/arnavm89/cpp-workspace/XbeeS6B/src/inc" -I"/home/arnavm89/cpp-workspace/XbeeS6B/src/MQTTPacket/src" -I"/home/arnavm89/cpp-workspace/XbeeS6B/src/xbee_ansic_library/include" -I"/home/arnavm89/cpp-workspace/XbeeS6B/src/MQTTClient-C/src/stm32" -I"/home/arnavm89/cpp-workspace/XbeeS6B/src/MQTTClient-C/src" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


