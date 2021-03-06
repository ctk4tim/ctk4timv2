/**
 *  @file coreModule.c
 *  @brief General CTK4TIM API Specifications
 *  @date 29/02/2012
 *  @version 1.0.2
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

#include "../ctk4timIncludes/coreModule.h"

/**
 * @brief Stop Watchdog Timer
 */
void stopWatchdogTimer()
{
	WDTCTL = WDTPW + WDTHOLD;
}

/**
 * @brief Configure DCO Frequency 1 MHz
 */
void configureDCOFrequency1MHz()
{
	BCSCTL1 = CALBC1_1MHZ;
	DCOCTL = CALDCO_1MHZ;
}

/**
 * @brief Configure DCO Frequency 8 MHz
 */
void configureDCOFrequency8MHz()
{
	BCSCTL1 = CALBC1_8MHZ;
	DCOCTL = CALDCO_8MHZ;
}

/**
 * @brief Configure DCO Frequency 12 MHz
 */
void configureDCOFrequency12MHz()
{
	BCSCTL1 = CALBC1_12MHZ;
	DCOCTL = CALDCO_12MHZ;
}

/**
 * @brief Configure DCO Frequency 16 MHz
 */
void configureDCOFrequency16MHz()
{
	BCSCTL1 = CALBC1_16MHZ;
	DCOCTL = CALDCO_16MHZ;
}

/**
 * @brief Enable Interrupts
 */
void enableInterrupts()
{
	_enable_interrupts();
}

/**
 * @brief Disable Interrupts
 */
void disableInterrupts()
{
	_disable_interrupts();
}

/**
 * @brief Entry Low Power Mode 0
 */
void entryLowPowerMode0()
{
	__low_power_mode_0();
}
