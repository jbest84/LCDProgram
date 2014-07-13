################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../libs/MLX90614/Adafruit_MLX90614.cpp 

OBJS += \
./libs/MLX90614/Adafruit_MLX90614.o 

CPP_DEPS += \
./libs/MLX90614/Adafruit_MLX90614.d 


# Each subdirectory must supply rules for building sources it contributes
libs/MLX90614/%.o: ../libs/MLX90614/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: AVR C++ Compiler'
	avr-g++ -I"C:\Users\Jason\workspace\ArduinoCore\src" -Wall -g2 -gstabs -Os -ffunction-sections -fdata-sections -ffunction-sections -fdata-sections -fno-exceptions --pedantic -mmcu=atmega328p -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


