#include "BitbloqEchidna.h"

namespace Bitbloq{

const uint8_t Echidna::led_pin[3] = {11,12,13};

Echidna::Echidna():
        rgbLed(9,5,6),
        joystick(A0,A1,2),
        button1_pin(2),
        button2_pin(3),
        buzzer_pin(10),
        ldr_pin(A5),
        accX_pin(A2),
        accY_pin(A3)
{
}

Echidna::~Echidna(){	
	//check that all of them are not NULL pointers, delete and set to NULL

}

void Echidna::setup(){
    
    pinMode(led_pin[0],OUTPUT);
    pinMode(led_pin[1],OUTPUT);
    pinMode(led_pin[2],OUTPUT);
    pinMode(button1_pin,INPUT);
    pinMode(button2_pin,INPUT);
    pinMode(buzzer_pin,OUTPUT);
    pinMode(ldr_pin,INPUT);
    pinMode(accX_pin,INPUT);
    pinMode(accY_pin, INPUT);
    rgbLed.setup();
    joystick.setup();
}

} //end namespace
