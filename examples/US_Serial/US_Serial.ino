#include <US.h>

US myUS(9,8);

void setup(){
  Serial.begin(9600);
}
void loop(){
  float distance = myUS.read();
  Serial.println(distance);
  delay(100);
}
