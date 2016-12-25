#include "Arduino.h"
#include "BitbloqMBot.h"
#include "BitbloqMeRGBLed.h"

#include <BitbloqUS.h>
#include <BitbloqDCMotor.h>


MBot::MBot(int lineFollowerPort, int USPort):
        buzzerPin(8),
        lightSensorPin(A6),
        buttonPin(A7),
        usSensor(NULL),
        leftDCMotorDir(4),
        leftDCMotorPWM(5),
        rightDCMotorDir(7),
        rightDCMotorPWM(6),
        rgbLEDPin(13),
        IRTransmitter(3),
        IRReceiver(2)
{
    //initialize ports stuct
    portsInit();
    
    rightLineFollowerPin = ports[lineFollowerPort].s1;
    leftLineFollowerPin = ports[lineFollowerPort].s2;
	
    usTriggerPin = ports[USPort].s2; /// this is weird. There are two components, but only one signal.
    usEchoPin = ports[USPort].s2;
    
    boardLeds = new BitbloqMeRGBLed(rgbLEDPin,24);
    leftDCMotor = new BitbloqDCMotor(leftDCMotorDir,leftDCMotorPWM);
    rightDCMotor = new BitbloqDCMotor(rightDCMotorDir,rightDCMotorPWM);
}

void MBot::portsInit(){
    ports[0].s1 = 0;
    ports[0].s2 = 0;
    
    ports[1].s1 = 11;
    ports[1].s2 = 12;
    
    ports[2].s1 = 9;
    ports[2].s2 = 10;
    
    ports[3].s1 = A2;
    ports[3].s2 = A3;
    
    ports[4].s1 = A0;
    ports[4].s2 = A1;
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
    pinMode(rightLineFollowerPin, INPUT);
    
    //initialize usSensor
    usSensor = new US(usTriggerPin,usEchoPin);
    
    
    //IR Comms
    pinMode(IRTransmitter,OUTPUT);
    pinMode(IRReceiver,INPUT);
    
    //actuators
    pinMode(buzzerPin,OUTPUT);
    
    //dc motors setup
    leftDCMotor->setup();
    rightDCMotor->setup();
}

int MBot::readLeftLineFollowerSensor() const{
    return digitalRead(leftLineFollowerPin);
}

int MBot::readRightLineFollowerSensor() const{
    return digitalRead(rightLineFollowerPin);
}

void MBot::setLed(int led, int red, int green, int blue){
	boardLeds->setColor(led, red, green, blue);
	boardLeds->show();
}

void MBot::playTone(int note, int beat){
	tone(buzzerPin, note, beat);
}

int MBot::readUSMeasuredDistanceCM() const{
	return usSensor->read(); //in centimeters
}

int MBot::readUSMeasuredDistanceIN() const{
	return 0,393701*usSensor->read(); //in inches
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

