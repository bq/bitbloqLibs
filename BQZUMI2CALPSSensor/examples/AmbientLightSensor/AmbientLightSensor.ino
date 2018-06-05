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
  float  f_AmbientLight = 0;

  f_AmbientLight = ALPSSensor.getAL();
  
  Serial.print("Ambient Light (Lux):");
  Serial.println(f_AmbientLight);

  delay(500);
}
