#include <BQZUMJunior.h>
#include <BQZUMI2CTempSensor.h>
#include <BQZUMI2CColorSensor.h>
#include <BQZUMI2CALPSSensor.h>

int i2cportA = BQ::ZUMJunior::i2cPorts[A];
BQ::ZUM::I2CALPSSensor ALPSSensor(i2cportA); //distance and ambient light sensor
BQ::ZUM::I2CColorSensor colorSensor(i2cportA); //color sensor
BQ::ZUM::I2CTempSensor tempSensor(i2cportA); //temperature sensor

void setup() {
  Serial.begin(115200);
  ALPSSensor.setup();
  colorSensor.setup();
  tempSensor.setup();
}

void loop(){
	
  //GET COLOR
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

  delay(1000);
  
  //GET DISTANCE
  uint16_t  ui16_Distance = 0;

  ui16_Distance = ALPSSensor.getDistance();
  
  Serial.print("DISTANCE:");
  Serial.println(ui16_Distance);

  delay(1000);

  //GET AMBIENT LIGHT
  float  f_AmbientLight = 0;

  f_AmbientLight = ALPSSensor.getAL();
  
  Serial.print("Ambient Light (Lux):");
  Serial.println(f_AmbientLight);

  delay(1000);

  //GET TEMPERATURE
  float     f_Temperature = tempSensor.getTemp();
  Serial.print("Temperature: ");
  Serial.println(f_Temperature);

  delay(5000);

}
