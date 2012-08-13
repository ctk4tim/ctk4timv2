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

#ifndef DEMOVERSION160

#include "../ctk4timIncludes/coreModule.h"
#include "../ctk4timIncludes/rgbLedModule.h"
#include "../ctk4timIncludes/adcModule.h"

/**
 * Step RGB Led
 */
uchar stepRGBLed = 0;

/**
 * Red RGB Value
 */
uint red = 0;

/**
 * Green RGB Value
 */
uint green = 0;

/**
 * Blue RGB Value
 */
uint blue = 0;

/*
 * @brief Application Program Loop
 */
void applicationDemo160()
{
	// Stop Watchdog Timer
	stopWatchdogTimer();

	// Configure DCO Frequency 8 MHz
	configureDCOFrequency8MHz();

	// Configure A0, A1 and A2 Input
	adcAnalogInputEnable(ADC_CH0);
	adcAnalogInputEnable(ADC_CH1);
	adcAnalogInputEnable(ADC_CH2);

	// ADC Init
	adcInit();

	// RGB Led Init
	rgbLedInit();

	// Enable Interrupts
	enableInterrupts();

	// Entry Low Power Mode 0
	entryLowPowerMode0();
}

/**
 * @brief Interrupt Service Routine Port 1
 */
void isrPort1Demo160()
{

}

/**
 * @brief Interrupt Service Routine Port 2
 */
void isrPort2Demo160()
{

}

/**
 * @brief Interrupt Service Routine Timer A Channel 1
 */
void isrTimerACh1Demo160()
{
	if(stepRGBLed == 0)
	{
		// Obtain ADC Value First Time
		red = adcStartWaitConversion(ADC_CH0);
		red >>= 2;
		green = adcStartWaitConversion(ADC_CH1);
		green >>= 2;
		blue = adcStartWaitConversion(ADC_CH2);
		blue >>= 2;

		// RGB Led Update
		stepRGBLed = rgbLedUpdate(red, green, blue);
	}
	else
	{
		// RGB Led Update
		stepRGBLed = rgbLedUpdate(red, green, blue);
	}

	// Clear Timer Interrupt
	TACTL &= ~(TAIFG);
}

/**
 * @brief Interrupt Service Routine Timer A Channel 0
 */
void isrTimerACh0Demo160()
{
	// Clear Timer Interrupt
	TACTL &= ~(TAIFG);
}

/**
 * @brief Interrupt Service Routine WatchDog Timer
 */
void isrWDTDemo160()
{

}

/**
 * @brief Interrupt Service Routine Comparator A
 */
void isrComparatorDemo160()
{

}

/**
 * @brief Interrupt Service Routine NMI
 */
void isrNMIDemo160()
{

}

#endif
