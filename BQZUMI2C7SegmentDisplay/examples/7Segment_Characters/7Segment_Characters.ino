#include <BQZUMJunior.h>
#include <BQZUMI2C7SegmentDisplay.h>

int i2cport = BQ::ZUMJunior::i2cPorts[A];
BQ::ZUM::I2C7SegmentDisplay segmentDisplay(i2cport);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  segmentDisplay.setup();

  segmentDisplay.displayChar('b','q');

  delay(1000);

  segmentDisplay.displayChar(' ',' ');
}

void loop() {
  static char c_caracter = 48;
  segmentDisplay.displayChar(c_caracter,c_caracter+1);
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
