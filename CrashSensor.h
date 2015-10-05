#ifndef CRASHSENSOR_h
#define CRASHSENSOR_h
#include "Arduino.h"

class CrashSensor
{
public:
	CrashSensor(int pinSensor);
	int readCrashSensor();
private:
	int _pinSensor;
};

#endif //CRASHSENSOR_h