#include "Arduino.h"
#include "BitbloqAuriga.h"
#include "BitbloqMeRGBLed.h"


BitbloqAuriga::BitbloqAuriga():
        powerSensorPin(A4),
        lightSensor1Pin(A3),
        lightSensor2Pin(A2),
        soundSensorPin(A1),
        temperatureSensorPin(A0),
        RGBLedsPin(D44),
        buzzerPin(D45),
        ports({Port(0,0),Port(4,5),Port(2,3),Port(6,7),Port(8,9),Port(17,16),
            Port(A15,A10),Port(A14,A9),Port(A13,A8),Port(A12,A7),Port(A11,A6)})
{
    boardLeds = new BitbloqMeRGBLed(rgbLEDPin,12);
}

BitbloqAuriga::~BitbloqAuriga(){	
	//check that all of them are not NULL pointers, delete and set to NULL
	if (boardLeds != NULL){
		delete boardLeds;
		boardLeds = NULL;
	}
}

void BitbloqAuriga::setup(){
    
    pinMode(powerSensorPin,INPUT);
    pinMode(lightSensor1Pin,INPUT);
    pinMode(lightSensor2Pin,INPUT);
    pinMode(soundSensorPin,INPUT);
    pinMode(temperatureSensorPin,INPUT);
    pinMOde(buzzerPin,OUTPUT);
}

int BitbloqAuriga::readPowerStatus(){
    return analogRead(powerSensorPin);
}

void BitbloqAuriga::setLed(int led, int red, int green, int blue){
	boardLeds->setColor(led, red, green, blue);
	boardLeds->show();
}

void BitbloqAuriga::playTone(int note, int beat){
	tone(buzzerPin, note, beat);
}

int BitbloqAuriga::readTemperature(){
        //TODO
}

int BitbloqAuriga::readSoundLevel(){
    //TODO
}
    
int BitbloqAuriga::readLightSensor(int number) const{
    if (number==1)
        return analogRead(lightSensorPin1);
    if (number==2)
        return analogRead(lightSensorPin2);
        
    return 0;
}
