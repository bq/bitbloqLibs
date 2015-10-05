#include "CrashSensor.h"
//****** CrashSensor ******//
CrashSensor::CrashSensor(int pinSensor){
  _pinSensor = pinSensor;
}

int CrashSensor::readCrashSensor(){
  return digitalRead(_pinSensor);
}