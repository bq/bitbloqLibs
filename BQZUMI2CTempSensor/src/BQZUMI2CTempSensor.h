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
 
#ifndef BQZUMI2CTEMPSENSOR_H
#define BQZUMI2CTEMPSENSOR_H

#ifndef NCT75_h
#define NCT75_h

namespace BQ{ namespace ZUM{
	
#define NCT75_ADDR            0x48
#define NCT75_THYST_DEFAULT   0x4B00
#define NTC75_RESOLUTION     (0.0625)

#define NCT75_REG_TEMP        0x00

#define NCT75_REG_CONF        0x01
#define NCT75_CONF_CONTINUOUS 0x00
#define NCT75_CONF_ONESHOT    0x20
#define NCT75_CONF_FAULT1     0x00
#define NCT75_CONF_FAULT2     0x08
#define NCT75_CONF_FAULT4     0x10
#define NCT75_CONF_FAULT6     0x18
#define NCT75_CONF_OSALRT_AL  0x00
#define NCT75_CONF_OSALRT_AH  0x04
#define NCT75_CONF_CMP        0x00
#define NCT75_CONF_INT        0x02
#define NCT75_CONF_NORMAL     0x00
#define NCT75_CONF_STDWN      0x01

#define NCT75_REG_THYST       0x02
#define NCT75_REG_TOS         0x03
#define NCT75_REG_ONESHOT     0x04

typedef enum {
	TEMP_OK,
	TEMP_NOK_i2cport,
	TEMP_NOK_config,
	TEMP_I2C_fail
} TempStat;

class	I2CTempSensor {
	public:
		I2CTempSensor(uint8_t ui8_i2cport);
		void		setup();
		float		getTemp();
	
	private:
		const uint8_t	tempsens_i2cport;
		TempStat		begin();
		uint16_t		getID();
};

}} //end namespace BQ::ZUM

#endif
#endif
