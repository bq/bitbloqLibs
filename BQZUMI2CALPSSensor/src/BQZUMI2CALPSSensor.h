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
 
#ifndef BQZUMI2CALPSSENSOR_H
#define BQZUMI2CALPSSENSOR_H

#ifndef VCNL4200_h
#define VCNL4200_h

namespace BQ{ namespace ZUM{

#define VCNL4200_ADDR					0x51
#define VCNL4200_ID						0x58
#define VCNL4200_AL_LUXES			   (0.024)
#define VCNL4200_PS_INVERT			   (4096)

#define VCNL4200_REG_ALS_CONF			0x00
#define VCNL4200_ALS_CONF_ALS_IT_50		0x00
#define VCNL4200_ALS_CONF_ALS_IT_100	0x40
#define VCNL4200_ALS_CONF_ALS_IT_200	0x80
#define VCNL4200_ALS_CONF_ALS_IT_400	0xC0
#define VCNL4200_ALS_CONF_ALS_INT_ALS	0x00
#define VCNL4200_ALS_CONF_ALS_INT_WH	0x20
#define VCNL4200_ALS_CONF_ALS_PERS_1	0x00
#define VCNL4200_ALS_CONF_ALS_PERS_2	0x04
#define VCNL4200_ALS_CONF_ALS_PERS_4	0x08
#define VCNL4200_ALS_CONF_ALS_PERS_8	0x0C
#define VCNL4200_ALS_CONF_ALS_INT_DIS	0x00
#define VCNL4200_ALS_CONF_ALS_INT_EN	0x02
#define VCNL4200_ALS_CONF_ALS_PO		0x00
#define VCNL4200_ALS_CONF_ALS_STD		0x01

#define VCNL4200_REG_ALS_THDH			0x01
#define VCNL4200_REG_ALS_THDL			0x02

#define VCNL4200_REG_PS_CONF1_CONF2		0x03
#define VCNL4200_PS_CONF1_PS_DUTY_160	0x00
#define VCNL4200_PS_CONF1_PS_DUTY_320	0x40
#define VCNL4200_PS_CONF1_PS_DUTY_640	0x80
#define VCNL4200_PS_CONF1_PS_DUTY_1280	0xC0
#define VCNL4200_PS_CONF1_PS_PERS_1		0x00
#define VCNL4200_PS_CONF1_PS_PERS_2		0x10
#define VCNL4200_PS_CONF1_PS_PERS_3		0x20
#define VCNL4200_PS_CONF1_PS_PERS_4		0x30
#define VCNL4200_PS_CONF1_PS_IT_1T		0x00
#define VCNL4200_PS_CONF1_PS_IT_1T5		0x02
#define VCNL4200_PS_CONF1_PS_IT_2T		0x04
#define VCNL4200_PS_CONF1_PS_IT_4T		0x06
#define VCNL4200_PS_CONF1_PS_IT_8T		0x08
#define VCNL4200_PS_CONF1_PS_IT_9T		0x0A
#define VCNL4200_PS_CONF1_PS_SD_PO		0x00
#define VCNL4200_PS_CONF1_PS_SD_ST		0x01
#define VCNL4200_PS_CONF2_PS_HD_12B		0x00
#define VCNL4200_PS_CONF2_PS_HD_16B		0x08
#define VCNL4200_PS_CONF2_PS_INT_DIS	0x00
#define VCNL4200_PS_CONF2_PS_INT_CLOSE	0x01
#define VCNL4200_PS_CONF2_PS_INT_AWAY	0x02
#define VCNL4200_PS_CONF2_PS_INT_CL&AW	0x03

#define VCNL4200_REG_PS_CONF3_MS			0x04
#define VCNL4200_PS_CONF3_MPS_1				0x00
#define VCNL4200_PS_CONF3_MPS_2				0x20
#define VCNL4200_PS_CONF3_MPS_4				0x40
#define VCNL4200_PS_CONF3_MPS_8				0x60
#define VCNL4200_PS_CONF3_SMART_PERS_DIS	0x00
#define VCNL4200_PS_CONF3_SMART_PERS_EN		0x10
#define VCNL4200_PS_CONF3_AF_DIS			0x00
#define VCNL4200_PS_CONF3_AF_EN				0x08
#define VCNL4200_PS_CONF3_TRIG_NO			0x00
#define VCNL4200_PS_CONF3_TRIG_1TC			0x04
#define VCNL4200_PS_CONF3_SC_ADV_TYP		0x00
#define VCNL4200_PS_CONF3_SC_ADV_2XTYP		0x02
#define VCNL4200_PS_CONF3_SC_DIS			0x00
#define VCNL4200_PS_CONF3_SC_EN				0x01
#define VCNL4200_PS_MS_NORMAL				0x00
#define VCNL4200_PS_MS_LOGIC				0x20
#define VCNL4200_PS_SP_TYPICAL				0x00
#define VCNL4200_PS_SP_15TYPICAL			0x10
#define VCNL4200_PS_SPO_00					0x00
#define VCNL4200_PS_SPO_FF					0x08
#define VCNL4200_PS_LED_I_50				0x00
#define VCNL4200_PS_LED_I_75				0x01
#define VCNL4200_PS_LED_I_100				0x02
#define VCNL4200_PS_LED_I_120				0x03
#define VCNL4200_PS_LED_I_140				0x04
#define VCNL4200_PS_LED_I_160				0x05
#define VCNL4200_PS_LED_I_180				0x06
#define VCNL4200_PS_LED_I_200				0x07

#define VCNL4200_REG_PS_CANC				0x05
#define VCNL4200_REG_PS_THDL				0x06
#define VCNL4200_REG_PS_THDH				0x07
#define VCNL4200_REG_PS_DATA				0x08
#define VCNL4200_REG_ALS_DATA				0x09
#define VCNL4200_REG_WHITE_DATA				0x0A

#define VCNL4200_REG_INT_FLAG				0x0D
#define VCNL4200_INT_PS_UPFLAG				0x80
#define VCNL4200_INT_PS_SPFLAG				0x40
#define VCNL4200_INT_ALS_IF_L				0x20
#define VCNL4200_INT_ALS_IF_H				0x10
#define VCNL4200_INT_PS_IF_CLOSE			0x02
#define VCNL4200_INT_PS_IF_AWAY				0x01

#define VCNL4200_REG_ID						0x0E

typedef enum {
	ALPS_OK,
	ALPS_NOK_i2cport,
	ALPS_NOK_config,
	ALPS_I2C_fail
} ALPSStat;

class	I2CALPSSensor {
		
	public:
		I2CALPSSensor(uint8_t ui8_i2cport);
		void		setup();
		uint16_t	getDistance(void);
		float		getAL(void);
	
	private:
		int			distsens_i2cport;
		ALPSStat	begin();
		void 		writeRegister(uint8_t ui8_Reg, uint8_t ui8_dataL, uint8_t ui8_dataH);
		void		readRegister(uint8_t ui8_Reg, uint8_t *ui8_dataL, uint8_t *ui8_dataH);
};

}} //end namespace BQ::ZUM

#endif
#endif
