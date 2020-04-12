################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/xbee_ansic_library/test/util/crc_test.c \
../src/xbee_ansic_library/test/util/jsll_gen.c \
../src/xbee_ansic_library/test/util/t_jslong.c \
../src/xbee_ansic_library/test/util/t_memcheck.c \
../src/xbee_ansic_library/test/util/t_srp.c 

OBJS += \
./src/xbee_ansic_library/test/util/crc_test.o \
./src/xbee_ansic_library/test/util/jsll_gen.o \
./src/xbee_ansic_library/test/util/t_jslong.o \
./src/xbee_ansic_library/test/util/t_memcheck.o \
./src/xbee_ansic_library/test/util/t_srp.o 

C_DEPS += \
./src/xbee_ansic_library/test/util/crc_test.d \
./src/xbee_ansic_library/test/util/jsll_gen.d \
./src/xbee_ansic_library/test/util/t_jslong.d \
./src/xbee_ansic_library/test/util/t_memcheck.d \
./src/xbee_ansic_library/test/util/t_srp.d 


# Each subdirectory must supply rules for building sources it contributes
src/xbee_ansic_library/test/util/%.o: ../src/xbee_ansic_library/test/util/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -DPOSIX -DXBEE_SERIAL_VERBOSE -I"/home/arnavm89/cpp-workspace/XbeeS6B/src/inc" -I"/home/arnavm89/cpp-workspace/XbeeS6B/src/xbee_ansic_library/include" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


