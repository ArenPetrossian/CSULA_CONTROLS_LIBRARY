/* Robosub 2019-2020 Stabilization Code 
 *  Current Revision:103119
 *  Ricardo Medina
 *  
 *  -- Revision Log --
 *  
 * 
 */
	
#ifndef Horizontal_Controller
#define Horizontal_Controller

#include "Thruster_Controller.h"


class Horizontal_Controller {
	private:
		Thruster_Controller right_thruster, left_thruster;
		PID h_PID, a_PID;
		double h_input, h_output, h_setpoint, a_input, a_output, a_setpoint;
		//define the direction for the right and left PID values from the Angle PID
		static int LEFT = 1;
		static int RIGHT = -1;

		//needs to be updated, C++ cannot return arrays
		double *mixer(); //left, right
		//mixer just needs to add errror pid values from angle

	public:
		Horizontal_Controller(int left_pin, int right_pin, int* h_konstants, int* a_konstants);//left pin, right pin, h_konstatt, a_konstant
		
		void update();
		void setSetPoints(double, double);//horizontal, angle
		void setMaxDistance(double); // set the max distance that the pid can reliably controll
									//anython sbove sets the max pwm
};
#endif
