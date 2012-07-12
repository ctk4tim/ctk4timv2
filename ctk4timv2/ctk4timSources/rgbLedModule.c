/**
 *  @file rgbLedModule.c
 *  @brief Module that controls a RGB LED
 *  @date 20/06/2012
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

#include "../ctk4timIncludes/rgbLedModule.h"

/**
 * Step RGB
 */
uint stepRGB = 0;

/**
 * Maximum Step RGB Led
 */
const uchar MAX_STEP_RGB = 255;

/**
 * @brief Init RGB Led Module
 */
void rgbLedInit()
{
	// RGB Pins Output
	pinDigitalWriteOn(RGBLED_RED);
	pinDigitalWriteOn(RGBLED_GREEN);
	pinDigitalWriteOn(RGBLED_BLUE);
	pinDigitalOutput(RGBLED_RED);
	pinDigitalOutput(RGBLED_GREEN);
	pinDigitalOutput(RGBLED_BLUE);

	// Init Step RGB
	stepRGB = 0;

	// Set Count 8 Cycles at 0.125us = 1us
	TACCR0 = 8;

	// Configure Timer Source SMCLK, Up Mode
	TACTL = TASSEL1 | MC0 | TACLR | TAIE;
}

/**
 * @brief RGB Update
 */
uchar rgbLedUpdate(uint red, uint green, uint blue)
{
	if(stepRGB < MAX_STEP_RGB)
	{
		if(stepRGB == 0)
		{
			// RBG Led Pins Off
			pinDigitalWriteOn(RGBLED_RED);
			pinDigitalWriteOn(RGBLED_GREEN);
			pinDigitalWriteOn(RGBLED_BLUE);
		}
		else
		{
			// On Red, Green or Blue Led
			if(stepRGB >= red && red < 254)
			{
				pinDigitalWriteOff(RGBLED_RED);
			}
			if(stepRGB >= green && green < 254)
			{
				pinDigitalWriteOff(RGBLED_GREEN);
			}
			if(stepRGB >= blue && blue < 254)
			{
				pinDigitalWriteOff(RGBLED_BLUE);
			}
		}

		// Increment Step
		stepRGB++;
	}
	else
	{
		stepRGB = 0;

		// RBG Led Pins Off
		pinDigitalWriteOn(RGBLED_RED);
		pinDigitalWriteOn(RGBLED_GREEN);
		pinDigitalWriteOn(RGBLED_BLUE);
	}

	// Return Step RGB
	return stepRGB;
}
