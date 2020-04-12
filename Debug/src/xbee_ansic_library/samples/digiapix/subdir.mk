################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/xbee_ansic_library/samples/digiapix/eblinfo.c \
../src/xbee_ansic_library/samples/digiapix/install_ebin.c \
../src/xbee_ansic_library/samples/digiapix/install_ebl.c \
../src/xbee_ansic_library/samples/digiapix/parse_serial_args.c \
../src/xbee_ansic_library/samples/digiapix/xbee_term_digiapix.c 

OBJS += \
./src/xbee_ansic_library/samples/digiapix/eblinfo.o \
./src/xbee_ansic_library/samples/digiapix/install_ebin.o \
./src/xbee_ansic_library/samples/digiapix/install_ebl.o \
./src/xbee_ansic_library/samples/digiapix/parse_serial_args.o \
./src/xbee_ansic_library/samples/digiapix/xbee_term_digiapix.o 

C_DEPS += \
./src/xbee_ansic_library/samples/digiapix/eblinfo.d \
./src/xbee_ansic_library/samples/digiapix/install_ebin.d \
./src/xbee_ansic_library/samples/digiapix/install_ebl.d \
./src/xbee_ansic_library/samples/digiapix/parse_serial_args.d \
./src/xbee_ansic_library/samples/digiapix/xbee_term_digiapix.d 


# Each subdirectory must supply rules for building sources it contributes
src/xbee_ansic_library/samples/digiapix/%.o: ../src/xbee_ansic_library/samples/digiapix/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -DPOSIX -DXBEE_SERIAL_VERBOSE -I"/home/arnavm89/cpp-workspace/XbeeS6B/src/inc" -I"/home/arnavm89/cpp-workspace/XbeeS6B/src/xbee_ansic_library/include" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


