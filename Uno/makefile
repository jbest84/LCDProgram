################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/subdir.mk
-include lib/MLX90614/subdir.mk
-include arduinolib/Wire/utility/subdir.mk
-include arduinolib/Wire/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
LCDProgram.lss \

FLASH_IMAGE += \
LCDProgram.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: LCDProgram.elf secondary-outputs

# Tool invocations
LCDProgram.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C++ Linker'
	avr-g++ -Wl,-Map,LCDProgram.map,--cref -mrelax -Wl,--gc-sections -L"C:\Users\Jason\workspace\ArduinoCore\Uno" -L"C:\Users\Jason\workspace\LCDShifter\Uno" -mmcu=atmega328p -o "LCDProgram.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

LCDProgram.lss: LCDProgram.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S LCDProgram.elf  >"LCDProgram.lss"
	@echo 'Finished building: $@'
	@echo ' '

LCDProgram.hex: LCDProgram.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex LCDProgram.elf  "LCDProgram.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: LCDProgram.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega328p LCDProgram.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(C_UPPER_DEPS)$(S_DEPS)$(LSS)$(C_DEPS)$(FLASH_IMAGE)$(CC_DEPS)$(ELFS)$(C++_DEPS)$(OBJS)$(CXX_DEPS)$(ASM_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(CPP_DEPS) LCDProgram.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
