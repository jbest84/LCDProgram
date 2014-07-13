#include "main.h"

// RS	: Bit 1
// R/W	: Bit 2
// E	: Bit 3
int PIN_DATA = 8;
int PIN_LATCH = 9;
int PIN_CLOCK = 10;

Adafruit_MLX90614 mlx = Adafruit_MLX90614();
LCDShifter lcd(PIN_DATA, PIN_LATCH, PIN_CLOCK);

void setup() {
	pinMode(PIN_DATA, OUTPUT);
	pinMode(PIN_LATCH, OUTPUT);
	pinMode(PIN_CLOCK, OUTPUT);

	mlx.begin();
	lcd.begin();
	Serial.begin(9600);

	lcd.writeData("LCD powered up!!");
}

void loop() {
	lcd.setCursor(0, 1);
	double temp = mlx.readObjectTempF();
	char buffer[50];
	char *results;
	results = dtostrf(temp, 0, 2, buffer);
	lcd.writeData(results);
	delay(100);
}
