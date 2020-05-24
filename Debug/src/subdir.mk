################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/gpio_config.c \
../src/main.c \
../src/rtos_tasks.c \
../src/syscalls.c \
../src/system_stm32f30x.c \
../src/test_rtos_tasks.c \
../src/usart_printf.c \
../src/usart_xbee.c \
../src/xbee.c \
../src/xbee_queue.c 

OBJS += \
./src/gpio_config.o \
./src/main.o \
./src/rtos_tasks.o \
./src/syscalls.o \
./src/system_stm32f30x.o \
./src/test_rtos_tasks.o \
./src/usart_printf.o \
./src/usart_xbee.o \
./src/xbee.o \
./src/xbee_queue.o 

C_DEPS += \
./src/gpio_config.d \
./src/main.d \
./src/rtos_tasks.d \
./src/syscalls.d \
./src/system_stm32f30x.d \
./src/test_rtos_tasks.d \
./src/usart_printf.d \
./src/usart_xbee.d \
./src/xbee.d \
./src/xbee_queue.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DSTM32 -DSTM32F3 -DSTM32F30 -DSTM32F303VCTx -DSTM32F3DISCOVERY -DDEBUG -DSTM32F303xC -DUSE_STDPERIPH_DRIVER -I"C:/Users/arnav/workspace/hippie_v2/src/xbee_ansic_library/include" -I"C:/Users/arnav/workspace/hippie_v2/Utilities" -I"C:/Users/arnav/workspace/hippie_v2/StdPeriph_Driver/inc" -I"C:/Users/arnav/workspace/hippie_v2/inc" -I"C:/Users/arnav/workspace/hippie_v2/CMSIS/device" -I"C:/Users/arnav/workspace/hippie_v2/USB-FS-Device_Driver/inc" -I"C:/Users/arnav/workspace/hippie_v2/CMSIS/core" -I"C:/Users/arnav/workspace/hippie_v2/src/FreeRTOS/Source/portable/GCC/ARM_CM4F" -I"C:/Users/arnav/workspace/hippie_v2/src/FreeRTOS/Source/include" -I"C:/Users/arnav/workspace/hippie_v2/src/xbee_ansic_library/ports/user" -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


