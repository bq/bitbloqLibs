#include <BQZUMJunior.h>

BQ::ZUMJunior zumJunior;

void setup() {
  // put your setup code here, to run once:
  zumJunior.setup();
}

void loop() {
  
  zumJunior.play(BQ::ZUMJunior::DO,1000);
  delay(1000);
  zumJunior.play(BQ::ZUMJunior::RE,1000);
  delay(1000);
  zumJunior.play(BQ::ZUMJunior::MI,1000);
  delay(1000);
  zumJunior.play(BQ::ZUMJunior::FA,1000);
  delay(1000);
  zumJunior.play(BQ::ZUMJunior::SOL,1000);
  delay(1000);
  zumJunior.play(BQ::ZUMJunior::LA,1000);
  delay(1000);
  zumJunior.play(BQ::ZUMJunior::SI,1000);
  delay(1000);
  while(true);



}
