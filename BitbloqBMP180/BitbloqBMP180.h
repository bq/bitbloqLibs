
#ifndef BMP180_H
#define BMP180_H

#if (ARDUINO >= 100)
 #include "Arduino.h"
#else
 #include "WProgram.h"
#endif
#include "Wire.h"

#define BMP180_I2CADDR 0x77

#define BMP180_ULTRALOWPOWER 0
#define BMP180_STANDARD      1
#define BMP180_HIGHRES       2
#define BMP180_ULTRAHIGHRES  3

#define BMP180_CAL_AC1           0xAA  // R   Calibration data (16 bits)
#define BMP180_CAL_AC2           0xAC  // R   Calibration data (16 bits)
#define BMP180_CAL_AC3           0xAE  // R   Calibration data (16 bits)    
#define BMP180_CAL_AC4           0xB0  // R   Calibration data (16 bits)
#define BMP180_CAL_AC5           0xB2  // R   Calibration data (16 bits)
#define BMP180_CAL_AC6           0xB4  // R   Calibration data (16 bits)
#define BMP180_CAL_B1            0xB6  // R   Calibration data (16 bits)
#define BMP180_CAL_B2            0xB8  // R   Calibration data (16 bits)
#define BMP180_CAL_MB            0xBA  // R   Calibration data (16 bits)
#define BMP180_CAL_MC            0xBC  // R   Calibration data (16 bits)
#define BMP180_CAL_MD            0xBE  // R   Calibration data (16 bits)

#define BMP180_CONTROL           0xF4 
#define BMP180_TEMPDATA          0xF6
#define BMP180_PRESSUREDATA      0xF6
#define BMP180_READTEMPCMD          0x2E
#define BMP180_READPRESSURECMD            0x34


class BMP180 {
  public:
    void init(uint8_t mode = BMP180_ULTRAHIGHRES);  // by default go highres
    float getTemperature();
    int32_t getPressure();
    float getAltitude();

    void setSealevelPressure(float pressure);
  
  private:
    uint16_t readRawTemperature(void);
    uint32_t readRawPressure(void);

    int32_t computeB5(int32_t UT);
    uint8_t read8(uint8_t addr);
    uint16_t read16(uint8_t addr);
    void write8(uint8_t addr, uint8_t data);

    uint8_t oversampling;

    int16_t ac1, ac2, ac3, b1, b2, mb, mc, md;
    uint16_t ac4, ac5, ac6;
    float sealevelPressure;
};


#endif //  BMP180_H
