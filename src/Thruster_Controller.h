#ifndef Thruster_Controller
#define Thruster_Controller

#include <Servo.h>
#include "PID_v1.h"

class Thruster_Controller{
	public:
		//double check this error
		Thruster_Controller(int pin);// pin
		void setMinPwm(double max); // set min
		void setMaxPwm(double min);	//set max


		//updates the PID and the output to the thrusters
		void setPWM(int);
		
	private:
		Servo thrusterServo;		
};

#endif
