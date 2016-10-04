class MeRGBLed;

class MBot
{
public:
	MBot();
	virtual ~MBot();

    void init();
    void setLed(int led, int red, int green, int blue);
private:
	MeRGBLed* boardLeds;
};