#include <BitbloqEncoder.h>

Encoder encoder (encoderUpdaterWrapper);

void setup()
{
	Serial.begin(19200);
}
void loop()
{
	Serial.print("Encoder value: ");
	Serial.println(encoder.read());

	delay(1000);
}

void encoderUpdaterWrapper(){
	encoder.update();
}