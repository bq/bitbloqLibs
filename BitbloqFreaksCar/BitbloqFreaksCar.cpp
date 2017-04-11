/*
 * BitbloqFreaksCar.cpp
 *
 * Copyright 2017 Alberto Valero <alberto.valero@bq.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 *
 *
 */

#include "Arduino.h"
#include "BitbloqFreaksCar.h"



BitbloqFreaksCar::BitbloqFreaksCar():
        usSensor(NULL),
        leftDCMotor(NULL),
        rightDCMotor(NULL),
        buzzerPin(-1),
        usTriggerPin(-1),
        usEchoPin(-1),
        DCMotor1Dir(-1),
        DCMotor1PWM(-1),
        DCMotor2Dir(-1),
        DCMotor2PWM(-1),
        endStopPin(-1),
        irArrayPin{-1,-1,-1,-1}
{
	usSensor = new BitbloqUSSenor(usTriggerPin,usEchoPin);
    leftDCMotor = new BitbloqDCMotor(DCMotor2Dir,DCMotor2PWM);
    rightDCMotor = new BitbloqDCMotor(DCMotor1Dir,DCMotor1PWM);
}


BitbloqFreaksCar::~BitbloqFreaksCar(){
	
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

void BitbloqFreaksCar::setup(){
    BitbloqMCore::setup();

	//IR Pins
	for (int i = 0; i<4; i++){
		pinMode(irPinArray[i],INPUT);
	}
	
	//Buzzer
	pinMode(buzzerPin,OUTPUT);

	//US Sensor setup
	usSensor->setup();
        
    //dc motors setup
    leftDCMotor->setup();
    rightDCMotor->setup();
    
    //endstop
    pinMode(endStopPin,INPUT);

}


int BitbloqFreaksCar::readUSMeasuredDistanceCM() const{
	return (usSensor != NULL ? usSensor->readDistanceInCM(): - 1 ); //in centimeters
}

int BitbloqFreaksCar::readUSMeasuredDistanceIN() const{
	return (usSensor != NULL ? usSensor->readDistanceInInches() : -1); //in inches
}
    
void BitbloqFreaksCar::move(int direction, int speed){
	int leftSpeed = 0;
	int rightSpeed = 0;
	if(direction == 1){
		leftSpeed = speed; //forward 
		rightSpeed = -speed;
		
	}else if(direction == 2){//backward
		leftSpeed = -speed;
		rightSpeed = speed;
		
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

void BitbloqFreaksCar::setRightMotorSpeed(int speed){
    rightDCMotor->setSpeed(speed);
}

void BitbloqFreaksCar::setLeftMotorSpeed(int speed){
    leftDCMotor->setSpeed(speed);
}

byte BitbloqFreaksCar::readIR(int index){
	if (index >=0 && index <4)
		return digitalRead(irArrayPin[index]);
	else
		return -1;
}

