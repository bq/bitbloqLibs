#include <IRremoteInt.h>
#include <IRremote.h>
#include <BitbloqIRControl.h>

#include <BitbloqMCore.h>

BitbloqMCore mcore;

void setup() {
  mcore.setup();
  Serial.begin(9600);
}


void loop() {
  Serial.println(mcore.getInfraredControlCommnad());
  Serial.println(mcore.irControl->getRaw());
}
