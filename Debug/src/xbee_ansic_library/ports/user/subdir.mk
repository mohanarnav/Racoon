################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/xbee_ansic_library/ports/user/xbee_platform_stm.c \
../src/xbee_ansic_library/ports/user/xbee_readline.c \
../src/xbee_ansic_library/ports/user/xbee_serial_stm.c 

OBJS += \
./src/xbee_ansic_library/ports/user/xbee_platform_stm.o \
./src/xbee_ansic_library/ports/user/xbee_readline.o \
./src/xbee_ansic_library/ports/user/xbee_serial_stm.o 

C_DEPS += \
./src/xbee_ansic_library/ports/user/xbee_platform_stm.d \
./src/xbee_ansic_library/ports/user/xbee_readline.d \
./src/xbee_ansic_library/ports/user/xbee_serial_stm.d 


# Each subdirectory must supply rules for building sources it contributes
src/xbee_ansic_library/ports/user/%.o: ../src/xbee_ansic_library/ports/user/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DSTM32 -DSTM32F3 -DSTM32F30 -DSTM32F303VCTx -DSTM32F3DISCOVERY -DDEBUG -DSTM32F303xC -DUSE_STDPERIPH_DRIVER -I"C:/Users/arnav/workspace/hippie_v2/src/xbee_ansic_library/include" -I"C:/Users/arnav/workspace/hippie_v2/Utilities" -I"C:/Users/arnav/workspace/hippie_v2/StdPeriph_Driver/inc" -I"C:/Users/arnav/workspace/hippie_v2/inc" -I"C:/Users/arnav/workspace/hippie_v2/CMSIS/device" -I"C:/Users/arnav/workspace/hippie_v2/USB-FS-Device_Driver/inc" -I"C:/Users/arnav/workspace/hippie_v2/CMSIS/core" -I"C:/Users/arnav/workspace/hippie_v2/src/tests" -I"C:/Users/arnav/workspace/hippie_v2/src/FreeRTOS/Source/portable/GCC/ARM_CM4F" -I"C:/Users/arnav/workspace/hippie_v2/src/FreeRTOS/Source/include" -I"C:/Users/arnav/workspace/hippie_v2/src/xbee_ansic_library/ports/user" -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


