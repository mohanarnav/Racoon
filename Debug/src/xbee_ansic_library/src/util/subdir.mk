################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/xbee_ansic_library/src/util/crc16buypass.c \
../src/xbee_ansic_library/src/util/hexdump.c \
../src/xbee_ansic_library/src/util/hexstrtobyte.c \
../src/xbee_ansic_library/src/util/jslong.c \
../src/xbee_ansic_library/src/util/memcheck.c \
../src/xbee_ansic_library/src/util/swapbytes.c \
../src/xbee_ansic_library/src/util/swapcpy.c \
../src/xbee_ansic_library/src/util/xmodem_crc16.c 

OBJS += \
./src/xbee_ansic_library/src/util/crc16buypass.o \
./src/xbee_ansic_library/src/util/hexdump.o \
./src/xbee_ansic_library/src/util/hexstrtobyte.o \
./src/xbee_ansic_library/src/util/jslong.o \
./src/xbee_ansic_library/src/util/memcheck.o \
./src/xbee_ansic_library/src/util/swapbytes.o \
./src/xbee_ansic_library/src/util/swapcpy.o \
./src/xbee_ansic_library/src/util/xmodem_crc16.o 

C_DEPS += \
./src/xbee_ansic_library/src/util/crc16buypass.d \
./src/xbee_ansic_library/src/util/hexdump.d \
./src/xbee_ansic_library/src/util/hexstrtobyte.d \
./src/xbee_ansic_library/src/util/jslong.d \
./src/xbee_ansic_library/src/util/memcheck.d \
./src/xbee_ansic_library/src/util/swapbytes.d \
./src/xbee_ansic_library/src/util/swapcpy.d \
./src/xbee_ansic_library/src/util/xmodem_crc16.d 


# Each subdirectory must supply rules for building sources it contributes
src/xbee_ansic_library/src/util/%.o: ../src/xbee_ansic_library/src/util/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -I"/home/arnavm89/cpp-workspace/XbeeS6B/src/inc" -I"/home/arnavm89/cpp-workspace/XbeeS6B/src/xbee_ansic_library/include" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


