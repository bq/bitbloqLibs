#ifndef BQBMP180_H
#define BQBMP180_H


#define BMP180_ADDRESS 0x77
#define oversampling 3

#define CONTROL 0xF4
#define DATA 0xF6
#define TEMPCMD 0x2E
#define PRESCMD 0x34


class BMP180{
  public:

    void init();

    float getTemperature();
    float getPressure();
    float getAltitude();

    void setSealevelPressure(float pressure);

  private:
    int ac1, ac2, ac3, b1, b2, mb, mc, md;
    unsigned int ac4, ac5, ac6;
    float sealevelPressure;

    int read16b(unsigned char address);
    char read8b(unsigned char address);
    long TemperatureCompensation();
};

#endif