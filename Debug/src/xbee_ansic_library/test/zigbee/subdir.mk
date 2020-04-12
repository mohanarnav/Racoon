################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/xbee_ansic_library/test/zigbee/zcl_24bit.c \
../src/xbee_ansic_library/test/zigbee/zcl_boolean.c \
../src/xbee_ansic_library/test/zigbee/zcl_encode_structured_values.c \
../src/xbee_ansic_library/test/zigbee/zcl_read.c \
../src/xbee_ansic_library/test/zigbee/zcl_test_common.c \
../src/xbee_ansic_library/test/zigbee/zcl_type_info.c \
../src/xbee_ansic_library/test/zigbee/zcl_type_name.c \
../src/xbee_ansic_library/test/zigbee/zcl_write.c \
../src/xbee_ansic_library/test/zigbee/zdo_match_desc_request.c \
../src/xbee_ansic_library/test/zigbee/zdo_simple_desc_respond.c \
../src/xbee_ansic_library/test/zigbee/zdo_tool.c 

OBJS += \
./src/xbee_ansic_library/test/zigbee/zcl_24bit.o \
./src/xbee_ansic_library/test/zigbee/zcl_boolean.o \
./src/xbee_ansic_library/test/zigbee/zcl_encode_structured_values.o \
./src/xbee_ansic_library/test/zigbee/zcl_read.o \
./src/xbee_ansic_library/test/zigbee/zcl_test_common.o \
./src/xbee_ansic_library/test/zigbee/zcl_type_info.o \
./src/xbee_ansic_library/test/zigbee/zcl_type_name.o \
./src/xbee_ansic_library/test/zigbee/zcl_write.o \
./src/xbee_ansic_library/test/zigbee/zdo_match_desc_request.o \
./src/xbee_ansic_library/test/zigbee/zdo_simple_desc_respond.o \
./src/xbee_ansic_library/test/zigbee/zdo_tool.o 

C_DEPS += \
./src/xbee_ansic_library/test/zigbee/zcl_24bit.d \
./src/xbee_ansic_library/test/zigbee/zcl_boolean.d \
./src/xbee_ansic_library/test/zigbee/zcl_encode_structured_values.d \
./src/xbee_ansic_library/test/zigbee/zcl_read.d \
./src/xbee_ansic_library/test/zigbee/zcl_test_common.d \
./src/xbee_ansic_library/test/zigbee/zcl_type_info.d \
./src/xbee_ansic_library/test/zigbee/zcl_type_name.d \
./src/xbee_ansic_library/test/zigbee/zcl_write.d \
./src/xbee_ansic_library/test/zigbee/zdo_match_desc_request.d \
./src/xbee_ansic_library/test/zigbee/zdo_simple_desc_respond.d \
./src/xbee_ansic_library/test/zigbee/zdo_tool.d 


# Each subdirectory must supply rules for building sources it contributes
src/xbee_ansic_library/test/zigbee/%.o: ../src/xbee_ansic_library/test/zigbee/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -DPOSIX -DXBEE_SERIAL_VERBOSE -I"/home/arnavm89/cpp-workspace/XbeeS6B/src/inc" -I"/home/arnavm89/cpp-workspace/XbeeS6B/src/xbee_ansic_library/include" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


