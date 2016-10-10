class MeRGBLed;
class MeBuzzer;
class MeUltrasonicSensor;
class MeLightSensor;
class MeDCMotor;

class MBot
{

	public:
		MBot();
		virtual ~MBot();

	    void init();
	    void setLed(int led, int red, int green, int blue);
	    void tome();
	    int getDistance();
	    int getButtonStatus();
	    int getLightSensor();
	    void move(int direction, int speed);

	private:
		MeRGBLed* boardLeds;
		MeBuzzer* buzzer;
		MeUltrasonicSensor* ultrasonicSensor;
		MeLightSensor* lightSensor;
		MeDCMotor* leftMotor;
		MeDCMotor* rightMotor;
};