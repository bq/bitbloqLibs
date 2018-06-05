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

#ifndef BQZUMI2CCOLORSENSOR_H
#define BQZUMI2CCOLORSENSOR_H

#ifndef BH1745NUC_h
#define BH1745NUC_h

namespace BQ{ namespace ZUM{

#define BH1745NUC_ADDR            0x38
#define BH1745NUC_ID              0x0B
#define BH1745NUC_RED_COMP       (1.39)
#define BH1745NUC_GREEN_COMP     (1)
#define BH1745NUC_BLUE_COMP      (1.79)

#define BH1745NUC_REG_SYSCTL      0x40
#define BH1745NUC_SYSCTL_SW_RST   0x80
#define BH1745NUC_SYSCTL_INT      0x40
#define BH1745NUC_SYSCTL_ID       0x3F

#define BH1745NUC_REG_MODE_CTL1   0x41
#define BH1745NUC_MCTL1_MST_160   0x00
#define BH1745NUC_MCTL1_MST_320   0x01
#define BH1745NUC_MCTL1_MST_640   0x02
#define BH1745NUC_MCTL1_MST_1280  0x03
#define BH1745NUC_MCTL1_MST_2560  0x04
#define BH1745NUC_MCTL1_MST_5120  0x05

#define BH1745NUC_REG_MODE_CTL2   0x42
#define BH1745NUC_MCTL2_VALID     0x80
#define BH1745NUC_MCTL2_RGBC_EN	  0x10
#define BH1745NUC_MCTL2_ADCG_1X   0x00
#define BH1745NUC_MCTL2_ADCG_2X   0x01
#define BH1745NUC_MCTL2_ADCG_16X  0x02

#define BH1745NUC_REG_MODE_CTL3   0x44
#define BH1745NUC_MCTL3           0x02

#define BH1745NUC_REG_RED_LSB     0x50
#define BH1745NUC_REG_RED_MSB     0x51
#define BH1745NUC_REG_GREEN_LSB   0x52
#define BH1745NUC_REG_GREEN_MSB   0x53
#define BH1745NUC_REG_BLUE_LSB    0x54
#define BH1745NUC_REG_BLUE_MSB    0x55
#define BH1745NUC_REG_CLEAR_LSB   0x56
#define BH1745NUC_REG_CLEAR_MSB   0x57
#define BH1745NUC_REG_DINT_LSB    0x58
#define BH1745NUC_REG_DINT_MSB    0x59

#define BH1745NUC_REG_INTERRUPT   0x60
#define BH1745NUC_INT_STAT        0x80
#define BH1745NUC_INT_LATCH       0x10
#define BH1745NUC_INT_RED         0x00
#define BH1745NUC_INT_GREEN       0x04
#define BH1745NUC_INT_BLUE        0x08
#define BH1745NUC_INT_CLEAR       0x0C

#define BH1745NUC_REG_PERSISTENCE 0x61
#define BH1745NUC_PERS_TOGGLE     0x00
#define BH1745NUC_PERS_UPD_1      0x01
#define BH1745NUC_PERS_UPD_4      0x02
#define BH1745NUC_PERS_UPD_8      0x03

#define BH1745NUC_REG_TH_LSB      0x62
#define BH1745NUC_REG_TH_MSB      0x63
#define BH1745NUC_REG_TL_LSB      0x64
#define BH1745NUC_REG_TL_MSB      0x65
#define BH1745NUC_REG_TH_LSB      0x62
#define BH1745NUC_MF_ID           0x92

typedef enum {
	COLOR_OK,
	COLOR_NOK_i2cport,
	COLOR_NOK_config,
	COLOR_I2C_fail
} ColorStat;



class	I2CColorSensor {
	public:
		I2CColorSensor(uint8_t ui8_i2cport);
		void	setup();

		typedef enum{
			RED,
			GREEN,
			BLUE,
			WHITE,
			BLACK
		} Colors;

		void	getColor(float *ui16_Red, float *ui16_Green, float *ui16_Blue, float *ui16_Clear);
		float	getComponent(uint8_t);

		Colors	whichColor();

	private:
		const uint8_t	colorsens_i2cport;
		ColorStat		begin();
		uint8_t 		readRegister(uint8_t ui8_Reg);
		void 			writeRegister(uint8_t ui8_Reg, uint8_t ui8_data);


};

}} //end namespace BQ::ZUM

#endif
#endif
