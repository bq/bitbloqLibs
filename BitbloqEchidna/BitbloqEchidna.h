/*
 * BitbloqEchidna.h
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

#ifndef BITBLOQECHIDNA_H
#define BITBLOQECHIDNA_H

#include <BitbloqRGB.h>
#include <BitbloqJoystick.h>

namespace Bitbloq{

class Echidna
{

public:
    Echidna(); // public constructor
    virtual ~Echidna(); // virtual public destructor

    /**
     * Sets pinmode of sensors and actuators (as in standard Arduino setup)
     */
    void setup();
    /**
     * Choose led and set value
     * @param led led number - 0: green, 1, orange, 2, red
     * @param status HIGH or LOW
     */
    void setLed(int led, bool status) const{
		if(led >=0 && led <=2) digitalWrite(led_pin[led],status);
	}
	
	bool readButton1() const{
		return digitalRead(button1_pin);
	}
	
	bool readButton2() const {
		return digitalRead(button2_pin);
	}
	
	int readLightSensor() const{
		return analogRead(ldr_pin);
	}

    /**
     * Play tone
     * @param note note frequency
     * @param beat time active
     */
    void playTone(int note, int beat){
		tone(buzzer_pin,note, beat);
	}
	
	void setRGBcolor(int redValue,int greenValue,int blueValue){
		rgbLed.setRGBcolor(redValue,greenValue,blueValue);
	}
	
	unsigned int readJoystickX()const {return joystick.readX();}
	unsigned int readJoystickY()const {return joystick.readY();}
	bool readJoystickButton()const {return joystick.readButton();}
	
	unsigned int readAccX() const {return analogRead(accX_pin);}
	unsigned int readAccY() const {return analogRead(accY_pin);}
	
	
protected:
	static const uint8_t led_pin[3];
	const uint8_t button1_pin, button2_pin;
	const uint8_t ldr_pin;
	const uint8_t buzzer_pin;
	const uint8_t accX_pin, accY_pin;

	Bitbloq::RGBLed rgbLed;
	Bitbloq::Joystick joystick;
};

} //end space

#endif
