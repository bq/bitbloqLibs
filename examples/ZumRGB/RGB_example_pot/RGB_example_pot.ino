#include <ZumRGB.h>

const int redPin = 9;      // RGB red LED connected to digital pin 9
const int greenPin = 10;   // RGB green LED connected to digital pin 10
const int bluePin = 11;    // RGB blue LED connected to digital pin 11

const int potRPin = A0; 
const int potGPin = A1; 
const int potBPin = A2; 

int redValue = 0;          // value to write to the red LED
int greenValue = 0;        // value to write to the green LED
int blueValue = 0;         // value to write to the blue LED


 
//Create ZumRGB object to control the Zum RGB LED module
ZumRGB myRGB(redPin, greenPin, bluePin);

void setup() {
  
  // set the digital pins as outputs
  pinMode(redPin,OUTPUT);
  pinMode(greenPin,OUTPUT);
  pinMode(bluePin,OUTPUT);
  
  myRGB.setRGBWait(2); //2ms insted of 10ms

}

void loop() {
  
  int potValue = 0;

  //Read sensors and map it:
  potValue = analogRead(potRPin);  
  redValue = map(potValue, 0, 1023, 0, 255);

  potValue = analogRead(potGPin);
  greenValue = map(potValue, 0, 1023, 0, 255);

  potValue = analogRead(potBPin);
  blueValue = map(potValue, 0, 1023, 0, 255);    
  
 //Set values to the LED:
  myRGB.setRGBcolor(redValue,greenValue,blueValue);
  delay(10);   

}
