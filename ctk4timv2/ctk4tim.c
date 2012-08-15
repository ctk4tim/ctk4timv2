/**
 *  @file ctk4tim.c
 *  @brief Main Program Loop
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

#include "ctk4tim.h"

/*
 * App or Demo Selection
 */
#ifdef DEMOVERSION100
	#include "ctk4timDemos/demoVersion1.0.0.h"
#endif
#ifdef DEMOVERSION110
	#include "ctk4timDemos/demoVersion1.1.0.h"
#endif
#ifdef DEMOVERSION120
	#include "ctk4timDemos/demoVersion1.2.0.h"
#endif
#ifdef DEMOVERSION130
	#include "ctk4timDemos/demoVersion1.3.0.h"
#endif
#ifdef DEMOVERSION140
	#include "ctk4timDemos/demoVersion1.4.0.h"
#endif
#ifdef DEMOVERSION150
	#include "ctk4timDemos/demoVersion1.5.0.h"
#endif
#ifdef DEMOVERSION160
	#include "ctk4timDemos/demoVersion1.6.0.h"
#endif
#ifdef APP
	#include "ctk4timApp.h"
#endif

/*
 * @brief Main Program Loop
 * @param void Void
 */
void main(void)
{
	application();
}

/**
 * @brief Interrupt Service Routine Port 1
 */
#pragma vector = PORT1_VECTOR
__interrupt void P1_ISR (void)
{
	isrPort1();
}

/**
 * @brief Interrupt Service Routine Port 2
 */
#pragma vector = PORT2_VECTOR
__interrupt void P2_ISR (void)
{
	isrPort2();
}

/**
 * @brief Interrupt Service Routine Timer A Channel 1
 */
#pragma vector = TIMER0_A1_VECTOR
__interrupt void TA1_ISR (void)
{
	isrTimerACh1();
}

/**
 * @brief Interrupt Service Routine Timer A Channel 0
 */
#pragma vector = TIMER0_A0_VECTOR
__interrupt void TA0_ISR (void)
{
	isrTimerACh0();
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
	isrComparatorA();
}

/**
 * @brief Interrupt Service Routine NMI
 */
#pragma vector = NMI_VECTOR
__interrupt void NMI_ISR (void)
{
	isrNMI();
}
