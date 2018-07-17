#include <ArduinoEventsLib.h>


#include <BQZUMJunior.h>
#include <BQZUMJuniorPorts.h>


Heap heap;

BQ::ZUMJunior zumJunior;


const uint8_t button1Pin = BQ::ZUMJunior::ports[1][0];
const uint8_t button2Pin = BQ::ZUMJunior::ports[2][0];
const uint8_t ledDoble1WhitePin = BQ::ZUMJunior::ports[3][0];
const uint8_t ledDoble1ColorPin = BQ::ZUMJunior::ports[3][1];
const uint8_t ledDoble2WhitePin = BQ::ZUMJunior::ports[4][0];
const uint8_t ledDoble2ColorPin = BQ::ZUMJunior::ports[4][1];

//flags to avoid button events triggers when actions are in course
bool button1PinOn = false;
bool button2PinOn = false;
/////////////////////// end flags ///////////////////////////////////


//ACTIONS TRIGGERED WHEN BUTTON 1 IS PRESSED /////////////////////////////////////


void button1action7(){
  digitalWrite(ledDoble1ColorPin,HIGH);
  
  button1PinOn = false;
}

void button1action6(){
  heap.delay(500);
  heap.insert(button1action7);
}


void button1action5(){
  digitalWrite(ledDoble1ColorPin,LOW);
  heap.insert(button1action6);
  
}

void button1action4(){
  heap.delay(500);
  heap.insert(button1action5);
}

void button1action3(){
  digitalWrite(ledDoble1ColorPin,HIGH);
  heap.insert(button1action4);
}

void button1action2(){
  heap.delay(500);
  heap.insert(button1action3);
}

void button1action1(){
  digitalWrite(ledDoble1ColorPin, LOW);
  heap.insert(button1action2);
}

/////////////////////////////// END ACTIONS BUTTON 1 //////////////////////////////////

//ACTIONS TRIGGERED WHEN BUTTON 2 IS PRESSED ///////////////////////////////////

void button2action3(){
  digitalWrite(ledDoble2ColorPin,HIGH);
  
  //last action must set flag to false
  button2PinOn = false;
}

void button2action2(){
  heap.delay(5000);
  heap.insert(button2action3);
}

void button2action1(){
  
  digitalWrite(ledDoble2ColorPin,LOW);
  heap.insert(button2action2);
}

/////////////////////////////// END ACTIONS BUTTON 2 //////////////////////////////////

void triggerButton1Actions(){
  if(button1PinOn) return;

  zumJunior.play(BQ::ZUMJunior::DO,50);
  button1PinOn = true;
  heap.insert(button1action1);
}

void triggerButton2Actions(){
  if(button2PinOn) return;
  
  zumJunior.play(BQ::ZUMJunior::RE,50);
  button2PinOn = true;
  heap.insert(button2action1);
}

void setup(){
  zumJunior.setup();
  pinMode(button1Pin, INPUT);
  pinMode(button2Pin, INPUT);
  pinMode(ledDoble1WhitePin, OUTPUT);
  pinMode(ledDoble1ColorPin, OUTPUT);
  pinMode(ledDoble2WhitePin, OUTPUT);
  pinMode(ledDoble2ColorPin, OUTPUT);
  digitalWrite(ledDoble1WhitePin, LOW);
  digitalWrite(ledDoble1ColorPin, LOW);
  digitalWrite(ledDoble2WhitePin, LOW);
  digitalWrite(ledDoble2ColorPin, LOW);

  delay(1000);

  digitalWrite(ledDoble1WhitePin, HIGH);
  digitalWrite(ledDoble1ColorPin, HIGH);
  digitalWrite(ledDoble2WhitePin, HIGH);
  digitalWrite(ledDoble2ColorPin, HIGH);

}

void loop(){


  //loop over all the items and run operations if required
  heap.eventloop();


  if(digitalRead(button1Pin)) triggerButton1Actions();
  if(digitalRead(button2Pin)) triggerButton2Actions();
}