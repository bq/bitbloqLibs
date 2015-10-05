#define RED_PIN        11
#define GREEN_PIN      10
#define BLUE_PIN       9


void setup()
{
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);  
}
 
void loop()
{
  setColor(255, 0, 0);  // red
  delay(5000);
  setColor(0, 255, 0);  // green
  delay(5000);
  setColor(0, 0, 255);  // blue
  delay(5000);
  setColor(255, 255, 0);  // yellow
  delay(1000);  
  setColor(255, 0, 255);  // magenta
  delay(1000);
  setColor(0, 255, 255);  // cyan
  delay(1000);
  
}
 
void setColor(unsigned char red, unsigned char green, unsigned char blue)
{
  analogWrite(RED_PIN, red);
  analogWrite(GREEN_PIN, green);
  analogWrite(BLUE_PIN, blue);  
}
