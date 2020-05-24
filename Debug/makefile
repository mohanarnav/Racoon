################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/xbee_ansic_library/src/zigbee/subdir.mk
-include src/xbee_ansic_library/src/xbee/subdir.mk
-include src/xbee_ansic_library/src/wpan/subdir.mk
-include src/xbee_ansic_library/src/util/subdir.mk
-include src/xbee_ansic_library/ports/user/subdir.mk
-include src/FreeRTOS/Source/portable/MemMang/subdir.mk
-include src/FreeRTOS/Source/portable/GCC/ARM_CM4F/subdir.mk
-include src/FreeRTOS/Source/subdir.mk
-include src/subdir.mk
-include inc/startup/subdir.mk
-include Utilities/subdir.mk
-include USB-FS-Device_Driver/src/subdir.mk
-include StdPeriph_Driver/src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: hippie_v2.elf

# Tool invocations
hippie_v2.elf: $(OBJS) $(USER_OBJS) C:\Users\arnav\workspace\hippie_v2/LinkerScript.ld
	@echo 'Building target: $@'
	@echo 'Invoking: MCU GCC Linker'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -T"C:/Users/arnav/workspace/hippie_v2/LinkerScript.ld" -Wl,-Map=output.map -Wl,--gc-sections -o "hippie_v2.elf" @"objects.list" $(USER_OBJS) $(LIBS) -lm
	@echo 'Finished building target: $@'
	@echo ' '
	$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

post-build:
	-@echo 'Generating binary and Printing size information:'
	arm-none-eabi-objcopy -O binary "hippie_v2.elf" "hippie_v2.bin"
	arm-none-eabi-size "hippie_v2.elf"
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY: post-build

-include ../makefile.targets
