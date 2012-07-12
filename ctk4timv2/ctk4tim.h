/**
 *  @file ctk4tim.c
 *  @brief Main Program Loop
 *  @date 29/02/2012
 *  @version 1.0.3
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

#ifndef CTK4TIM_H_
#define CTK4TIM_H_

/*
 * PushButton Definition
 */
#define RTCSET		&P1IN,BIT0
#define RTCDEC		&P1IN,BIT1
#define RTCINC		&P1IN,BIT2

/*
 * SMCLK Definition
 */
#define	SMCLK		&P1OUT,BIT4

/*
 * Piano Output
 */
#define	BUZZER		&P1OUT,BIT6

/*
 * LCD Pin Definition
 */
#define E_LCD		&P2OUT,BIT5
#define RS_LCD		&P2OUT,BIT4
#define D7_LCD		&P2OUT,BIT3
#define D6_LCD		&P2OUT,BIT2
#define D5_LCD		&P2OUT,BIT1
#define D4_LCD		&P2OUT,BIT0

/*
 * Motor PAP Pines
 */
#define A1_MOTPAP	&P1OUT,BIT3
#define B1_MOTPAP	&P1OUT,BIT4
#define A2_MOTPAP	&P1OUT,BIT6
#define B2_MOTPAP	&P1OUT,BIT7

/*
 * Led Matrix Pin Definition
 */
#define F1_LEDMATRIX	&P1OUT,BIT0
#define F2_LEDMATRIX	&P1OUT,BIT1
#define F3_LEDMATRIX	&P1OUT,BIT2
#define F4_LEDMATRIX	&P1OUT,BIT3
#define F5_LEDMATRIX	&P1OUT,BIT4
#define F6_LEDMATRIX	&P1OUT,BIT6
#define F7_LEDMATRIX	&P1OUT,BIT7

#define SRCLK_LEDMATRIX	&P2OUT,BIT0
#define SRDAT_LEDMATRIX	&P2OUT,BIT1

/*
 * RS-232 Communications
 */
#define RX_RS232		&P2IN,BIT3
#define TX_RS232		&P2OUT,BIT4
#define SAMPLE_RS232	&P2OUT,BIT5

/*
 * RGB Led
 */
#define RGBLED_BLUE		&P1OUT,BIT3
#define RGBLED_GREEN	&P1OUT,BIT4
#define RGBLED_RED		&P1OUT,BIT5

#endif
