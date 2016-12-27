#include "Arduino.h"
#include "BitbloqMBot.h"
#include "BitbloqMeRGBLed.h"

#include <BitbloqUS.h>
#include <BitbloqDCMotor.h>


BitbloqMBot::BitbloqMBot(int lineFollowerPort, int USPort):
        BitbloqMCore(),
        usSensor(NULL)
{
    rightLineFollowerPin = ports[lineFollowerPort].s1;
    leftLineFollowerPin = ports[lineFollowerPort].s2;
	
    usTriggerPin = ports[USPort].s2; /// this is weird. There are two components, but only one signal.
    usEchoPin = ports[USPort].s2;
    
    leftDCMotor = new BitbloqDCMotor(leftDCMotorDir,leftDCMotorPWM);
    rightDCMotor = new BitbloqDCMotor(rightDCMotorDir,rightDCMotorPWM);
}


BitbloqMBot::~BitbloqMBot(){
	
	//check that all of them are not NULL pointers, delete and set to NULL
	
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

void BitbloqMBot::setup(){
    BitbloqMCore::setup();

    //sensors
    pinMode(leftLineFollowerPin,INPUT);
    pinMode(rightLineFollowerPin, INPUT);
    
    //initialize usSensor
    usSensor = new US(usTriggerPin,usEchoPin);
        
    //dc motors setup
    leftDCMotor->setup();
    rightDCMotor->setup();
}

int BitbloqMBot::readLeftLineFollowerSensor() const{
    return digitalRead(leftLineFollowerPin);
}

int BitbloqMBot::readRightLineFollowerSensor() const{
    return digitalRead(rightLineFollowerPin);
}

int BitbloqMBot::readUSMeasuredDistanceCM() const{
	return usSensor->read(); //in centimeters
}

int BitbloqMBot::readUSMeasuredDistanceIN() const{
	return 0,393701*usSensor->read(); //in inches
}
    
void BitbloqMBot::move(int direction, int speed){
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

void BitbloqMBot::setRightMotorSpeed(int speed){
    rightDCMotor->setSpeed(speed);
}

void BitbloqMBot::setLeftMotorSpeed(int speed){
    leftDCMotor->setSpeed(speed);
}

