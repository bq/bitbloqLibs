#include <ButtonPad.h>

ButtonPad myPad(A0);

void setup(){
  Serial.begin(9600);
}
void loop(){
  Serial.println(String(myPad.read()));
}