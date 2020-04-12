################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/xbee_ansic_library/ports/digiapix/xbee_platform_digiapix.c \
../src/xbee_ansic_library/ports/digiapix/xbee_readline.c \
../src/xbee_ansic_library/ports/digiapix/xbee_serial_digiapix.c 

OBJS += \
./src/xbee_ansic_library/ports/digiapix/xbee_platform_digiapix.o \
./src/xbee_ansic_library/ports/digiapix/xbee_readline.o \
./src/xbee_ansic_library/ports/digiapix/xbee_serial_digiapix.o 

C_DEPS += \
./src/xbee_ansic_library/ports/digiapix/xbee_platform_digiapix.d \
./src/xbee_ansic_library/ports/digiapix/xbee_readline.d \
./src/xbee_ansic_library/ports/digiapix/xbee_serial_digiapix.d 


# Each subdirectory must supply rules for building sources it contributes
src/xbee_ansic_library/ports/digiapix/%.o: ../src/xbee_ansic_library/ports/digiapix/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -DPOSIX -DXBEE_SERIAL_VERBOSE -I"/home/arnavm89/cpp-workspace/XbeeS6B/src/inc" -I"/home/arnavm89/cpp-workspace/XbeeS6B/src/xbee_ansic_library/include" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


