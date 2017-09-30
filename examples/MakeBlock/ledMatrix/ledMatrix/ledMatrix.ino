#include <BitbloqAuriga.h>

#include <BitbloqMeLEDMatrixData.h>
#include <BitbloqMeLEDMatrix.h>

uint8_t drawing[128];
  

BitbloqMeLEDMatrix ledMatrix(BitbloqAuriga::ports[10][1],BitbloqAuriga::ports[10][2]);

void setup() {
  ledMatrix.setup();
}

void loop() {
  // put your main code here, to run repeatedly:

  ledMatrix.clearScreen();

  //ledMatrix.drawLed(1,0,1);
  for (int i=1; i<=16; i++){
    if(i>8)
      ledMatrix.drawLed(i,17-i,true);
    else
      ledMatrix.drawLed(i,i,true);
    delay(100);
  }

  ledMatrix.clearScreen();

  ledMatrix.drawRectangle(2,1,5,7);
  delay(1000);

  ledMatrix.drawLine(16,0,0,8);
  delay(1000);

  /*int x = 2;
  int y = 3;
  uint8_t pos = (x-1)+16*(y-1);
  drawing[pos] = 1;
    
  uint8_t result = 0;
  for (int c = 0; c < 8; c++){
    Serial.print("c: ");
    Serial.println(c);
    Serial.print("pos: "); Serial.println((x-1)+16*c);
    Serial.print("value: ");Serial.println(drawing[(x-1)+16*c]);
    Serial.print("result: ");Serial.println(drawing[(x-1)+16*c] * pow(2,c));
    Serial.println("---");
    delay(100);
    result = result + drawing[(x-1)+16*c] * pow(2,c);
    Serial.print("result: ");Serial.println(result);
    
  }  
  Serial.println(result);
  delay(1000);
  */
}
