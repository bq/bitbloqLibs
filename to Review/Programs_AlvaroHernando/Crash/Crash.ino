#define ENDSTOP_PIN      9      // the number of the endstop pin
#define LED_PIN         13     // the number of the LED pin
 

unsigned char sensorState = 1;         // variable for reading the sensor status
 
 
void setup() {
  // initialize the LED pin as an output:
  pinMode(LED_PIN, OUTPUT);      
  // initialize the endstop pin as an input:
  pinMode(ENDSTOP_PIN, INPUT);     
}
 
void loop(){
  // read the state of the sensor value:
  sensorState = digitalRead(ENDSTOP_PIN);
 
  // check if the sensor is closed.
  // if it is, the sensorState is HIGH:
  if (sensorState == LOW) {     
    // turn LED on:    
    digitalWrite(LED_PIN, HIGH);  
  } 
  else {
    // turn LED off:
    digitalWrite(LED_PIN, LOW); 
  }
}

