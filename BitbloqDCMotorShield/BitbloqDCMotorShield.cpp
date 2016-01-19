#include "Arduino.h"
#include "BitbloqDCMotorShield.h"

void DCMotorShield::init(){
	pinMode(PIN_MOTOR1DIR, OUTPUT);
	pinMode(PIN_MOTOR2DIR, OUTPUT);
	pinMode(PIN_MOTOR1PWM, OUTPUT);
	pinMode(PIN_MOTOR2PWM, OUTPUT);
	pinMode(PIN_MOTOR1SLEEP, OUTPUT);
	pinMode(PIN_MOTOR2SLEEP, OUTPUT);

	digitalWrite(PIN_MOTOR1SLEEP, LOW);  //Disable both motors
	digitalWrite(PIN_MOTOR2SLEEP, LOW);
}



void DCMotorShield::spinMotor(unsigned char motor, bool dir, unsigned char perc){
	if(motor == MOTOR1){
		if (dir != dirMotor1) {
			stopMotor(motor);
			digitalWrite(PIN_MOTOR1DIR, dir);
			dirMotor1 = dir;
		}
		analogWrite(PIN_MOTOR1PWM, byte(perc*2.55));
		digitalWrite(PIN_MOTOR1SLEEP, HIGH);
	} else {
		if (dir != dirMotor2) {
			stopMotor(motor);
			digitalWrite(PIN_MOTOR2DIR, dir);
			dirMotor2 = dir;
		}
		analogWrite(PIN_MOTOR2PWM, byte(perc*2.55));
		digitalWrite(PIN_MOTOR2SLEEP, HIGH);
	}
}

void DCMotorShield::stopMotor(unsigned char motor){
	if(motor == MOTOR1){
		digitalWrite(PIN_MOTOR1SLEEP, LOW);
		digitalWrite(PIN_MOTOR1PWM, LOW);
	} else {
		digitalWrite(PIN_MOTOR2SLEEP, LOW);
		digitalWrite(PIN_MOTOR2PWM, LOW);
	}
}



float DCMotorShield::getwheelgap(){
	return halfwheelgap * 2;
}

void DCMotorShield::setwheelgap(float gap){
	halfwheelgap = gap / 2;
}



void DCMotorShield::goForward(unsigned char perc){
	spinMotor(MOTOR1,CW,perc);
	spinMotor(MOTOR2,CCW,perc);
}

void DCMotorShield::goBackward(unsigned char perc){
	spinMotor(MOTOR1,CCW,perc);
	spinMotor(MOTOR2,CW,perc);
}

void DCMotorShield::turnLeft(unsigned char perc, float radio){
	unsigned char percLeft, percRight;
	bool dirLeft = CCW;
	float halfdifspeed;

	halfdifspeed = halfwheelgap / radio;

	percLeft = perc * (1 - halfdifspeed);
	percRight = perc * (1 + halfdifspeed);

	if (percRight > 100){
		percRight = 100;
		percLeft = percRight * (radio - halfwheelgap) / (radio + halfwheelgap);
	}
	if (percLeft < 0){
		percLeft = - percLeft;
		dirLeft = !dirLeft;
	}

	spinMotor(MOTOR1,CW,percRight);
	spinMotor(MOTOR2,dirLeft,percLeft);
}

void DCMotorShield::turnRight(unsigned char perc, float radio){
	unsigned char percLeft, percRight;
	bool dirRight = CW;
	float halfdifspeed;

	halfdifspeed = halfwheelgap / radio;

	percRight = perc * (1 - halfdifspeed);
	percLeft = perc * (1 + halfdifspeed);

	if (percLeft > 100){
		percLeft = 100;
		percLeft = percLeft * (radio - halfwheelgap) / (radio + halfwheelgap);
	}
	if (percRight < 0){
		percRight = - percRight;
		dirRight = !dirRight;
	}

	spinMotor(MOTOR1,dirRight,percRight);
	spinMotor(MOTOR2,CCW,percLeft);
}

void DCMotorShield::stop(){
	stopMotor(MOTOR1);
	stopMotor(MOTOR2);
}