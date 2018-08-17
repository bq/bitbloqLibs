#include <BQZUMJunior.h>
#include <BQZUMI2CColorSensor.h>



int i2cportA = BQ::ZUMJunior::i2cPorts[A];
BQ::ZUM::I2CColorSensor colorSensor(i2cportA); //color sensor

void setup() {
  Serial.begin(115200);
  colorSensor.setup();
}

void loop(){
  
  BQ::ZUM::I2CColorSensor::Colors color = colorSensor.whichColor();
  
  switch(color){
    case 0: Serial.println("RED");break;
    case 1: Serial.println("GREEN");break;
    case 2: Serial.println("BLUE");break;
    case 3: Serial.println("WHITE");break;
    case 4: Serial.println("BLACK");break;
  }
  
  delay(1000);

}
