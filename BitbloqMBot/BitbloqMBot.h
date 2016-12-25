
/******************************************************************************
* MakeBlock MBot control library for Bitbloq
* 
*
* @author Tomas Calvo - tomas.calvo@bq.com
* @author Alberto Valero - alberto.valero@bq.com
*
******************************************************************************/

#ifndef BITBLOQMBOT_H
#define BITBLOQMBOT_H


//class predeclaration

class US;
class BitbloqDCMotor;
class BitbloqMeRGBLed;

class MBot
{

	public:
		MBot(); //public constructor
		virtual ~MBot(); //virtual public destructor
        
        /**
         * Sets pinmode of sensors and actuators (as in standard Arduino setup)
         */
        void setup();

		/**
		 * Choose led and set color
		 * @param led led number
		 * @param red red component of rgb color
		 * @param green green component of rgb color
		 * @param blue blue component of rgb color
		 */
		void setLed(int led, int red, int green, int blue);
		
        /**
         * Play tone
         * @param note note frequency
         * @param beat time active
         */
        void playTone(int note, int beat);

		/**
		 * gets distance measured by US sensor
		 * @return distance in cm
         */
		int readDistance();


		/**
		 * gets button status (0, 1023)
         * @return button status
		 */
		int readButtonStatus() const;
        
        /**
		 * gets wether buttons is pressed or not
         * @return button is pressed (true false)
		 */
        bool isButtonPushed() const;
		
        /**
		 * Gets LDR sensor measure (analog)
		 * @return LDR reading
		 */
		int readLightSensor() const;
		
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

        const int buzzerPin; ///pin where the buzzer is connected. It is hardwired on the board (D8)
        const int lightSensorPin; ///pin where the light sensor is connected. It is hardwired on the board (A6) 
        const int buttonPin; ///pin where the buzzer is connected. It is hardwired on the board (A7)
        const int usTriggerPin;
        const int usEchoPin;
        const int rightLineFollowerPin;
        const int leftLineFollowerPin;
        const int rightDCMotorDir;
        const int rightDCMotorPWM;
        const int leftDCMotorDir;
        const int leftDCMotorPWM;
        const int rgbLEDPin;
                
        US* usSensor;
        BitbloqDCMotor* rightDCMotor;
        BitbloqDCMotor* leftDCMotor;
        BitbloqMeRGBLed* rgbLED;
        
};

#endif       


