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

#ifndef BQZUMI2C7SEGMENT_H
#define BQZUMI2C7SEGMENT_H

namespace BQ{ namespace ZUM{

#ifndef TCA9535_h
#define TCA9535_h

#define TCA9535_ADDR          0x20

#define TCA9535_REG_IP0       0x00
#define TCA9535_REG_IP1       0x01
#define TCA9535_REG_OP0       0x02
#define TCA9535_REG_OP1       0x03
#define TCA9535_REG_PIP0      0x04
#define TCA9535_REG_PIP1      0x05

#define TCA9535_REG_CP0       0x06
#define TCA9535_REG_CP1       0x07
#define TCA9535_CP_B0_OUT     0x00
#define TCA9535_CP_B0_IN      0x01
#define TCA9535_CP_B1_OUT     0x00
#define TCA9535_CP_B1_IN      0x02
#define TCA9535_CP_B2_OUT     0x00
#define TCA9535_CP_B2_IN      0x04
#define TCA9535_CP_B3_OUT     0x00
#define TCA9535_CP_B3_IN      0x08
#define TCA9535_CP_B4_OUT     0x00
#define TCA9535_CP_B4_IN      0x10
#define TCA9535_CP_B5_OUT     0x00
#define TCA9535_CP_B5_IN      0x20
#define TCA9535_CP_B6_OUT     0x00
#define TCA9535_CP_B6_IN      0x40
#define TCA9535_CP_B7_OUT     0x00
#define TCA9535_CP_B7_IN      0x80

#define TCA9535_CHAR_BLANK    0x00
#define TCA9535_CHAR_0        0x3F
#define TCA9535_CHAR_1        0x06
#define TCA9535_CHAR_2        0x5B
#define TCA9535_CHAR_3        0x4F
#define TCA9535_CHAR_4        0x66
#define TCA9535_CHAR_5        0x6D
#define TCA9535_CHAR_6        0x7D
#define TCA9535_CHAR_7        0x07
#define TCA9535_CHAR_8        0x7F
#define TCA9535_CHAR_9        0x67
#define TCA9535_CHAR_A        0x77
#define TCA9535_CHAR_B        0x7C
#define TCA9535_CHAR_C        0x39
#define TCA9535_CHAR_D        0x5E
#define TCA9535_CHAR_E        0x79
#define TCA9535_CHAR_F        0x71
#define TCA9535_CHAR_G        0x6F
#define TCA9535_CHAR_H        0x76
#define TCA9535_CHAR_I        0x30
#define TCA9535_CHAR_J        0x1E
#define TCA9535_CHAR_K        0x7A
#define TCA9535_CHAR_L        0x38
#define TCA9535_CHAR_M        0x37
#define TCA9535_CHAR_N        0x54
#define TCA9535_CHAR_Ñ        0x55
#define TCA9535_CHAR_O        0x3F
#define TCA9535_CHAR_P        0x73
#define TCA9535_CHAR_Q        0x67
#define TCA9535_CHAR_R        0x50
#define TCA9535_CHAR_S        0x6D
#define TCA9535_CHAR_T        0x78
#define TCA9535_CHAR_U        0x1C
#define TCA9535_CHAR_V        0x3E
#define TCA9535_CHAR_W        0x1D
#define TCA9535_CHAR_X        0x70
#define TCA9535_CHAR_Y        0x6E
#define TCA9535_CHAR_Z        0x49

#define TCA9535_CHAR_DOT      0x80


typedef enum {
	SEGMENT_OK,
	SEGMENT_NOK_i2cport,
	SEGMENT_NOK_config,
	SEGMENT_I2C_fail
} SegmentStat;

class	I2C7SegmentDisplay {
	public:
		I2C7SegmentDisplay(uint8_t ui8_port);
		void	setup();
		void	display(uint8_t i_disp1, uint8_t i_disp0);
		void	displayString(String s);
		void	displayInt(int num);
		void	displayChar(char c_disp1, char c_disp0);
		void    displayInPos(uint8_t pos, uint8_t i_disp);
		void	displayCharInPos(uint8_t pos, char c_disp);
		
		void	displayPos0(uint8_t i_disp0);
		void	displayPos1(uint8_t i_disp1);
		void	displayChar0(char c_disp0);
		void	displayChar1(char c_disp1);
		
		
	
	private:
		const uint8_t	segmentdisplay_i2cport;
		SegmentStat		begin();
		void			writeRegister(uint8_t ui8_Reg, uint8_t ui8_data);
		uint8_t			readRegister(uint8_t ui8_Reg);
		
};

}} //end namespace BQ::ZUM

#endif
#endif
