/**
 *  @file rs232Module.h
 *  @brief Module that allows RS-232 Communications
 *  @date 14/06/2012
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

#ifndef RS232MODULE_H_
#define RS232MODULE_H_

#include "coreModule.h"
#include "delayModule.h"
#include "ioModule.h"

/**
 * @brief Init RS-232 Module
 */
void rs232Init();

/**
 * @brief Read Byte RS-232
 */
uchar rs232ReadByte();

/**
 * @brief RS-232 Delay Middle Bit
 */
void rs232DelayMiddleBit();

/**
 * @brief RS-232 Delay Bit
 */
void rs232DelayBit();

/**
 * @brief Write Byte RS-232
 */
void rs232WriteByte(uchar byte);

#endif
