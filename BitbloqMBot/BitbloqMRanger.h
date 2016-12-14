
/******************************************************************************
* MakeBlock MBot control library for Bitbloq
* 
*
* @author Tomas Calvo - tomas.calvo@bq.com
* @author Alberto Valero - alberto.valero@bq.com
*
******************************************************************************/

#ifndef BITBLOQMRANGER_H
#define BITBLOQMRANGER_H

class MeRGBLed;
class MeLightSensor;
class MeEncoderOnBoard;

class MRanger
{

	
	public:
		MRanger(MeEncoderOnBoard* , MeEncoderOnBoard*); //public constructor
		virtual ~MRanger(); //virtual public destructor

		MeEncoderOnBoard* enc1;
		MeEncoderOnBoard* enc2;

		void init();
		
		/**
		 * Choose led and set color
		 * @param led led number
		 * @param red red component of rgb color
		 * @param green green component of rgb color
		 * @param blue blue component of rgb color
		 */
		void setLed(int led, int red, int green, int blue);
		/**
		 * gets distance measured by US sensor
		 * @param port port number
		 * @return distance in cm*/
		int getDistance(int port);

		/**
		 * Gets LDR sensor measure (analog)
		 * @return LDR reading
		 */
		int getLightSensor(int numSensor);
		/**
		 * gets IR sensor status (digital)
		 * @param IR sensor pin
		 * @return IR sensor status
		 */
		int getLineFollower(int port);

		void move(int direction, int speed);

	private:
		MeRGBLed* boardLeds;
		MeLightSensor* lightSensor1;
		MeLightSensor* lightSensor2;
};

#endif
