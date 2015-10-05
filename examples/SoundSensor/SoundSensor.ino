#include <SoundSensor.h>

const int soundSensorPin = 9;  // SoundSensor module connected to digital pin 9
const int ledPin = 13;         // the number of the D13 led pin

int SensorState = 0;           // variable for reading the Sensor status
 
//Create SoundSensor object to control the Zum Sound Sensor module
SoundSensor mySensor(soundSensorPin);


void setup() {
  // initialize the led pin as an output:
  pinMode(ledPin, OUTPUT);      
  // initialize the Sensor pin as an input:
  pinMode(soundSensorPin, INPUT);  

}

void loop() {
  
//Read the state of the Sensor value:
  SensorState = mySensor.readSoundSensor();
 
  // Check if the Sensor is close.
  // If it is, the SensorState is HIGH:
  if (SensorState == HIGH) {     
    // turn led on:    
    digitalWrite(ledPin, HIGH);  
    delay(200);
  } 
  else {
    // turn led off:
    digitalWrite(ledPin, LOW); 
    delay(200);
  }

}
