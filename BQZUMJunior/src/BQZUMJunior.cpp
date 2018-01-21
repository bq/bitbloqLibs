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

const ZUMJuniorPort ports[6] = {ZUMJuniorPort(A3,3),ZUMJuniorPort(A2,9),ZUMJuniorPort(A5,A4),ZUMJuniorPort(22,23),ZUMJuniorPort(A1,6),ZUMJuniorPort(A0,5)};
const ZUMJuniorPorts ZUMJunior::ports = ZUMJuniorPorts(ports);
const ZUMJuniorI2CPorts ZUMJunior::i2cPorts(0,1);

ZUMJunior::ZUMJunior():
        buzzerPin(4)
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


void ZUMJunior::playTone(int note, int beat){
	tone(buzzerPin, note, beat);
}

} //end namespace
