/*
  Ejemplo de programación de la LCD como SPI
  y el nuevo módulo de Humedad y Temperatura como I2C

 LCD SPI conection:
 * 5V to Arduino 5V pin
 * GND to Arduino GND pin
 * CK to Digital 2
 * MO to Digital 3
 * SS to Digital 4
 
 Temperature & Humidity conection:
 * 5V to Arduino 5V pin
 * GND to Arduino GND pin
 * SCL to Analog A5 
 * SDA to Analog A4
  
*/
 
 
//Librería necesaria:
#include <Wire.h>

// Librerías nuevas:
#include <bqLiquidCrystal.h>

#include <HTS221.h>
#include <HTS221_Registers.h>


//Objetos y variables globales:
//   CK to Digital 2 - clock
//   MO to Digital 3 - data pin
//   SS to Digital 4 - Lanch

LiquidCrystal lcd(3, 2, 4);

HTS221 hts221;

float humidity = 0.0, temperature = 0.0;

 
void setup() {
  
  Wire.begin();
    
  // set up the LCD's number of rows and columns: 
  lcd.begin(16, 2);  
  lcd.setBacklight(HIGH); //luz a tope!

  hts221.begin(); 
  
  //temperature = hts221.getTemperature();
  //humidity = hts221.getHumidity();
}
 
void loop() {
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 0);  
  lcd.print("Humedad:");
  lcd.setCursor(9, 0);
  humidity = hts221.getHumidity();
  lcd.print(humidity);
  lcd.setCursor(15, 0);lcd.print("%");
  
  lcd.setCursor(0, 1); 
  lcd.print("Temp:");
  lcd.setCursor(9, 1);
  temperature = hts221.getTemperature();
  lcd.print(temperature);
  lcd.setCursor(15, 1);lcd.print("C");

//  lcd.setBacklight(HIGH);
//  delay(800);
//  lcd.setBacklight(LOW);
//  delay(200);
  
  //lcd.scrollDisplayRight();
  //delay(3000);
  
  //lcd.clear();
  
  delay(1000);
}
