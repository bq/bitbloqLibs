/*
 * BQZUMI2CTempSensor.h
 * 
 * Copyright 2018 Alberto Valero <alberto.valero@bq.com>
 *                Pablo García <pablo.garcia@bq.com> 
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

#if ARDUINO >= 100
 #include "Arduino.h"
#else
 #include "WProgram.h"
#endif

#include <Wire.h>

#include <BQZUMI2CTempSensor.h>

namespace BQ{ namespace ZUM{

// Instantiate I2CTempSensor class
I2CTempSensor::I2CTempSensor(uint8_t ui8_i2cport):tempsens_i2cport(ui8_i2cport)
{
}

void I2CTempSensor::setup(){
	for (int i=0;i<10;i++){
		if(begin()==TEMP_OK) break;
	}
}


TempStat I2CTempSensor::begin()
{
	uint16_t	ui16_TempID;
	
	switch (tempsens_i2cport) {
		case 0:
			Wire.begin();
			break;
		case 1:
			Wire1.begin();
			break;
		default:
			return TEMP_NOK_i2cport;
	}
	
	ui16_TempID = getID();
	if (ui16_TempID != NCT75_THYST_DEFAULT)
	{
		return TEMP_NOK_config;
	}
	
	return TEMP_OK;
}


float I2CTempSensor::getTemp()
{
	byte    b_data_msb	= 0;
	byte    b_data_lsb	= 0;
	int		i_Temp		= 0;
	float	f_Temp		= 0;
	
	switch (tempsens_i2cport) {
		case 0:
			Wire.beginTransmission(NCT75_ADDR);
			Wire.write((byte)NCT75_REG_TEMP);
			Wire.endTransmission(false);
			Wire.requestFrom(NCT75_ADDR,2);
			b_data_msb = Wire.read();
			b_data_lsb = Wire.read();
			break;
		case 1:
			Wire1.beginTransmission(NCT75_ADDR);
			Wire1.write((byte)NCT75_REG_TEMP);
			Wire1.endTransmission(false);
			Wire1.requestFrom(NCT75_ADDR,2);
			b_data_msb = Wire1.read();
			b_data_lsb = Wire1.read();
			break;
		default:
			return 0;
	}
	i_Temp = ((b_data_msb << 8) | b_data_lsb) >> 4;
	f_Temp = i_Temp * NTC75_RESOLUTION;
	
	return f_Temp;
}

uint16_t I2CTempSensor::getID()
{
	uint8_t 	ui8_data_msb	= 0;
	uint8_t 	ui8_data_lsb	= 0;
	uint16_t	ui16_ID			= 0;

	switch (tempsens_i2cport) {
		case 0:
			Wire.beginTransmission(NCT75_ADDR);
			Wire.write(NCT75_REG_THYST);
			Wire.endTransmission();
			Wire.requestFrom(NCT75_ADDR,2);
			ui8_data_msb = Wire.read();
			ui8_data_lsb = Wire.read();
			break;
		case 1:
			Wire1.beginTransmission(NCT75_ADDR);
			Wire1.write(NCT75_REG_THYST);
			Wire1.endTransmission();
			Wire1.requestFrom(NCT75_ADDR,2);
			ui8_data_msb = Wire1.read();
			ui8_data_lsb = Wire1.read();
			break;
		default:
			return 0;
	}
	ui16_ID = (ui8_data_msb << 8) | ui8_data_lsb;
	return ui16_ID;
}

}} //end namespace BQ::ZUM
