################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/xbee_ansic_library/test/win32/coverity.c \
../src/xbee_ansic_library/test/win32/serial-passthru.c 

OBJS += \
./src/xbee_ansic_library/test/win32/coverity.o \
./src/xbee_ansic_library/test/win32/serial-passthru.o 

C_DEPS += \
./src/xbee_ansic_library/test/win32/coverity.d \
./src/xbee_ansic_library/test/win32/serial-passthru.d 


# Each subdirectory must supply rules for building sources it contributes
src/xbee_ansic_library/test/win32/%.o: ../src/xbee_ansic_library/test/win32/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -DPOSIX -DXBEE_SERIAL_VERBOSE -I"/home/arnavm89/cpp-workspace/XbeeS6B/src/inc" -I"/home/arnavm89/cpp-workspace/XbeeS6B/src/xbee_ansic_library/include" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


