/*
 * JoystickOptions.hpp
 *
 *  Created on: Oct 25, 2011
 *      Author: mriedel
 */

#ifndef JOYSTICKOPTIONS_HPP_
#define JOYSTICKOPTIONS_HPP_

#include <telekyb_defines/telekyb_defines.hpp>
#include <telekyb_base/Base.hpp>
#include <telekyb_base/Options.hpp>

namespace TELEKYB_NAMESPACE
{

class JoystickOptions : public OptionContainer, public Singleton<JoystickOptions>
{
public:
	Option<std::string>* tDevicePath;
	Option<double>* tDeadZone;
	Option<double>* tAutoRepeatRate;
	Option<double>* tCoalesceInterval;

	Option<std::string>* tPubName;
	Option< std::vector<int> >* tButtonRemapping;
	Option< std::vector<int> >* tAxesRemapping;
	Option< std::vector<double> >* tAxisMultiplier;

	Option< bool >* tPublishVector3;

	JoystickOptions();
};

} // namespace

#endif /* JOYSTICKOPTIONS_HPP_ */
