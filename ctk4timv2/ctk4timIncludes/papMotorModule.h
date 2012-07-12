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

#ifndef PAPMOTORMODULE_H_
#define PAPMOTORMODULE_H_

#include "coreModule.h"
#include "ioModule.h"

/**
 * @brief Init PAP Motor Module
 */
void papMotorInit();

/**
 * @brief Get PAP Motor State
 * @return PAP State
 */
uchar papMotorGetState();

/**
 * @brief PAP Motor Left Step
 */
void papMotorLeftStep();

/**
 * @brief PAP Motor Right Step
 */
void papMotorRightStep();

/**
 * @brief Move PAP Motor
 */
void papMotorMove();

/**
 * @brief PAP Motor Left Cycles
 */
void papMotorLeftCycles(uchar numberCycles);

/**
 * @brief PAP Motor Right Cycles
 */
void papMotorRightCycles(uchar numberCycles);

#endif
