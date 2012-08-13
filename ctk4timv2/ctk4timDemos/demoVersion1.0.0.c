/**
 *  @file ctk4timApp.c
 *  @brief Application Program
 *  @date 13/08/2012
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

#ifndef DEMOVERSION100

#include "../ctk4timIncludes/coreModule.h"
#include "../ctk4timIncludes/ioModule.h"
#include "../ctk4timIncludes/delayModule.h"
#include "../ctk4timIncludes/timerModule.h"
#include "../ctk4timIncludes/pianoModule.h"
#include "../ctk4timIncludes/lcdModule.h"

const uint fraySantiago [] = {C3,D3,E3,C3,SPACE,C3,D3,E3,C3,SPACE,E3,F3,G3,SPACE,E3,F3,G3,SPACE,G3,A3,G3,F3,E3,C3,SPACE,G3,A3,G3,F3,E3,C3,SPACE,D3,D3,C3,SPACE,D3,D3,C3,STOP};
const uchar mensaje [] = "CTK4TIM! Easy!!!";

/*
 * Led Default Definition
 */
#define	LED1		&P1OUT,BIT7
#define LED2		&P1OUT,BIT6

/*
 * @brief Application Program Loop
 */
void applicationDemo100()
{
	uint i = 0;

	// Stop Watchdog Timer
	stopWatchdogTimer();

	// Configure DCO Frequency 1 MHz
	configureDCOFrequency1MHz();

	// Leds Initial State
	pinDigitalWriteOff(LED1);

	// Configure Leds Outputs
	pinDigitalOutput(LED1);

	// Initialize LCD Module
	lcdInit();

	// Initialize Piano Module
	pianoInit();

	// Write Message Constant
	lcdWriteMessage(1,1,mensaje);

	for(;;)
	{
		// Write value variable
		for(i = 0; i < 256; i++)
		{
			// Write counter value
			lcdSetCursor(2,1);
			lcdDataDecFormat(i,3);
			lcdDataBinFormat(2,5,i);
			lcdDataHexFormat(2,15,i);

			// Increment counter
			delayMs(20);
		}

		// Play a song
		pinDigitalWriteOn(LED1);
		pianoPlaySong(fraySantiago, 350, 30);
		pinDigitalWriteOff(LED1);
	}
}

/**
 * @brief Interrupt Service Routine Port 1
 */
void isrPort1Demo100()
{

}

/**
 * @brief Interrupt Service Routine Port 2
 */
void isrPort2Demo100()
{

}

/**
 * @brief Interrupt Service Routine Timer A Channel 1
 */
void isrTimerACh1Demo100()
{
	// Clear Timer Interrupt
	TACTL &= ~(TAIFG);
}

/**
 * @brief Interrupt Service Routine Timer A Channel 0
 */
void isrTimerACh0Demo100()
{
	// Clear Timer Interrupt
	TACTL &= ~(TAIFG);
}

/**
 * @brief Interrupt Service Routine WatchDog Timer
 */
void isrWDTDemo100()
{

}

/**
 * @brief Interrupt Service Routine Comparator A
 */
void isrComparatorDemo100()
{

}

/**
 * @brief Interrupt Service Routine NMI
 */
void isrNMIDemo100()
{

}

#endif
