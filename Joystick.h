#ifndef JOYSTICK_H
#define JOYSTICK_H
#include "Arduino.h"

class Joystick
{
public:
	Joystick(int pinX, int pinY, int pinButton);
	int * read();
	int readPinX();
	int readPinY();
	int readPinButton();
private:
	int _pinX;
	int _pinY;
	int _pinButton;
};

#endif //JOYSTICK_H