#include "Thruster_Controller.h"

Thruster_Controller::Thruster_Controller(int pin){
	//note that attach also has a attach(pin, minPwm, maxPwm)
		
	thrusterServo = new Servo();
	thrusterServo.attach(pin);
}

Thruster_Controller::setPWM(double pwm_signal){
	thrusterServo.writeMicroseconds(pwm_signal);
}
