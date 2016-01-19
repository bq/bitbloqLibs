#ifndef BitbloqDCMotorShield_h
#define BitbloqDCMotorShield_h


#define CW               0
#define CCW              1

#define MOTOR1           1
#define MOTOR2           2

#define PIN_MOTOR1DIR    8
#define PIN_MOTOR2DIR    9
#define PIN_MOTOR1PWM    10
#define PIN_MOTOR2PWM    11
#define PIN_MOTOR1SLEEP  12
#define PIN_MOTOR2SLEEP  13


class DCMotorShield {
  public:

    void init();

    void spinMotor(unsigned char motor, bool dir, unsigned char perc);
    void stopMotor(unsigned char motor);

    float getwheelgap();
    void setwheelgap(float gap);

    void goForward(unsigned char perc);
    void goBackward(unsigned char perc);
    void turnLeft(unsigned char perc, float radio);
    void turnRight(unsigned char perc, float radio);
    void stop();

  private:
    float halfwheelgap;
    bool dirMotor1;
    bool dirMotor2;
};

#endif