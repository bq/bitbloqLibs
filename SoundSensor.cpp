#include "SoundSensor.h"
//****** SoundSensor ******//
SoundSensor::SoundSensor(int pinSensor){
  _pinSensor = pinSensor;
}

int SoundSensor::readSoundSensor(){
  return digitalRead(_pinSensor);
}