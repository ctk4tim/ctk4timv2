/**
 *  @file keyMatrixModule.c
 *  @brief Module that allows controls Key Matrix
 *  @date 06/08/2012
 *  @version 1.0.0
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

#include "../ctk4timIncludes/keyMatrixModule.h"

/**
 * ASCII Table Conversion
 */
uchar const keyMatrixData [4][4] = {{'0','1','2','3',},		// Row 0
									{'4','5','6','7',}, 	// Row 1
									{'8','9','A','B',}, 	// Row 2
									{'C','D','E','F',}};	// Row 3
/**
 * @brief Init Key Matrix
 */
void keyMatrixInit()
{
	// Configure Inputs
	pinDigitalInput(KEYMATRIX_X1);
	pinDigitalEnabledPullUp(KEYMATRIX_X1);
	pinDigitalInput(KEYMATRIX_X2);
	pinDigitalEnabledPullUp(KEYMATRIX_X2);
	pinDigitalInput(KEYMATRIX_X3);
	pinDigitalEnabledPullUp(KEYMATRIX_X3);
	pinDigitalInput(KEYMATRIX_X4);
	pinDigitalEnabledPullUp(KEYMATRIX_X4);

	// Configure Outpus
	pinDigitalWriteOn(KEYMATRIX_Y1);
	pinDigitalOutput(KEYMATRIX_Y1);
	pinDigitalWriteOn(KEYMATRIX_Y2);
	pinDigitalOutput(KEYMATRIX_Y2);
	pinDigitalWriteOn(KEYMATRIX_Y3);
	pinDigitalOutput(KEYMATRIX_Y3);
	pinDigitalWriteOn(KEYMATRIX_Y4);
	pinDigitalOutput(KEYMATRIX_Y4);
}

/**
 * @brief Key Matrix Read Data
 * @return Key Pressed Value
 */
uchar keyMatrixRead()
{
	uchar i, j = 0;
	int dataRead = 0;

	// Scan Rows and Columns
	for( i = 0; i < 4; i++)
	{
		for( j = 0; j < 4; j++)
		{
			// Read Key
			dataRead = readRow(i,j);

			// Exit when Key Pressed
			if(dataRead != -1)
			{
				break;
			}
		}
	}
	return dataRead;
}

/**
 * @brief Read Row Value
 * @param row Row to Read
 * @param column Column to Read
 * @return Key Pressed Value
 */
int readRow(uchar row, uchar column)
{
	int rowValue = -1;

	switch(column)
	{
		case 0:
			// Read Key Pressed Column 0
			pinDigitalWriteOff(KEYMATRIX_Y1);
			if(pinDigitalRead(KEYMATRIX_X1) == 0)
			{
				delayMs(50);
				if(pinDigitalRead(KEYMATRIX_X1) == 0)
				{
					rowValue = 0;
				}
			}
			pinDigitalWriteOn(KEYMATRIX_Y1);
			break;
		case 1:
			// Read Key Pressed Column 1
			pinDigitalWriteOff(KEYMATRIX_Y2);
			if(pinDigitalRead(KEYMATRIX_X2) == 0)
			{
				delayMs(50);
				if(pinDigitalRead(KEYMATRIX_X2) == 0)
				{
					rowValue = 1;
				}
			}
			pinDigitalWriteOn(KEYMATRIX_Y2);
			break;
		case 2:
			// Read Key Pressed Column 2
			pinDigitalWriteOff(KEYMATRIX_Y3);
			if(pinDigitalRead(KEYMATRIX_X3) == 0)
			{
				delayMs(50);
				if(pinDigitalRead(KEYMATRIX_X3) == 0)
				{
					rowValue = 2;
				}
			}
			pinDigitalWriteOn(KEYMATRIX_Y3);
			break;
		case 3:
			// Read Key Pressed Column 3
			pinDigitalWriteOff(KEYMATRIX_Y4);
			if(pinDigitalRead(KEYMATRIX_X4) == 0)
			{
				delayMs(50);
				if(pinDigitalRead(KEYMATRIX_X4) == 0)
				{
					rowValue = 3;
				}
			}
			pinDigitalWriteOn(KEYMATRIX_Y4);
			break;
	}

	// If key pressed, complete key value
	if(rowValue != -1)
	{
		switch(row)
		{
			case 0:
				rowValue += 0;
				break;
			case 1:
				rowValue += 4;
				break;
			case 2:
				rowValue += 8;
				break;
			case 3:
				rowValue += 12;
				break;
		}
	}
	return rowValue;
}
