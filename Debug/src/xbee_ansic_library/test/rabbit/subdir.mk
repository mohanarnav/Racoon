################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/xbee_ansic_library/test/rabbit/new\ xbee\ param.c \
../src/xbee_ansic_library/test/rabbit/test_xbee_device.c \
../src/xbee_ansic_library/test/rabbit/test_xbee_param.c \
../src/xbee_ansic_library/test/rabbit/unittest_xbee_device.c \
../src/xbee_ansic_library/test/rabbit/unittest_xbee_serial.c 

OBJS += \
./src/xbee_ansic_library/test/rabbit/new\ xbee\ param.o \
./src/xbee_ansic_library/test/rabbit/test_xbee_device.o \
./src/xbee_ansic_library/test/rabbit/test_xbee_param.o \
./src/xbee_ansic_library/test/rabbit/unittest_xbee_device.o \
./src/xbee_ansic_library/test/rabbit/unittest_xbee_serial.o 

C_DEPS += \
./src/xbee_ansic_library/test/rabbit/new\ xbee\ param.d \
./src/xbee_ansic_library/test/rabbit/test_xbee_device.d \
./src/xbee_ansic_library/test/rabbit/test_xbee_param.d \
./src/xbee_ansic_library/test/rabbit/unittest_xbee_device.d \
./src/xbee_ansic_library/test/rabbit/unittest_xbee_serial.d 


# Each subdirectory must supply rules for building sources it contributes
src/xbee_ansic_library/test/rabbit/new\ xbee\ param.o: ../src/xbee_ansic_library/test/rabbit/new\ xbee\ param.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -DPOSIX -DXBEE_SERIAL_VERBOSE -I"/home/arnavm89/cpp-workspace/XbeeS6B/src/inc" -I"/home/arnavm89/cpp-workspace/XbeeS6B/src/xbee_ansic_library/include" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/xbee_ansic_library/test/rabbit/new xbee param.d" -MT"src/xbee_ansic_library/test/rabbit/new\ xbee\ param.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/xbee_ansic_library/test/rabbit/%.o: ../src/xbee_ansic_library/test/rabbit/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -DPOSIX -DXBEE_SERIAL_VERBOSE -I"/home/arnavm89/cpp-workspace/XbeeS6B/src/inc" -I"/home/arnavm89/cpp-workspace/XbeeS6B/src/xbee_ansic_library/include" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


