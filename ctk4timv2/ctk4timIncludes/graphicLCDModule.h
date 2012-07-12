/**
 *  @file graphicLCDModule.h
 *  @brief Module that allows controls Standard Grpahic LCD Module
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

#ifndef GRAPHICLCDMODULE_H_
#define GRAPHICLCDMODULE_H_

#include "coreModule.h"
#include "ioModule.h"

/**
 * @brief Init Graphic LCD Module
 */
void graphLcdInit();

/**
 * @brief Send Data Graphic LCD Module
 * @param data GraphLcd Data
 */
void graphLcdData(char data);

/**
 * @brief Send Instruction Graphic LCD Module
 * @param instru GraphLcd Instruction
 */
void graphLcdInstru(char instru);

/**
 * @brief Send Data Binary Format Graphic LCD Module
 */
void graphLcdDataBinFormat();

/**
 * @brief Send Data Hexadecimal Format Graphic LCD Module
 */
void graphLcdDataHexFormat();

/**
 * @brief Send Data Decimal Format Graphic LCD Module
 */
void graphLcdDataDecFormat();

#endif
