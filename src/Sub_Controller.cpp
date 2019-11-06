/* Robosub 2019-2020 Stabilization Code 
 *  Current Revision:103119
 *  Ricardo Medina
 *  
 *  -- Revision Log --
 *  102719 Current version only supports two horizontal thrusters
 *  103119 Changes made to add the horizontal controller class
 *
 * -- To DO --
 * Implementation of the vertical stabilizations will occur in this class
 * 
 * -----USE------ 
 *  Create the Sub object with the horisonal and vertical stabilizers
 *  recieves input from the IMU and sends the data to the trusters
 */

#include "Sub_Controller.h"

//Need to consider scalability
Sub_Controller::Sub_Controller(int left_pin, int right_pin, double *hor_PID_konstants, double *ang_PID_konstants){

	h_controller = new HorizontalController(left_pin, right_pin, hor_PID_konstants, ang_PID_konstants);
	h_controller.set_h_setpoint(1500);//sets the default 1500 of neutral to the thrusters
	h_controller.set_a_setpoint(1500);//need to update to see how to make this respond porperly
	
}	

void Sub_Controller::setHorizontalThrusters(double setpoint){
	h_controller.set(setpoint);
}

void Sub_Controller::setAngleInput(double input){
	imu_angle_reading = input;
}

void Sub_Controller::setDistanceInput(double input){
	imu_angle_reading = input;
}
