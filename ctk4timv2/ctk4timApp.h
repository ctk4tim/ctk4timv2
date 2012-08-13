/**
 *  @file ctk4timApp.h
 *  @brief Application Program
 *  @date 13/08/2012
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
 *
 *  @mainpage C Toolkit For MSP430 Texas Instrument Microcontroller
 *  This page resumes the CTK4TIM API
 *  @par General Group
 *  @par Pheripherals Group
 *  @par External Group
 */

#ifndef CTK4TIMAPP_H_
#define CTK4TIMAPP_H_

/*
 * @brief Application Program
 * @param void Void
 */
void applicationApp();

/**
 * @brief Interrupt Service Routine Port 1
 */
void isrPort1App();

/**
 * @brief Interrupt Service Routine Port 2
 */
void isrPort2App();

/**
 * @brief Interrupt Service Routine Timer A Channel 1
 */
void isrTimerACh1App();

/**
 * @brief Interrupt Service Routine Timer A Channel 0
 */
void isrTimerACh0App();

/**
 * @brief Interrupt Service Routine WatchDog Timer
 */
void isrWDTApp();

/**
 * @brief Interrupt Service Routine Comparator A
 */
void isrComparatorAApp();

/**
 * @brief Interrupt Service Routine NMI
 */
void isrNMIApp();

#endif
