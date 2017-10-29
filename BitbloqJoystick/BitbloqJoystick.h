#ifndef JOYSTICK_H
#define JOYSTICK_H
#include "Arduino.h"

class Joystick
{
public:
	Joystick(float pinX, float pinY, float pinButton);
	float * read();
	float readPinX();
	float readPinY();
	float readPinButton();
private:
	float _pinX;
	float _pinY;
	float _pinButton;
};

namespace Bitbloq{

class Joystick
{
public:
	Joystick(int pinX, int pinY, int pinButton);
	void setup();
	int * read();
	int readX() const;
	int readY() const;
	int readButton() const;
private:
	uint8_t _pinX;
	uint8_t _pinY;
	uint8_t _pinButton;
	
	int readings[3];
};

} //end namespace

#endif //JOYSTICK_H
