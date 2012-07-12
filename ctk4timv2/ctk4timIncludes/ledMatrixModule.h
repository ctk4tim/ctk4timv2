/**
 *  @file ledMatrixModule.h
 *  @brief Module that allows controls a Led Matrix
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

#ifndef LEDMATRIXMODULE_H_
#define LEDMATRIXMODULE_H_

#include "coreModule.h"
#include "ioModule.h"

/**
 * Max Columns Led Matrix Constant
 */
#define MAX_COLUMNS 		5

/**
 * Max Columns Led Matrix Constant
 */
#define COLUMNS_BY_CHAR		5

/**
 * Max Buffer Chars
 */
#define MAX_BUFFER_CHARS	20

/**
 * Max Buffer Offset
 */
#define MAX_BUFFER_OFFSET	(MAX_BUFFER_CHARS - 1) * 6

/**
 * @brief Init Led Matrix
 */
void ledMatrixInit();

/**
 * @brief Led Matrix Buffer Clear
 */
void ledMatrixBufferClear();

/**
 * @brief Led Matrix Write Buffer
 * @param bufferPosition Buffer Position
 * @param data Data to Write
 */
void ledMatrixWriteBuffer(uchar bufferPosition, uchar data);

/**
 * @brief Led Matrix Update
 */
void ledMatrixUpdate();

/**
 * @brief Select Column Led Matrix
 * @param column Select Column
 */
void ledMatrixSelectColumn(uchar column);

/**
 * @brief Set Rows Led Matrix
 * @param dataRow Data by Row
 */
void ledMatrixSetRows(uchar dataRow);

/**
 * @brief Led Matrix Scroll On
 * @param setTimeScroll Set Time Scroll
 */
void ledMatrixScrollOn(uchar setTimeScroll);

/**
 * @brief Led Matrix Scroll Off
 */
void ledMatrixScrollOff();

/**
 * @brief Write Message into Led Matrix Buffer
 * @param column Column to Start Write
 * @param message Array Message to Send to Led Matrix
 */
void ledMatrixWriteMessage(uchar column, const uchar message []);

#endif
