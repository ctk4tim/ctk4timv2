/**
 *  @file lcdModule.c
 *  @brief Module that controls Standard LCD Module
 *  @date 30/03/2012
 *  @version 1.0.1
 *
 *  C Toolkit For MSP430 Texas Instrument Microcontroller
 *  Copyright (C) 2012  Leandro Perez Guatibonza
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "../ctk4timIncludes/lcdModule.h"

/**
 * @brief Init LCD Module
 */
void lcdInit()
{
	// Configure LCD Pins
	pinDigitalOutput(RS_LCD);
	pinDigitalOutput(E_LCD);
	pinDigitalOutput(D7_LCD);
	pinDigitalOutput(D6_LCD);
	pinDigitalOutput(D5_LCD);
	pinDigitalOutput(D4_LCD);

	// Idle State
	pinDigitalWriteOff(RS_LCD);
	pinDigitalWriteOff(E_LCD);
	delayMs(15);

	// Init 4-bit LCD Mode
	pinDigitalWriteOn(E_LCD);
	pinDigitalWriteOff(D7_LCD);
	pinDigitalWriteOff(D6_LCD);
	pinDigitalWriteOn(D5_LCD);
	pinDigitalWriteOn(D4_LCD);
	pinDigitalWriteOff(E_LCD);
	delayMs(5);
	pinDigitalWriteOn(E_LCD);
	pinDigitalWriteOff(E_LCD);
	delayMs(1);
	pinDigitalWriteOn(E_LCD);
	pinDigitalWriteOff(E_LCD);
	delayMs(5);
	pinDigitalWriteOn(E_LCD);
	pinDigitalWriteOff(D4_LCD);
	pinDigitalWriteOff(E_LCD);
	delayMs(1);

	// LCD 4-bit Interface
	lcdInstru(0x28);

	// LCD Off Display
	lcdInstru(0x08);

	// LCD On Display
	lcdInstru(0x0C);

	// LCD Message Static with cursor auto-increment
	lcdInstru(0x06);

	// LCD Cursor Home
	lcdInstru(0x02);

	// LCD Cursor Clear
	lcdInstru(0x01);
}

/**
 * @brief Send Byte to Two Nibbles
 * @param byteExport Byte to send to LCD Module
 */
void lcdSendByte(uchar byteExport)
{
	uchar bitExport = 0;

	// Send 4-bit MSB
	pinDigitalWriteOn(E_LCD);

	bitExport = byteExport & 0x80;
	if(bitExport == 0x80)
	{
		pinDigitalWriteOn(D7_LCD);
	}
	else
	{
		pinDigitalWriteOff(D7_LCD);
	}

	bitExport = byteExport & 0x40;
	if(bitExport == 0x40)
	{
		pinDigitalWriteOn(D6_LCD);
	}
	else
	{
		pinDigitalWriteOff(D6_LCD);
	}

	bitExport = byteExport & 0x20;
	if(bitExport == 0x20)
	{
		pinDigitalWriteOn(D5_LCD);
	}
	else
	{
		pinDigitalWriteOff(D5_LCD);
	}

	bitExport = byteExport & 0x10;
	if(bitExport == 0x10)
	{
		pinDigitalWriteOn(D4_LCD);
	}
	else
	{
		pinDigitalWriteOff(D4_LCD);
	}
	pinDigitalWriteOff(E_LCD);

	// Send 4-bit LSB
	pinDigitalWriteOn(E_LCD);

	bitExport = byteExport & 0x08;
	if(bitExport == 0x08)
	{
		pinDigitalWriteOn(D7_LCD);
	}
	else
	{
		pinDigitalWriteOff(D7_LCD);
	}

	bitExport = byteExport & 0x04;
	if(bitExport == 0x04)
	{
		pinDigitalWriteOn(D6_LCD);
	}
	else
	{
		pinDigitalWriteOff(D6_LCD);
	}

	bitExport = byteExport & 0x02;
	if(bitExport == 0x02)
	{
		pinDigitalWriteOn(D5_LCD);
	}
	else
	{
		pinDigitalWriteOff(D5_LCD);
	}

	bitExport = byteExport & 0x01;
	if(bitExport == 0x01)
	{
		pinDigitalWriteOn(D4_LCD);
	}
	else
	{
		pinDigitalWriteOff(D4_LCD);
	}
	pinDigitalWriteOff(E_LCD);

	// Delay 2 ms
	delayMs(2);
}

/**
 * @brief Send Data LCD Module
 */
void lcdData(uchar data)
{
	// Data Mode
	pinDigitalWriteOn(RS_LCD);

	// Send Byte
	lcdSendByte(data);
}

/**
 * @brief Send Instruction LCD Module
 * @param instru Instruction to send to LCD Module
 */
void lcdInstru(uchar instru)
{
	// Instruction Mode
	pinDigitalWriteOff(RS_LCD);

	// Send Byte
	lcdSendByte(instru);
}

/**
 * @brief Clear LCD Module
 */
void lcdClear()
{
	lcdInstru(LCD_CLEAR);
}

/**
 * @brief Set Home Cursor Position LCD Module
 */
void lcdHome()
{
	lcdInstru(LCD_HOME);
}

/**
 * @brief Set Cursor Position LCD Module
 * @param row LCD Row
 * @param column LCD Column
 */
void lcdSetCursor(uchar row, uchar column)
{
	uchar lcdPosition = 0;

	if(row > 0 && row <= 4 && column > 0 && column <= 20)
	{
		if(row == 1)
		{
			lcdPosition = 0x80 + (column - 1);
		}
		else if(row == 2)
		{
			lcdPosition = 0xC0 + (column - 1);
		}
		else if(row == 3)
		{
			lcdPosition = 0x94 + (column - 1);
		}
		else if(row == 4)
		{
			lcdPosition = 0xD4 + (column - 1);
		}

		// Send position to LCD Module
		lcdInstru(lcdPosition);
	}
}

/**
 * @brief Write Character LCD Module
 * @param exportData Data to Send to LCD Module
 */
void lcdWrite(uchar exportData)
{
	lcdData(exportData);
}

/**
 * @brief Write Character LCD Module
 * @param row LCD Row
 * @param column LCD Column
 * @param exportData Data to Send to LCD Module
 */
void lcdWriteSetPosition(uchar row, uchar column, uchar exportData)
{
	// LCD Position
	lcdSetCursor(row, column);

	// Write Data LCD Module
	lcdData(exportData);
}

/**
 * @brief Write Character LCD Module
 * @param row LCD Row
 * @param column LCD Column
 * @param message Array Message to Send to LCD Module
 */
void lcdWriteMessage(uchar row, uchar column, const uchar message [])
{
	int i = 0;

	// LCD Position
	lcdSetCursor(row, column);

	while(message[i] != 0)
	{
		lcdData(message[i]);

		// Next Character
		i++;
	}
}

/**
 * @brief Set Cursor Blink On LCD Module
 */
void lcdCursorBlinkOn()
{
	lcdInstru(LCD_BLINK_ON);
}

/**
 * @brief Set Cursor Blink Off LCD Module
 */
void lcdCursorBlinkOff()
{
	lcdInstru(LCD_BLINK_OFF);
}

/**
 * @brief Set Cursor Display On LCD Module
 */
void lcdCursorDisplayOn()
{
	lcdInstru(LCD_CURSOR_ON);
}

/**
 * @brief Set Cursor Display Off LCD Module
 */
void lcdCursorDisplayOff()
{
	lcdInstru(LCD_CURSOR_OFF);
}

/**
 * @brief Set Display On LCD Module
 */
void lcdDisplayOn()
{
	lcdInstru(LCD_DISPLAY_ON);
}

/**
 * @brief Set Display Off LCD Module
 */
void lcdDisplayOff()
{
	lcdInstru(LCD_DISPLAY_OFF);
}

/**
 * @brief Set Shift Off LCD Module
 */
void lcdShiftOff()
{
	lcdInstru(LCD_SHIFT_OFF);
}

/**
 * @brief Set Shift Left LCD Module
 */
void lcdShiftLeft()
{
	lcdInstru(LCD_SHIFT_LEFT);
}

/**
 * @brief Set Shift Right LCD Module
 */
void lcdShiftRight()
{
	lcdInstru(LCD_SHIFT_RIGHT);
}

/**
 * @brief Send Data Binary Format LCD Module
 * @param row LCD Row
 * @param column LCD Column
 * @param exportData Data to Send to LCD Module
 */
void lcdDataBinFormat(uchar row, uchar column, uchar exportData)
{
	// LCD Position
	lcdSetCursor(row, column);

	uchar binaryMask = 0x80;
	uchar digit = 0;

	int i = 0;

	for(i=0; i < 8; i++)
	{
		// Get Digit
		digit = (exportData / binaryMask);

		// Fix the Export Data and Binary Mask
		if(digit == 1)
		{
			exportData = exportData - binaryMask;
		}
		binaryMask = binaryMask >> 1;

		// Export Digit to LCD Module
		digit += 0x30;
		lcdData(digit);
	}

	// Print Binary Symbol
	lcdData('b');
}

/**
 * @brief Send Data Hexadecimal Format LCD Module
 * @param row LCD Row
 * @param column LCD Column
 * @param exportData Data to Send to LCD Module
 */
void lcdDataHexFormat(uchar row, uchar column, uchar exportData)
{
	// LCD Position
	lcdSetCursor(row, column);

	uchar firstDigit = 0;
	uchar secondDigit = 0;

	// Print Hex Symbol
	lcdData('0');
	lcdData('x');

	// First Digit
	firstDigit = exportData / 16;

	// Second Digit
	secondDigit = exportData - (firstDigit * 16);

	// Export First Digit
		if(firstDigit > 9)
	{
		firstDigit += 0x37;
	}
	else
	{
		firstDigit += 0x30;
	}
	lcdData(firstDigit);

	// Export Second Digit
	if(secondDigit > 9)
	{
		secondDigit += 0x37;
	}
	else
	{
		secondDigit += 0x30;
	}
	lcdData(secondDigit);
}

/**
 * @brief Send Data Decimal Format LCD Module
 * @param row LCD Row
 * @param column LCD Column
 * @param exportData Data to Send to LCD Module
 * @param quantityDigits Quantity Digits
 */
void lcdDataDecFormatSetPosition(uchar row, uchar column, uint exportData, uchar quantityDigits)
{
	// LCD Position
	lcdSetCursor(row, column);

	// Send Data Decimal Format LCD Module
	lcdDataDecFormat(exportData, quantityDigits);
}

/**
 * @brief Send Data Decimal Format LCD Module
 * @param dataExport Data to Send to LCD Module
 * @param quantityDigits Quantity Digits
 */
void lcdDataDecFormat(uint dataExport, uchar quantityDigits)
{
	uchar i = 0;
	uint divisor = 1;
	uchar digitExport = 0;

	// Get Divisor
	for(i = 1; i < quantityDigits; i++)
	{
		divisor *= 10;
	}

	// Get and Export Digits
	for(i = 1; i <= quantityDigits; i++)
	{
		// Export Digit
		digitExport = (dataExport / divisor) + 0x30;
		lcdData(digitExport);

		// Decrement export data and divisor
		dataExport %= divisor;
		divisor /= 10;
	}
}

/**
 * @brief Send Data Double Format LCD Module
 * @param row LCD Row
 * @param column LCD Column
 * @param dataExport Data to Send to LCD Module
 * @param quantityDigits Quantity Digits
 * @param quantityDecimals Quantity Decimals
 */
void lcdDataDoubleFormatSetPosition(uchar row, uchar column, double dataExport, uchar quantityDigits, uchar quantityDecimals)
{
	// LCD Position
	lcdSetCursor(row, column);

	// Send Data Double Format LCD Module
	lcdDataDoubleFormat(dataExport, quantityDigits, quantityDecimals);
}

/**
 * @brief Send Data Double Format LCD Module
 * @param dataExport Data to Send to LCD Module
 * @param quantityDigits Quantity Digits
 * @param quantityDecimals Quantity Decimals
 */
void lcdDataDoubleFormat(double dataExport, uchar quantityDigits, uchar quantityDecimals)
{
	uchar i = 0;
	uint divisorDigits = 1;
	uint divisorDecimals = 1;
	uint digitPart = 0;
	uint decimalPart = 0;
	uchar digitExport = 0;

	// Get Divisor Digits
	for(i = 1; i < quantityDigits; i++)
	{
		divisorDigits *= 10;
	}

	// Get Divisor Decimals
	for(i = 1; i < quantityDecimals; i++)
	{
		divisorDecimals *= 10;
	}

	// Separate digit and part
	digitPart = (uchar) dataExport;

	// Separate decimal part
	dataExport -= digitPart;
	dataExport *= (divisorDecimals * 10);
	decimalPart = (uchar) dataExport;

	// Get and Export Digits
	for(i = 1; i <= quantityDigits; i++)
	{
		// Export Digit
		digitExport = (digitPart / divisorDigits) + 0x30;
		lcdData(digitExport);

		// Decrement export data and divisor
		digitPart %= divisorDigits;
		divisorDigits /= 10;
	}

	lcdWrite('.');

	// Get and Export Decimals
	for(i = 1; i <= quantityDecimals; i++)
	{
		// Export Digit
		digitExport = (decimalPart / divisorDecimals) + 0x30;
		lcdData(digitExport);

		// Decrement export data and divisor
		decimalPart %= divisorDecimals;
		divisorDecimals /= 10;
	}
}

/**
 * @brief Send Data Date Format LCD Module
 * @param row LCD Row
 * @param column LCD Column
 * @param day Day
 * @param month Month
 * @param year Year
 */
void lcdDataDateFormat(uchar row, uchar column, uint day, uint month, uint year)
{
	// LCD Position
	lcdSetCursor(row, column);

	// Write Day
	lcdDataDecFormat(day,2);
	lcdWrite('/');

	// Write Month
	lcdDataDecFormat(month,2);
	lcdWrite('/');

	// Write Day
	lcdDataDecFormat(year,4);
}

/**
 * @brief Send Data Time Format LCD Module
 * @param row LCD Row
 * @param column LCD Column
 * @param hour Hour
 * @param minute Minute
 * @param second Second
 */
void lcdDataTimeFormat(uchar row, uchar column, uint hour, uint minute, uint second)
{
	// LCD Position
	lcdSetCursor(row, column);

	// Write Day
	lcdDataDecFormat(hour,2);
	lcdWrite(':');

	// Write Month
	lcdDataDecFormat(minute,2);
	lcdWrite(':');

	// Write Day
	lcdDataDecFormat(second,2);
}
