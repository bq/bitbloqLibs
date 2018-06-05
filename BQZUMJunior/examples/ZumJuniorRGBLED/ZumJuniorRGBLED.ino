#include <BQZUMJunior.h>

BQ::ZUMJunior zumJunior;

void setup() {
  // put your setup code here, to run once:
  zumJunior.setup();
}

void loop() {
  
  //RED
  zumJunior.setRGBLEDColor(BQ::ZUMJunior::RED);
  delay(1000);
  //GREEN
  zumJunior.setRGBLEDColor(BQ::ZUMJunior::GREEN);
  delay(1000);
  //BLUE
  zumJunior.setRGBLEDColor(BQ::ZUMJunior::BLUE);
  delay(1000);
  //YELLOW
  zumJunior.setRGBLEDColor(BQ::ZUMJunior::YELLOW);
  delay(1000);
  //PINK
  zumJunior.setRGBLEDColor(BQ::ZUMJunior::PINK);
  delay(1000);
  //WHITE
  zumJunior.setRGBLEDColor(BQ::ZUMJunior::WHITE);
  delay(1000);
  //OFF
  zumJunior.setRGBLEDColor(BQ::ZUMJunior::BLACK);
  delay(1000);



}
