################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/xbee_ansic_library/samples/dos/atinter.c 

OBJS += \
./src/xbee_ansic_library/samples/dos/atinter.o 

C_DEPS += \
./src/xbee_ansic_library/samples/dos/atinter.d 


# Each subdirectory must supply rules for building sources it contributes
src/xbee_ansic_library/samples/dos/%.o: ../src/xbee_ansic_library/samples/dos/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -DPOSIX -DXBEE_SERIAL_VERBOSE -I"/home/arnavm89/cpp-workspace/XbeeS6B/src/inc" -I"/home/arnavm89/cpp-workspace/XbeeS6B/src/xbee_ansic_library/include" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


