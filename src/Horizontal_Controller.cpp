/* Robosub 2019-2020 Stabilization Code 
 *  Current Revision:103119
 *  Ricardo Medina
 *  
 *  -- Revision Log --
 *
 * 
 *
 * -- To DO --
 * 
 * 
 * -----USE------ 
 *  Header File for the SUB_Controller
 */


#include "Horizontal_Controller.h"

Horizontal_Controller::Horizontal_Controller(int left_pin, int right_pin, int *h_konstants, int *a_konstants){
	//konstants = kp, ki, kd
	right_thruster = new ThrusterController(right_pin);
	left_thruster = new ThrusterController(left_pin);

	//set up a PID with default values
	//uset the set pid constants methods to set the values
	a_PID = new PID(&a_input, &a_output, &a_setpoint, a_konstants[0], a_konstants[1], a_konstants[2]);
	h_PID = new PID(&h_input, &h_output, &h_setpoint, h_konstants[0]. h_konstants[1], h_konstants[2]);
}


//returns an array of length two for the new setpoints for the left and right thruster respectivly
void Horizontal_Controller::mixer(){
	//to do
	int[] setpoints = [0,0];
	setPoints[0] = h_output + a_output * LEFT;
	setPoints[1] = h_output + a_output * RIGHT;	
}

void Horizontal_Controller::setSetpoints(horiozntal, angle){
	//set the new desired angle and distance
	h_setpoint = horizontal;
	a_setpoint = angle;
}

void HorizontalController::setMaxDistance(max){

}

void HorizontalController::update(){
	//update the desired outputs of each controller
	a_PID.Compute();
	h_PID.Compute();

	//calculate the desired signals after mixing the values from the angle and horizontal controler
	setPoints = mixer();
	
	//setpoints[0] = left thruster, setpoints[1] = right thruster
	right_thruster.setPWM(setPoints[0]);
	left_thruster.setPWM(setPoints[1]);
}
