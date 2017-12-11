// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// released under the GPLv3 license to match the rest of the AdaFruit NeoPixel library

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

const int pin = 5;
const int num = 1;

Bitbloq::Adafruit_NeoPixel rgbLed = Bitbloq::Adafruit_NeoPixel(num, pin, NEO_GRB + NEO_KHZ800);


void setup() {
  rgbLed.begin(); // This initializes the NeoPixel library.
}

void loop() {
    rgbLed.setPixelColor(0, rgbLed.Color(0,150,0)); // Moderately bright green color.
    rgbLed.show(); // This sends the updated pixel color to the hardware.
    delay(100); // Delay for a period of time (in milliseconds).
}
