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

#include "../ctk4timIncludes/rtcModule.h"

uint hour;
uint minute;
uint second;
uint day;
uint month;
uint year;
uint isRunning;

// Maximum Days of Month
uchar maximumDaysOfMonth [] = {31,28,31,30,31,30,31,31,30,31,30,31};

/**
 * @brief RTC Init
 */
void rtcInit()
{
	// Init date and time
	hour = 0;
	minute = 0;
	second = 0;
	day = 1;
	month = 1;
	year = 2012;

	// Select LFTX1 Low Frequency / 1
	BCSCTL1 &= ~(XTS | DIVA1 | DIVA0);

	// Select 12.5pF Capacitor and 32.768KHz
	BCSCTL3 = XCAP1 | XCAP0;

	// Set Count 32768 Cycles
	TACCR0 = 32767;

	// Configure Timer Source ACLK, Up Mode
	TACTL = TASSEL0 | MC0 | TACLR | TAIE;
}

/**
 * @brief RTC Start
 */
void rtcStart()
{
	isRunning = 1;
}

/**
 * @brief RTC Stop
 */
void rtcStop()
{
	isRunning = 0;
}

/**
 * @brief RTC Test Running
 * @return RTC State Running
 */
uint rtcIsRunning()
{
	return isRunning;
}

/**
 * @brief RTC Update Up
 */
void rtcUpdateUp()
{
	if(isRunning)
	{
		if(rtcAddSecond() == 0)
		{
			if(rtcAddMinute() == 0)
			{
				if(rtcAddHour() == 0)
				{
					if(rtcAddDay() == 1)
					{
						if(rtcAddMonth() == 1)
						{
							rtcAddYear();
						}
					}
				}
			}
		}
	}
}

/**
 * @brief RTC Update Down
 */
void rtcUpdateDown()
{
	if(isRunning)
	{
		// Get Days of Month
		uchar daysOfMonth = rtgGetDayOfMonth(month);

		if(rtcSubSecond() == 59)
		{
			if(rtcSubMinute() == 59)
			{
				if(rtcAddHour() == 23)
				{
					if(rtcSubDay() == daysOfMonth)
					{
						if(rtcSubMonth() == 12)
						{
							rtcSubYear();
						}
					}
				}
			}
		}
	}
}

/**
 * @brief Increment One Second
 * @return Second Update
 */
uint rtcAddSecond()
{
	if(second == 59)
	{
		second = 0;
	}
	else
	{
		second++;
	}
	return second;
}

/**
 * @brief Decrement One Second
 * @return Second Update
 */
uint rtcSubSecond()
{
	if(second == 0)
	{
		second = 59;
	}
	else
	{
		second--;
	}
	return second;
}

/**
 * @brief Increment One Minute
 * @return Minute Update
 */
uint rtcAddMinute()
{
	if(minute == 59)
	{
		minute = 0;
	}
	else
	{
		minute++;
	}
	return minute;
}

/**
 * @brief Decrement One Minute
 * @return Minute Update
 */
uint rtcSubMinute()
{
	if(minute == 0)
	{
		minute = 59;
	}
	else
	{
		minute--;
	}
	return minute;
}

/**
 * @brief Increment One Hour
 * @return Hour Update
 */
uint rtcAddHour()
{
	if(hour == 23)
	{
		hour = 0;
	}
	else
	{
		hour++;
	}
	return hour;
}

/**
 * @brief Decrement One Hour
 * @return Hour Update
 */
uint rtcSubHour()
{
	if(hour == 0)
	{
		hour = 23;
	}
	else
	{
		hour--;
	}
	return hour;
}

/**
 * @brief Increment One Day
 * @return Day Update
 */
uint rtcAddDay()
{
	// Get Days of Month
	uchar daysOfMonth = rtgGetDayOfMonth(month);

	if(day >= daysOfMonth)
	{
		day = 1;
	}
	else
	{
		day++;
	}
	return day;
}

/**
 * @brief Decrement One Day
 * @return Day Update
 */
uint rtcSubDay()
{
	// Get Days of Month
	uchar daysOfMonth = rtgGetDayOfMonth(month);

	if(day == 1)
	{
		if(month == 1)
		{
			day = rtgGetDayOfMonth(12);
		}
		else
		{
			day = rtgGetDayOfMonth(month - 1);
		}
	}
	else
	{
		day--;
	}
	return day;
}

/**
 * @brief Increment One Month
 * @return Month Update
 */
uint rtcAddMonth()
{
	if(month == 13)
	{
		month = 1;
	}
	else
	{
		month++;
	}
	return month;
}

/**
 * @brief Decrement One Month
 * @return Month Update
 */
uint rtcSubMonth()
{
	if(month == 1)
	{
		month = 12;
	}
	else
	{
		month--;
	}
	return month;
}

/**
 * @brief Increment One Year
 * @return Year Update
 */
uint rtcAddYear()
{
	if(year == 9999)
	{
		year = 2012;
	}
	else
	{
		year++;
	}
	return year;
}

/**
 * @brief Decrement One Year
 * @return Year Update
 */
uint rtcSubYear()
{
	if(year == 2012)
	{
		year = 9999;
	}
	else
	{
		year--;
	}
	return year;
}

/**
 * @brief RTC Get Year
 * @return Year
 */
uint rtcGetYear()
{
	return year;
}

/**
 * @brief RTC Set Year
 * @param setYear Year Set
 */
void rtcSetYear(int setYear)
{
	if(setYear >= 2012 && setYear <= 2999)
	{
		year = setYear;
	}
	else
	{
		if(setYear == 3000)
		{
			year = 2012;
		}
		if(setYear == 2011)
		{
			year = 2999;
		}
	}
}

/**
 * @brief RTC Get Month
 * @return Month
 */
uint rtcGetMonth()
{
	return month;
}

/**
 * @brief RTC Set Month
 * @param setMonth Month Set
 */
void rtcSetMonth(int setMonth)
{
	if(setMonth >= 1 && setMonth <= 12)
	{
		month = setMonth;
	}
	else
	{
		if(setMonth == 13)
		{
			month = 1;
		}
		if(setMonth == 0)
		{
			month = 12;
		}
	}

	// Correct Maximum Day of Month Selected
	uchar daysOfMonth = rtgGetDayOfMonth(month);
	if(day > daysOfMonth)
	{
		day = daysOfMonth;
	}
}

/**
 * @brief RTC Get Day
 * @return Day
 */
uint rtcGetDay()
{
	return day;
}

/**
 * @brief RTC Set Day
 * @param setDay Day Set
 */
void rtcSetDay(int setDay)
{
	// Get Days of Month
	uchar daysOfMonth = rtgGetDayOfMonth(month);

	if(setDay >= 1 && setDay <= 31)
	{
		if(setDay <= daysOfMonth)
		{
			day = setDay;
		}
		else
		{
			day = daysOfMonth;
		}
	}
	else
	{
		if(setDay == 32)
		{
			day = 1;
		}
		if(setDay == 0)
		{
			day = daysOfMonth;
		}
	}
}

/**
 * @brief RTC Get Hour
 * @return Hour
 */
uint rtcGetHour()
{
	return hour;
}

/**
 * @brief RTC Set Hour
 * @param setHour Hour Set
 */
void rtcSetHour(int setHour)
{
	if(setHour >= 0 && setHour <= 23)
	{
		hour = setHour;
	}
	else
	{
		if(setHour == 24)
		{
			hour = 0;
		}
		if(setHour == -1)
		{
			hour = 23;
		}
	}
}

/**
 * @brief RTC Get Minute
 * @return Minute
 */
uint rtcGetMinute()
{
	return minute;
}

/**
 * @brief RTC Set Minute
 * @param setMinute Minute Set
 */
void rtcSetMinute(int setMinute)
{
	if(setMinute >= 0 && setMinute <= 59)
	{
		minute = setMinute;
	}
	else
	{
		if(setMinute == 60)
		{
			minute = 0;
		}
		if(setMinute == -1)
		{
			minute = 59;
		}
	}
}

/**
 * @brief RTC Get Second
 * @return Second
 */
uint rtcGetSecond()
{
	return second;
}

/**
 * @brief RTC Set Second
 * @param setSecond Second Set
 */
void rtcSetSecond(int setSecond)
{
	if(setSecond >= 0 && setSecond <= 59)
	{
		second = setSecond;
	}
	else
	{
		if(setSecond == 60)
		{
			second = 0;
		}
		if(setSecond == -1)
		{
			second = 59;
		}
	}
}

/**
 * @brief RTC Get Days of Month
 * @param month Month
 */
uchar rtgGetDayOfMonth(uint month)
{
	// Get Days Of Month
	uchar daysOfMonth = maximumDaysOfMonth[month - 1];

	// Ask Bisiest Year
	if(month == 2 && (year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
	{
		daysOfMonth++;
	}
	return daysOfMonth;
}

/**
 * @brief RTC Set Date
 * @param setDay Day Set
 * @param setMonth Month Set
 * @param setYear Year Set
 */
void rtcSetDate(uint setDay, uint setMonth, uint setYear)
{
	rtcSetDay(setDay);
	rtcSetMonth(setMonth);
	rtcSetYear(setYear);
}

/**
 * @brief RTC Set Time
 * @param setHour Hour Set
 * @param setMinute Minute Set
 * @param setSecond Second Set
 */
void rtcSetTime(uint setHour, uint setMinute, uint setSecond)
{
	rtcSetHour(setHour);
	rtcSetMinute(setMinute);
	rtcSetSecond(setSecond);
}
