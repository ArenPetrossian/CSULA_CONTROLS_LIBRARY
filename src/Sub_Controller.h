/*
 * Sub_Controller.h
 *
 *  Created on: Nov 4, 2019
 *      Author: ricardo
 */

#ifndef SRC_SUB_CONTROLLER_H_
#define SRC_SUB_CONTROLLER_H_


#include "Horizontal_Controller.h"

class Sub_Controller{
	private:
		Horizontal_Controller h_controller;
		double angleInput, distanceInput;


//		Vertical_Controller v_controller;
	public:
		Sub_Controller(int left_pin, int right_pin, double *hor_PID_konstants, double *ang_PID_konstants); //set left thruster pin, right thruster pin
						//kp, ki, kd  in the array in that order
		void setHorizontalSetPoints(double distance, double angle); //set pwm target for horizontal thrusters
		void update(double distance, double angle);//update the input values from navigation
//		void set_IMU_angle_reading(double *pwm_signal);
//		void set_IMU_distance_reading(double *pwm_signal);

};


#endif /* SRC_SUB_CONTROLLER_H_ */
