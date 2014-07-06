#include "main.h"
#include <string.h>

// RS	: Bit 1
// R/W	: Bit 2
// E	: Bit 3
int PIN_DATA = 8;
int PIN_LATCH = 9;
int PIN_CLOCK = 10;

void setup() {
	pinMode(PIN_DATA, OUTPUT);
	pinMode(PIN_LATCH, OUTPUT);
	pinMode(PIN_CLOCK, OUTPUT);

	initLCD();

	writeData("LCD powered up!");
	setCursor(0, 1);
	writeData("Pew pew pewchew!");
}

void initLCD() {
	delayMicroseconds(50000);

	int pinState = RS_LOW | ENABLE_LOW | RW_LOW;

	write16Bits(NO_DATA, pinState);

	pulseLCD(NO_DATA, pinState);

	// Function set (1)
	sendCommand(LCD_CMD_FUNCTION_SET | LCD_CMDOP_FUNC_INTERFACE_8BIT | LCD_CMDOP_FUNC_DISPLAY_2LINES);
	delayMicroseconds(4500);// Wait for more than 4.1 ms

	// Function set (2)
	sendCommand(LCD_CMD_FUNCTION_SET | LCD_CMDOP_FUNC_INTERFACE_8BIT | LCD_CMDOP_FUNC_DISPLAY_2LINES);
	// Wait for more than 100 microseconds
	delayMicroseconds(150);

	// Function set (3)
	sendCommand(LCD_CMD_FUNCTION_SET | LCD_CMDOP_FUNC_INTERFACE_8BIT | LCD_CMDOP_FUNC_DISPLAY_2LINES);

	//**************************
	// Final initialization table (page 45)
	sendCommand(LCD_CMD_FUNCTION_SET | LCD_CMDOP_FUNC_INTERFACE_8BIT | LCD_CMDOP_FUNC_DISPLAY_2LINES);

	sendCommand(LCD_CMD_DISPLAY | LCD_CMDOP_DISP_ON | LCD_CMDOP_DISP_CURSOR_BLINK | LCD_CMDOP_DISP_ONCURSOR);

	sendCommand(LCD_CMD_CLEAR_DISPLAY);

	sendCommand(LCD_CMD_ENTRYMODE_SET | LCD_CMDOP_ENTRY_CURSOR_MV_DIR_RIGHT);
}

void sendCommand(int data) {
	int pinState = RS_LOW | RW_LOW | ENABLE_LOW;
	write16Bits(data, pinState);
	pulseLCD(data, pinState);
}

void clearDisplay() {
	sendCommand(LCD_CMD_CLEAR_DISPLAY);
	delayMicroseconds(2000);
}

void returnHome() {
	sendCommand(LCD_CMD_RETURN_HOME);
	delayMicroseconds(2000);
}

void entryModeSet(int options) {
	sendCommand(LCD_CMD_ENTRYMODE_SET | options);
}

void displayControl(int options) {
	sendCommand(LCD_CMD_DISPLAY | options);
}

void cursorControl(int options) {
	sendCommand(LCD_CMD_CURSOR_SHIFT | options);
}

void functionSet(int options) {
	sendCommand(LCD_CMD_FUNCTION_SET | options);
}

void setCGRAMAddr(int options) {
	sendCommand(LCD_CMD_SET_CGRAM_ADDR | options);
}

void setDDRAMAddr(int options) {
	sendCommand(LCD_CMD_SET_DDRAM_ADDR | options);
}

void writeData(const char *str) {
	int pinState;
	size_t length;

	pinState = RS_HIGH | RW_LOW | ENABLE_LOW;

	length = strlen(str);

	for (size_t i = 0; i < length; i++) {
		Serial.println(str[i]);
		write16Bits(str[i], pinState);
		pulseLCD(str[i], pinState);
	}
}

void setCursor(uint8_t col, uint8_t row) {
	int offset[] = { 0x00, 0x40, 0x14, 0x54 };
	sendCommand(LCD_CMD_SET_DDRAM_ADDR | (col + offset[row]));
}

// Write 8 bits to the shift register
// Data should be called first, command pins second (RS, RW, EN)
void write8Bits(int data) {
	// Start with the left most bit, check it for HIGH/LOW
	for(int i = 0; i < 8; i++) {
		int value = data << i;
		if ((value & B10000000) == B10000000) {
			digitalWrite(PIN_DATA, HIGH);
		} else {
			digitalWrite(PIN_DATA, LOW);
		}

		pulseClock();
	}
}

void write16Bits(int data, int pinState) {
	// Latch should start low
	digitalWrite(PIN_LATCH, LOW);

	// Write 8 bits for the second chip
	write8Bits(data);

	// Write 8 bits for the first chip
	write8Bits(pinState);

	// Pull the latch high, shifting the data out
	digitalWrite(PIN_LATCH, HIGH);
}

/**
 * Pulses the clock on the LCD.
 * pinState should be the state of RS, R/W and Enable
 * data should be the data pins (DB0 through DB7)
 */
void pulseLCD(int data, int pinState) {
	write16Bits(data, (pinState | ENABLE_LOW));
	delayMicroseconds(1);

	write16Bits(data, (pinState | ENABLE_HIGH));
	delayMicroseconds(1);

	write16Bits(data, (pinState | ENABLE_LOW));
	delayMicroseconds(100);
}

void pulseClock() {
	digitalWrite(PIN_CLOCK, HIGH);
	delay(1);
	digitalWrite(PIN_CLOCK, LOW);
}

void loop() {

}
