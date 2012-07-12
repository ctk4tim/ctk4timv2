/**
 *  @file papMotorModule.h
 *  @brief Module that controlls PAP Motor
 *  @date 03/04/2012
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

#include "../ctk4timIncludes/papMotorModule.h"

char papMotorState;

/**
 * @brief Init PAP Motor Module
 */
void papMotorInit()
{
	// Configure Initial State PAP Motor Output Pins
	pinDigitalWriteOff(A1_MOTPAP);
	pinDigitalWriteOff(A2_MOTPAP);
	pinDigitalWriteOff(B1_MOTPAP);
	pinDigitalWriteOff(B2_MOTPAP);

	// Configure PAP Motor Output Pins
	pinDigitalOutput(A1_MOTPAP);
	pinDigitalOutput(A2_MOTPAP);
	pinDigitalOutput(B1_MOTPAP);
	pinDigitalOutput(B2_MOTPAP);

	// Initial PAP Motor State
	papMotorRightCycles(1);
	papMotorState = 0;
}

/**
 * @brief Get PAP Motor State
 * @return PAP State
 */
uchar papMotorGetState()
{
	return papMotorState;
}

/**
 * @brief PAP Motor Left Step
 */
void papMotorLeftStep()
{
	// Next Step
	papMotorState--;

	// Init State
	if(papMotorState == 0)
	{
		papMotorState = 4;
	}

	// Move PAP Motor
	papMotorMove();
}

/**
 * @brief PAP Motor Right Step
 */
void papMotorRightStep()
{
	// Previous Step
	papMotorState++;

	// Init State
	if(papMotorState == 5)
	{
		papMotorState = 1;
	}

	// Move PAP Motor
	papMotorMove();
}

/**
 * @brief Move PAP Motor
 */
void papMotorMove()
{
	switch(papMotorState)
	{
		case 1:
			pinDigitalWriteOn(A1_MOTPAP);
			delayMs(50);
			pinDigitalWriteOff(A1_MOTPAP);
			delayMs(50);
			break;
		case 2:
			pinDigitalWriteOn(B1_MOTPAP);
			delayMs(50);
			pinDigitalWriteOff(B1_MOTPAP);
			delayMs(50);
			break;
		case 3:
			pinDigitalWriteOn(A2_MOTPAP);
			delayMs(50);
			pinDigitalWriteOff(A2_MOTPAP);
			delayMs(50);
			break;
		case 4:
			pinDigitalWriteOn(B2_MOTPAP);
			delayMs(50);
			pinDigitalWriteOff(B2_MOTPAP);
			delayMs(50);
			break;
	}
}

/**
 * @brief PAP Motor Left Cycles
 */
void papMotorLeftCycles(uchar numberCycles)
{
	uint i = 0;

	// Move PAP Motor N Left Cycles
	for(i = 0; i < numberCycles; i++)
	{
		papMotorLeftStep();
		papMotorLeftStep();
		papMotorLeftStep();
		papMotorLeftStep();
	}
}

/**
 * @brief PAP Motor Right Cycles
 */
void papMotorRightCycles(uchar numberCycles)
{
	uint i = 0;

	// Move PAP Motor N Left Cycles
	for(i = 0; i < numberCycles; i++)
	{
		papMotorRightStep();
		papMotorRightStep();
		papMotorRightStep();
		papMotorRightStep();
	}
}
