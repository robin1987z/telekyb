/*
 * FiltFlyTo.hpp
 *
 *  Created on: Jan 9, 2012
 *      Author: mriedel
 */

#ifndef FILTFLYTO_HPP_
#define FILTFLYTO_HPP_

#include <telekyb_defines/telekyb_defines.hpp>

#include <tk_behavior/Behavior.hpp>

// plugin stuff
#include <pluginlib/class_list_macros.h>

#include <telekyb_base/Filter/QuadrupleIntegrator.hpp>
#include <telekyb_base/Time.hpp>

using namespace TELEKYB_NAMESPACE;

namespace telekyb_behavior {

class FiltFlyTo : public Behavior {
protected:

	Option<Position3D>* tFlyToDestination; // destination
	Option<double>* tFlyToYawDestination; // destination
	Option<double>* tGroundHeight;

	Option<Eigen::Vector4d>* tSmoothingGains;
	Option<Eigen::Vector2d>* tSmoothingGainsYaw;

	Option<bool>* tPublishSmoothedTrajectory;
	Option<std::string>* tSmoothedTrajectoryTopic;

	QuadrupleIntegrator filter;
	QuadrupleIntegratorState filterState;

	bool firstStep;

	telekyb::Timer timer;

public:
	FiltFlyTo();

	virtual void initialize();
	virtual void destroy();

	// Called directly after Change Event is registered.
	virtual bool willBecomeActive(const TKState& currentState, const Behavior& previousBehavior);
	// Called after actual Switch. Note: During execution trajectoryStepCreation is used
	virtual void didBecomeActive(const TKState& currentState, const Behavior& previousBehavior);
	// Called directly after Change Event is registered: During execution trajectoryStepTermination is used
	virtual void willBecomeInActive(const TKState& currentState, const Behavior& nextBehavior);
	// Called after actual Switch. Runs in seperate Thread.
	virtual void didBecomeInActive(const TKState& currentState, const Behavior& nextBehavior);

	// called everytime a new TKState is available AND it is the NEW Behavior of an active Switch
	virtual void trajectoryStepCreation(const TKState& currentState, TKTrajectory& generatedTrajInput);

	// called everytime a new TKState is available. Should return false if invalid (swtich to next behavior, or Hover if undef).
	virtual void trajectoryStepActive(const TKState& currentState, TKTrajectory& generatedTrajInput);

	// called everytime a new TKState is available AND it is the OLD Behavior of an active Switch
	virtual void trajectoryStepTermination(const TKState& currentState, TKTrajectory& generatedTrajInput);

	// Return true if the active Behavior is (still) valid. Initiate Switch otherwise
	virtual bool isValid(const TKState& currentState) const;

};

} /* namespace telekyb_behavior */
#endif /* DYNAMICFLYTO_HPP_ */
