#include <HTS221.h>
#include <HTS221_Registers.h>

#include "Wire.h"
 
HTS221 hts221;

float humidity = 0.0, temperature = 0.0;

void setup() {     
  Serial.begin(19200);
  Wire.begin();

  hts221.begin(); 
  if(hts221.checkConnection()) Serial.println("Error checking HTS221 connection");
  else Serial.println("HTS221 connected");
  
  temperature = hts221.getTemperature();
  humidity = hts221.getHumidity();
 /* 
 //  while (humidity > 60.0) {
    if(hts221.heater()) Serial.println("Error with the heater");
    else Serial.println("Heater Ok");
    delay(10000);    // wait 10 seconds
    humidity = hts221.getHumidity();

  //}
//  humidity = hts221.getHumidity();
*/
}

void loop() {

  humidity = hts221.getHumidity();
  Serial.print("Humidity: ");
  Serial.print(humidity,1);
  Serial.println(" %");
  delay(3000);    // wait 3 seconds

  temperature = hts221.getTemperature();
  Serial.print("Temperature: ");
  Serial.print(temperature,1);
  Serial.println(" degC");
  delay(3000);    // wait 3 seconds

}
