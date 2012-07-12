/**
 *  @file rs232Module.c
 *  @brief Module that allows A/D Conversions
 *  @date 14/06/2012
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

#include "../ctk4timIncludes/rs232Module.h"
#include "../ctk4timIncludes/delayModule.h"

/**
 * @brief Init RS-232 Module
 */
void rs232Init()
{
	// Configure RX Pin
	pinDigitalEnabledPullUp(RX_RS232);
	pinDigitalInput(RX_RS232);

	// Configure TX Pin
	pinDigitalWriteOn(TX_RS232);
	pinDigitalOutput(TX_RS232);

	// Configure Sample Pin
	pinDigitalWriteOff(SAMPLE_RS232);
	pinDigitalOutput(SAMPLE_RS232);
}

/**
 * @brief Read Byte RS-232
 */
uchar rs232ReadByte()
{
	uchar i, readByte = 0;
	uchar inProgress = 1;

	// Off Sample Signal
	pinDigitalWriteOff(SAMPLE_RS232);

	while(inProgress)
	{
		// Wait Start Condition
		while(pinDigitalRead(RX_RS232) == 1);

		// Disable Interrupts
		disableInterrupts();

		// Delay Middle Bit
		rs232DelayMiddleBit();

		// Ask Start Condition
		if(pinDigitalRead(RX_RS232) == 0)
		{
			// Receive 8 bits
			for(i = 0; i < 8; i++)
			{
				// Delay Bit
				rs232DelayBit();

				// Rotate Buffer
				readByte >>= 1;

				// Read Bit and Integrate Value
				if(pinDigitalRead(RX_RS232) == 1)
				{
					readByte |= 0x80;
				}
			}

			// Delay Bit
			rs232DelayBit();

			// Wait Stop Condition
			while(pinDigitalRead(RX_RS232) == 0);

			// Finish Reception
			inProgress = 0;
		}
	}

	// Off Sample Signal
	pinDigitalWriteOff(SAMPLE_RS232);

	return readByte;
}

/**
 * @brief RS-232 Delay Middle Bit
 */
void rs232DelayMiddleBit()
{
	_delay_cycles(10);

	// Toogle Sample Signal
	pinDigitalWriteToggle(SAMPLE_RS232);
}

/**
 * @brief RS-232 Delay Bit
 */
void rs232DelayBit()
{
	_delay_cycles(54);

	// Toogle Sample Signal
	pinDigitalWriteToggle(SAMPLE_RS232);
}

/**
 * @brief Write Byte RS-232
 * @param writeByte Byte to Write
 */
void rs232WriteByte(uchar writeByte)
{
	uchar i = 0;

	// Start Condition
	pinDigitalWriteOn(TX_RS232);
	pinDigitalWriteOff(TX_RS232);

	// Delay 1 Bit
	rs232DelayBit();

	// Send 8 bits
	for(i = 0; i < 8; i++)
	{
		// Read Bit to Send and Export Pin
		if(writeByte & 0x01 != 0)
		{
			pinDigitalWriteOn(TX_RS232);
		}
		else
		{
			pinDigitalWriteOff(TX_RS232);
		}

		// Delay Bit
		rs232DelayBit();

		// Rotate Buffer
		writeByte >>= 1;
	}

	// Stop Condition
	pinDigitalWriteOn(TX_RS232);

	// Delay Bit
	rs232DelayBit();
}
