
/******************************************************************************
* MakeBlock BitbloqMBot control library for Bitbloq
*
*
* @author Tomas Calvo - tomas.calvo@bq.com
* @author Alberto Valero - alberto.valero@bq.com
*
******************************************************************************/

#ifndef BITBLOQMBOT_H
#define BITBLOQMBOT_H

#include <BitbloqMCore.h>

// class predeclaration

class US;
class BitbloqDCMotor;
class BitbloqMeRGBLed;

class BitbloqMBot:public BitbloqMCore
{

public:
    BitbloqMBot(int lineFollowerPort = 2, int USPort = 3); // public constructor
    virtual ~BitbloqMBot(); // virtual public destructor

    /**
     * Sets pinmode of sensors and actuators (as in standard Arduino setup)
     */
    void setup();

    /**
     * gets distance measured by US sensor
     * @return distance in cm
     */
    int readUSMeasuredDistanceCM() const;

    /**
     * gets distance measured by US sensor
     * @return distance in inches
     */
    int readUSMeasuredDistanceIN() const;

    /**
     * gets right IR sensor status (digital)
     * @return IR sensor status
     */
    int readRightLineFollowerSensor() const;


    /**
     * gets left IR sensor status (digital)
     * @return IR sensor status
     */
    int readLeftLineFollowerSensor() const;

    void move(int direction, int speed);
    void setRightMotorSpeed(int speed);
    void setLeftMotorSpeed(int speed);


private:

    BitbloqMeRGBLed* boardLeds;

    int usTriggerPin; /// set from port using ports array.
    int usEchoPin; /// set from port using ports array.
    int rightLineFollowerPin; /// set from port using ports array.
    int leftLineFollowerPin; /// set from port using ports array.

    US* usSensor;
    BitbloqDCMotor* rightDCMotor;
    BitbloqDCMotor* leftDCMotor;
};

#endif
