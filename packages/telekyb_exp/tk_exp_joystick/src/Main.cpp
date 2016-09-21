/*
 * Main.cpp
 *
 *  Created on: Nov 15, 2011
 *      Author: mriedel
 */

#include <telekyb_base/TeleKyb.hpp>
#include <ros/ros.h>

#include "Experiment.hpp"

int main(int argc, char **argv) {

	// disable
	//telekyb::RawOptionsContainer::addOption("tRosNrSpinnerThreads","4");
	telekyb::TeleKyb::init(argc,argv, "tk_exp_joystick");

	Experiment* e = new Experiment();

	// spin here
	ros::waitForShutdown();

	delete e;

	telekyb::TeleKyb::shutdown();
}
