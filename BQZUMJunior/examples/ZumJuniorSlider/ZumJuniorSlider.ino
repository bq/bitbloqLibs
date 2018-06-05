#include <BQZUMJunior.h>
#include <BQZUMJuniorPorts.h>

//slider connedted to port 1
const uint8_t pinSlider1 = BQ::ZUMJunior::ports[1][0];
const uint8_t pinSlider2 = BQ::ZUMJunior::ports[1][1];

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(pinSlider1,INPUT);
  pinMode(pinSlider2,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("Slider 1 status: ");
  Serial.println(digitalRead(pinSlider1));
  Serial.print("Slider 2 status: ");
  Serial.println(digitalRead(pinSlider2));
  delay(2000);

}
