#include <BQZUMJunior.h>
#include <BQZUMI2CALPSSensor.h>

int i2cport = BQ::ZUMJunior::i2cPorts[A];
BQ::ZUM::I2CALPSSensor ALPSSensor(i2cport);

void setup() {
  Serial.begin(115200);
  ALPSSensor.setup();
}

void loop() {
  // put your main code here, to run repeatedly:
  uint16_t  ui16_Distance = 0;

  ui16_Distance = ALPSSensor.getDistance();
  
  Serial.print("DISTANCE:");
  Serial.println(ui16_Distance);

  delay(500);
}
