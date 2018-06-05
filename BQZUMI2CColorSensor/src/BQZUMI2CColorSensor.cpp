/*
 * BQZUMI2CColorSensor.h
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
#include <BQZUMI2CColorSensor.h>

namespace BQ{ namespace ZUM{

// Instantiate I2CColorSensor class
I2CColorSensor::I2CColorSensor(uint8_t ui8_i2cport):colorsens_i2cport(ui8_i2cport)
{
}

void I2CColorSensor::setup(){
	for (int i=0;i<10;i++){
		if(begin()==COLOR_OK) break;
	}
}

ColorStat I2CColorSensor::begin()
{
	uint8_t ui8_DRVid	= 0;
	uint8_t ui8_DRVconf	= 0;

	switch (colorsens_i2cport) {
		case 0:
			Wire.begin();
			break;
		case 1:
			Wire1.begin();
			break;
		default:
			return COLOR_NOK_i2cport;
	}

	ui8_DRVid = readRegister(BH1745NUC_REG_SYSCTL) & BH1745NUC_SYSCTL_ID;

	if (ui8_DRVid != BH1745NUC_ID)
	{
		return COLOR_NOK_config;
	}

	// Configure sensor
	//ui8_DRVconf = BH1745NUC_SYSCTL_INT;
	//writeRegister(BH1745NUC_REG_SYSCTL, ui8_DRVconf);

	ui8_DRVconf = BH1745NUC_MCTL1_MST_160;
	writeRegister(BH1745NUC_REG_MODE_CTL1, ui8_DRVconf);

	ui8_DRVconf = BH1745NUC_MCTL2_VALID | BH1745NUC_MCTL2_RGBC_EN | BH1745NUC_MCTL2_ADCG_1X;
	writeRegister(BH1745NUC_REG_MODE_CTL2, ui8_DRVconf);

	ui8_DRVconf = BH1745NUC_MCTL3;
	writeRegister(BH1745NUC_REG_MODE_CTL3, ui8_DRVconf);

	return COLOR_OK;
}

void I2CColorSensor::writeRegister(uint8_t ui8_Reg, uint8_t ui8_data)
{
	switch (colorsens_i2cport) {
		case 0:
			Wire.beginTransmission(BH1745NUC_ADDR);
			Wire.write((byte)ui8_Reg);
			Wire.write((byte)ui8_data);
			Wire.endTransmission();
			break;
		case 1:
			Wire1.beginTransmission(BH1745NUC_ADDR);
			Wire1.write((byte)ui8_Reg);
			Wire1.write((byte)ui8_data);
			Wire1.endTransmission();
			break;
		default:
			return;
	}

}

uint8_t I2CColorSensor::readRegister(uint8_t ui8_Reg)
{
	uint8_t ui8_data = 0;

	switch (colorsens_i2cport) {
		case 0:
			Wire.beginTransmission(BH1745NUC_ADDR);
			Wire.write((byte)ui8_Reg);
			Wire.endTransmission(false);
			Wire.requestFrom((byte)BH1745NUC_ADDR, (byte)1);
			ui8_data = Wire.read();
			break;
		case 1:
			Wire1.beginTransmission(BH1745NUC_ADDR);
			Wire1.write((byte)ui8_Reg);
			Wire1.endTransmission(false);
			Wire1.requestFrom((byte)BH1745NUC_ADDR, (byte)1);
			ui8_data = Wire1.read();
			break;
		default:
			return 0;
	}

  return ui8_data;
}

float I2CColorSensor::getComponent(uint8_t ui8_component){
  float     f_Red	= 0;
  float     f_Green = 0;
  float     f_Blue	= 0;
  float     f_Clear = 0;
  getColor(&f_Red,&f_Green,&f_Blue,&f_Clear);
  switch(ui8_component){
    case 0:
      return f_Red;
    case 1:
      return f_Green;
    case 2:
      return f_Blue;
    default:
      return 0;
  }
}

void I2CColorSensor::getColor(float *f_Red, float *f_Green, float *f_Blue, float *f_Clear)
{
	uint8_t     ui8_data = 0;
	uint16_t    ui16_color = 0;

	do
	{
		ui8_data = readRegister(BH1745NUC_REG_MODE_CTL2);
	}
	while (ui8_data & BH1745NUC_MCTL2_VALID != 0);

	ui16_color = (readRegister(BH1745NUC_REG_RED_MSB)<<8) + (readRegister(BH1745NUC_REG_RED_LSB));
	*f_Red = ui16_color * BH1745NUC_RED_COMP;

	ui16_color = (readRegister(BH1745NUC_REG_GREEN_MSB)<<8) + (readRegister(BH1745NUC_REG_GREEN_LSB));
	*f_Green = ui16_color * BH1745NUC_GREEN_COMP;

	ui16_color = (readRegister(BH1745NUC_REG_BLUE_MSB)<<8) + (readRegister(BH1745NUC_REG_BLUE_LSB));
	*f_Blue = ui16_color * BH1745NUC_BLUE_COMP;

	ui16_color = (readRegister(BH1745NUC_REG_CLEAR_MSB)<<8) + (readRegister(BH1745NUC_REG_CLEAR_LSB));
	*f_Clear = ui16_color;
}

I2CColorSensor::Colors I2CColorSensor::whichColor(){
	//GET COLOR
	float	f_Red	= 0;
	float	f_Green	= 0;
	float	f_Blue	= 0;
	float	f_Clear	= 0;
	float 	f_RedAverage 	= 0;
	float	f_GreenAverage	= 0;
	float	f_BlueAverage	= 0;
	float	f_ClearAverage	= 0;

	for(int i_Cont=0;i_Cont<100;i_Cont++){
		getColor(&f_Red, &f_Green, &f_Blue, &f_Clear);
		f_RedAverage+=f_Red;
		f_GreenAverage+=f_Green;
		f_BlueAverage+=f_Blue;
		f_ClearAverage+=f_Clear;
	}

  f_RedAverage		= f_RedAverage/100;
  f_GreenAverage	= f_GreenAverage/100;
  f_BlueAverage		= f_BlueAverage/100;
  f_ClearAverage	= f_ClearAverage/100;

  #ifdef DEBUG
  Serial.print("COLOR Red:");
  Serial.print(f_RedAverage);
  Serial.print("\tGreen:");
  Serial.print(f_GreenAverage);
  Serial.print("\tBlue:");
  Serial.print(f_BlueAverage);
  Serial.print("\tClear:");
  Serial.print(f_ClearAverage);
  Serial.println();
  #endif //DEBUG

  if ( (f_RedAverage > 130) && (f_GreenAverage > 130) && (f_BlueAverage > 130) ) return I2CColorSensor::WHITE;
  if ( (f_RedAverage < 50) && (f_GreenAverage < 50) && (f_BlueAverage < 50) ) return I2CColorSensor::BLACK;
  if ( f_RedAverage > (f_GreenAverage+f_BlueAverage)) return I2CColorSensor::RED;
  if ( f_GreenAverage > (f_RedAverage + f_BlueAverage)) return I2CColorSensor::GREEN;
  if ( f_BlueAverage > (f_GreenAverage + f_RedAverage)) return I2CColorSensor::BLUE;
  if ( (f_RedAverage > 130) || (f_GreenAverage > 130) || (f_BlueAverage > 130) ) return I2CColorSensor::WHITE;
  if ( (f_RedAverage < 50) || (f_GreenAverage < 50) || (f_BlueAverage < 50) ) return I2CColorSensor::BLACK;
  return I2CColorSensor::WHITE;
}

}} //end namespace BQ::ZUM
