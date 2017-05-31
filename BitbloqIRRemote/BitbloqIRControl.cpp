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

long int BitbloqIRControl::getRaw(){
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
          
        }
        return _InfraredControlCommand2;
    }
    
}	

char BitbloqIRControl::getInfraredControlCommand(){
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
                case -1497820227:
                return 'F'; //forward
                break;
            
                case 1113853081:
                return 'B'; //backward
                break;
            
                case 32049505:
                return 'L'; //left 
                break;
                
                case -885166211:
                return 'R'; //right
                break;
            
                case -1839375523:
                return 'S'; //OK
                break;

                case 1811778305:
                return '0';
                break;

                case -555408703:
                return '1';
                break;

                case 1868133565:
                return '2';
                break;

                case -1737510107:
                return '3';
                break;

                case -875377411:
                return '4';
                break;

                case 629155073:
                return '5';
                break;

                case -2048877215:
                return '6';
                break;

                case -949029659:
                return '7';
                break;

                case 1474512609:
                return '8';
                break;

                case -1866245375:
                return '9';
                break;

                case 373604801:
                return '+';
                break;

                case -1309689187:
                return '-';
                break;

                case -799895003:
                return 'R'; //Return
                break;

                case 46690913: //Menu
                return 'M';
                break;

                case -1292968131: //Power ON/FF
                return 'P';
                break;
                
                default:
                return 'T';
                break;
            }
        }
    }
}
