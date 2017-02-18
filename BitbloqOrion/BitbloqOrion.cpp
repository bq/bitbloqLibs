#include "Arduino.h"
#include "BitbloqOrion.h"

//setting Orion ports values
const Port BitbloqOrion::ports[11] = {Port(0,0),Port(10,11),Port(9,3),Port(13,12),Port(2,8),Port(0,1),Port(A3,A2),Port(A1,A6),Port(A0,A7)};

BitbloqOrion::BitbloqOrion():
        buzzerPin(8),
        DCMotor2Dir(4),
        DCMotor2PWM(5),
        DCMotor1Dir(7),
        DCMotor1PWM(6),
{
    //Nothing here
}
 

BitbloqOrion::~BitbloqOrion(){
	//Nothing here
}

void BitbloqOrion::setup(){    
    //actuators
    pinMode(buzzerPin,OUTPUT);
}


void BitbloqOrion::playTone(int note, int beat){
	tone(buzzerPin, note, beat);
}
