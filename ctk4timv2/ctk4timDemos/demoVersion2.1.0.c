/**
 *  @file demoVersion2.1.0.c
 *  @brief Demo Version 2.1.0
 *  @date 15/08/2012
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

#include "demoVersion2.1.0.h"

#ifdef DEMOVERSION210

#include "../ctk4timIncludes/coreModule.h"
#include "../ctk4timIncludes/lcdModule.h"
#include "../ctk4timIncludes/keyMatrixModule.h"

const uchar mensaje [] = "KeyMatrixTest";

/*
 * @brief Application Program Loop
 */
void application()
{
	int i, data = 0;

	// Stop Watchdog Timer
	stopWatchdogTimer();

	// Configure DCO Frequency 1 MHz
	configureDCOFrequency1MHz();

	// Init LCD Module
	lcdInit();

	// KeyMatrix Init Module
	keyMatrixInit();

	// Write Init Message
	lcdWriteMessage(1,1,mensaje);

	for(;;)
	{
		// Set LCD Position
		lcdSetCursor(2,1);

		for(i = 1; i <=16; i++)
		{
			do
			{
				data = keyMatrixRead();
			}
			while(data == -1);

			// Write Key Pressed Value
			lcdWrite(keyMatrixKeyASCII(data));
		}
	}
}

/**
 * @brief Interrupt Service Routine Port 1
 */
void isrPort1()
{

}

/**
 * @brief Interrupt Service Routine Port 2
 */
void isrPort2()
{

}

/**
 * @brief Interrupt Service Routine Timer A Channel 1
 */
void isrTimerACh1()
{
	// Display Update
	display7SegUpdate();

	// Clear Timer Interrupt
	TACTL &= ~(TAIFG);
}

/**
 * @brief Interrupt Service Routine Timer A Channel 0
 */
void isrTimerACh0()
{
	// Clear Timer Interrupt
	TACTL &= ~(TAIFG);
}

/**
 * @brief Interrupt Service Routine WatchDog Timer
 */
void isrWDT()
{

}

/**
 * @brief Interrupt Service Routine Comparator A
 */
void isrComparatorA()
{

}

/**
 * @brief Interrupt Service Routine NMI
 */
void isrNMI()
{

}

#endif
