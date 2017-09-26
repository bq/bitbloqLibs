#include <BitbloqAuriga.h>

#include <BitbloqMeLEDMatrixData.h>
#include <BitbloqMeLEDMatrix.h>


BitbloqMeLEDMatrix ledMatrix(BitbloqAuriga::ports[10][1],BitbloqAuriga::ports[10][2]);

void setup() {
  ledMatrix.setup();
}

void loop() {
  // put your main code here, to run repeatedly:
  ledMatrix.drawLed(8,5,true);
  /*for (int i=0; i<16; i++){
    ledMatrix.drawLed(i,0,true);
    delay(500);
  }*/

}
