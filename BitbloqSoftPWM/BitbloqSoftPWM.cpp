/* $Id: SoftPWM.cpp 132 2012-02-14 04:15:05Z bhagman@roguerobotics.com $

  A Software PWM Library
  
  Written by Brett Hagman
  http://www.roguerobotics.com/
  bhagman@roguerobotics.com

  Minor modification by Paul Stoffregen to support different timers

    This library is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

*************************************************/

#include <avr/io.h>
#include <avr/interrupt.h>
#include "BitbloqSoftPWM.h"
#include "BitbloqSoftPWM_timer.h"

#if defined(WIRING)
 #include <Wiring.h>
#elif ARDUINO >= 100
 #include <Arduino.h>
#else
 #include <WProgram.h>
#endif

#if F_CPU
#define SOFTPWM_FREQ 60UL
#define SOFTPWM_OCR (F_CPU/(8UL*256UL*SOFTPWM_FREQ))
#else
// 130 == 60 Hz (on 16 MHz part)
#define SOFTPWM_OCR 130
#endif

volatile uint8_t _isr_softcount = 0xff;

typedef struct
{
  // hardware I/O port and pin for this channel
  int8_t pin;
  volatile uint8_t *outport;
  uint8_t pinmask;
  uint8_t pwmvalue;
  uint8_t checkval;
} softPWMChannel;

softPWMChannel _softpwm_channels[SOFTPWM_MAXCHANNELS];


// Here is the meat and gravy
#ifdef WIRING
void SoftPWM_Timer_Interrupt(void)
#else
ISR(SOFTPWM_TIMER_INTERRUPT)
#endif
{
  uint8_t i;

  if(++_isr_softcount == 0)
  {
    // set available channels high - let's start again
    // and accept new checkvals
    for (i = 0; i < SOFTPWM_MAXCHANNELS; i++)
    {
      if (_softpwm_channels[i].pin >= 0)  // if it's a valid pin
      {
        _softpwm_channels[i].checkval = _softpwm_channels[i].pwmvalue;
        // now set the pin high (if not 0)
        if (_softpwm_channels[i].checkval > 0)  // don't set if checkval == 0
          *_softpwm_channels[i].outport |= _softpwm_channels[i].pinmask;
        }
    }
  }

  for (i = 0; i < SOFTPWM_MAXCHANNELS; i++)
  {
    if (_softpwm_channels[i].pin >= 0)  // if it's a valid pin
    {
      if (_softpwm_channels[i].checkval == _isr_softcount)  // if we have hit the width
        *_softpwm_channels[i].outport &= ~(_softpwm_channels[i].pinmask);  // turn off the channel
    }
  }  
}



void SoftPWMBegin()
{
  // We can tweak the number of PWM period by changing the prescalar
  // and the OCR - we'll default to ck/8 (CS21 set) and OCR=128.
  // This gives 1024 cycles between interrupts.  And the ISR consumes ~200 cycles, so
  // we are looking at about 20 - 30% of CPU time spent in the ISR.
  // At these settings on a 16 MHz part, we will get a PWM period of
  // approximately 60Hz (~16ms).

  uint8_t i;

#ifdef WIRING
  Timer2.setMode(0b010);  // CTC
  Timer2.setClockSource(CLOCK_PRESCALE_8);
  Timer2.setOCR(CHANNEL_A, SOFTPWM_OCR);
  Timer2.attachInterrupt(INTERRUPT_COMPARE_MATCH_A, SoftPWM_Timer_Interrupt);
#else
  SOFTPWM_TIMER_INIT(SOFTPWM_OCR);
#endif



  for (i = 0; i < SOFTPWM_MAXCHANNELS; i++)
  {
    _softpwm_channels[i].pin = -1;
    _softpwm_channels[i].outport = 0;
  }
}


void SoftPWMSet(int8_t pin, uint8_t value)
{
  int8_t firstfree = -1;  // first free index
  uint8_t i;

  // If the pin isn't already set, add it
  for (i = 0; i < SOFTPWM_MAXCHANNELS; i++)
  {
    if ((pin < 0 && _softpwm_channels[i].pin >= 0) ||  // ALL pins
       (pin >= 0 && _softpwm_channels[i].pin == pin))  // individual pin
    {
      // set the pin (and exit, if individual pin)
      _softpwm_channels[i].pwmvalue = value;

      if (pin >= 0) // we've set the individual pin
        return;
    }

    // get the first free pin if available
    if (firstfree < 0 && _softpwm_channels[i].pin < 0)
      firstfree = i;
  }

  if (pin >= 0 && firstfree >= 0)
  {
    // we have a free pin we can use
    _softpwm_channels[firstfree].pin = pin;
    //_softpwm_channels[firstfree].polarity = _softpwm_defaultPolarity;
    _softpwm_channels[firstfree].outport = portOutputRegister(digitalPinToPort(pin));
    _softpwm_channels[firstfree].pinmask = digitalPinToBitMask(pin);
    _softpwm_channels[firstfree].pwmvalue = value;
//    _softpwm_channels[firstfree].checkval = 0;
    
    // now prepare the pin for output
    // turn it off to start (no glitch)
    digitalWrite(pin, LOW);
    pinMode(pin, OUTPUT);
  }
}
