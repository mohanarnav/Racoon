################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/xbee_ansic_library/src/mbedtls/aes.c \
../src/xbee_ansic_library/src/mbedtls/bignum.c \
../src/xbee_ansic_library/src/mbedtls/ctr_drbg.c \
../src/xbee_ansic_library/src/mbedtls/entropy.c \
../src/xbee_ansic_library/src/mbedtls/entropy_poll.c \
../src/xbee_ansic_library/src/mbedtls/mbedtls_util.c \
../src/xbee_ansic_library/src/mbedtls/sha256.c 

OBJS += \
./src/xbee_ansic_library/src/mbedtls/aes.o \
./src/xbee_ansic_library/src/mbedtls/bignum.o \
./src/xbee_ansic_library/src/mbedtls/ctr_drbg.o \
./src/xbee_ansic_library/src/mbedtls/entropy.o \
./src/xbee_ansic_library/src/mbedtls/entropy_poll.o \
./src/xbee_ansic_library/src/mbedtls/mbedtls_util.o \
./src/xbee_ansic_library/src/mbedtls/sha256.o 

C_DEPS += \
./src/xbee_ansic_library/src/mbedtls/aes.d \
./src/xbee_ansic_library/src/mbedtls/bignum.d \
./src/xbee_ansic_library/src/mbedtls/ctr_drbg.d \
./src/xbee_ansic_library/src/mbedtls/entropy.d \
./src/xbee_ansic_library/src/mbedtls/entropy_poll.d \
./src/xbee_ansic_library/src/mbedtls/mbedtls_util.d \
./src/xbee_ansic_library/src/mbedtls/sha256.d 


# Each subdirectory must supply rules for building sources it contributes
src/xbee_ansic_library/src/mbedtls/%.o: ../src/xbee_ansic_library/src/mbedtls/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -DPOSIX -DXBEE_SERIAL_VERBOSE -I"/home/arnavm89/cpp-workspace/XbeeS6B/src/inc" -I"/home/arnavm89/cpp-workspace/XbeeS6B/src/xbee_ansic_library/include" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


