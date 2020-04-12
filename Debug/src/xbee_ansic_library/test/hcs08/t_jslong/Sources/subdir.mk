################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/xbee_ansic_library/test/hcs08/t_jslong/Sources/ExampleFuncs.c \
../src/xbee_ansic_library/test/hcs08/t_jslong/Sources/main.c \
../src/xbee_ansic_library/test/hcs08/t_jslong/Sources/serial.c \
../src/xbee_ansic_library/test/hcs08/t_jslong/Sources/vector_table.c 

OBJS += \
./src/xbee_ansic_library/test/hcs08/t_jslong/Sources/ExampleFuncs.o \
./src/xbee_ansic_library/test/hcs08/t_jslong/Sources/main.o \
./src/xbee_ansic_library/test/hcs08/t_jslong/Sources/serial.o \
./src/xbee_ansic_library/test/hcs08/t_jslong/Sources/vector_table.o 

C_DEPS += \
./src/xbee_ansic_library/test/hcs08/t_jslong/Sources/ExampleFuncs.d \
./src/xbee_ansic_library/test/hcs08/t_jslong/Sources/main.d \
./src/xbee_ansic_library/test/hcs08/t_jslong/Sources/serial.d \
./src/xbee_ansic_library/test/hcs08/t_jslong/Sources/vector_table.d 


# Each subdirectory must supply rules for building sources it contributes
src/xbee_ansic_library/test/hcs08/t_jslong/Sources/%.o: ../src/xbee_ansic_library/test/hcs08/t_jslong/Sources/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -DPOSIX -DXBEE_SERIAL_VERBOSE -I"/home/arnavm89/cpp-workspace/XbeeS6B/src/inc" -I"/home/arnavm89/cpp-workspace/XbeeS6B/src/xbee_ansic_library/include" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


