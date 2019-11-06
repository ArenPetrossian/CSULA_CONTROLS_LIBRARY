/*
 * Thruster_Controller.h
 *
 *  Created on: Nov 4, 2019
 *      Author: ricardo
 */

#ifndef SRC_THRUSTER_CONTROLLER_H_
#define SRC_THRUSTER_CONTROLLER_H_

#include <Servo.h>
#include "PID_v1.h"


class Thruster_Controller{
	public:
		//double check this error
		Thruster_Controller(int pin);// pin
		void setMinPwm(double max); // set min
		void setMaxPwm(double min);	//set max


		//updates the PID and the output to the thrusters
		void setPWM(double pwm_signal);

	private:
		Servo thrusterServo;
};



#endif /* SRC_THRUSTER_CONTROLLER_H_ */
