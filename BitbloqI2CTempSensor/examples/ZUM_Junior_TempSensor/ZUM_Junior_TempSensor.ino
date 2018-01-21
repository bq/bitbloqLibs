#include <BQZUMJunior.h>

#include <BitbloqI2CTempSensor.h>


int i2cport = BQ::ZUMJunior::i2cPorts['A'];
Bitbloq::I2CTempSensor tempSensor(i2cport);

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

