################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/xbee_ansic_library/test/hcs08/Shared/flash32KB.c \
../src/xbee_ansic_library/test/hcs08/Shared/flash_cfgblk.c \
../src/xbee_ansic_library/test/hcs08/Shared/rtc.c \
../src/xbee_ansic_library/test/hcs08/Shared/sharedRAM.c \
../src/xbee_ansic_library/test/hcs08/Shared/spi.c \
../src/xbee_ansic_library/test/hcs08/Shared/stdio_SCI1.c \
../src/xbee_ansic_library/test/hcs08/Shared/stdio_SCI1_int.c \
../src/xbee_ansic_library/test/hcs08/Shared/stdio_null.c 

OBJS += \
./src/xbee_ansic_library/test/hcs08/Shared/flash32KB.o \
./src/xbee_ansic_library/test/hcs08/Shared/flash_cfgblk.o \
./src/xbee_ansic_library/test/hcs08/Shared/rtc.o \
./src/xbee_ansic_library/test/hcs08/Shared/sharedRAM.o \
./src/xbee_ansic_library/test/hcs08/Shared/spi.o \
./src/xbee_ansic_library/test/hcs08/Shared/stdio_SCI1.o \
./src/xbee_ansic_library/test/hcs08/Shared/stdio_SCI1_int.o \
./src/xbee_ansic_library/test/hcs08/Shared/stdio_null.o 

C_DEPS += \
./src/xbee_ansic_library/test/hcs08/Shared/flash32KB.d \
./src/xbee_ansic_library/test/hcs08/Shared/flash_cfgblk.d \
./src/xbee_ansic_library/test/hcs08/Shared/rtc.d \
./src/xbee_ansic_library/test/hcs08/Shared/sharedRAM.d \
./src/xbee_ansic_library/test/hcs08/Shared/spi.d \
./src/xbee_ansic_library/test/hcs08/Shared/stdio_SCI1.d \
./src/xbee_ansic_library/test/hcs08/Shared/stdio_SCI1_int.d \
./src/xbee_ansic_library/test/hcs08/Shared/stdio_null.d 


# Each subdirectory must supply rules for building sources it contributes
src/xbee_ansic_library/test/hcs08/Shared/%.o: ../src/xbee_ansic_library/test/hcs08/Shared/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -DPOSIX -DXBEE_SERIAL_VERBOSE -I"/home/arnavm89/cpp-workspace/XbeeS6B/src/inc" -I"/home/arnavm89/cpp-workspace/XbeeS6B/src/xbee_ansic_library/include" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


