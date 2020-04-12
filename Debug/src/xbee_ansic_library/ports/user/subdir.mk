################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/xbee_ansic_library/ports/user/xbee_platform_posix.c \
../src/xbee_ansic_library/ports/user/xbee_readline.c \
../src/xbee_ansic_library/ports/user/xbee_serial_posix.c 

OBJS += \
./src/xbee_ansic_library/ports/user/xbee_platform_posix.o \
./src/xbee_ansic_library/ports/user/xbee_readline.o \
./src/xbee_ansic_library/ports/user/xbee_serial_posix.o 

C_DEPS += \
./src/xbee_ansic_library/ports/user/xbee_platform_posix.d \
./src/xbee_ansic_library/ports/user/xbee_readline.d \
./src/xbee_ansic_library/ports/user/xbee_serial_posix.d 


# Each subdirectory must supply rules for building sources it contributes
src/xbee_ansic_library/ports/user/%.o: ../src/xbee_ansic_library/ports/user/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -I"/home/arnavm89/cpp-workspace/XbeeS6B/src/inc" -I"/home/arnavm89/cpp-workspace/XbeeS6B/src/xbee_ansic_library/include" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


