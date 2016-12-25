/*
 * BitbloqDCMotor.h
 * 
 * Copyright 2016 Alberto Valero <avalero.valero@bq.com>
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

#ifndef BITBLOQDCMOTOR_H
#define BITBLOQDCMOTOR_H

class BitbloqDCMotor 
{
    
    public:
        BitbloqDCMotor(int _dirPin, int _pwmPin); //public constructor
        virtual ~BitbloqDCMotor(){};
        
        
        /**
         * sets pinModes
         */
        void setup();
        
        /**
         * Sets Motor Speed
         * @param speed in [-255,255]
         */
        void setSpeed(int _speed);
        
    private:
        const int dirPin;
        const int pwmPin;
        int speed;
        int last_speed;
};

#endif
