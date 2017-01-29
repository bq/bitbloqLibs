#include "Arduino.h"
#include "BitbloqMBotRanger.h"
#include "BitbloqMeRGBLed.h"

#include <BitbloqUS.h>
//#include <BitbloqDCMotor.h>


BitbloqMBotRanger::BitbloqMBotRanger(int lineFollowerPort, int USPort):
        BitbloqAuriga(),
        usSensor(NULL)
{
    rightLineFollowerPin = getPinFromPort(lineFollowerPort,1);
    leftLineFollowerPin = getPinFromPort(lineFollowerPort,2);
	
    usTriggerPin = getPinFromPort(USPort,1); /// this is weird. There are two components, but only one signal.
    usEchoPin = getPinFromPort(USPort,1);
        
    //leftDCMotor = new BitbloqDCMotor(leftDCMotorDir,leftDCMotorPWM);
    //rightDCMotor = new BitbloqDCMotor(rightDCMotorDir,rightDCMotorPWM);
}

BitbloqMBotRanger::BitbloqMBotRanger():
        BitbloqAuriga(),
        usSensor(NULL){
    //TODO
}


BitbloqMBotRanger::~BitbloqMBotRanger(){
	
	//check that all of them are not NULL pointers, delete and set to NULL
	
    if(usSensor!=NULL){
        delete usSensor;
        usSensor=NULL;
    }
    
    //if(leftDCMotor!=NULL){
        //delete leftDCMotor;
        //leftDCMotor=NULL;
    //}
    
//    if(rightDCMotor!=NULL){
//        delete rightDCMotor;
//        rightDCMotor=NULL;
//    }
}


void BitbloqMBotRanger::setLineFollowerPort(int port){
    rightLineFollowerPin = getPinFromPort(port,1);
    leftLineFollowerPin = getPinFromPort(port,2);
}

void BitbloqMBotRanger::setUSPort(int port){
    usTriggerPin = getPinFromPort(port,2); /// this is weird. There are two components, but only one signal.
    usEchoPin = getPinFromPort(port,2);
}



void BitbloqMBotRanger::setup(){
    BitbloqAuriga::setup();

    //sensors
    pinMode(leftLineFollowerPin,INPUT);
    pinMode(rightLineFollowerPin, INPUT);
    
    //initialize usSensor
    usSensor = new US(usTriggerPin,usEchoPin);
        
    //dc motors setup
    //leftDCMotor->setup();
    //rightDCMotor->setup();
}


int BitbloqMBotRanger::readRightLightSensor() const{
    readLightSensor(rightLightSensor);
}

int BitbloqMBotRanger::readLeftLightSensor() const{
    readLightSensor(leftLightSensor);
}


int BitbloqMBotRanger::readLeftLineFollowerSensor() const{
    return digitalRead(leftLineFollowerPin);
}

int BitbloqMBotRanger::readRightLineFollowerSensor() const{
    return digitalRead(rightLineFollowerPin);
}

int BitbloqMBotRanger::readUSMeasuredDistanceCM() const{
	return usSensor->read(); //in centimeters
}

int BitbloqMBotRanger::readUSMeasuredDistanceIN() const{
	return 0,393701*usSensor->read(); //in inches
}
    
void BitbloqMBotRanger::move(int direction, int speed){
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
/*	
    leftDCMotor->setSpeed(leftSpeed);
    rightDCMotor->setSpeed(rightSpeed);
*/
}

void BitbloqMBotRanger::setRightMotorSpeed(int speed){
//    rightDCMotor->setSpeed(speed);
}

void BitbloqMBotRanger::setLeftMotorSpeed(int speed){
//    leftDCMotor->setSpeed(speed);
}

