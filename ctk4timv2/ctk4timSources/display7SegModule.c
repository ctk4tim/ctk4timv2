/**
 *  @file display7SegModule.c
 *  @brief Module that allows controls a Led Matrix
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

#include "../ctk4timIncludes/display7SegModule.h"

/**
 * Display 7-Seg Font
 */
uchar const display7SegFont [16]= {0x40,0x79,0x24,0x30,0x19,0x12,0x02,0x78,0x00,0x18,0x08,0x03,0x27,0x21,0x06,0x0E};
/**
 * Display 7-Seg Buffer
 */
uchar bufferDisplay7Seg [MAX_BUFFER_DISPLAY_CHARS];

/**
 * Display Counter
 */
uchar displayCounter = 0;

/**
 * Display 7-Seg Buffer Pointer
 */
uchar *bufferDisplay7SegPtr;

/**
 * Display 7-Seg Offset Buffer
 */
uchar offsetBufferDisplay7Seg = 0;

/**
 * Display 7-Seg Delay Scroll
 */
uchar delayScrollDisplay7Seg = 0;

/**
 * Display 7-Seg Time Scroll
 */
uchar timeScrollDisplay7Seg = 0;

/**
 * Display 7-Seg Scroll On
 */
uchar scrollOnDisplay7Seg = 0;

/**
 * @brief Init Display 7-Seg
 */
void display7SegInit()
{
	uchar i = 0;

	// Configure Output Display 7-Seg Pins
	pinDigitalWriteOn(DISPLAY7SEG_A);
	pinDigitalOutput(DISPLAY7SEG_A);
	pinDigitalWriteOn(DISPLAY7SEG_B);
	pinDigitalOutput(DISPLAY7SEG_B);
	pinDigitalWriteOn(DISPLAY7SEG_C);
	pinDigitalOutput(DISPLAY7SEG_C);
	pinDigitalWriteOn(DISPLAY7SEG_D);
	pinDigitalOutput(DISPLAY7SEG_D);
	pinDigitalWriteOn(DISPLAY7SEG_E);
	pinDigitalOutput(DISPLAY7SEG_E);
	pinDigitalWriteOn(DISPLAY7SEG_F);
	pinDigitalOutput(DISPLAY7SEG_F);
	pinDigitalWriteOn(DISPLAY7SEG_G);
	pinDigitalOutput(DISPLAY7SEG_G);

	// Clock Off
	pinDigitalWriteOff(DISPLAY7SEG_SRCLK);
	pinDigitalOutput(DISPLAY7SEG_SRCLK);
	// Data On
	pinDigitalWriteOn(DISPLAY7SEG_SRDAT);
	pinDigitalOutput(DISPLAY7SEG_SRDAT);

	// Init display counter
	displayCounter = 0;

	// Point to buffer
	bufferDisplay7SegPtr = (uchar *) &bufferDisplay7Seg;

	// Off All Displays
	for(i = 0; i < MAX_DISPLAYS; i++)
	{
		pinDigitalWriteOn(SRCLK_LEDMATRIX);
		pinDigitalWriteOff(SRCLK_LEDMATRIX);
	}

	// Display Buffer Clear
	display7SegBufferClear();

	// Set Count 2000 Cycles at 1us = 2ms
	TACCR0 = 2000;

	// Configure Timer Source SMCLK, Up Mode
	TACTL = TASSEL1 | MC0 | TACLR | TAIE;
}

/**
 * @brief Display 7-Seg Buffer Clear
 */
void display7SegBufferClear()
{
	uchar i = 0;

	for(i = 0; i < MAX_BUFFER_DISPLAY_CHARS; i++)
	{
		bufferDisplay7Seg [i] = 0xFF;
	}
}

/**
 * @brief Display 7-Seg Write Buffer
 * @param bufferPosition Buffer Position
 * @param data Data to Write
 */
void display7SegWriteBuffer(uchar bufferPosition, uchar data)
{
	if(bufferPosition <= MAX_BUFFER_DISPLAY_CHARS)
	{
		bufferDisplay7Seg[bufferPosition - 1] = data;
	}
}

/**
 * @brief Display 7-Seg Update
 */
void display7SegUpdate()
{
	// Clear Data Row
	pinDigitalWriteOn(DISPLAY7SEG_A);
	pinDigitalWriteOn(DISPLAY7SEG_B);
	pinDigitalWriteOn(DISPLAY7SEG_C);
	pinDigitalWriteOn(DISPLAY7SEG_D);
	pinDigitalWriteOn(DISPLAY7SEG_E);
	pinDigitalWriteOn(DISPLAY7SEG_F);
	pinDigitalWriteOn(DISPLAY7SEG_G);

	// Verify Scroll On/Off and calculate Buffer Offset
	if(scrollOnDisplay7Seg)
	{
		delayScrollDisplay7Seg++;

		if(delayScrollDisplay7Seg == timeScrollDisplay7Seg)
		{
			delayScrollDisplay7Seg = 0;

			offsetBufferDisplay7Seg++;

			if(offsetBufferDisplay7Seg > MAX_BUFFER_DISPLAY_OFFSET)
			{
				offsetBufferDisplay7Seg = 0;
			}
		}
	}

	// Increment Display
	displayCounter++;

	// Reset Display Counter
	if(displayCounter > MAX_DISPLAYS)
	{
		displayCounter = 1;

		// Point to buffer
		bufferDisplay7SegPtr = (uchar *) &bufferDisplay7Seg;
		bufferDisplay7SegPtr += offsetBufferDisplay7Seg;
	}

	// Select Display
	display7SegSelectDisplay(displayCounter);

	// Set 7-Seg Segments
	display7SegSetSegments(display7SegFont[*bufferDisplay7SegPtr]);

	// Increment Buffer Pointer
	bufferDisplay7SegPtr++;
}

/**
 * @brief Select Display 7-Seg
 * @param display Select Display
 */
void display7SegSelectDisplay(uchar display)
{
	// On Column
	pinDigitalWriteOn(SRDAT_LEDMATRIX);

	if(display == 1)
	{
		pinDigitalWriteOff(SRDAT_LEDMATRIX);
	}

	// Clock 74HC164
	pinDigitalWriteOn(SRCLK_LEDMATRIX);
	pinDigitalWriteOff(SRCLK_LEDMATRIX);
}

/**
 * @brief Set Segments
 * @param dataSegments Data by Row
 */
void display7SegSetSegments(uchar dataSegments)
{
	// Set Data Row
	if((dataSegments & BIT0) == 0)
	{
		pinDigitalWriteOff(DISPLAY7SEG_A);
	}
	if((dataSegments & BIT1) == 0)
	{
		pinDigitalWriteOff(DISPLAY7SEG_B);
	}
	if((dataSegments & BIT2) == 0)
	{
		pinDigitalWriteOff(DISPLAY7SEG_C);
	}
	if((dataSegments & BIT3) == 0)
	{
		pinDigitalWriteOff(DISPLAY7SEG_D);
	}
	if((dataSegments & BIT4) == 0)
	{
		pinDigitalWriteOff(DISPLAY7SEG_E);
	}
	if((dataSegments & BIT5) == 0)
	{
		pinDigitalWriteOff(DISPLAY7SEG_F);
	}
	if((dataSegments & BIT6) == 0)
	{
		pinDigitalWriteOff(DISPLAY7SEG_G);
	}
}

/**
 * @brief Led Matrix Scroll On
 * @param setTimeScroll Set Time Scroll
 */
void display7SegScrollOn(uchar setTimeScroll)
{
	// Enabled Scroll
	scrollOnDisplay7Seg = 1;

	// Set Time Scroll
	timeScrollDisplay7Seg = setTimeScroll / 2;
}

/**
 * @brief Led Matrix Scroll Off
 */
void display7SegScrollOff()
{
	// Disabled Scroll
	scrollOnDisplay7Seg = 0;
}

/**
 * @brief Write Message into Display 7-Seg Buffer
 * @param display Display to Start Write
 * @param message Array Message to Send to Led Matrix
 */
void display7SegWriteMessage(uchar display, const uchar message [])
{
	int i = 0;

	while(message[i] != 0xFF)
	{
		display7SegWriteBuffer(display, message[i]);

		// Next Character
		display++;
		i++;
	}
}
