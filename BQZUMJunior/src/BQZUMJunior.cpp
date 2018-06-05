/*
 * BQZUMJunior.cpp
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



#include "Arduino.h"
#include "BQZUMJunior.h"

namespace BQ{
//initialize port equivalences - index 0 is not used
const int ZUMJunior::ports[7][2] = {{-1,-1},{6,A1},{5,A0},{3,A3},{9,A2},{A4,A5},{22,23}};
//initialize i2cports equivalences
const ZUMJuniorI2CPorts ZUMJunior::i2cPorts(0,1);

ZUMJunior::ZUMJunior():
        buzzerPin(4),
        rPin(7),
        gPin(8),
        bPin(2),
        rgbColors{{255,0,0},{0,255,0},{0,0,255},{255,255,0},{255,0,255},{255,255,255},{0,0,0}},
        tones{261,294,329,349,392,440,493}
{
    //Nothing here
}
 

ZUMJunior::~ZUMJunior(){
	//Nothing here
}

void ZUMJunior::setup(){    
    //actuators
    pinMode(buzzerPin,OUTPUT);
}

void ZUMJunior::setRGBLEDColor(RGBColors color){
		setRGBLED(rgbColors[color][0],rgbColors[color][1],rgbColors[color][2]);
	}

void ZUMJunior::playTone(int note, int beat){
	tone(buzzerPin, note, beat);
}

void ZUMJunior::play(Tones note, int beat){
	tone(buzzerPin, tones[note], beat);
}

void ZUMJunior::setRGBLED(uint8_t r, uint8_t g, uint8_t b){
	analogWrite(rPin,255-r);
	analogWrite(gPin,255-g);
	analogWrite(bPin,255-b);
}

} //end namespace
