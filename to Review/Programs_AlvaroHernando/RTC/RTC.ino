// Date and time functions using a DS1307 RTC connected via I2C and Wire lib

#include <Wire.h>
#include "RTClib.h"

RTC_DS1307 rtc;

void setup () {
  Serial.begin(19200);
  
  Wire.begin();

  rtc.begin();

  if (! rtc.isrunning()) {
    Serial.println("RTC is NOT running!");
    // following line sets the RTC to the date & time this sketch was compiled
    //rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    // This line sets the RTC with an explicit date & time, for example to set
    // January 2, 2015 at 03:04:05 you would call:
    //rtc.adjust(DateTime(2015, 1, 2, 3, 4, 5));
  }
  
    // Test SQW pin
 /*  
    rtc.writeSqwPinMode(SquareWave1HZ);      // 1 Hz square wave
    delay(5000);
    rtc.writeSqwPinMode(SquareWave4kHz);     // 4.096 kHz square wave
    delay(5000);
    rtc.writeSqwPinMode(SquareWave8kHz);     // 8.192 kHz square wave
    delay(5000);
    rtc.writeSqwPinMode(SquareWave32kHz);    // 32.768 kHz square wave
    delay(5000);
    rtc.writeSqwPinMode(OFF);                // Disable SQW pin
*/
}

void loop () {
    DateTime now = rtc.now();
    
    Serial.print(now.year(), DEC);
    Serial.print('/');
    Serial.print(now.month(), DEC);
    Serial.print('/');
    Serial.print(now.day(), DEC);
    Serial.print(' ');
    Serial.print(now.hour(), DEC);
    Serial.print(':');
    Serial.print(now.minute(), DEC);
    Serial.print(':');
    Serial.print(now.second(), DEC);
    Serial.println();
    
    // UNIX time
/*
    Serial.print(" since 1970 = ");
    Serial.print(now.unixtime());
    Serial.print("s = ");
    Serial.print(now.unixtime() / 86400L);    //60x60x24
    Serial.println("d");
*/

    Serial.println();
    delay(3000);
}

