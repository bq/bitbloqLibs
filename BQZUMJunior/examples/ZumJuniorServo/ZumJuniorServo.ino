#include <BQZUMJunior.h>
#include <BQZUMJuniorPorts.h>
#include <Servo.h>

//ZUM Junior Servo connedted to port 2. ATTENTION-> Servo is on wire 1.
const uint8_t pinServo = BQ::ZUMJunior::ports[2][1];
Servo servo;
void setup() {
  // put your setup code here, to run once:
  servo.attach(pinServo);

}

void loop() {
  servo.write(10);
  delay(1500);
  servo.write(170);
  delay(1500);
}
