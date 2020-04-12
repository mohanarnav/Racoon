################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/xbee_ansic_library/samples/win32/comports.c \
../src/xbee_ansic_library/samples/win32/eblinfo.c \
../src/xbee_ansic_library/samples/win32/install_ebin.c \
../src/xbee_ansic_library/samples/win32/install_ebl.c \
../src/xbee_ansic_library/samples/win32/parse_serial_args.c \
../src/xbee_ansic_library/samples/win32/pxbee_ota_update.c \
../src/xbee_ansic_library/samples/win32/pxbee_update.c \
../src/xbee_ansic_library/samples/win32/win32_select_file.c \
../src/xbee_ansic_library/samples/win32/xbee_term_win32.c 

OBJS += \
./src/xbee_ansic_library/samples/win32/comports.o \
./src/xbee_ansic_library/samples/win32/eblinfo.o \
./src/xbee_ansic_library/samples/win32/install_ebin.o \
./src/xbee_ansic_library/samples/win32/install_ebl.o \
./src/xbee_ansic_library/samples/win32/parse_serial_args.o \
./src/xbee_ansic_library/samples/win32/pxbee_ota_update.o \
./src/xbee_ansic_library/samples/win32/pxbee_update.o \
./src/xbee_ansic_library/samples/win32/win32_select_file.o \
./src/xbee_ansic_library/samples/win32/xbee_term_win32.o 

C_DEPS += \
./src/xbee_ansic_library/samples/win32/comports.d \
./src/xbee_ansic_library/samples/win32/eblinfo.d \
./src/xbee_ansic_library/samples/win32/install_ebin.d \
./src/xbee_ansic_library/samples/win32/install_ebl.d \
./src/xbee_ansic_library/samples/win32/parse_serial_args.d \
./src/xbee_ansic_library/samples/win32/pxbee_ota_update.d \
./src/xbee_ansic_library/samples/win32/pxbee_update.d \
./src/xbee_ansic_library/samples/win32/win32_select_file.d \
./src/xbee_ansic_library/samples/win32/xbee_term_win32.d 


# Each subdirectory must supply rules for building sources it contributes
src/xbee_ansic_library/samples/win32/%.o: ../src/xbee_ansic_library/samples/win32/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -DPOSIX -DXBEE_SERIAL_VERBOSE -I"/home/arnavm89/cpp-workspace/XbeeS6B/src/inc" -I"/home/arnavm89/cpp-workspace/XbeeS6B/src/xbee_ansic_library/include" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


