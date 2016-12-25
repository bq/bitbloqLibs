#include <BitbloqMBot.h>

MBot mbot;

void setup() {
  // put your setup code here, to run once:
  mbot.setup();
  Serial.begin(9600);

}

void loop() {

  Serial.print("Button Status (1-pushed): ");
  Serial.println(mbot.isButtonPushed());
  delay(1000);
  // put your main code here, to run repeatedly:

}
