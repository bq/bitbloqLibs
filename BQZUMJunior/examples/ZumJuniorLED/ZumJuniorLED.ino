#include <BQZUMJunior.h>
#include <BQZUMJuniorPorts.h>

//connected to port 2
const uint8_t led1WhitePin = BQ::ZUMJunior::ports[2][0];
const uint8_t led1ColorPin = BQ::ZUMJunior::ports[2][1];

//it could be connected to any port, including A, B, for example
//const uint8_t led1WhitePin = BQ::ZUMJunior::ports[A][0];
//const uint8_t led1ColorPin = BQ::ZUMJunior::ports[A][1];


void setup() {
  // put your setup code here, to run once:

pinMode(led1WhitePin,OUTPUT);
pinMode(led1ColorPin,OUTPUT);
digitalWrite(led1WhitePin,HIGH);
digitalWrite(led1ColorPin,HIGH);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(led1WhitePin,HIGH); //TURN OFF
  digitalWrite(led1ColorPin,LOW); //TURN ON
  delay(500);
  digitalWrite(led1WhitePin,LOW); //TURN ON
  digitalWrite(led1ColorPin,HIGH); //TURN OFF
  delay(500);
}
