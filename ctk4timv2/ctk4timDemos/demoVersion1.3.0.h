/**
 *  @file demoVersion1.3.0.h
 *  @brief Demo Version 1.3.0
 *  @date 14/08/2012
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

#include "../ctk4tim.h"

#ifdef DEMOVERSION130

/*
 * @brief Application Program Loop
 */
void application();

/**
 * @brief Interrupt Service Routine Port 1
 */
void isrPort1();

/**
 * @brief Interrupt Service Routine Port 2
 */
void isrPort2();

/**
 * @brief Interrupt Service Routine Timer A Channel 1
 */
void isrTimerACh1();

/**
 * @brief Interrupt Service Routine Timer A Channel 0
 */
void isrTimerACh0();

/**
 * @brief Interrupt Service Routine WatchDog Timer
 */
void isrWDT();

/**
 * @brief Interrupt Service Routine Comparator A
 */
void isrComparatorA();

/**
 * @brief Interrupt Service Routine NMI
 */
void isrNMI();

#endif
