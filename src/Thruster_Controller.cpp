/*
 * Thruster_Controller.cpp
 *
 *  Created on: Nov 4, 2019
 *      Author: ricardo
 */


#include "Thruster_Controller.h"

Thruster_Controller::Thruster_Controller(int pin){
	//note that attach also has a attach(pin, minPwm, maxPwm)

	thrusterServo = new Servo();
	thrusterServo.attach(pin);
}

void Thruster_Controller::setPWM(double pwm_signal){
	thrusterServo.writeMicroseconds(pwm_signal);
}


