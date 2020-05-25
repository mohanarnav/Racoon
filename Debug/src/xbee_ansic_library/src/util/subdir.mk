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
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DSTM32 -DSTM32F3 -DSTM32F30 -DSTM32F303VCTx -DSTM32F3DISCOVERY -DDEBUG -DSTM32F303xC -DUSE_STDPERIPH_DRIVER -I"C:/Users/arnav/workspace/hippie_v2/src/xbee_ansic_library/include" -I"C:/Users/arnav/workspace/hippie_v2/Utilities" -I"C:/Users/arnav/workspace/hippie_v2/StdPeriph_Driver/inc" -I"C:/Users/arnav/workspace/hippie_v2/inc" -I"C:/Users/arnav/workspace/hippie_v2/CMSIS/device" -I"C:/Users/arnav/workspace/hippie_v2/USB-FS-Device_Driver/inc" -I"C:/Users/arnav/workspace/hippie_v2/CMSIS/core" -I"C:/Users/arnav/workspace/hippie_v2/src/tests" -I"C:/Users/arnav/workspace/hippie_v2/src/FreeRTOS/Source/portable/GCC/ARM_CM4F" -I"C:/Users/arnav/workspace/hippie_v2/src/FreeRTOS/Source/include" -I"C:/Users/arnav/workspace/hippie_v2/src/xbee_ansic_library/ports/user" -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


