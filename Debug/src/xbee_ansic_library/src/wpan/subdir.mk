################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/xbee_ansic_library/src/wpan/wpan_aps.c \
../src/xbee_ansic_library/src/wpan/wpan_types.c 

OBJS += \
./src/xbee_ansic_library/src/wpan/wpan_aps.o \
./src/xbee_ansic_library/src/wpan/wpan_types.o 

C_DEPS += \
./src/xbee_ansic_library/src/wpan/wpan_aps.d \
./src/xbee_ansic_library/src/wpan/wpan_types.d 


# Each subdirectory must supply rules for building sources it contributes
src/xbee_ansic_library/src/wpan/%.o: ../src/xbee_ansic_library/src/wpan/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -I"/home/arnavm89/cpp-workspace/XbeeS6B/src/inc" -I"/home/arnavm89/cpp-workspace/XbeeS6B/src/xbee_ansic_library/include" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


