#include "Arduino.h"
#include "BitbloqMRanger.h"
#include <MeAuriga.h>

// volatile MeEncoderOnBoard* encoder1;
// volatile MeEncoderOnBoard* encoder2;

// volatile void isrProcessEncoder(MeEncoderOnBoard* encoder){
// 	if(digitalRead(encoder->getPortB()) == 0){
//             encoder->pulsePosMinus();
//       }else{
//             encoder->pulsePosPlus();
//       }
// }

// void isrProcessEncoder1(){
// 	isrProcessEncoder(encoder1);
// }
// void isrProcessEncoder2(){
// 	isrProcessEncoder(encoder2);	
// }



MRanger::MRanger(MeEncoderOnBoard* _enc1, MeEncoderOnBoard* _enc2){
	enc1 = _enc1;
	enc2 = _enc2;
	boardLeds = new MeRGBLed(0,12);
	lightSensor1 = new MeLightSensor(11);
	lightSensor2 = new MeLightSensor(12);
	enc1 = new MeEncoderOnBoard(SLOT1);
	enc2 = new MeEncoderOnBoard(SLOT2);
	attachInterrupt(enc1->getIntNum(),isrProcessEncoder1, RISING);
	attachInterrupt(enc1->getIntNum(),isrProcessEncoder2, RISING);
}

MRanger::~MRanger(){
	
	//check that all of them are not NULL pointers, delete and set to NULL
	if (boardLeds != NULL){
		delete boardLeds;
		boardLeds = NULL;
	}

	if (lightSensor1 != NULL){
		delete lightSensor1;
		lightSensor1 = NULL;
	}

	if (lightSensor2 != NULL){
		delete lightSensor2;
		lightSensor2 = NULL;
	}

	if(enc1!=NULL){ 
		delete enc1;
		enc1=NULL;
	}

	if(enc2!=NULL){ 
		delete enc1;
		enc2=NULL;
	}

}

void MRanger::init(){

}

void MRanger::setLed(int led, int red, int green, int blue){
	boardLeds->setpin(44);
	boardLeds->setColor(led, red, green, blue);
	boardLeds->show();
}


int MRanger::getDistance(int port){
	MeUltrasonicSensor ultrasonicSensor(port);
	return ultrasonicSensor.distanceCm();
}

int MRanger::getLineFollower(int port){
	MeLineFollower lineFollower(port);
	return lineFollower.readSensors();
}


int MRanger::getLightSensor(int numSensor){
	if(numSensor == 1){
		return lightSensor1->read();
	}else{
		return lightSensor2->read();
	}
	
}



void MRanger::move(int direction, int speed){
	int leftSpeed = 0;
	int rightSpeed = 0;
	if(direction == 1){
		leftSpeed = -speed; //adelante
		rightSpeed = speed;
		
	}else if(direction == 2){
		leftSpeed = speed;
		rightSpeed = -speed;
		
	}else if(direction == 3){
		leftSpeed = -speed; //derecha
		rightSpeed = -speed;
	}else if(direction == 4){
		
		leftSpeed = speed; //izquierda
		rightSpeed = speed;
	}
	encoder1.setTarPWM(leftSpeed);
    encoder2.setTarPWM(rightSpeed);
}
