/*
 * BitbloqIRControl.cpp
 * 
 * Copyright 2017 Alberto Valero <avalero.valero@bq.com>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
*/

#include "BitbloqIRControl.h"

BitbloqIRControl::BitbloqIRControl(int pin):
	receiverPin(pin)
{}

void BitbloqIRControl::setup(){
	//infrared receiver
    pinMode(receiverPin,INPUT_PULLUP);
}

char BitbloqIRControl::getInfraredControlCommnad(){
	IRrecv _InfraredReceiveCommand(receiverPin);
    _InfraredReceiveCommand.enableIRIn();
    while(1)
    {
        if(_InfraredReceiveCommand.decode(&_InfraredControlCommand))
        {
            _InfraredControlCommand2=_InfraredControlCommand.value;
            if(_InfraredControlCommand2>0xFD00FE&&_InfraredControlCommand2<0xFDB050)
            {
                _InfraredControlCommand1=_InfraredControlCommand2;
            }
            switch(_InfraredControlCommand2)
            {
                case 0xFDA05F:
                return 'F';
                break;
            
                case 0xFDB04F:
                return 'D';
                break;
            
                case 0xFD10EF:
                return 'L';
                break;
                
                case 0xFD50AF:
                return 'R';
                break;
            
                case 0xFD906F:
                return 'S';
                break;

                case 0xFD708F:
                return '0';
                break;

                case 0xFD08F7:
                return '1';
                break;

                case 0xFD8877:
                return '2';
                break;

                case 0xFD48B7:
                return '3';
                break;

                case 0xFD28D7:
                return '4';
                break;

                case 0xFDA857:
                return '5';
                break;

                case 0xFD6897:
                return '6';
                break;

                case 0xFD18E7:
                return '7';
                break;

                case 0xFD9867:
                return '8';
                break;

                case 0xFD58A7:
                return '9';
                break;

                case 0xFD20DF:
                return '+';
                break;

                case 0xFD30CF:
                return '-';
                break;

                case 0xFD609F:
                return 'B';
                break;

                case 0xFD40BF:
                return 'M';
                break;

                case 0xFD00FF:
                return 'P';
                break;
                
                default:
                return 'T';
                break;
            }
        }
    }
}
