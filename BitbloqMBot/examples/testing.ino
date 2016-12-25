#include <BitbloqMBot.h>

MBot mbot;

void setup() {
  // put your setup code here, to run once:
  mbot.setup();
  Serial.begin(9600);

}

void loop() {

  //Check Button
  Serial.print("Button Status (1-pushed): ");
  Serial.println(mbot.isButtonPushed());
  
  //Check LDR
  Serial.print("LDR value: ");
  Serial.println(mbot.readLightSensor());
  delay(1000);
  
}
