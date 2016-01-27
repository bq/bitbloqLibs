#include "BitbloqBMP180.h"
#include "Wire.h"
#include "Arduino.h"

void BMP180::init(){
  Wire.begin();
  ac1 = read16b(0xAA);
  ac2 = read16b(0xAC);
  ac3 = read16b(0xAE);
  ac4 = read16b(0xB0);
  ac5 = read16b(0xB2);
  ac6 = read16b(0xB4);
  b1 = read16b(0xB6);
  b2 = read16b(0xB8);
  mb = read16b(0xBA);
  mc = read16b(0xBC);
  md = read16b(0xBE);
  sealevelPressure = 101325;
}


float BMP180::getTemperature(){
  float temp;

  temp = (TemperatureCompensation() + 8)>>4;
  temp /= 10;

  return temp;
}

float BMP180::getPressure(){
  long PressureCompensation, x1, x2, x3, b3, b6, p;
  unsigned long b4, b7;

  Wire.beginTransmission(BMP180_ADDRESS);
  Wire.write(CONTROL);
  Wire.write(PRESCMD + (oversampling<<6));
  Wire.endTransmission();
  delay(2 + (3<<oversampling));

  PressureCompensation = read16b(DATA);
  PressureCompensation <<= 8;
  PressureCompensation |= read8b(DATA+2);
  PressureCompensation >>= (8 - oversampling);

  b6 = TemperatureCompensation() - 4000L;
  x1 = ((long)b2 * (b6 * b6)>>12)>>11;
  x2 = ((long)ac2 * b6)>>11;
  x3 = x1 + x2;
  b3 = (((((long)ac1)*4 + x3)<<oversampling) + 2)>>2;

  x1 = ((long)ac3 * b6)>>13;
  x2 = ((long)b1 * ((b6 * b6)>>12))>>16;
  x3 = ((x1 + x2) + 2)>>2;
  b4 = ((unsigned long)ac4 * (unsigned long)(x3 + 32768))>>15;
  b7 = ((unsigned long)PressureCompensation - b3) * (unsigned long)(50000UL>>oversampling);

  if (b7 < 0x80000000)
    p = (b7<<1)/b4;
  else
    p = (b7/b4)<<1;

  x1 = (p>>8) * (p>>8);
  x1 = (x1 * 3038)>>16;
  x2 = (-7357 * p)>>16;
  p += (x1 + x2 + 3791UL)>>4;

  return (float) p;
}

float BMP180::getAltitude(){
  return 44307.69396 * (1.0 - pow(getPressure()/sealevelPressure, 0.190284));
}


void BMP180::setSealevelPressure(float pressure){
  sealevelPressure = pressure;
}


int BMP180::read16b(unsigned char address){
	unsigned char data;

  Wire.beginTransmission(BMP180_ADDRESS);
  Wire.write(address);
  Wire.endTransmission();
  
  Wire.requestFrom(BMP180_ADDRESS, 2);
  while(Wire.available()<2);
  data = Wire.read();
  data <<= 8;
  data |= Wire.read();

  return (int) data;
}

char BMP180::read8b(unsigned char address){
  Wire.beginTransmission(BMP180_ADDRESS);
  Wire.write(address);
  Wire.endTransmission();
  
  Wire.requestFrom(BMP180_ADDRESS, 1);
  while(Wire.available());
  return Wire.read();
}

long BMP180::TemperatureCompensation(){
  long x1, x2;

  Wire.beginTransmission(BMP180_ADDRESS);
  Wire.write(CONTROL);
  Wire.write(TEMPCMD);
  Wire.endTransmission();
  delay(5);

  x1 = (((long)read16b(DATA) - (long)ac6)*(long)ac5) >> 15;
  x2 = ((long)mc << 11)/(x1 + md);

  return x1 + x2;
}
