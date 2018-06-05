/* 7 Segment Display */
/*
 * ----     --> bit 0
 * |  |     --> bit 5  |  bit 1
 * ----     --> bit 6
 * |  |     --> bit 4  |  bit 2
 * ---- *   --> bit 3  |  bit 7
 */

#include <BQZUMJunior.h>
#include <BQZUMI2C7SegmentDisplay.h>

int i2cport = BQ::ZUMJunior::i2cPorts[A];
BQ::ZUM::I2C7SegmentDisplay segmentDisplay(i2cport);

void setup() {
  // put your setup code here, to run once:
  segmentDisplay.setup();

  segmentDisplay.displayChar('b','q');

  delay(1000);

  segmentDisplay.displayChar(' ',' ');
}

void loop() {
  // put your main code here, to run repeatedly:
  segmentDisplay.display(0b00000001, 0b00000001);
  delay(500);
  segmentDisplay.display(0b00000010, 0b00000010);
  delay(500);
  segmentDisplay.display(0b00000100, 0b00000100);
  delay(500);
  segmentDisplay.display(0b00001000, 0b00001000);
  delay(500);
  segmentDisplay.display(0b00010000, 0b00010000);
  delay(500);
  segmentDisplay.display(0b00100000, 0b00100000);
  delay(500);
  segmentDisplay.display(0b01000000, 0b01000000);
  delay(500);
  segmentDisplay.display(0b10000000, 0b10000000);
  delay(500);
}
