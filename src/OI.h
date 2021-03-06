// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#ifndef OI_H
#define OI_H

#include "WPILib.h"

class OI {
private:

	// This is the right hand driver joystick. Nobody should access this straight.
	std::shared_ptr<Joystick> rightJoystick;

	// This is the left hand operator joystick. Nobody should access this straight.
	std::shared_ptr<Joystick> leftJoystick;

	// This is the button which we will use to drive the collector to intake.
	std::shared_ptr<JoystickButton> collectorReverse;

	std::shared_ptr<JoystickButton> collectorForward;

	// This is the operator Xbox controller.
	// Joysticks are denoted the same way, but this is an xbox controller.
	std::shared_ptr<Joystick> operatorJoystick;

public:
	/*
	 * Initializes a new instance of the OI (operator input) class.
	 */
	OI();

	/*
	 * This method will return a shared pointer to the operator joystick so that
	 * you may control from there.
	 *
	 * @return: A joystick pointer. Note that this is supposed to be an Xbox controller.
	 */
	std::shared_ptr<Joystick> getOperatorJoystick();

	/*
	 * This method will return a pointer to the left driver joystick
	 *
	 * @return: A joystick pointer to the driver's left joystick.
	 */
	std::shared_ptr<Joystick> getLeftJoystick();

	/*
	 * This method will return a pointer to the right driver joystick
	 *
	 * @return: A joystick pointer to the driver's right joystick.
	 */
	std::shared_ptr<Joystick> getRightJoystick();
};

#endif
