#include "Joystick.h"
//****** JOYSTICK ******//
Joystick::Joystick(int pinX, int pinY, int pinButton){
  _pinX = pinX;
  _pinY = pinY;
  _pinButton = pinButton;
}
int * Joystick::read(){
  int * position = (int*)malloc(3*sizeof(int));
  position[0] = Joystick::readPinX();
  position[1] = Joystick::readPinY();
  position[2] = Joystick::readPinButton();
  return position;
}
int Joystick::readPinX(){
  return analogRead(_pinX);
}
int Joystick::readPinY(){
  return analogRead(_pinY);
}
int Joystick::readPinButton(){
  return digitalRead(_pinButton);
}