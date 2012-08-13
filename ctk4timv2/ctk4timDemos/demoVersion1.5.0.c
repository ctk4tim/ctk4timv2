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

#ifdef DEMOVERSION150

#include "../ctk4timIncludes/coreModule.h"
#include "../ctk4timIncludes/ledMatrixModule.h"
#include "../ctk4timIncludes/rs232Module.h"

/**
 * Led Matrix Message
 */
const uchar ledMatrixMessage [] = " CTK4TIM! ";

/*
 * @brief Application Program Loop
 */
void applicationDemo150()
{
	uchar dataReceive = 0;
	uchar bufferPosition = 1;

	// Stop Watchdog Timer
	stopWatchdogTimer();

	// Configure DCO Frequency 1 MHz
	configureDCOFrequency1MHz();

	// Led Matrix Init
	ledMatrixInit();

	// RS-232 Init
	rs232Init();

	// Capture Data User
	do
	{
		// Receive Data
		dataReceive = rs232ReadByte();

		// Write data in Buffer Led Matrix
		ledMatrixWriteBuffer(bufferPosition,dataReceive);

		// Send Byte
		rs232WriteByte(dataReceive);

		// Increment Position
		bufferPosition++;
	}
	while(dataReceive != '.');


	// Set Scroll On and Time Scroll
	ledMatrixScrollOn(70);

	// Enable Interrupts
	enableInterrupts();

	// Entry Low Power Mode 0
	entryLowPowerMode0();
}

/**
 * @brief Interrupt Service Routine Port 1
 */
void isrPort1Demo150()
{

}

/**
 * @brief Interrupt Service Routine Port 2
 */
void isrPort2Demo150()
{

}

/**
 * @brief Interrupt Service Routine Timer A Channel 1
 */
void isrTimerACh1Demo150()
{
	// Led Matrix Update
	ledMatrixUpdate();

	// Clear Timer Interrupt
	TACTL &= ~(TAIFG);
}

/**
 * @brief Interrupt Service Routine Timer A Channel 0
 */
void isrTimerACh0Demo150()
{
	// Clear Timer Interrupt
	TACTL &= ~(TAIFG);
}

/**
 * @brief Interrupt Service Routine WatchDog Timer
 */
void isrWDTDemo150()
{

}

/**
 * @brief Interrupt Service Routine Comparator A
 */
void isrComparatorDemo150()
{

}

/**
 * @brief Interrupt Service Routine NMI
 */
void isrNMIDemo150()
{

}

#endif
