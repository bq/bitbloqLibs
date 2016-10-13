#include "BitbloqBMP180.h"


void BMP180::init(uint8_t mode) {
  if (mode > BMP180_ULTRAHIGHRES) 
    mode = BMP180_ULTRAHIGHRES;
  oversampling = mode;

  Wire.begin();

  /* read calibration data */
  ac1 = read16(BMP180_CAL_AC1);
  ac2 = read16(BMP180_CAL_AC2);
  ac3 = read16(BMP180_CAL_AC3);
  ac4 = read16(BMP180_CAL_AC4);
  ac5 = read16(BMP180_CAL_AC5);
  ac6 = read16(BMP180_CAL_AC6);

  b1 = read16(BMP180_CAL_B1);
  b2 = read16(BMP180_CAL_B2);

  mb = read16(BMP180_CAL_MB);
  mc = read16(BMP180_CAL_MC);
  md = read16(BMP180_CAL_MD);

  sealevelPressure = 101325;
}

int32_t BMP180::computeB5(int32_t UT) {
  int32_t X1 = (UT - (int32_t)ac6) * ((int32_t)ac5) >> 15;
  int32_t X2 = ((int32_t)mc << 11) / (X1+(int32_t)md);
  return X1 + X2;
}

uint16_t BMP180::readRawTemperature(void) {
  write8(BMP180_CONTROL, BMP180_READTEMPCMD);
  delay(5);
  return read16(BMP180_TEMPDATA);
}

uint32_t BMP180::readRawPressure(void) {
  uint32_t raw;

  write8(BMP180_CONTROL, BMP180_READPRESSURECMD + (oversampling << 6));

  if (oversampling == BMP180_ULTRALOWPOWER) 
    delay(5);
  else if (oversampling == BMP180_STANDARD) 
    delay(8);
  else if (oversampling == BMP180_HIGHRES) 
    delay(14);
  else 
    delay(26);

  raw = read16(BMP180_PRESSUREDATA);

  raw <<= 8;
  raw |= read8(BMP180_PRESSUREDATA+2);
  raw >>= (8 - oversampling);

  return raw;
}


int32_t BMP180::getPressure() {
  int32_t UT, UP, B3, B5, B6, X1, X2, X3, p;
  uint32_t B4, B7;

  UT = readRawTemperature();
  UP = readRawPressure();

  B5 = computeB5(UT);

  // do pressure calcs
  B6 = B5 - 4000;
  X1 = ((int32_t)b2 * ( (B6 * B6)>>12 )) >> 11;
  X2 = ((int32_t)ac2 * B6) >> 11;
  X3 = X1 + X2;
  B3 = ((((int32_t)ac1*4 + X3) << oversampling) + 2) / 4;

  X1 = ((int32_t)ac3 * B6) >> 13;
  X2 = ((int32_t)b1 * ((B6 * B6) >> 12)) >> 16;
  X3 = ((X1 + X2) + 2) >> 2;
  B4 = ((uint32_t)ac4 * (uint32_t)(X3 + 32768)) >> 15;
  B7 = ((uint32_t)UP - B3) * (uint32_t)( 50000UL >> oversampling );

  if (B7 < 0x80000000) {
    p = (B7 * 2) / B4;
  } else {
    p = (B7 / B4) * 2;
  }
  X1 = (p >> 8) * (p >> 8);
  X1 = (X1 * 3038) >> 16;
  X2 = (-7357 * p) >> 16;

  p = p + ((X1 + X2 + (int32_t)3791)>>4);

  return p;
}

void BMP180::setSealevelPressure(float pressure){
  sealevelPressure = pressure;
}

float BMP180::getTemperature() {
  int32_t UT, B5;     // following ds convention
  float temp;

  UT = readRawTemperature();

  B5 = computeB5(UT);
  temp = (B5+8) >> 4;
  temp /= 10;
  
  return temp;
}

float BMP180::getAltitude() {
  float altitude;

  float pressure = getPressure();

  altitude = 44330 * (1.0 - pow(pressure /sealevelPressure,0.1903));

  return altitude;
}


/*********************************************************************/

uint8_t BMP180::read8(uint8_t a) {
  uint8_t ret;

  Wire.beginTransmission(BMP180_I2CADDR); // start transmission to device 
#if (ARDUINO >= 100)
  Wire.write(a); // sends register address to read from
#else
  Wire.send(a); // sends register address to read from
#endif
  Wire.endTransmission(); // end transmission
  
  Wire.beginTransmission(BMP180_I2CADDR); // start transmission to device 
  Wire.requestFrom(BMP180_I2CADDR, 1);// send data n-bytes read
#if (ARDUINO >= 100)
  ret = Wire.read(); // receive DATA
#else
  ret = Wire.receive(); // receive DATA
#endif
  Wire.endTransmission(); // end transmission

  return ret;
}

uint16_t BMP180::read16(uint8_t a) {
  uint16_t ret;

  Wire.beginTransmission(BMP180_I2CADDR); // start transmission to device 
#if (ARDUINO >= 100)
  Wire.write(a); // sends register address to read from
#else
  Wire.send(a); // sends register address to read from
#endif
  Wire.endTransmission(); // end transmission
  
  Wire.beginTransmission(BMP180_I2CADDR); // start transmission to device 
  Wire.requestFrom(BMP180_I2CADDR, 2);// send data n-bytes read
#if (ARDUINO >= 100)
  ret = Wire.read(); // receive DATA
  ret <<= 8;
  ret |= Wire.read(); // receive DATA
#else
  ret = Wire.receive(); // receive DATA
  ret <<= 8;
  ret |= Wire.receive(); // receive DATA
#endif
  Wire.endTransmission(); // end transmission

  return ret;
}

void BMP180::write8(uint8_t a, uint8_t d) {
  Wire.beginTransmission(BMP180_I2CADDR); // start transmission to device 
#if (ARDUINO >= 100)
  Wire.write(a); // sends register address to read from
  Wire.write(d);  // write data
#else
  Wire.send(a); // sends register address to read from
  Wire.send(d);  // write data
#endif
  Wire.endTransmission(); // end transmission
}
