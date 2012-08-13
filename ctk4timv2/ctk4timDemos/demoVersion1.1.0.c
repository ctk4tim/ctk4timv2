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

#ifndef DEMOVERSION110

#include "../ctk4timIncludes/coreModule.h"
#include "../ctk4timIncludes/ioModule.h"
#include "../ctk4timIncludes/delayModule.h"
#include "../ctk4timIncludes/timerModule.h"
#include "../ctk4timIncludes/pianoModule.h"
#include "../ctk4timIncludes/lcdModule.h"
#include "../ctk4timIncludes/rtcModule.h"

const uchar mensaje [] = "CTK4TIM Easy!!!";
uchar digitToModify = 0;

/*
 * @brief Application Program Loop
 */
void applicationDemo110()
{
	// Stop Watchdog Timer
	stopWatchdogTimer();

	// Configure DCO Frequency 1 MHz
	configureDCOFrequency1MHz();

	// Configure PushButtons Inputs
	pinDigitalInput(RTCSET);
	pinDigitalInput(RTCINC);
	pinDigitalInput(RTCDEC);

	// Configure PullUps
	pinDigitalEnabledPullUp(RTCSET);
	pinDigitalEnabledPullUp(RTCINC);
	pinDigitalEnabledPullUp(RTCDEC);

	// Configure High Low Interrupt
	pinDigitalSelectHighLowTransitionInterrupt(RTCSET);
	pinDigitalSelectHighLowTransitionInterrupt(RTCINC);
	pinDigitalSelectHighLowTransitionInterrupt(RTCDEC);

	// Configure Pin Interrupts
	pinDigitalEnableInterrupt(RTCSET);
	pinDigitalEnableInterrupt(RTCINC);
	pinDigitalEnableInterrupt(RTCDEC);

	// RTC Init
	rtcInit();

	// Start RTC
	rtcStart();

	// Initialize LCD Module
	lcdInit();

	// Write Message Constant
	lcdWriteMessage(1,1,mensaje);

	// Write Date and Time LCD Module
	lcdDataTimeFormat(2, 1, rtcGetHour(), rtcGetMinute(), rtcGetSecond());
	lcdDataDateFormat(2, 11, rtcGetDay(), rtcGetMonth(), rtcGetYear());

	// Enable Interrupts
	enableInterrupts();

	// Entry Low Power Mode 0
	entryLowPowerMode0();
}

/**
 * @brief Interrupt Service Routine Port 1
 */
void isrPort1Demo110()
{
	// Process RTCSET Pin
	if(pinDigitalIsPendingInterrupt(RTCSET))
	{
		if(pinDigitalRead(RTCSET) == 0)
		{
			delayMs(10);

			if(pinDigitalRead(RTCSET) == 0)
			{
				digitToModify++;

				// LCD Blink On
				lcdCursorBlinkOn();

				// Write On Configure RTC Indicator
				lcdWriteSetPosition(1,17,'*');

				// Stop RTC
				rtcStop();

				switch(digitToModify)
				{
					case 1:
						lcdSetCursor(2,1);
						break;
					case 2:
						lcdSetCursor(2,4);
						break;
					case 3:
						lcdSetCursor(2,7);
						break;
					case 4:
						lcdSetCursor(2,11);
						break;
					case 5:
						lcdSetCursor(2,14);
						break;
					case 6:
						lcdSetCursor(2,17);
						break;
					default:
						digitToModify = 0;

						// LCD Blink Off
						lcdCursorBlinkOff();

						// Write Off Configure RTC Indicator
						lcdWriteSetPosition(1,17,' ');

						// Start RTC
						rtcStart();

						break;
				}
			}
		}
		// Clear RTCSET Interrupt
		pinDigitalClearPendingInterrupt(RTCSET);
	}

	// Process RTCINC Pin
	if(pinDigitalIsPendingInterrupt(RTCINC))
	{
		if(pinDigitalRead(RTCINC) == 0)
		{
			delayMs(10);

			if(pinDigitalRead(RTCINC) == 0)
			{
				switch(digitToModify)
				{
				case 1:
					rtcSetHour(rtcGetHour() + 1);
					lcdDataDecFormat(rtcGetHour(),2);
					lcdSetCursor(2,1);
					break;
				case 2:
					rtcSetMinute(rtcGetMinute() + 1);
					lcdDataDecFormat(rtcGetMinute(),2);
					lcdSetCursor(2,4);
					break;
				case 3:
					rtcSetSecond(rtcGetSecond() + 1);
					lcdDataDecFormat(rtcGetSecond(),2);
					lcdSetCursor(2,7);
					break;
				case 4:
					rtcSetDay(rtcGetDay() + 1);
					lcdDataDecFormat(rtcGetDay(),2);
					lcdSetCursor(2,11);
					break;
				case 5:
					rtcSetMonth(rtcGetMonth() + 1);
					lcdDataDecFormat(rtcGetMonth(),2);
					lcdSetCursor(2,14);
					break;
				case 6:
					rtcSetYear(rtcGetYear() + 1);
					lcdDataDecFormat(rtcGetYear(),4);
					lcdSetCursor(2,17);
					break;
				}
			}
		}
		// Clear RTCINC Interrupt
		pinDigitalClearPendingInterrupt(RTCINC);
	}

	// Process RTCDEC Pin
	if(pinDigitalIsPendingInterrupt(RTCDEC))
	{
		if(pinDigitalRead(RTCDEC) == 0)
		{
			delayMs(10);

			if(pinDigitalRead(RTCDEC) == 0)
			{
				switch(digitToModify)
				{
				case 1:
					rtcSetHour(rtcGetHour() - 1);
					lcdDataDecFormat(rtcGetHour(),2);
					lcdSetCursor(2,1);
					break;
				case 2:
					rtcSetMinute(rtcGetMinute() - 1);
					lcdDataDecFormat(rtcGetMinute(),2);
					lcdSetCursor(2,4);
					break;
				case 3:
					rtcSetSecond(rtcGetSecond() - 1);
					lcdDataDecFormat(rtcGetSecond(),2);
					lcdSetCursor(2,7);
					break;
				case 4:
					rtcSetDay(rtcGetDay() - 1);
					lcdDataDecFormat(rtcGetDay(),2);
					lcdSetCursor(2,11);
					break;
				case 5:
					rtcSetMonth(rtcGetMonth() - 1);
					lcdDataDecFormat(rtcGetMonth(),2);
					lcdSetCursor(2,14);
					break;
				case 6:
					rtcSetYear(rtcGetYear() - 1);
					lcdDataDecFormat(rtcGetYear(),4);
					lcdSetCursor(2,17);
					break;
				}
			}
		}
		// Clear RTCDEC Interrupt
		pinDigitalClearPendingInterrupt(RTCDEC);
	}
}

/**
 * @brief Interrupt Service Routine Port 2
 */
void isrPort2Demo110()
{

}

/**
 * @brief Interrupt Service Routine Timer A Channel 1
 */
void isrTimerACh1Demo110()
{
	// Increment RTC
	rtcUpdateUp();

	// Write RTC data in LCD Module
	if(rtcIsRunning())
	{
		// Write Date and Time LCD Module
		lcdDataTimeFormat(2, 1, rtcGetHour(), rtcGetMinute(), rtcGetSecond());
		lcdDataDateFormat(2, 11, rtcGetDay(), rtcGetMonth(), rtcGetYear());
	}

	// Clear Timer Interrupt
	TACTL &= ~(TAIFG);
}

/**
 * @brief Interrupt Service Routine Timer A Channel 0
 */
void isrTimerACh0Demo110()
{
	// Clear Timer Interrupt
	TACTL &= ~(TAIFG);
}

/**
 * @brief Interrupt Service Routine WatchDog Timer
 */
void isrWDTDemo110()
{

}

/**
 * @brief Interrupt Service Routine Comparator A
 */
void isrComparatorDemo110()
{

}

/**
 * @brief Interrupt Service Routine NMI
 */
void isrNMIDemo110()
{

}

#endif
