/**
 *  @file adcModule.c
 *  @brief Module that allows A/D Conversions
 *  @date 13/04/2012
 *  @version 1.0.1
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

#include "../ctk4timIncludes/adcModule.h"
#include "../ctk4timIncludes/delayModule.h"

/**
 * @brief Init ADC Module
 */
void adcInit()
{
	// Select ADC10OSC ADC Clock
	ADC10CTL1 = ADC10SSEL1 | ADC10DIV1 | ADC10DIV0;

	// Enable ADC Conversion
	ADC10CTL0 = ADC10SHT1 | ENC | REFON | ADC10ON;
}

/**
 * @brief ADC On
 */
void adcOn()
{
	ADC10CTL0 |= ADC10ON;
}

/**
 * @brief ADC Off
 */
void adcOff()
{
	ADC10CTL0 &= ~(ADC10ON);
}

/**
 * @brief ADC Enable Interrupt
 */
void adcEnableInterrupt()
{
	ADC10CTL0 |= ADC10IE;
}

/**
 * @brief ADC Disable Interrupt
 */
void adcDisableInterrupt()
{
	ADC10CTL0 &= ~(ADC10IE);
}

/**
 * @brief ADC Verify Pending Interrupt
 */
uchar adcIsPendingInterrupt()
{
	return (uchar) ADC10CTL0 & ADC10IFG;
}

/**
 * @brief ADC Clear Pending Interrupt
 */
void adcClearPendingInterrupt()
{
	ADC10CTL0 &= ~(ADC10IFG);
}

/**
 * @brief Configure Analog Input Pin
 * @param adcChannel ADC Channel Selected
 */
void adcAnalogInputEnable(uchar adcChannel)
{
	switch(adcChannel)
	{
		case 0:
			ADC10AE0 |= BIT0;
			break;
		case 1:
			ADC10AE0 |= BIT1;
			break;
		case 2:
			ADC10AE0 |= BIT2;
			break;
		case 3:
			ADC10AE0 |= BIT3;
			break;
		case 4:
			ADC10AE0 |= BIT4;
			break;
		case 5:
			ADC10AE0 |= BIT5;
			break;
		case 6:
			ADC10AE0 |= BIT6;
			break;
		case 7:
			ADC10AE0 |= BIT7;
			break;
	}
}

/**
 * @brief ADC Start Conversion
 * @param adcChannel ADC Channel Selected
 */
void adcStartConversion(uchar adcChannel)
{
	// Select ADC Channel
	adcSelectChannel(adcChannel);

	// Start Conversion
	ADC10CTL0 |= ADC10SC;
}

/**
 * @brief ADC Start and Wait Conversion
 * @param adcChannel ADC Channel Selected
 * @return ADC Value Conversion
 */
uint adcStartWaitConversion(uchar adcChannel)
{
	// Select ADC Channel
	adcSelectChannel(adcChannel);

	// Start ADC Conversion
	ADC10CTL0 |= ADC10SC;

	// Wait ADC Conversion
	while(ADC10CTL1 & ADC10BUSY);

	return ADC10MEM;
}

/**
 * @brief Select ADC Channel
 * @param adcChannel ADC Channel Selected
 */
void adcSelectChannel(uchar adcChannel)
{
	// Unlock ADC
	ADC10CTL0 &= ~(ENC);

	// Select Default Channel 0
	ADC10CTL1 &= 0x0FFF;

	// Select VCC Reference
	ADC10CTL0 &= 0x1FFF;

	// Off VRef
	ADC10CTL0 &= ~(REFON);

	switch(adcChannel)
	{
		case 0:
			ADC10CTL1 |= INCH_0;
			break;
		case 1:
			ADC10CTL1 |= INCH_1;
			break;
		case 2:
			ADC10CTL1 |= INCH_2;
			break;
		case 3:
			ADC10CTL1 |= INCH_3;
			break;
		case 4:
			ADC10CTL1 |= INCH_4;
			break;
		case 5:
			ADC10CTL1 |= INCH_5;
			break;
		case 6:
			ADC10CTL1 |= INCH_6;
			break;
		case 7:
			ADC10CTL1 |= INCH_7;
			break;
		case 10:
			// Select VREF Reference
			ADC10CTL0 |= (SREF0 | REFON);

			// Select Default Channel 10
			ADC10CTL1 |= INCH_10;
			break;
	}
	// Lock ADC
	ADC10CTL0 |= ENC;
}

/**
 * @brief Get Temperature Value
 * @return Internal Temperature Value
 */
double adcGetTemperatureSensor()
{
	double temperature = 0.00;

	// Select ADC Channel
	adcSelectChannel(ADC_CHTEMP);

	// Delay 1ms
	delayMs(1);

	// Start ADC Conversion
	ADC10CTL0 |= ADC10SC;

	// Wait ADC Conversion
	while(ADC10CTL1 & ADC10BUSY);

	// Get ADC Temperature Sensor Value
	temperature = ((ADC10MEM * 0.413) - 277.746);

	// Return Temperature
	return temperature;
}
