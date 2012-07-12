/**
 *  @file spiModule.h
 *  @brief Module that allows SPI Communications
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

#ifndef SPIMODULE_H_
#define SPIMODULE_H_

#include "coreModule.h"
#include "ioModule.h"

/**
 * @brief SPI Init
 * @param spiModeInit SPI Mode
 * @param csPinPolarityInit Polarity CS Pin
 */
void spiInit(uchar spiModeInit, uchar csPinPolarityInit);

/**
 * @brief SPI Send
 * @param dataPointer dataPointer Pointer Send Data
 * @param dataLength Length Send Data
 */
void spiSend(uchar *dataPointer, uchar dataLength);

/**
 * @brief SPI Receive
 * @param dataPointer dataPointer Pointer Send Receive
 * @param dataLength Length Send Receive
 */
void spiReceive(uchar *dataPointer, uchar dataLength);

/**
 * @brief SPI Receive
 * @return SPI Byte Receive
 */
uchar spiReceiveByte();

#endif
