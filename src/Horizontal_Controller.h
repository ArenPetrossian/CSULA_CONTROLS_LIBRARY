/*
 * Horizontal_Controller.h
 *
 *  Created on: Nov 4, 2019
 *      Author: ricardo
 */

#ifndef SRC_HORIZONTAL_CONTROLLER_H_
#define SRC_HORIZONTAL_CONTROLLER_H_

#include "Thruster_Controller.h"
#include "PID_v1.h"

class Horizontal_Controller {
	private:
		Thruster_Controller right_thruster, left_thruster;
		PID h_PID, a_PID;
		double h_input, h_output, h_setpoint, a_input, a_output, a_setpoint;
		double max_distance;
		//define the direction for the right and left PID values from the Angle PID
		static int LEFT = 1;
		static int RIGHT = -1;

		//needs to be updated, C++ cannot return arrays
		double *mixer(); //left, right
		//mixer just needs to add errror pid values from angle

	public:
		Horizontal_Controller(int left_pin, int right_pin, double* h_konstants, double* a_konstants);//left pin, right pin, h_konstatt, a_konstant

		void update(double distance, double angle); //supply current readings of each
		void setSetPoints(double horizontal, double angle);//horizontal, angle
		void setMaxDistance(double distance); // set the max distance that the pid can reliably controll
									//anython sbove sets the max pwm
};



#endif /* SRC_HORIZONTAL_CONTROLLER_H_ */
