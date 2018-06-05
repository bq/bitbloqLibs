#include <BQZUMJunior.h>
#include <BQZUMJuniorPorts.h>
#include <Servo.h>


Servo servo;

//connected to port 2
const uint8_t servoPin = BQ::ZUMJunior::ports[2][0];

//it could be connected to any port, including A, B, for example
//const uint8_t servoPin = BQ::ZUMJunior::ports[A][0];


void setup() {
  // put your setup code here, to run once:
  servo.attach(servoPin);
}

void loop() {
  servo.write(180);
}
