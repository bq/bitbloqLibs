/*
 * BitbloqZUMJunior.cpp
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
#include "BitbloqZUMJunior.h"


namespace Bitbloq{

const Bitbloq::ZUMJunior::Port BQZUMJunior::ports[7] = {Bitbloq::ZUMJunior::Port(-1,-1), Bitbloq::ZUMJunior::Port(A3,3),Bitbloq::ZUMJunior::Port(A2,9),Bitbloq::ZUMJunior::Port(A5,A4),Bitbloq::ZUMJunior::Port(22,23),Bitbloq::ZUMJunior::Port(A1,6),Bitbloq::ZUMJunior::Port(A0,5)};
const Bitbloq::ZUMJunior::I2CPorts BQZUMJunior::i2cPorts(0,1);

BQZUMJunior::BQZUMJunior():
        buzzerPin(4)
{
    //Nothing here
}
 

BQZUMJunior::~BQZUMJunior(){
	//Nothing here
}

void BQZUMJunior::setup(){    
    //actuators
    pinMode(buzzerPin,OUTPUT);
}


void BQZUMJunior::playTone(int note, int beat){
	tone(buzzerPin, note, beat);
}

} //end namespace
