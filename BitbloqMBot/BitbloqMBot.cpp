#include "Arduino.h"
#include "BitbloqMBot.h"

#include "MeMCore.h"


MBot::MBot(){
	boardLeds = new MeRGBLed(7);
	buzzer = new MeBuzzer();
	lightSensor = new MeLightSensor(6);
	leftMotor = new MeDCMotor(9);
	rightMotor = new MeDCMotor(10);
}

MBot::~MBot(){
	if (boardLeds != NULL){
		delete boardLeds;
		boardLeds = NULL;
	}
	if (buzzer != NULL){
		delete buzzer;
		buzzer = NULL;
	}
	if (ultrasonicSensor != NULL){
		delete ultrasonicSensor;
		ultrasonicSensor = NULL;
	}
	if (lightSensor != NULL){
		delete lightSensor;
		lightSensor = NULL;
	}
	if (lineFollower != NULL){
		delete lineFollower;
		lineFollower = NULL;
	}
}

void MBot::init(){

}

void MBot::setLed(int led, int red, int green, int blue){
    boardLeds->setColor(led, red, green, blue);
    boardLeds->show();
}

void MBot::tone(int note, int beat){
    buzzer->tone(note, beat);
}

int MBot::getDistance(int port){
	ultrasonicSensor = new MeUltrasonicSensor(port);
	return ultrasonicSensor->distanceCm();
}

int MBot::getLineFollower(int port){
	lineFollower = new MeLineFollower(port);
	return lineFollower->readSensors();
}

int MBot::getButtonStatus(){
	return analogRead(A7);
}

int MBot::getLightSensor(){
	return lightSensor->read();
}

void MBot::move(int direction, int speed){
	int leftSpeed = 0;
	int rightSpeed = 0;
	if(direction == 1){
		leftSpeed = speed;
		rightSpeed = speed;
	}else if(direction == 2){
		leftSpeed = -speed;
		rightSpeed = -speed;
	}else if(direction == 3){
		leftSpeed = -speed;
		rightSpeed = speed;
	}else if(direction == 4){
		leftSpeed = speed;
		rightSpeed = -speed;
	}
	leftMotor->run(leftSpeed);
	rightMotor->run(rightSpeed);
}
