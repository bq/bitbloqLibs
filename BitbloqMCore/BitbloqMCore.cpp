#include "Arduino.h"
#include "BitbloqMCore.h"
#include "BitbloqMeRGBLed.h"


BitbloqMCore::BitbloqMCore():
        buzzerPin(8),
        lightSensorPin(A6),
        buttonPin(A7),
        leftDCMotorDir(4),
        leftDCMotorPWM(5),
        rightDCMotorDir(7),
        rightDCMotorPWM(6),
        rgbLEDPin(2),
        IRTransmitter(3),
        IRReceiver(2),
        ports({Port(0,0),Port(11,12),Port(9,10),Port(A2,A3),Port(A0,A1)})
{
    //initialize ports struct
   // portsInit();
    
    boardLeds = new BitbloqMeRGBLed(rgbLEDPin,2);
}

//~ void BitbloqMCore::portsInit(){
    //~ ports[0].s1 = 0;
    //~ ports[0].s2 = 0;
    
    //~ ports[1].s1 = 11;
    //~ ports[1].s2 = 12;
    
    //~ ports[2].s1 = 9;
    //~ ports[2].s2 = 10;
    
    //~ ports[3].s1 = A2;
    //~ ports[3].s2 = A3;
    
    //~ ports[4].s1 = A0;
    //~ ports[4].s2 = A1;
//~ }
    
    

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
