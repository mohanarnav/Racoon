################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/xbee_ansic_library/ports/win32/xbee_platform_win32.c \
../src/xbee_ansic_library/ports/win32/xbee_readline.c \
../src/xbee_ansic_library/ports/win32/xbee_serial_win32.c 

OBJS += \
./src/xbee_ansic_library/ports/win32/xbee_platform_win32.o \
./src/xbee_ansic_library/ports/win32/xbee_readline.o \
./src/xbee_ansic_library/ports/win32/xbee_serial_win32.o 

C_DEPS += \
./src/xbee_ansic_library/ports/win32/xbee_platform_win32.d \
./src/xbee_ansic_library/ports/win32/xbee_readline.d \
./src/xbee_ansic_library/ports/win32/xbee_serial_win32.d 


# Each subdirectory must supply rules for building sources it contributes
src/xbee_ansic_library/ports/win32/%.o: ../src/xbee_ansic_library/ports/win32/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -DPOSIX -DXBEE_SERIAL_VERBOSE -I"/home/arnavm89/cpp-workspace/XbeeS6B/src/inc" -I"/home/arnavm89/cpp-workspace/XbeeS6B/src/xbee_ansic_library/include" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


