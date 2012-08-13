/**
 *  @file ctk4tim.c
 *  @brief Main Program Loop
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

#include "ctk4timIncludes/coreModule.h"

#define DEMO

#ifdef DEMO

/*
 * Point Demo Application
 */
#include "ctk4timDemos/demoVersion1.0.0.h"
#define app 		application##Demo100
#define isrP1 		isrPort1##Demo100
#define isrP2 		isrPort2##Demo100
#define isrTimCh1	isrTimerACh1##Demo100
#define isrTimCh0	isrTimerACh0##Demo100
#define isrWDT		isrWDT##Demo100
#define isrComp		isrComparator##Demo100
#define isrNMI		isrNMI##Demo100

#else

/*
 * Point Main Application
 */
#include "ctk4timApp.h"
#define app 		application##App
#define isrP1 		isrPort1##App
#define isrP2 		isrPort2##App
#define isrTimCh1	isrTimerACh1##App
#define isrTimCh0	isrTimerACh0##App
#define isrWDT		isrWDT##App
#define isrComp		isrComparator##App
#define isrNMI		isrNMI##App

#endif

/*
 * @brief Main Program Loop
 * @param void Void
 */
void main(void)
{
	app();
}

/**
 * @brief Interrupt Service Routine Port 1
 */
#pragma vector = PORT1_VECTOR
__interrupt void P1_ISR (void)
{
	isrP1();
}

/**
 * @brief Interrupt Service Routine Port 2
 */
#pragma vector = PORT2_VECTOR
__interrupt void P2_ISR (void)
{
	isrP2();
}

/**
 * @brief Interrupt Service Routine Timer A Channel 1
 */
#pragma vector = TIMER0_A1_VECTOR
__interrupt void TA1_ISR (void)
{
	isrTimCh1();
}

/**
 * @brief Interrupt Service Routine Timer A Channel 0
 */
#pragma vector = TIMER0_A0_VECTOR
__interrupt void TA0_ISR (void)
{
	isrTimCh0();
}

/**
 * @brief Interrupt Service Routine WatchDog Timer
 */
#pragma vector = WDT_VECTOR
__interrupt void WDT_ISR (void)
{
	isrWDT();
}

/**
 * @brief Interrupt Service Routine Comparator A
 */
#pragma vector = COMPARATORA_VECTOR
__interrupt void CMPA_ISR (void)
{
	isrComp();
}

/**
 * @brief Interrupt Service Routine NMI
 */
#pragma vector = NMI_VECTOR
__interrupt void NMI_ISR (void)
{
	isrNMI();
}
