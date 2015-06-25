#include <ButtonPad.h>
#include <Wire.h>
ButtonPad myPad(A0);

void setup(){
  Serial.begin(9600);
}
void loop(){
  Serial.println(String(myPad.read()));
}