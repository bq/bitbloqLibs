#define SENSOR_PIN     9       // the number of the Sensor pin
#define LED_PIN        13      // the number of the led pin
 
 
int sensorState = 0;         // variable for reading the Sensor status
 
void setup() {
  // initialize the led pin as an output:
  pinMode(LED_PIN, OUTPUT);      
  // initialize the Sensor pin as an input:
  pinMode(SENSOR_PIN, INPUT);     
}
 
void loop(){
  // read the state of the Sensor value:
  sensorState = digitalRead(SENSOR_PIN);
 
  if (sensorState == HIGH) {     
    // turn led on:    
    digitalWrite(LED_PIN, HIGH);  
    delay(100);
  } 
  else {
    // turn led off:
    digitalWrite(LED_PIN, LOW);
//    delay(100);
  }
}
