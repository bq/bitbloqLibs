#include <BitbloqI2C7SegmentDisplay.h>

Bitbloq::ZUMJunior::I2C7SegmentDisplay SegmentDisplay;
char c_caracter = 48;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  SegmentDisplay.begin(1);

  SegmentDisplay.displayChar('b','q');

  delay(1000);

  SegmentDisplay.displayChar(' ',' ');
}

void loop() {
  // put your main code here, to run repeatedly:
  SegmentDisplay.displayChar(c_caracter,c_caracter+1);
  c_caracter++;
  if ((c_caracter > 57) & (c_caracter < 65)){
    c_caracter = 65;  
  }
  if (c_caracter > 90){
    c_caracter = 48;  
  }
  Serial.println(c_caracter);
  delay(500);
}
