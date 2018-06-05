#include <BQZUMJunior.h>
#include <BQZUMJuniorPorts.h>



void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  const uint8_t pinNumberPort2Wire1 = BQ::ZUMJunior::ports[2][1];
  const uint8_t pinNumberPortAWire1 = BQ::ZUMJunior::ports[A][1];
  const uint8_t = BQ::ZUMJunior::i2cPorts[B];
  Serial.println(pinNumberPort2Wire1);
  Serial.println(pinNumberPortAWire1);
  Serial.println(i2cNumber);
}

void loop() {
  // put your main code here, to run repeatedly:

}
