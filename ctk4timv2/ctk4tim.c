/**
 *  @file ctk4tim.c
 *  @brief Main Program Loop
 *  @date 29/02/2012
 *  @version 1.0.3
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

#include "ctk4timIncludes/coreModule.h"
#include "ctk4timIncludes/display7SegModule.h"

const uchar display7SegMessage [] ={0x00,0x01,0x02,0x03,
									0x04,0x05,0x06,0x07,
									0x08,0x09,0x0A,0x0B,
									0x0C,0x0D,0x0E,0x0F,0xFF};
/*
 * @brief Main Program Loop
 * @param void Void
 */
void main(void)
{
	// Stop Watchdog Timer
	stopWatchdogTimer();

	// Configure DCO Frequency 1 MHz
	configureDCOFrequency1MHz();

	// Init LCD Module
	display7SegInit();

	// Set Scroll On and Time Scroll
	display7SegScrollOn(250);

	// Write 1234 in buffer
	display7SegWriteMessage(5,display7SegMessage);

	// Enable Interrupts
	enableInterrupts();

	// Entry Low Power Mode 0
	entryLowPowerMode0();
}

/**
 * @brief Interrupt Service Routine Port 1
 */
#pragma vector = PORT1_VECTOR
__interrupt void P1_ISR (void)
{

}

/**
 * @brief Interrupt Service Routine Port 2
 */
#pragma vector = PORT2_VECTOR
__interrupt void P2_ISR (void)
{

}

/**
 * @brief Interrupt Service Routine Timer A Channel 1
 */
#pragma vector = TIMER0_A1_VECTOR
__interrupt void TA1_ISR (void)
{
	// Display Update
	display7SegUpdate();

	// Clear Timer Interrupt
	TACTL &= ~(TAIFG);
}

/**
 * @brief Interrupt Service Routine Timer A Channel 0
 */
#pragma vector = TIMER0_A0_VECTOR
__interrupt void TA0_ISR (void)
{
	// Clear Timer Interrupt
	TACTL &= ~(TAIFG);
}

/**
 * @brief Interrupt Service Routine WatchDog Timer
 */
#pragma vector = WDT_VECTOR
__interrupt void WDT_ISR (void)
{

}

/**
 * @brief Interrupt Service Routine Comparator A
 */
#pragma vector = COMPARATORA_VECTOR
__interrupt void CMPA_ISR (void)
{

}

/**
 * @brief Interrupt Service Routine NMI
 */
#pragma vector = NMI_VECTOR
__interrupt void NMI_ISR (void)
{

}
