#include <BQZUMJunior.h>
#include <BQZUMJuniorPorts.h>

//connected to port 2
const uint8_t botonPin = BQ::ZUMJunior::ports[2][0];

//it could be connected to any port, including A, B, for example
//const uint8_t botonPin = BQ::ZUMJunior::ports[A][0];


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Testing button");
  pinMode(botonPin,INPUT);

}

void loop() {
  Serial.println(digitalRead(botonPin));
  delay(1000);
}

