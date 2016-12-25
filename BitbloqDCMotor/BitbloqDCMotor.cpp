/*
 * BitbloqDCMotor.cpp
 * 
 * Copyright 2016 Alberto Valero <alberto.valero@bq.com>
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


#include <Arduino.h>
#include "BitbloqDCMotor.h"


BitbloqDCMotor::BitbloqDCMotor(int _dirPin, int _pwmPin):
    dirPin(_dirPin),
    pwmPin(_pwmPin)
{
    
}

void BitbloqDCMotor::setup(){
    pinMode(dirPin,OUTPUT);
    pinMode(pwmPin,OUTPUT);
}

void BitbloqDCMotor::setSpeed(int _speed){
    
    //speed in [-255, 255]
    speed	= _speed > 255 ? 255 : _speed;
    speed	= _speed < -255 ? -255 : _speed;
    
    
    //check if speed has changed
    if(last_speed != speed){
        last_speed = speed;
    }else{
        return;
    }
    //control DC Motor
    if(speed >= 0)
    {
        digitalWrite(dirPin,HIGH);
        analogWrite(pwmPin,speed);
    }else{
        digitalWrite(dirPin,LOW);
        analogWrite(pwmPin,-speed);
    }
}
