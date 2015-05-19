#include <LineFollower.h>

LineFollower myLineFollower(11,12);

void setup(){
  Serial.begin(9600);
}
void loop(){
  int * position = myLineFollower.read();
  Serial.println("\n------\nLineFollower:\nLeft:"+ String(position[0])+"\nRight:"+ String(position[1])+"\n------\n");
  delay(500);
}
