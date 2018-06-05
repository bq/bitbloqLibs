#include <BQZUMJunior.h>
#include <BQZUMI2CTempSensor.h>

int i2cport = BQ::ZUMJunior::i2cPorts[A];
BQ::ZUM::I2CTempSensor tempSensor(i2cport);

void setup() {
  Serial.begin(115200);
  tempSensor.setup();
}

void loop() {
  float     f_Temperature = tempSensor.getTemp();
  Serial.print("Temperature: ");
  Serial.println(f_Temperature);

  delay(1000);
}


