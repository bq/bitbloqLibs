#include <BitbloqEchidna.h>

Bitbloq::Echidna echidna;

void setup() {
  echidna.setup();
  Serial.begin(9600);
}

void loop() {
  if (echidna.readButton1() == HIGH){
    echidna.setLed(0,LOW);
    echidna.setLed(1,HIGH);
  }else{
    echidna.setLed(0,HIGH);
    echidna.setLed(1,LOW);
  }

  if (echidna.readButton2() == HIGH){
    echidna.setLed(2,HIGH);
    echidna.playTone(261,1000);
    echidna.setRGBcolor(0,255,0);
  }

  Serial.print("Joystick X: ");Serial.println(echidna.readJoystickX());
  Serial.print("Joystick Y: ");Serial.println(echidna.readJoystickY());
  Serial.print("Acc X: ");Serial.println(echidna.readAccX());
  Serial.print("Acc Y: ");Serial.println(echidna.readAccY());
  Serial.print("Boton: ");Serial.println(echidna.readJoystickButton());
  Serial.print("Luz: "); Serial.println(echidna.readLightSensor());

  for(int r = 0; r < 255; r++){
    echidna.setRGBcolor(r,0,0);
    delay(5);
  }

  for(int g = 0; g < 255; g++){
    echidna.setRGBcolor(0,g,0);
    delay(5);
  }

  for(int b = 0; b < 255; b++){
    echidna.setRGBcolor(0,0,b);
    delay(5);
  }
}
