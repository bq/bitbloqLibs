#include "Arduino.h"
#include "BitbloqMBot.h"

#include "MeMCore.h"


MBot::MBot(){
	boardLeds = new MeRGBLed(7);
}

MBot::~MBot(){
	if (boardLeds != NULL){
		delete boardLeds;
		boardLeds = NULL;
	}
}

void MBot::init(){

}

void MBot::setLed(int led, int red, int green, int blue){
    boardLeds->setColor(led, red, green, blue);
    boardLeds->show();
}