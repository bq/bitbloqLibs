#include "Encoder.h"


Encoder::Encoder () {
	Encoder::sum = 0;

	Encoder::encoderValue = 0;
	Encoder::lastEncoded = 3;


	Encoder::saPin = 2;
	Encoder::sbPin = 3;
	Encoder::kPin = 4;

	pinMode(Encoder::saPin, INPUT); 
	pinMode(Encoder::sbPin, INPUT);

	pinMode(Encoder::kPin, INPUT);


	digitalWrite(Encoder::saPin, HIGH); //turn pullup resistor on
	digitalWrite(Encoder::sbPin, HIGH); //turn pullup resistor on

	digitalWrite(Encoder::kPin, HIGH); //turn pullup resistor on

	attachInterrupt(0, trial, CHANGE);
	attachInterrupt(1, trial, CHANGE);

}

// Encoder::Encoder (int saPin, int sbPin, int kPin) {
// 	Encoder::sum = 0;
// 	Encoder::encoderValue = 0;
// 	Encoder::lastEncoded = 0;


// 	Encoder::saPin = saPin;
// 	Encoder::sbPin = sbPin;
// 	Encoder::kPin = kPin;

// 	pinMode(Encoder::saPin, INPUT); 
// 	pinMode(Encoder::sbPin, INPUT);

// 	pinMode(kPin, INPUT);


// 	digitalWrite(Encoder::saPin, HIGH); //turn pullup resistor on
// 	digitalWrite(Encoder::sbPin, HIGH); //turn pullup resistor on

// 	digitalWrite(kPin, HIGH); //turn pullup resistor on

// 	attachInterrupt(0, trial, CHANGE); 
// 	attachInterrupt(1, trial, CHANGE);
// }

long Encoder::read(){
	return Encoder::encoderValue;
}


void Encoder::updateEncoder(){
  // Serial.print(Encoder::encoderValue);
  int MSB = digitalRead(Encoder::saPin); //MSB = most significant bit
  int LSB = digitalRead(Encoder::sbPin); //LSB = least significant bit
  int encoded = (MSB << 1) |LSB; //converting the 2 pin value to single number
  Encoder::sum  = (Encoder::lastEncoded << 2) | encoded; //adding it to the previous encoded value  
  
  if(sum == 0b1101 || sum == 0b0100 || sum == 0b0010 || sum == 0b1011) Encoder::encoderValue ++;
  if(sum == 0b1110 || sum == 0b0111 || sum == 0b0001 || sum == 0b1000) Encoder::encoderValue --;
  Encoder::lastEncoded = encoded; //store this value for next time
  // Serial.print(" ");
  // Serial.print(Encoder::encoderValue);
  // Serial.print(" ->");
  // Serial.println(sum);

}

void trial(){
	Encoder a; 
	a.updateEncoder();
}