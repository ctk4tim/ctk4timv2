/**
 *  @file rtcModule.h
 *  @brief Module that allows drive Real Time Clock
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

#ifndef RTCMODULE_H_
#define RTCMODULE_H_

#include "coreModule.h"

/*
 * RTC Init
 */
void rtcInit();

/*
 * RTC Start
 */
void rtcStart();

/*
 * RTC Stop
 */
void rtcStop();

/*
 * RTC Test Running
 */
uint rtcIsRunning();

/*
 * RTC Update Up
 */
void rtcUpdateUp();

/*
 * RTC Update Down
 */
void rtcUpdateDown();

/*
 * Increment One Second
 */
uint rtcAddSecond();

/*
 * Decrement One Second
 */
uint rtcSubSecond();

/*
 * Increment One Minute
 */
uint rtcAddMinute();

/*
 * Decrement One Minute
 */
uint rtcSubMinute();

/*
 * Increment One Hour
 */
uint rtcAddHour();

/*
 * Decrement One Hour
 */
uint rtcSubHour();

/*
 * Increment One Day
 */
uint rtcAddDay();

/*
 * Decrement One Day
 */
uint rtcSubDay();

/*
 * Increment One Month
 */
uint rtcAddMonth();

/*
 * Decrement One Month
 */
uint rtcSubMonth();

/*
 * Increment One Year
 */
uint rtcAddYear();

/*
 * Decrement One Year
 */
uint rtcSubYear();

/*
 * RTC Get Year
 */
uint rtcGetYear();

/*
 * RTC Set Year
 */
void rtcSetYear(int setYear);

/*
 * RTC Get Month
 */
uint rtcGetMonth();

/*
 * RTC Set Month
 */
void rtcSetMonth(int setMonth);

/*
 * RTC Get Day
 */
uint rtcGetDay();

/*
 * RTC Set Day
 */
void rtcSetDay(int setDay);

/*
 * RTC Get Hour
 */
uint rtcGetHour();

/*
 * RTC Set Hour
 */
void rtcSetHour(int setHour);

/*
 * RTC Get Minute
 */
uint rtcGetMinute();

/*
 * RTC Set Minute
 */
void rtcSetMinute(int setMinute);

/*
 * RTC Get Second
 */
uint rtcGetSecond();

/*
 * RTC Set Second
 */
void rtcSetSecond(int setSecond);

/*
 * RTC Get Days of Month
 */
uchar rtgGetDayOfMonth(uint month);

/*
 * RTC Set Date
 */
void rtcSetDate(uint setDay, uint setMonth, uint setYear);

/*
 * RTC Set Time
 */
void rtcSetTime(uint hour, uint minute, uint second);

#endif
