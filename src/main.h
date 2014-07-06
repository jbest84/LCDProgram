/*
 * main.h
 *
 *  Created on: Jun 29, 2014
 *      Author: Jason
 */

#ifndef MAIN_H_
#define MAIN_H_

#include <Arduino.h>

// Table 6 from page 24
// Command table
void clearDisplay();
void returnHome();
void writeData(const char *str);
void entryModeSet(int data);
void displayControl(int data);
void cursorControl(int data);
void functionSet(int data);
void setCGRAMAddr(int data);
void setDDRAMAddr(int data);
void setCursor(uint8_t col, uint8_t row);

void sendCommand(int);
void write8Bits(int data);
void write16Bits(int data, int pinState);
void pulseClock();
void pulseLCD(int data, int pinState);
void initLCD();

const uint8_t NO_DATA = 0x00;

// Commands
const uint8_t RS_HIGH = 0x01;
const uint8_t RS_LOW = 0x00;
const uint8_t RW_HIGH = 0x02;
const uint8_t RW_LOW = 0x00;
const uint8_t ENABLE_HIGH = 0x04;
const uint8_t ENABLE_LOW = 0x00;

const uint8_t LCD_CMD_CLEAR_DISPLAY = 0x01;
const uint8_t LCD_CMD_RETURN_HOME = 0x02;
const uint8_t LCD_CMD_ENTRYMODE_SET = 0x04;
const uint8_t LCD_CMD_DISPLAY = 0x08;
const uint8_t LCD_CMD_CURSOR_SHIFT = 0x10;
const uint8_t LCD_CMD_FUNCTION_SET = 0x20;
const uint8_t LCD_CMD_SET_CGRAM_ADDR = 0x40;
const uint8_t LCD_CMD_SET_DDRAM_ADDR = 0x80;

// Command options
const uint8_t LCD_CMDOP_ENTRY_CURSOR_MV_DIR_LEFT = 0x00;
const uint8_t LCD_CMDOP_ENTRY_CURSOR_MV_DIR_RIGHT = 0x02;
const uint8_t LCD_CMDOP_ENTRY_DISP_SHIFT = 0x01;
const uint8_t LCD_CMDOP_ENTRY_DISP_NOSHIFT = 0x00;

const uint8_t LCD_CMDOP_DISP_ON = 0x04;
const uint8_t LCD_CMDOP_DISP_OFF = 0x00;
const uint8_t LCD_CMDOP_DISP_ONCURSOR = 0x02;
const uint8_t LCD_CMDOP_DISP_OFFCURSOR = 0x00;
const uint8_t LCD_CMDOP_DISP_CURSOR_BLINK = 0x01;

const uint8_t LCD_CMDOP_FUNC_INTERFACE_8BIT = 0x10;
const uint8_t LCD_CMDOP_FUNC_INTERFACE_4BIT = 0x00;
const uint8_t LCD_CMDOP_FUNC_DISPLAY_2LINES = 0x08;
const uint8_t LCD_CMDOP_FUNC_DISPLAY_1LINE = 0x00;
const uint8_t LCD_CMDOP_FUNC_FONT_5x10 = 0x04;
const uint8_t LCD_CMDOP_FUNC_FONT_5x8 = 0x00;

const uint8_t LCD_CMDOP_CURSOR_SHIFTRIGHT = 0x00;
const uint8_t LCD_CMDOP_CURSOR_SHIFTLEFT = 0x04;
const uint8_t LCD_CMDOP_CURSOR_MOVE_DISP = 0x08;
const uint8_t LCD_CMDOP_CURSOR_MOVE_CURSOR = 0x00;

const uint8_t LCD_COL1_ROW1 = 0x00;
const uint8_t LCD_COL1_ROW2 = 0x40;

#endif /* MAIN_H_ */
