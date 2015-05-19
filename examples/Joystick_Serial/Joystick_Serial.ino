#include <Joystick.h>

Joystick myJoystick(A1,A2,4);

void setup(){
  Serial.begin(9600);
}
void loop(){
  int * joystick_position = myJoystick.read();
  Serial.println("\n------\nJoystick:\nX axis:"+ String(joystick_position[0])+"\nY axis:"+ String(joystick_position[1])+"\nButton:"+ String(joystick_position[2])+"\n------\n");
  delay(500);
}
