#include <BQZUMI2CTempSensor.h>
#include <BQZUMJunior.h>
#include <BQZUMJuniorPorts.h>



int i2cport = BQ::ZUMJunior::i2cPorts['A'];
BQ::ZUM::I2CTempSensor tempSensor(i2cport);

void setup() {
  Serial.begin(9600); 
  tempSensor.setup();
}

void loop() {
  // put your main code here, to run repeatedly:
  float     f_Temperature = tempSensor.getTemp();
  Serial.print("Temperature:");
  Serial.println(f_Temperature);
  delay(1000);
}
