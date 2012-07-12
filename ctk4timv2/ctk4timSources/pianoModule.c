/**
 *  @file pianoModule.c
 *  @brief Module that simulate Piano Tones
 *  @date 29/02/2012
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

#include "../ctk4timIncludes/pianoModule.h"

/**
 * @brief Init Piano Module
 */
void pianoInit()
{
	// Buzzer Initial State
	pinDigitalWriteOff(BUZZER);
	pinDigitalOutput(BUZZER);
}

/**
 * @brief Piano Play Note
 * @param toneValue Note
 * @param timeOn Time Note On
 * @param timeOff Time Note Off
 */
void pianoPlayNote(uint toneValue, ulong timeOn, ulong timeOff)
{
	uint i = 0;
	uint polling = 0;
	uint cycles = 0;

	if(toneValue != SPACE)
	{
		// Calculate Count Cycles
		timeOn = timeOn * 1000;
		cycles = timeOn/toneValue;

		// Set Frequency Tone
		TACCR0 = toneValue;

		// Play Tone N Cycles
		for(i = 0; i < cycles; i++)
		{
			// Configure Timer Frequency
			TACTL = TASSEL1|MC0|TACLR;

			// Clear Timer Flag Interrupt
			TACTL &= ~(TAIFG);

			// Polling Timer Interrupt
			do
			{
				polling = TACTL & TAIFG;
			}
			while (polling == 0);

			// Toogle Buzzer
			pinDigitalWriteToggle(BUZZER);
		}

		// Buzzer Off
		pinDigitalWriteOff(BUZZER);

		// Wait Time Off
		delayMs(timeOff);
	}
	else
	{
		// Wait Time On
		delayMs(timeOn);
	}
}

/**
 * @brief Piano Play Song
 * @param tonesSong Array Tones Song
 * @param timeOn Time Note On
 * @param timeOff Time Note Off
 */
void pianoPlaySong(const uint tonesSong [], ulong timeOn, ulong timeOff)
{
	int i = 0;

	while(tonesSong[i] != 0)
	{
		pianoPlayNote(tonesSong[i], timeOn, timeOff);
		i++;
	}
}
