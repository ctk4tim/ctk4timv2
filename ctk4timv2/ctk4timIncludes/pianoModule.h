/**
 *  @file pianoModule.h
 *  @brief Module that simulate Piano Tones
 *  @date 29/02/2012
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

#ifndef PIANOMODULE_H_
#define PIANOMODULE_H_

#include "coreModule.h"
#include "delayModule.h"
#include "ioModule.h"

/**
 * Note Space Constant
 */
#define SPACE	1
/**
 * Note Stop Constant
 */
#define STOP	0

/**
 * Note C Scale 1 Constant
 */
#define C1		1 / (65.406391 * PERTIM * 2)
/**
 * Note C# Scale 1 Constant
 */
#define CS1		1 / (69.295658 * PERTIM * 2)
/**
 * Note D Scale 1 Constant
 */
#define D1		1 / (73.416192 * PERTIM * 2)
/**
 * Note D# Scale 1 Constant
 */
#define DS1		1 / (77.781746 * PERTIM * 2)
/**
 * Note E Scale 1 Constant
 */
#define E1		1 / (82.406889 * PERTIM * 2)
/**
 * Note F Scale 1 Constant
 */
#define F1		1 / (87.307058 * PERTIM * 2)
/**
 * Note F# Scale 1 Constant
 */
#define FS1		1 / (92.498606 * PERTIM * 2)
/**
 * Note G Scale 1 Constant
 */
#define G1		1 / (97.998859 * PERTIM * 2)
/**
 * Note G# Scale 1 Constant
 */
#define GS1		1 / (103.826174 * PERTIM * 2)
/**
 * Note A Scale 1 Constant
 */
#define A1		1 / (110.0 * PERTIM * 2)
/**
 * Note A# Scale 1 Constant
 */
#define AS1		1 / (116.540940 * PERTIM * 2)
/**
 * Note B Scale 1 Constant
 */
#define B1		1 / (123.470825 * PERTIM * 2)
/**
 * Note C Scale 2 Constant
 */
#define C2		1 / (130.812783 * PERTIM * 2)
/**
 * Note C# Scale 2 Constant
 */
#define CS2		1 / (138.591315 * PERTIM * 2)
/**
 * Note D Scale 2 Constant
 */
#define D2		1 / (146.832384 * PERTIM * 2)
/**
 * Note D# Scale 2 Constant
 */
#define DS2		1 / (155.563492 * PERTIM * 2)
/**
 * Note E Scale 2 Constant
 */
#define E2		1 / (164.813778 * PERTIM * 2)
/**
 * Note F Scale 2 Constant
 */
#define F2		1 / (174.614116 * PERTIM * 2)
/**
 * Note F# Scale 2 Constant
 */
#define FS2		1 / (184.997211 * PERTIM * 2)
/**
 * Note G Scale 2 Constant
 */
#define G2		1 / (195.997718 * PERTIM * 2)
/**
 * Note G# Scale 2 Constant
 */
#define GS2		1 / (207.652349 * PERTIM * 2)
/**
 * Note A Scale 2 Constant
 */
#define A2		1 / (220.0 * PERTIM * 2)
/**
 * Note A# Scale 2 Constant
 */
#define AS2		1 / (233.081881 * PERTIM * 2)
/**
 * Note B Scale 2 Constant
 */
#define B2		1 / (246.941651 * PERTIM * 2)
/**
 * Note C Scale 3 Constant
 */
#define C3		1 / (261.625565 * PERTIM * 2)
/**
 * Note C# Scale 3 Constant
 */
#define CS3		1 / (277.182631 * PERTIM * 2)
/**
 * Note D Scale 3 Constant
 */
#define D3		1 / (293.664768 * PERTIM * 2)
/**
 * Note D# Scale 3 Constant
 */
#define DS3		1 / (311.126984 * PERTIM * 2)
/**
 * Note E Scale 3 Constant
 */
#define E3		1 / (329.627557 * PERTIM * 2)
/**
 * Note F Scale 3 Constant
 */
#define F3		1 / (349.228231 * PERTIM * 2)
/**
 * Note F# Scale 3 Constant
 */
#define FS3		1 / (369.994423 * PERTIM * 2)
/**
 * Note G Scale 3 Constant
 */
#define G3		1 / (391.995436 * PERTIM * 2)
/**
 * Note G# Scale 3 Constant
 */
#define GS3		1 / (415.304698 * PERTIM * 2)
/**
 * Note A Scale 3 Constant
 */
#define A3		1 / (440.0 * PERTIM * 2)
/**
 * Note A# Scale 3 Constant
 */
#define AS3		1 / (466.163762 * PERTIM * 2)
/**
 * Note B Scale 3 Constant
 */
#define B3		1 / (493.883301 * PERTIM * 2)
/**
 * Note C Scale 4 Constant
 */
#define C4		1 / (523.251131 * PERTIM * 2)
/**
 * Note C# Scale 4 Constant
 */
#define CS4		1 / (554.365262 * PERTIM * 2)
/**
 * Note D Scale 4 Constant
 */
#define D4		1 / (587.329536 * PERTIM * 2)
/**
 * Note D# Scale 4 Constant
 */
#define DS4		1 / (622.253967 * PERTIM * 2)
/**
 * Note E Scale 4 Constant
 */
#define E4		1 / (659.255114 * PERTIM * 2)
/**
 * Note F Scale 4 Constant
 */
#define F4		1 / (698.456463 * PERTIM * 2)
/**
 * Note F# Scale 4 Constant
 */
#define FS4		1 / (739.988845 * PERTIM * 2)
/**
 * Note G Scale 4 Constant
 */
#define G4		1 / (783.990872 * PERTIM * 2)
/**
 * Note G# Scale 4 Constant
 */
#define GS4		1 / (830.609395 * PERTIM * 2)
/**
 * Note A Scale 4 Constant
 */
#define A4		1 / (880.0 *PERTIM *2)
/**
 * Note A# Scale 4 Constant
 */
#define AS4		1 / (932.327523 * PERTIM * 2)
/**
 * Note B Scale 4 Constant
 */
#define B4		1 / (987.766603 * PERTIM * 2)
/**
 * Note C Scale 5 Constant
 */
#define C5		1 / (1046.502261 * PERTIM * 2)
/**
 * Note C# Scale 5 Constant
 */
#define CS5		1 / (1108.730524 * PERTIM * 2)
/**
 * Note D Scale 5 Constant
 */
#define D5		1 / (1174.659072 * PERTIM * 2)
/**
 * Note D# Scale 5 Constant
 */
#define DS5		1 / (1244.507935 * PERTIM * 2)
/**
 * Note E Scale 5 Constant
 */
#define E5		1 / (1318.510228 * PERTIM * 2)
/**
 * Note F Scale 5 Constant
 */
#define F5		1 / (1396.912926 * PERTIM * 2)
/**
 * Note F# Scale 5 Constant
 */
#define FS5		1 / (1479.977691 * PERTIM * 2)
/**
 * Note G Scale 5 Constant
 */
#define G5		1 / (1567.981744 * PERTIM * 2)
/**
 * Note G# Scale 5 Constant
 */
#define GS5		1 / (1661.218790 * PERTIM * 2)
/**
 * Note A Scale 5 Constant
 */
#define A5		1 / (1760.0 * PERTIM *2)
/**
 * Note A# Scale 5 Constant
 */
#define AS5		1 / (1864.655046 * PERTIM * 2)
/**
 * Note B Scale 5 Constant
 */
#define B5		1 / (1975.533205 * PERTIM * 2)
/**
 * Note C Scale 6 Constant
 */
#define C6		1 / (2093.004522 * PERTIM * 2)
/**
 * Note C# Scale 6 Constant
 */
#define CS6		1 / (2217.461048 * PERTIM * 2)
/**
 * Note D Scale 6 Constant
 */
#define D6		1 / (2349.318143 * PERTIM * 2)
/**
 * Note D# Scale 6 Constant
 */
#define DS6		1 / (2489.015870 * PERTIM * 2)
/**
 * Note E Scale 6 Constant
 */
#define E6		1 / (2637.020455 * PERTIM * 2)
/**
 * Note F Scale 6 Constant
 */
#define F6		1 / (2793.825851 * PERTIM * 2)
/**
 * Note F# Scale 6 Constant
 */
#define FS6		1 / (2959.955382 * PERTIM * 2)
/**
 * Note G Scale 6 Constant
 */
#define G6		1 / (3135.963488 * PERTIM * 2)
/**
 * Note G# Scale 6 Constant
 */
#define GS6		1 / (3322.437581 * PERTIM * 2)
/**
 * Note A Scale 6 Constant
 */
#define A6		1 / (3520.0 * PERTIM * 2)
/**
 * Note A# Scale 6 Constant
 */
#define AS6		1 / (3729.310092 * PERTIM * 2)
/**
 * Note B Scale 6 Constant
 */
#define B6		1 / (3951.066410 * PERTIM * 2)

/**
 * @brief Init Piano Module
 */
void pianoInit();

/**
 * @brief Piano Play Note
 * @param toneValue Note
 * @param timeOn Time Note On
 * @param timeOff Time Note Off
 */
void pianoPlayNote(uint toneValue, ulong timeOn, ulong timeOff);

/**
 * @brief Piano Play Song
 * @param tonesSong Array Tones Song
 * @param timeOn Time Note On
 * @param timeOff Time Note Off
 */
void pianoPlaySong(const uint tonesSong [], ulong timeOn, ulong timeOff);

#endif
