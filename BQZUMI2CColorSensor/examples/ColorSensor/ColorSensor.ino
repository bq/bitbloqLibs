#include <BQZUMJunior.h>
#include <BQZUMI2CColorSensor.h>

int i2cport = BQ::ZUMJunior::i2cPorts[A];
BQ::ZUM::I2CColorSensor colorSensor(i2cport);


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  colorSensor.setup();
}

void loop() {
  // put your main code here, to run repeatedly:
  float     f_Red = 0;
  float     f_Green = 0;
  float     f_Blue = 0;
  float     f_Clear = 0;

  colorSensor.getColor(&f_Red, &f_Green, &f_Blue, &f_Clear);
  
  Serial.print("COLOR Red:");
  Serial.print(f_Red);
  Serial.print("\tGreen:");
  Serial.print(f_Green);
  Serial.print("\tBlue:");
  Serial.print(f_Blue);
  Serial.print("\tClear:");
  Serial.print(f_Clear);
  Serial.println();

  delay(500);
}
