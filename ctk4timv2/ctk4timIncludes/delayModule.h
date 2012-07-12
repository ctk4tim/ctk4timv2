/**
 *  @file delayModule.h
 *  @brief Module that allows for delays
 *  @date 17/02/2012
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

#ifndef DELAYMODULE_H_
#define DELAYMODULE_H_

#include "coreModule.h"

/**
 * @brief Delay in Miliseconds
 * @param delayMs Milisecond Value
 */
void delayMs(uint delayMs);

/**
 * @brief Delay in Microseconds
 * @param delayUs Microsecond Value
 */
void delayUs(uint delayUs);

#endif
