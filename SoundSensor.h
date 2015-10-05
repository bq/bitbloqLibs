#ifndef SOUNDSENSOR_h
#define SOUNDSENSOR_h
#include "Arduino.h"

class SoundSensor
{
public:
	SoundSensor(int pinSensor);
	int readSoundSensor();
private:
	int _pinSensor;
};

#endif //SOUNDSENSOR_h