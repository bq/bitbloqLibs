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


     //ports structure of MakeBlock Orion Board.
    static const ZUMJuniorPorts ports;
    static const ZUMJuniorI2CPorts i2cPorts;

protected:

    const int buzzerPin; /// pin where the buzzer is connected. It is hardwired on the board (D8) 
};

} //end namespace

#endif
