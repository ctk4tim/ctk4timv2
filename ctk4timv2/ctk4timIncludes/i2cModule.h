/**
 *  @file i2cModule.h
 *  @brief Module that allows I2C Communications
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

#ifndef I2CMODULE_H_
#define I2CMODULE_H_

#include "coreModule.h"
#include "ioModule.h"

/**
 * @brief Init I2C Module
 */
void i2cInit();

/**
 * @brief Read I2C Data
 * @param dirSlave Slave Direction
 */
void i2cRead(int dirSlave);

/**
 * @brief Write I2C Data
 * @param dirSlave Slave Direction
 */
void i2cWrite(int dirSlave);

/**
 * @brief I2C Start Signal
 */
void i2cStartSignal();

/**
 * @brief I2C Stop Signal
 */
void i2cStopSignal();

/**
 * @brief I2C ACK Signal
 */
void i2cAckSignal();

/**
 * @brief I2C Restart Signal
 */
void i2cRestartSignal();

#endif
