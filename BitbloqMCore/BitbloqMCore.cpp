#include "Arduino.h"
#include "BitbloqMCore.h"
#include "BitbloqMeRGBLed.h"

//setting ports value
const Port BitbloqMCore::ports[5] = {Port(-1,-1),Port(11,12),Port(9,10),Port(A2,A3),Port(A0,A1)};

BitbloqMCore::BitbloqMCore():
        buzzerPin(8),
        lightSensorPin(A6),
        buttonPin(A7),
        DCMotor2Dir(4),
        DCMotor2PWM(5),
        DCMotor1Dir(7),
        DCMotor1PWM(6),
        rgbLEDPin(2),
        IRTransmitter(3),
        IRReceiver(2)
{
    
    boardLeds = new BitbloqMeRGBLed(rgbLEDPin,2);
}


BitbloqMCore::~BitbloqMCore(){
	
	//check that all of them are not NULL pointers, delete and set to NULL
	if (boardLeds != NULL){
		delete boardLeds;
		boardLeds = NULL;
	}
}

void BitbloqMCore::setup(){
    //sensors
    pinMode(lightSensorPin,INPUT);
    pinMode(buttonPin,INPUT);
    
    //IR Comms
    pinMode(IRTransmitter,OUTPUT);
    pinMode(IRReceiver,INPUT);
    
    //actuators
    pinMode(buzzerPin,OUTPUT);
}

void BitbloqMCore::setLed(int led, int red, int green, int blue){
	boardLeds->setColor(led, red, green, blue);
	boardLeds->show();
}

void BitbloqMCore::playTone(int note, int beat){
	tone(buzzerPin, note, beat);
}


int BitbloqMCore::readButtonStatus() const{
	return analogRead(A7);
}

bool BitbloqMCore::isButtonPushed() const{
    if (readButtonStatus() == 0) return true;
    else return false;
}
    
int BitbloqMCore::readLightSensor() const{
	return analogRead(lightSensorPin);
}
