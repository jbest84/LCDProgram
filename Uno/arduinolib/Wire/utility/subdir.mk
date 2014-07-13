################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../arduinolib/Wire/utility/twi.c 

C_DEPS += \
./arduinolib/Wire/utility/twi.d 

OBJS += \
./arduinolib/Wire/utility/twi.o 


# Each subdirectory must supply rules for building sources it contributes
arduinolib/Wire/utility/%.o: ../arduinolib/Wire/utility/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"C:\Users\Jason\workspace\ArduinoCore\src" -DARDUINO=22 -Wall -g2 -gstabs -Os -ffunction-sections -fdata-sections -ffunction-sections -fdata-sections -std=gnu99 -mmcu=atmega328p -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


