/*
 * BQZUMI2CDistSensor.h
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
 
#define DEBUG

#if ARDUINO >= 100
 #include "Arduino.h"
#else
 #include "WProgram.h"
#endif

#include <Wire.h>

#include <BQZUMI2CALPSSensor.h>

namespace BQ{ namespace ZUM{
	
// Instantiate BQZUM_ColorSensor class
I2CALPSSensor::I2CALPSSensor(uint8_t ui8_i2cport):distsens_i2cport(ui8_i2cport)
{
}

void I2CALPSSensor::setup(){
	for (int i=0;i<10;i++){
		if(begin()==ALPS_OK) break;
	}
}

ALPSStat I2CALPSSensor::begin()
{
	uint8_t ui8_datawH = 0;
	uint8_t ui8_datawL = 0;
	uint8_t ui8_datarH = 256;
	uint8_t ui8_datarL = 256;
	uint16_t ui16_data = 0;
	
	switch (distsens_i2cport) {
	case 0:
		Wire.begin();
		break;
	case 1:
		Wire1.begin();
		break;
	default:
		return ALPS_NOK_i2cport;
	}
	
	// Configure ALS
	ui8_datawL = VCNL4200_ALS_CONF_ALS_IT_50 | VCNL4200_ALS_CONF_ALS_INT_ALS | VCNL4200_ALS_CONF_ALS_PERS_1 | VCNL4200_ALS_CONF_ALS_INT_DIS | VCNL4200_ALS_CONF_ALS_PO;
	ui8_datawH = 0;
	writeRegister(VCNL4200_REG_ALS_CONF, ui8_datawH, ui8_datawL);
	readRegister(VCNL4200_REG_ALS_CONF, &ui8_datarH, &ui8_datarL);
	if ((ui8_datawH!=ui8_datarH) | (ui8_datawL!=ui8_datarL))
	{
		return ALPS_NOK_config;
	}
		
	// Configure PS
	ui8_datawL = VCNL4200_PS_CONF1_PS_DUTY_160 | VCNL4200_PS_CONF1_PS_PERS_1 | VCNL4200_PS_CONF1_PS_IT_1T | VCNL4200_PS_CONF1_PS_SD_PO;
	ui8_datawH = VCNL4200_PS_CONF2_PS_HD_16B | VCNL4200_PS_CONF2_PS_INT_DIS;
	writeRegister(VCNL4200_REG_PS_CONF1_CONF2, ui8_datawH, ui8_datawL);
	readRegister(VCNL4200_REG_PS_CONF1_CONF2, &ui8_datarH, &ui8_datarL);
	if ((ui8_datawH!=ui8_datarH) | (ui8_datawL!=ui8_datarL))
	{
		return ALPS_NOK_config;
	}
	
	ui8_datawL = VCNL4200_PS_CONF3_MPS_1 | VCNL4200_PS_CONF3_SMART_PERS_DIS | VCNL4200_PS_CONF3_AF_DIS | VCNL4200_PS_CONF3_TRIG_NO | VCNL4200_PS_CONF3_SC_ADV_TYP | VCNL4200_PS_CONF3_SC_DIS;
	ui8_datawH = VCNL4200_PS_MS_NORMAL | VCNL4200_PS_SP_TYPICAL | VCNL4200_PS_SPO_00 | VCNL4200_PS_LED_I_50;
	writeRegister(VCNL4200_REG_PS_CONF3_MS, ui8_datawH, ui8_datawL);
	readRegister(VCNL4200_REG_PS_CONF3_MS, &ui8_datarH, &ui8_datarL);
	if ((ui8_datawH!=ui8_datarH) | (ui8_datawL!=ui8_datarL))
	{
		return ALPS_NOK_config;
	}
	
	// Configure TOP threshold register
	writeRegister(VCNL4200_REG_PS_THDL, B10001000, B00010011);
	writeRegister(VCNL4200_REG_PS_THDH, B11100000, B00101110);
	
	// Read ID
	readRegister(VCNL4200_REG_ID, &ui8_datarL, &ui8_datarH);
	if (ui8_datarL != VCNL4200_ID)
	{
		return ALPS_NOK_config;
	}

	return ALPS_OK;
}

uint16_t I2CALPSSensor::getDistance(void)
{
	uint8_t		ui8_dataL;
	uint8_t		ui8_dataH;
	uint16_t	ui16_distance;
	readRegister(VCNL4200_REG_PS_DATA, &ui8_dataL, &ui8_dataH);
	ui16_distance = (ui8_dataH << 8) + ui8_dataL;
	return ui16_distance;
}

float I2CALPSSensor::getAL(void)
{
	uint8_t		ui8_dataL;
	uint8_t		ui8_dataH;
	uint16_t	ui16_ambient;
	float		f_ambient;
	readRegister(VCNL4200_REG_ALS_DATA, &ui8_dataL, &ui8_dataH);
	ui16_ambient = (ui8_dataH << 8) + ui8_dataL;
	f_ambient = ui16_ambient * VCNL4200_AL_LUXES;
	return f_ambient;
}

void I2CALPSSensor::writeRegister(uint8_t ui8_Reg, uint8_t ui8_dataL, uint8_t ui8_dataH)
{
	
	switch (distsens_i2cport) {
		case 0:
			Wire.beginTransmission(VCNL4200_ADDR);
			Wire.write((byte)ui8_Reg);
			Wire.write((byte)ui8_dataL);
			Wire.write((byte)ui8_dataH);
			Wire.endTransmission();
			break;
		case 1:
			Wire1.beginTransmission(VCNL4200_ADDR);
			Wire1.write((byte)ui8_Reg);
			Wire1.write((byte)ui8_dataL);
			Wire1.write((byte)ui8_dataH);
			Wire1.endTransmission();
			break;
		default:
			return;
	}

}

void I2CALPSSensor::readRegister(uint8_t ui8_Reg, uint8_t *ui8_dataL, uint8_t *ui8_dataH)
{
	switch (distsens_i2cport) {
		case 0:
			Wire.beginTransmission(VCNL4200_ADDR);
			Wire.write((byte)ui8_Reg);
			Wire.endTransmission(false);
			Wire.requestFrom((byte)VCNL4200_ADDR, (byte)2);
			*ui8_dataL = Wire.read();
			*ui8_dataH = Wire.read();
			break;		
		case 1:
			Wire1.beginTransmission(VCNL4200_ADDR);
			Wire1.write((byte)ui8_Reg);
			Wire1.endTransmission(false);
			Wire1.requestFrom((byte)VCNL4200_ADDR, (byte)2);
			*ui8_dataL = Wire1.read();
			*ui8_dataH = Wire1.read();
			break;
		default:
			return;
	}
}

}} //end namespace BQ::ZUM
