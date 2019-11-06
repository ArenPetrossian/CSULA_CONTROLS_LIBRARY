/*
 * Sub_Controller.cpp
 *
 *  Created on: Nov 4, 2019
 *      Author: ricardo
 */

#include "Sub_Controller.h"

//Need to consider scalability
Sub_Controller::Sub_Controller(int left_pin, int right_pin, double *hor_PID_konstants, double *ang_PID_konstants){

	h_controller = new Horizontal_Controller(left_pin, right_pin, hor_PID_konstants, ang_PID_konstants);

	//need to find the best defaults for the intialization
	h_controller.setSetPoints(1500, 1500);//sets the horizontal, angle setpoints
}

void Sub_Controller::setHorizontalSetPoints(double distance, double angle){
	h_controller.setSetPoints(distance, angle);
}

void Sub_Controller::update(double distance, double angle){
	h_controller.update(distance, angle);
}

//void Sub_Controller::setAngleInput(double *input){
//	imu_angle_reading = *input;
//}
//
//void Sub_Controller::setDistanceInput(double *input){
//	imu_angle_reading = *input;
//}


