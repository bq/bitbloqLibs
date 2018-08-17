/*
 * BQZUMJunior.h
 *
 * Copyright 2018 Alberto Valero <alberto.valero@bq.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 *
 *
 */

#ifndef BQZUMJUNIOR_H
#define BQZUMJUNIOR_H

#include "BQZUMJuniorPorts.h"

namespace BQ{ 

class ZUMJunior
{

public:
    ZUMJunior(); // public constructor
    virtual ~ZUMJunior(); // virtual public destructor



	typedef enum {
		RED,
		GREEN,
		BLUE,
		YELLOW,
		PINK,
		WHITE,
		BLACK
		} RGBColors;
		
	typedef enum{
		DO,
		RE,
		MI,
		FA,
		SOL,
		LA,
		SI
	} Tones;


    /**
     * Sets pinmode of sensors and actuators (as in standard Arduino setup)
     */
    void setup();

    
    /**
     * Play tone
     * @param note note frequency
     * @param beat time active
     */
    void playTone(int note, int beat);

	/**
     * Play tone
     * @param note tone form list
     * @param beat time active
     */
    void play(Tones note, int beat);

	/**
     * Set RGB Led (0,0,0 for switch off)
     * @param r red color 0-255
     * @param g red color 0-255
     * @param b red color 0-255
     */
	void setRGBLED(uint8_t r, uint8_t g, uint8_t b);
	
	void setRGBLEDColor(RGBColors color);

    //there are 6 ports. We use 7 because the 0 index is not used. Index vary from 1 to 6.
    static const int ports[7][2];
    static const ZUMJuniorI2CPorts i2cPorts;



protected:


	const uint8_t rgbColors[7][3];
	const int tones[7];
    const uint8_t buzzerPin; /// pin where the buzzer is connected. It is hardwired on the board (D8) 
    const uint8_t rPin; /// green led pin (7)
    const uint8_t gPin; /// green led pin (8)
    const uint8_t bPin; /// green led pin (2)
};

} //end namespace

#endif
