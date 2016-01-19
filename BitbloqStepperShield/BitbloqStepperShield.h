#ifndef BitbloqStepperShield_h
#define BitbloqStepperShield_h


#define CW              0
#define CCW             1

#define STEPPER1        1
#define STEPPER2        2
#define STEPPER1_2      0

#define MICROSTEPS      32

#define PIN_STEPPER2FAULT 6
#define PIN_STEPPER1FAULT 7
#define PIN_STEPPER2EN    8
#define PIN_STEPPER2DIR   9
#define PIN_STEPPER2STEP  10
#define PIN_STEPPER1EN    11
#define PIN_STEPPER1DIR   12
#define PIN_STEPPER1STEP  13


class StepperShield {
  public:
    StepperShield(int steps_rev=200);
    StepperShield(double deg_step);

    void init();

    int getrevsteps();
    void setrevsteps(int steps_rev);
    void setrevsteps(double deg_step);

    void step(byte stepper, float deg, bool dir, float rpm);

  private:
    int revsteps;
};

#endif