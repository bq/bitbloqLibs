/*
 * BQZUMI2C7SegmentDisplay.cpp
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

#include <BQZUMI2C7SegmentDisplay.h>

namespace BQ{ namespace ZUM{

// Instantiate I2C7SegmentDisplay class
I2C7SegmentDisplay::I2C7SegmentDisplay(uint8_t ui8_port):segmentdisplay_i2cport(ui8_port)
{
}

void I2C7SegmentDisplay::setup(){
	//try to begin 10 times
	for (int i=0;i<10;i++){
		if(begin()) break;
		delay(10);
	}
}

SegmentStat I2C7SegmentDisplay::begin()
{
	uint8_t ui8_Data = 0;
	uint8_t ui8_Conf = 0;
	
	switch (segmentdisplay_i2cport) {
		case 0:
			Wire.begin();
			break;
		case 1:
			Wire1.begin();
			break;
		default:
			return SEGMENT_NOK_i2cport;
	}
	
	ui8_Data = TCA9535_CP_B0_OUT | TCA9535_CP_B1_OUT | TCA9535_CP_B2_OUT | TCA9535_CP_B3_OUT | TCA9535_CP_B4_OUT | TCA9535_CP_B5_OUT | TCA9535_CP_B6_OUT | TCA9535_CP_B7_OUT;
	writeRegister(TCA9535_REG_CP0, ui8_Data);
	ui8_Conf = readRegister(TCA9535_REG_CP0);
	if (ui8_Conf != ui8_Data)
	{
		return SEGMENT_NOK_config;
	}	
	
	ui8_Data = TCA9535_CP_B0_OUT | TCA9535_CP_B1_OUT | TCA9535_CP_B2_OUT | TCA9535_CP_B3_OUT | TCA9535_CP_B4_OUT | TCA9535_CP_B5_OUT | TCA9535_CP_B6_OUT | TCA9535_CP_B7_OUT;
	writeRegister(TCA9535_REG_CP1, ui8_Data);
	ui8_Conf = readRegister(TCA9535_REG_CP1);
	if (ui8_Conf != ui8_Data)
	{
		return SEGMENT_NOK_config;
	}
	
	return SEGMENT_OK;
}

void I2C7SegmentDisplay::display(uint8_t i_disp1, uint8_t i_disp0)
{
	displayPos0(i_disp0);
	displayPos1(i_disp1);
}

void I2C7SegmentDisplay::displayChar(char c_disp1, char c_disp0)
{
	displayChar1(c_disp1);
	displayChar0(c_disp0);			
}

void I2C7SegmentDisplay::displayString(String s){
	if (s.length() == 1){
		displayChar(' ',s[0]);
	}else{
		displayChar(s[0],s[1]);
	}
}

void I2C7SegmentDisplay::displayInt(int num){
	displayString(String(num));
}

void I2C7SegmentDisplay::displayPos0(uint8_t i_disp0){
	writeRegister(TCA9535_REG_OP0, i_disp0);
}
	
void I2C7SegmentDisplay::displayPos1(uint8_t i_disp1){
	writeRegister(TCA9535_REG_OP1, i_disp1);
}

void I2C7SegmentDisplay::displayChar0(char c_disp0){
	switch (c_disp0) {
		case '0':
			writeRegister(TCA9535_REG_OP0, TCA9535_CHAR_0);
			break;
		case '1':
			writeRegister(TCA9535_REG_OP0, TCA9535_CHAR_1);
			break;
		case '2':
			writeRegister(TCA9535_REG_OP0, TCA9535_CHAR_2);
			break;
		case '3':
			writeRegister(TCA9535_REG_OP0, TCA9535_CHAR_3);
			break;			
		case '4':
			writeRegister(TCA9535_REG_OP0, TCA9535_CHAR_4);
			break;			
		case '5':
			writeRegister(TCA9535_REG_OP0, TCA9535_CHAR_5);
			break;			
		case '6':
			writeRegister(TCA9535_REG_OP0, TCA9535_CHAR_6);
			break;			
		case '7':
			writeRegister(TCA9535_REG_OP0, TCA9535_CHAR_7);
			break;			
		case '8':
			writeRegister(TCA9535_REG_OP0, TCA9535_CHAR_8);
			break;			
		case '9':
			writeRegister(TCA9535_REG_OP0, TCA9535_CHAR_9);
			break;			
		case 'a':
		case 'A':
			writeRegister(TCA9535_REG_OP0, TCA9535_CHAR_A);
			break;
		case 'b':
		case 'B':
			writeRegister(TCA9535_REG_OP0, TCA9535_CHAR_B);
			break;
		case 'c':
		case 'C':
			writeRegister(TCA9535_REG_OP0, TCA9535_CHAR_C);
			break;
		case 'd':
		case 'D':
			writeRegister(TCA9535_REG_OP0, TCA9535_CHAR_D);
			break;			
		case 'e':
		case 'E':
			writeRegister(TCA9535_REG_OP0, TCA9535_CHAR_E);
			break;			
		case 'f':
		case 'F':
			writeRegister(TCA9535_REG_OP0, TCA9535_CHAR_F);
			break;			
		case 'g':
		case 'G':
			writeRegister(TCA9535_REG_OP0, TCA9535_CHAR_G);
			break;			
		case 'h':
		case 'H':
			writeRegister(TCA9535_REG_OP0, TCA9535_CHAR_H);
			break;			
		case 'i':
		case 'I':
			writeRegister(TCA9535_REG_OP0, TCA9535_CHAR_I);
			break;			
		case 'j':
		case 'J':
			writeRegister(TCA9535_REG_OP0, TCA9535_CHAR_J);
			break;
		case 'k':
		case 'K':
			writeRegister(TCA9535_REG_OP0, TCA9535_CHAR_K);
			break;	
		case 'l':
		case 'L':
			writeRegister(TCA9535_REG_OP0, TCA9535_CHAR_L);
			break;	
		case 'm':
		case 'M':
			writeRegister(TCA9535_REG_OP0, TCA9535_CHAR_M);
			break;	
		case 'n':
		case 'N':
			writeRegister(TCA9535_REG_OP0, TCA9535_CHAR_N);
			break;	
		case 'o':
		case 'O':
			writeRegister(TCA9535_REG_OP0, TCA9535_CHAR_O);
			break;	
		case 'p':
		case 'P':
			writeRegister(TCA9535_REG_OP0, TCA9535_CHAR_P);
			break;	
		case 'q':
		case 'Q':
			writeRegister(TCA9535_REG_OP0, TCA9535_CHAR_Q);
			break;	
		case 'r':
		case 'R':
			writeRegister(TCA9535_REG_OP0, TCA9535_CHAR_R);
			break;	
		case 's':
		case 'S':
			writeRegister(TCA9535_REG_OP0, TCA9535_CHAR_S);
			break;	
		case 't':
		case 'T':
			writeRegister(TCA9535_REG_OP0, TCA9535_CHAR_T);
			break;	
		case 'u':
		case 'U':
			writeRegister(TCA9535_REG_OP0, TCA9535_CHAR_U);
			break;	
		case 'v':
		case 'V':
			writeRegister(TCA9535_REG_OP0, TCA9535_CHAR_V);
			break;	
		case 'w':
		case 'W':
			writeRegister(TCA9535_REG_OP0, TCA9535_CHAR_W);
			break;	
		case 'x':
		case 'X':
			writeRegister(TCA9535_REG_OP0, TCA9535_CHAR_X);
			break;	
		case 'y':
		case 'Y':
			writeRegister(TCA9535_REG_OP0, TCA9535_CHAR_Y);
			break;	
		case 'z':
		case 'Z':
			writeRegister(TCA9535_REG_OP0, TCA9535_CHAR_Z);
			break;	
		default:
			writeRegister(TCA9535_REG_OP0, TCA9535_CHAR_BLANK);
			break;
	}	
}


void I2C7SegmentDisplay::displayChar1(char c_disp1){
		switch (c_disp1) {
		case '0':
			writeRegister(TCA9535_REG_OP1, TCA9535_CHAR_0);
			break;
		case '1':
			writeRegister(TCA9535_REG_OP1, TCA9535_CHAR_1);
			break;
		case '2':
			writeRegister(TCA9535_REG_OP1, TCA9535_CHAR_2);
			break;
		case '3':
			writeRegister(TCA9535_REG_OP1, TCA9535_CHAR_3);
			break;			
		case '4':
			writeRegister(TCA9535_REG_OP1, TCA9535_CHAR_4);
			break;			
		case '5':
			writeRegister(TCA9535_REG_OP1, TCA9535_CHAR_5);
			break;			
		case '6':
			writeRegister(TCA9535_REG_OP1, TCA9535_CHAR_6);
			break;			
		case '7':
			writeRegister(TCA9535_REG_OP1, TCA9535_CHAR_7);
			break;			
		case '8':
			writeRegister(TCA9535_REG_OP1, TCA9535_CHAR_8);
			break;			
		case '9':
			writeRegister(TCA9535_REG_OP1, TCA9535_CHAR_9);
			break;			
		case 'a':
		case 'A':
			writeRegister(TCA9535_REG_OP1, TCA9535_CHAR_A);
			break;
		case 'b':
		case 'B':
			writeRegister(TCA9535_REG_OP1, TCA9535_CHAR_B);
			break;
		case 'c':
		case 'C':
			writeRegister(TCA9535_REG_OP1, TCA9535_CHAR_C);
			break;
		case 'd':
		case 'D':
			writeRegister(TCA9535_REG_OP1, TCA9535_CHAR_D);
			break;			
		case 'e':
		case 'E':
			writeRegister(TCA9535_REG_OP1, TCA9535_CHAR_E);
			break;			
		case 'f':
		case 'F':
			writeRegister(TCA9535_REG_OP1, TCA9535_CHAR_F);
			break;			
		case 'g':
		case 'G':
			writeRegister(TCA9535_REG_OP1, TCA9535_CHAR_G);
			break;			
		case 'h':
		case 'H':
			writeRegister(TCA9535_REG_OP1, TCA9535_CHAR_H);
			break;			
		case 'i':
		case 'I':
			writeRegister(TCA9535_REG_OP1, TCA9535_CHAR_I);
			break;			
		case 'j':
		case 'J':
			writeRegister(TCA9535_REG_OP1, TCA9535_CHAR_J);
			break;
		case 'k':
		case 'K':
			writeRegister(TCA9535_REG_OP1, TCA9535_CHAR_K);
			break;	
		case 'l':
		case 'L':
			writeRegister(TCA9535_REG_OP1, TCA9535_CHAR_L);
			break;	
		case 'm':
		case 'M':
			writeRegister(TCA9535_REG_OP1, TCA9535_CHAR_M);
			break;	
		case 'n':
		case 'N':
			writeRegister(TCA9535_REG_OP1, TCA9535_CHAR_N);
			break;	
		case 'o':
		case 'O':
			writeRegister(TCA9535_REG_OP1, TCA9535_CHAR_O);
			break;	
		case 'p':
		case 'P':
			writeRegister(TCA9535_REG_OP1, TCA9535_CHAR_P);
			break;	
		case 'q':
		case 'Q':
			writeRegister(TCA9535_REG_OP1, TCA9535_CHAR_Q);
			break;	
		case 'r':
		case 'R':
			writeRegister(TCA9535_REG_OP1, TCA9535_CHAR_R);
			break;	
		case 's':
		case 'S':
			writeRegister(TCA9535_REG_OP1, TCA9535_CHAR_S);
			break;	
		case 't':
		case 'T':
			writeRegister(TCA9535_REG_OP1, TCA9535_CHAR_T);
			break;	
		case 'u':
		case 'U':
			writeRegister(TCA9535_REG_OP1, TCA9535_CHAR_U);
			break;	
		case 'v':
		case 'V':
			writeRegister(TCA9535_REG_OP1, TCA9535_CHAR_V);
			break;	
		case 'w':
		case 'W':
			writeRegister(TCA9535_REG_OP1, TCA9535_CHAR_W);
			break;	
		case 'x':
		case 'X':
			writeRegister(TCA9535_REG_OP1, TCA9535_CHAR_X);
			break;	
		case 'y':
		case 'Y':
			writeRegister(TCA9535_REG_OP1, TCA9535_CHAR_Y);
			break;	
		case 'z':
		case 'Z':
			writeRegister(TCA9535_REG_OP1, TCA9535_CHAR_Z);
			break;	
		default:
			writeRegister(TCA9535_REG_OP1, TCA9535_CHAR_BLANK);
			break;
	}
}

void I2C7SegmentDisplay::writeRegister(uint8_t ui8_Reg, uint8_t ui8_data)
{
	switch (segmentdisplay_i2cport) {
		case 0:
			Wire.beginTransmission(TCA9535_ADDR);
			Wire.write((byte)ui8_Reg);
			Wire.write((byte)ui8_data);
			Wire.endTransmission(false);
			break;
		case 1:
			Wire1.beginTransmission(TCA9535_ADDR);
			Wire1.write((byte)ui8_Reg);
			Wire1.write((byte)ui8_data);
			Wire1.endTransmission(false);
			break;
		default:
			return;
	}

}

uint8_t I2C7SegmentDisplay::readRegister(uint8_t ui8_Reg)
{
	uint8_t ui8_data = 0;
  
	switch (segmentdisplay_i2cport) {
		case 0:
			Wire.beginTransmission(TCA9535_ADDR);
			Wire.write((byte)ui8_Reg);
			Wire.endTransmission(false);
			Wire.requestFrom((byte)TCA9535_ADDR, (byte)1);
			ui8_data = Wire.read();
			break;		
		case 1:
			Wire1.beginTransmission(TCA9535_ADDR);
			Wire1.write((byte)ui8_Reg);
			Wire1.endTransmission(false);
			Wire1.requestFrom((byte)TCA9535_ADDR, (byte)1);
			ui8_data = Wire1.read();
			break;
		default:
			return 0;
	}
  
  return ui8_data;
}

}} //end namespace BQ::ZUM

