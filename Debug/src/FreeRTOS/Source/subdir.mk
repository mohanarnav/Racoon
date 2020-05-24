################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/FreeRTOS/Source/croutine.c \
../src/FreeRTOS/Source/event_groups.c \
../src/FreeRTOS/Source/list.c \
../src/FreeRTOS/Source/queue.c \
../src/FreeRTOS/Source/stream_buffer.c \
../src/FreeRTOS/Source/tasks.c \
../src/FreeRTOS/Source/timers.c 

OBJS += \
./src/FreeRTOS/Source/croutine.o \
./src/FreeRTOS/Source/event_groups.o \
./src/FreeRTOS/Source/list.o \
./src/FreeRTOS/Source/queue.o \
./src/FreeRTOS/Source/stream_buffer.o \
./src/FreeRTOS/Source/tasks.o \
./src/FreeRTOS/Source/timers.o 

C_DEPS += \
./src/FreeRTOS/Source/croutine.d \
./src/FreeRTOS/Source/event_groups.d \
./src/FreeRTOS/Source/list.d \
./src/FreeRTOS/Source/queue.d \
./src/FreeRTOS/Source/stream_buffer.d \
./src/FreeRTOS/Source/tasks.d \
./src/FreeRTOS/Source/timers.d 


# Each subdirectory must supply rules for building sources it contributes
src/FreeRTOS/Source/%.o: ../src/FreeRTOS/Source/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DSTM32 -DSTM32F3 -DSTM32F30 -DSTM32F303VCTx -DSTM32F3DISCOVERY -DDEBUG -DSTM32F303xC -DUSE_STDPERIPH_DRIVER -I"C:/Users/arnav/workspace/hippie_v2/src/xbee_ansic_library/include" -I"C:/Users/arnav/workspace/hippie_v2/Utilities" -I"C:/Users/arnav/workspace/hippie_v2/StdPeriph_Driver/inc" -I"C:/Users/arnav/workspace/hippie_v2/inc" -I"C:/Users/arnav/workspace/hippie_v2/CMSIS/device" -I"C:/Users/arnav/workspace/hippie_v2/USB-FS-Device_Driver/inc" -I"C:/Users/arnav/workspace/hippie_v2/CMSIS/core" -I"C:/Users/arnav/workspace/hippie_v2/src/FreeRTOS/Source/portable/GCC/ARM_CM4F" -I"C:/Users/arnav/workspace/hippie_v2/src/FreeRTOS/Source/include" -I"C:/Users/arnav/workspace/hippie_v2/src/xbee_ansic_library/ports/user" -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


