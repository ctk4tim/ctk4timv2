/**
 *  @file demoVersion1.4.0.c
 *  @brief Demo Version 1.4.0
 *  @date 14/08/2012
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

#include "demoVersion1.4.0.h"

#ifdef DEMOVERSION140

#include "../ctk4timIncludes/coreModule.h"
#include "../ctk4timIncludes/ledMatrixModule.h"

/**
 * Led Matrix Message
 */
const uchar ledMatrixMessage [] = " CTK4TIM! ";

/*
 * @brief Application Program Loop
 */
void application()
{
	// Stop Watchdog Timer
	stopWatchdogTimer();

	// Configure DCO Frequency 1 MHz
	configureDCOFrequency1MHz();

	// Led Matrix Init
	ledMatrixInit();

	// Set Scroll On and Time Scroll
	ledMatrixScrollOn(70);

	// Write data in Buffer Led Matrix
	ledMatrixWriteMessage(1, ledMatrixMessage);

	// Enable Interrupts
	enableInterrupts();

	// Entry Low Power Mode 0
	entryLowPowerMode0();
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
	// Led Matrix Update
	ledMatrixUpdate();

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
