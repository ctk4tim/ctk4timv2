/**
 *  @file keyMatrixModule.h
 *  @brief Module that allows controls Key Matrix
 *  @date 01/03/2012
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

#ifndef KEYMATRIXMODULE_H_
#define KEYMATRIXMODULE_H_

#include "coreModule.h"
#include "ioModule.h"

/**
 * @brief Init Key Matrix
 */
void keyMatrixInit();

/**
 * @brief Key Matrix Read Data
 */
void keyMatrixRead();

#endif
