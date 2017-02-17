/*
 * BitbloqMBot.cpp
 *
 * Copyright 2016 Alberto Valero <alberto.valero@bq.com>
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
#include "BitbloqMBot.h"
#include <BitbloqUS.h>
#include <BitbloqDCMotor.h>


BitbloqMBot::BitbloqMBot(int lineFollowerPort, int USPort):
        BitbloqMCore(),
        usSensor(NULL)
{
    rightLineFollowerPin = getPinFromPort(lineFollowerPort,1);
    leftLineFollowerPin = getPinFromPort(lineFollowerPort,2);
	
    usTriggerPin = getPinFromPort(USPort,2); /// this is weird. There are two components, but only one signal.
    usEchoPin = getPinFromPort(USPort,2);
    
    leftDCMotor = new BitbloqDCMotor(DCMotor2Dir,DCMotor2PWM);
    rightDCMotor = new BitbloqDCMotor(DCMotor1Dir,DCMotor1PWM);
}

BitbloqMBot::BitbloqMBot():
        BitbloqMCore(),
        usSensor(NULL)
{
    leftDCMotor = new BitbloqDCMotor(DCMotor2Dir,DCMotor2PWM);
    rightDCMotor = new BitbloqDCMotor(DCMotor1Dir,DCMotor1PWM);
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

void BitbloqMBot::setLineFollowerPort(int port){
    rightLineFollowerPin = getPinFromPort(port,1);
    leftLineFollowerPin = getPinFromPort(port,2);
}

void BitbloqMBot::setUSPort(int port){
    usTriggerPin = getPinFromPort(port,2); /// this is weird. There are two components, but only one signal.
    usEchoPin = getPinFromPort(port,2);
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

int BitbloqMBot::readLineFollowerSensor() const{
    if(digitalRead(rightLineFollowerPin) && digitalRead(leftLineFollowerPin)){
        return 3;
    }else if(digitalRead(rightLineFollowerPin)){
        return 2;
    }else if(digitalRead(leftLineFollowerPin)){
        return 1;
    }else{
        return 0;
    }
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

