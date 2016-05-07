// Motor.h

#ifndef _SERVOMOTOR_h
#define _SERVOMOTOR_h

#include <Arduino.h>

//#include "StandardCplusplus.h"
//#include "vector"
using namespace std;

#include <Servo.h>

#include "SerialExt.h"
#include "RTCExt.h"
//#include "RunScheduleExt.h" <- only needed for non RTC Timer
//#include "PinValMemoryExt.h"
#include "AnalogSwitch.h"
using namespace Utils;
using namespace Models;

class ServoMotor {
public:
	Servo TheServo;
	AnalogSwitch TheSwitch;
	int Shakes;
	long RunEverySeconds;
	short RelayPin;
protected:
	int _theSpeed;
	AccessoryType ServoType;
private:
	int _pin;
	int _pos;
	
public:
	bool ShouldRunMotor(bool printToSerial);
	void PrintSerialInstructions();
	void SetShakes(int shakes);
	int GetShakes();
	bool ProcessSerialInput(int incomingNum);

	//3-6 = 6 shakes, returns true if could process successfully
	static bool ProcessSerialInput(int incomingNum, vector<ServoMotor> motors);
	
	//1 to run, 2 to run demo
	static bool ShouldRunMotorBySerialInput(int incomingByte);
	static bool ShouldRunMotorDemo(int incomingByte);
	int Calibrate();
	
protected:
	/*ServoMotor(Servo servo, int pin, int shakes, long runEverySeconds);
	ServoMotor(Servo servo, int pin, int shakes, short relayPin);
	ServoMotor(Servo servo, int pin, int shakes);
	ServoMotor(Servo servo, int pin, int shakes, short relayPin, long runEverySeconds);
	ServoMotor(Servo servo, int pin, int shakes, long runEverySeconds, AnalogSwitch theSwitch);
	ServoMotor(Servo servo, int pin, int shakes, short relayPin, long runEverySeconds, AnalogSwitch theSwitch);

	ServoMotor(Servo servo, int pin, int shakes, int pos, int theSpeed);
	ServoMotor(Servo servo, int pin, int shakes, int pos, int theSpeed, short relayPin);
	ServoMotor(Servo servo, int pin, int shakes, int pos, int theSpeed, short relayPin, long runEverySeconds);*/
	ServoMotor(Servo servo, int pin, int shakes, int pos, int theSpeed, short relayPin, long runEverySeconds, AnalogSwitch theSwitch);
	ServoMotor();
	
	static int GetNumberOfShakes(int potVal);
	void Run();
	static void RunMotorDemos(vector<ServoMotor> motors);
	static void RunMotorDemo(Servo myServo);
	
private:
	void Init();
	void TranslateSpeed();
	bool ShouldSignalRelay();
	int GetNextRunInSeconds();
	bool IsSwitchOn(bool isTimeToRun);
	void RunServo();
};

#endif

