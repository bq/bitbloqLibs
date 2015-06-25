#include "ButtonPad.h"

//****** BUTTONPAD ******//
ButtonPad::ButtonPad(int pin){
  _pin = pin;
  _num_keys = 5;
  _adc_key_val = (int*)malloc(_num_keys*sizeof(int));
  _adc_key_val[0] = 20;
  _adc_key_val[1] = 50;
  _adc_key_val[2] = 100;
  _adc_key_val[3] = 200;
  _adc_key_val[4] = 600;
  _key=-1;
  _oldkey=-1;
}
ButtonPad::ButtonPad(int pin, int num_keys, int * adc_key_val){
  _pin = pin;
  _num_keys = num_keys;
  _adc_key_val = adc_key_val;
}
int ButtonPad::read(){
    int adc_key_in =analogRead(_pin);
    _key = get_key(adc_key_in);
    if (_key != _oldkey)
    {
      delay(50);
      adc_key_in = analogRead(_pin);
      _key = get_key(adc_key_in);
      if (_key>=0)
      {
        _oldkey = _key;
        return _key;
      }
      return -1;
    }
}
int ButtonPad::get_key(int input)
  {
    int k;
    for (k = 0; k < _num_keys; k++)
    {
      if (input < _adc_key_val[k])
      {
        return k;
      }
    }
    return -1;
}