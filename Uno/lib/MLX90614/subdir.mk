################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../lib/MLX90614/Adafruit_MLX90614.cpp 

OBJS += \
./lib/MLX90614/Adafruit_MLX90614.o 

CPP_DEPS += \
./lib/MLX90614/Adafruit_MLX90614.d 


# Each subdirectory must supply rules for building sources it contributes
lib/MLX90614/%.o: ../lib/MLX90614/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: AVR C++ Compiler'
	avr-g++ -I"C:\Users\Jason\workspace\ArduinoCore\src" -I"C:\Users\Jason\workspace\LCDShifter\src" -I"C:\Users\Jason\workspace\LCDProgram\lib\MLX90614" -I"C:\Users\Jason\workspace\LCDProgram\arduinolib" -I"C:\Users\Jason\workspace\LCDProgram\arduinolib\Wire" -Wall -g2 -gstabs -Os -ffunction-sections -fdata-sections -ffunction-sections -fdata-sections -fno-exceptions --pedantic -mmcu=atmega328p -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


