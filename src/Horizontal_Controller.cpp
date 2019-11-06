/*
 * Horizontal_Controller.cpp
 *
 *  Created on: Nov 4, 2019
 *      Author: ricardo
 */


#include "Horizontal_Controller.h"

Horizontal_Controller::Horizontal_Controller(int left_pin, int right_pin, double *h_konstants, double *a_konstants){
	//konstants = kp, ki, kd
	right_thruster = new Thruster_Controller(right_pin);
	left_thruster = new Thruster_Controller(left_pin);

	//set up a PID with default values
	//uset the set pid constants methods to set the values
	a_PID = new PID(&a_input, &a_output, &a_setpoint, a_konstants[0], a_konstants[1], a_konstants[2], DIRECT);
	h_PID = new PID(&h_input, &h_output, &h_setpoint, h_konstants[0], h_konstants[1], h_konstants[2], DIRECT);
}


//returns an array of length two for the new setpoints for the left and right thruster respectivly
double *Horizontal_Controller::mixer(){
	//to do
	double setPoints[2] = {0,0};
	setPoints[0] = h_output + a_output * LEFT;
	setPoints[1] = h_output + a_output * RIGHT;

	return *setPoints;
}


//second version of the mixerr
//void Results_Mixer (int PID_D_Right_Thruster,int PID_D_Left_Thruster,int PID_A_Right_Thruster,int PID_A_Left_Thruster) {
//  if (PID_A_Right_Thruster == 0){
//    Right_Thruster.Set_Thruster_Target(converter(PID_D_Right_Thruster));
//  } else{
//    Right_Thruster.Set_Thruseter_Target(converter((PID_A_Right_Thruster + PID_D_Right_Thruster)/2))
//  }
//
//  if (PID_A_Left_Thruster == 0){
//    Left_Thruster.Set_Thruster_Target(converter(PID_D_Left_Thruster));
//  }else{
//    Left_Thruster.Set_Thruster_Target(converter((PID_A_Left_Thruster + PID_D_Left_Thruster)/2))
//  }
//
//}

void Horizontal_Controller::setSetPoints(double horizontal, double angle){
	//set the new desired angle and distance
	h_setpoint = horizontal;
	a_setpoint = angle;
}

void Horizontal_Controller::setMaxDistance(double max){
	max_distance = max;
}

void Horizontal_Controller::update(double distance, double angle){
	//update the current inputs from nav of each controller
	a_input = angle;
	h_input = distance;

	//compute new outputs
	a_PID.Compute();
	h_PID.Compute();

	//calculate the desired signals after mixing the values from the angle and horizontal controler
	//returns an array of size 2
	int *setPoints = mixer();// left, right

	//setpoints[0] = left thruster, setpoints[1] = right thruster
	right_thruster.setPWM(setPoints[0]);
	left_thruster.setPWM(setPoints[1]);
}


