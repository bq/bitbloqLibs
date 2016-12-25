#include "Arduino.h"
#include "BitbloqMBot.h"
#include "BitbloqMeRGBLed.h"

#include <BitbloqUS.h>
#include <BitbloqDCMotor.h>


MBot::MBot():
        buzzerPin(8),
        lightSensorPin(A6),
        buttonPin(A7),
        usSensor(NULL),
        usTriggerPin(A2),
        usEchoPin(A3),
        rightLineFollowerPin(9),
        leftLineFollowerPin(10),
        leftDCMotorDir(6),
        leftDCMotorPWM(7),
        rightDCMotorDir(6),
        rightDCMotorPWM(7),
        rgbLEDPin(13)
{
	boardLeds = new BitbloqMeRGBLed(rgbLEDPin,24);
    leftDCMotor = new BitbloqDCMotor(leftDCMotorDir,leftDCMotorPWM);
    rightDCMotor = new BitbloqDCMotor(rightDCMotorDir,rightDCMotorPWM);
}

MBot::~MBot(){
	
	//check that all of them are not NULL pointers, delete and set to NULL
	if (boardLeds != NULL){
		delete boardLeds;
		boardLeds = NULL;
	}
	
    if(usSensor!=NULL){
        delete usSensor;
        usSensor=NULL;
    }
    
    if(leftDCMotor!=NULL){
        delete leftDCMotor;
        leftDCMotor=NULL;
    }
    
    if(rightDCMotor!=NULL){
        delete rightDCMotor;
        rightDCMotor=NULL;
    }
}

void MBot::setup(){
    //sensors
    pinMode(lightSensorPin,INPUT);
    pinMode(buttonPin,INPUT);
    pinMode(leftLineFollowerPin,INPUT);
    pinMode(rightLineFollowerPin, OUTPUT);
    
    //initialize usSensor
    usSensor = new US(usTriggerPin,usEchoPin);
    
    
    //actuators
    pinMode(buzzerPin,OUTPUT);
    
    //dc motors setup
    leftDCMotor->setup();
    rightDCMotor->setup();
}

int MBot::readLeftLineFollowerSensor() const{
    return digitalRead(leftLineFollowerPin);
}

int MBot::readRightLineFollowerSensor() const {
    return digitalRead(rightLineFollowerPin);
}

void MBot::setLed(int led, int red, int green, int blue){
	boardLeds->setColor(led, red, green, blue);
	boardLeds->show();
}

void MBot::playTone(int note, int beat){
	tone(buzzerPin, note, beat);
}

int MBot::readDistance(){
	return usSensor->read(); //in centimeters
}

int MBot::readButtonStatus() const{
	return analogRead(A7);
}

bool MBot::isButtonPushed() const{
    if (readButtonStatus() == 0) return true;
    else return false;
}
    

int MBot::readLightSensor() const{
	return analogRead(lightSensorPin);
}

void MBot::move(int direction, int speed){
	int leftSpeed = 0;
	int rightSpeed = 0;
	if(direction == 1){
		leftSpeed = -speed; //forward
		rightSpeed = speed;
		
	}else if(direction == 2){
		leftSpeed = speed;
		rightSpeed = -speed;
		
	}else if(direction == 3){
		leftSpeed = -speed; //right
		rightSpeed = -speed;
	}else if(direction == 4){
		
		leftSpeed = speed; //left
		rightSpeed = speed;
	}
	
    leftDCMotor->setSpeed(leftSpeed);
    rightDCMotor->setSpeed(rightSpeed);
}

void MBot::setRightMotorSpeed(int speed){
    rightDCMotor->setSpeed(speed);
}

void MBot::setLeftMotorSpeed(int speed){
    leftDCMotor->setSpeed(speed);
}

