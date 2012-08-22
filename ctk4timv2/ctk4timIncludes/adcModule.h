/**
 *  @file adcModule.h
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

#ifndef ADCMODULE_H_
#define ADCMODULE_H_

#include "coreModule.h"
#include "ioModule.h"
#include "delayModule.h"

/**
 * @brief Init ADC Module
 */
void adcInit();

/**
 * @brief ADC On
 */
void adcOn();

/**
 * @brief ADC Off
 */
void adcOff();

/**
 * @brief ADC Enable Interrupt
 */
void adcEnableInterrupt();

/**
 * @brief ADC Disable Interrupt
 */
void adcDisableInterrupt();

/**
 * @brief ADC Verify Pending Interrupt
 */
uchar adcIsPendingInterrupt();

/**
 * @brief ADC Clear Pending Interrupt
 */
void adcClearPendingInterrupt();

/**
 * @brief Configure Analog Input Pin
 * @param adcChannel ADC Channel Selected
 */
void adcAnalogInputEnable(uchar adcChannel);

/**
 * @brief ADC Start Conversion
 * @param adcChannel ADC Channel Selected
 */
void adcStartConversion(uchar adcChannel);

/**
 * @brief ADC Start and Wait Conversion
 * @param adcChannel ADC Channel Selected
 * @return ADC Value Conversion
 */
uint adcStartWaitConversion(uchar adcChannel);

/**
 * @brief Select ADC Channel
 * @param adcChannel ADC Channel Selected
 */
void adcSelectChannel(uchar adcChannel);

/**
 * @brief Get Temperature Value
 * @return Internal Temperature Value
 */
double adcGetTemperatureSensor();

#endif
