#include "Arduino.h"
#include "BitbloqStepperShield.h"

/*
 * Constructor to characterize the steppers with the number of
 *   steps per revolution
 */
StepperShield::StepperShield(int steps_rev){
  revsteps = steps_rev;
}

/*
 * Constructor to characterize the steppers with the number of
 *   degrees per step
 */
StepperShield::StepperShield(double deg_step){
  revsteps = 360/deg_step;
}



/*
 * Initializer for the mode of the pins which will be used
 */
void StepperShield::init(){
  pinMode(PIN_STEPPER1STEP, OUTPUT);
  pinMode(PIN_STEPPER1DIR, OUTPUT);
  pinMode(PIN_STEPPER1EN, OUTPUT);
  pinMode(PIN_STEPPER2STEP, OUTPUT);
  pinMode(PIN_STEPPER2DIR, OUTPUT);
  pinMode(PIN_STEPPER2EN, OUTPUT);

  pinMode(PIN_STEPPER1FAULT, INPUT);
  pinMode(PIN_STEPPER2FAULT, INPUT);

  digitalWrite(PIN_STEPPER1EN, HIGH);  //Disable both steppers
  digitalWrite(PIN_STEPPER2EN, HIGH);
}



/*
 * getrevsteps() returns the feature of the steppers as the number of
 *   steps per revolution
 */
int StepperShield::getrevsteps(){
  return revsteps;
}

/*
 * Set the feature of the steppers as the number of steps per revolution
 */
void StepperShield::setrevsteps(int steps_rev){
  revsteps = steps_rev;
}

/*
 * Set the feature of the steppers as the number of degrees per step
 */
void StepperShield::setrevsteps(double deg_step){
  revsteps = 360/deg_step;
}



/*
 * Moves one stepper or both synchronously:
 *   stepper: stepper which is going to move [STEPPER1, STEPPER2, STEPPER1_2]
 *   deg: degrees of the movement 
 *   dir: direction of the movement [CW, CCW]
 *   rpm: speed of the movement in revolutions per minute
 */
void StepperShield::step(int stepper, float deg, bool dir, float rpm){

  digitalWrite(PIN_STEPPER1DIR, dir);  //establish the direction
  digitalWrite(PIN_STEPPER2DIR, dir);

  int steps = abs(deg * revsteps / 360);  //calculate the number of steps needed

  unsigned long  stephalfmicrodelay = 60000000 / (2 * revsteps * rpm);  //calculate the delay needed to reach the speed (divided by two)
  if (stephalfmicrodelay<2) stephalfmicrodelay = 2;  //limit the maxmimum speed

  unsigned long lasthalfsteptime = 0;
  bool laststate = LOW;

  switch (stepper) {
    case STEPPER1:                 //To move the stepper 1
      digitalWrite(PIN_STEPPER1EN, LOW);  //Enable the stepper
      delayMicroseconds(1);

      while(steps>0) {             //While there wasn't reached the calculated steps
        
        if (digitalRead(PIN_STEPPER1FAULT) == LOW) break;     //Stop if it is overtemp or overcurrent

        if (micros() - lasthalfsteptime >= stephalfmicrodelay) {  //Send a pulse of the calculated period to reach the given speed
          lasthalfsteptime = micros();

          if (laststate == LOW) {
            digitalWrite(PIN_STEPPER1STEP, HIGH);
            laststate = HIGH;
          }
          else {
            digitalWrite(PIN_STEPPER1STEP, LOW);
            laststate = LOW;
            steps--;
          }
        }
      }

      digitalWrite(PIN_STEPPER1EN, HIGH);  //Disable the stepper
      break;


    case STEPPER2:                 //For the stepper 2 (same)
      digitalWrite(PIN_STEPPER2EN, LOW);
      delayMicroseconds(1);

      while(steps>0) {
        if (digitalRead(PIN_STEPPER2FAULT) == LOW) break;
        if (micros() - lasthalfsteptime >= stephalfmicrodelay) {
          lasthalfsteptime = micros();

          if (laststate == LOW) {
            digitalWrite(PIN_STEPPER2STEP, HIGH);
            laststate = HIGH;
          }
          else {
            digitalWrite(PIN_STEPPER2STEP, LOW);
            laststate = LOW;
            steps--;
          }
        }
      }

      digitalWrite(PIN_STEPPER2EN, HIGH);
      break;


    case STEPPER1_2:                 //For both steppers moving synchronously (same)
      digitalWrite(PIN_STEPPER1EN, LOW);
      digitalWrite(PIN_STEPPER2EN, LOW);
      delayMicroseconds(1);

      while(steps>0) {
        if (digitalRead(PIN_STEPPER1FAULT) == LOW  ||  digitalRead(PIN_STEPPER2FAULT) == LOW) break;
        if (micros() - lasthalfsteptime >= stephalfmicrodelay) {
          lasthalfsteptime = micros();

          if (laststate == LOW) {
            digitalWrite(PIN_STEPPER1STEP, HIGH);
            digitalWrite(PIN_STEPPER2STEP, HIGH);
            laststate = HIGH;
          }
          else {
            digitalWrite(PIN_STEPPER1STEP, LOW);
            digitalWrite(PIN_STEPPER2STEP, LOW);
            laststate = LOW;
            steps--;
          }
        }
      }

      digitalWrite(PIN_STEPPER1EN, HIGH);
      digitalWrite(PIN_STEPPER2EN, HIGH);
      break;


    default:
      break;
  }
}