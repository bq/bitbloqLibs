#include "BitbloqJoystick.h"
//****** JOYSTICK ******//
Joystick::Joystick(float pinX, float pinY, float pinButton){
  _pinX = pinX;
  _pinY = pinY;
  _pinButton = pinButton;
}
float * Joystick::read(){
  float * position = (float*)malloc(3*sizeof(float));
  position[0] = Joystick::readPinX();
  position[1] = Joystick::readPinY();
  position[2] = Joystick::readPinButton();
  free (position);
  return position;
}
float Joystick::readPinX(){
  return analogRead(_pinX);
}
float Joystick::readPinY(){
  return analogRead(_pinY);
}
float Joystick::readPinButton(){
  return digitalRead(_pinButton);
}



/*************************************************************************/


namespace Bitbloq{

Joystick::Joystick(int pinX, int pinY, int pinButton){
  _pinX = pinX;
  _pinY = pinY;
  _pinButton = pinButton;
}

void Joystick::setup(){
	pinMode(_pinX,INPUT);
	pinMode(_pinY,INPUT);
	pinMode(_pinButton,INPUT);
}


int * Joystick::read(){
  readings[0] = readX();
  readings[1] = readY();
  readings[2] = readButton();
  return readings;
}

int Joystick::readX() const{
  return analogRead(_pinX);
}
int Joystick::readY() const{
  return analogRead(_pinY);
}
int Joystick::readButton() const{
  return digitalRead(_pinButton);
}

}//end namespace
