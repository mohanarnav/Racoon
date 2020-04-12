################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/xbee_ansic_library/test/xbee/t_cbuf.c \
../src/xbee_ansic_library/test/xbee/t_packed_struct.c \
../src/xbee_ansic_library/test/xbee/xbee_timer_compare.c 

OBJS += \
./src/xbee_ansic_library/test/xbee/t_cbuf.o \
./src/xbee_ansic_library/test/xbee/t_packed_struct.o \
./src/xbee_ansic_library/test/xbee/xbee_timer_compare.o 

C_DEPS += \
./src/xbee_ansic_library/test/xbee/t_cbuf.d \
./src/xbee_ansic_library/test/xbee/t_packed_struct.d \
./src/xbee_ansic_library/test/xbee/xbee_timer_compare.d 


# Each subdirectory must supply rules for building sources it contributes
src/xbee_ansic_library/test/xbee/%.o: ../src/xbee_ansic_library/test/xbee/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -DPOSIX -DXBEE_SERIAL_VERBOSE -I"/home/arnavm89/cpp-workspace/XbeeS6B/src/inc" -I"/home/arnavm89/cpp-workspace/XbeeS6B/src/xbee_ansic_library/include" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


