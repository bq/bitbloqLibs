/* Ultrasonic Ranging
 Library for BAT Ultrasonic Ranging Module.librar
 created 2014
 by Robi.Wang
 www.Elecfreak.com
 */
 
 
#define CM       1      //Centimeter
#define INC      0      //Inch

#define TRI_PIN       8      //Trig_pin
#define ECH_PIN       9      //Echo_pin


void setup(){
  pinMode(TRI_PIN,OUTPUT);       // set TP output for trigger  
  pinMode(ECH_PIN,INPUT);        // set EP input for echo
  Serial.begin(19200);      // init serial 19200
}

void loop(){  
  long microseconds = TP_init();
  Serial.print("ret=");      //
  Serial.println(microseconds);
  long distance_cm = Distance(microseconds, CM);
  Serial.print("Distance_cm = ");
  Serial.println(distance_cm);
  delay(3000);
}

long Distance(long time, int flag)
{
  long distance;
  if(flag)
    distance = time /29 / 2  ;     // Distance_cm  = ((Duration of high level)*(Sonic :340m/s))/2
                                   //              = ((Duration of high level)*(Sonic :0.034 cm/us))/2
                                   //              = ((Duration of high level)/(Sonic :29.4 cm/us))/2
  else
    distance = time / 74 / 2;      // INC
  return distance;
}

long TP_init()
{                     
  digitalWrite(TRI_PIN, LOW);                    
  delayMicroseconds(2);
  digitalWrite(TRI_PIN, HIGH);                 // pull the Trig pin to high level for more than 10us impulse 
  delayMicroseconds(10);
  digitalWrite(TRI_PIN, LOW);
  long microseconds = pulseIn(ECH_PIN,HIGH);   // waits for the pin to go HIGH, and returns the length of the pulse in microseconds
  return microseconds;                    // return microseconds
}
