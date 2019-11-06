/* Robosub 2019-2020 Stabilization Code 
 *  Current Revision:102719
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


#ifndef Sub_Controller
#define Sub_Controller

#include "Horizontal_Controller.h"

class Sub_Controller{
	private:
		Horizontal_Controller h_controller;
		double angleInput, distanceInput;


//		Vertical_Controller v_controller;
	public:
		Sub_Controller(int, int, int, int); //set left thruster pin, right thruster pin
						//kp, ki, kd  in the array in that order
		void setHorizontalThrusters(int); //set pwm target for horizontal thrusters
		void set_IMU_angle_reading(int);
		void set_IMU_distance_reading(int);
};
#endif
