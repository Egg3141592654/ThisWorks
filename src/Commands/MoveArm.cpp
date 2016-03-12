// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "MoveArm.h"

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

MoveArm::MoveArm(): Command() {
        // Use requires() here to declare subsystem dependencies
    // eg. requires(chassis);
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES


    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES

	// Init to origin plane
	init(0.0);
}
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

MoveArm::MoveArm(double position) : Command()
{
	// Init to some other point.
	init(position);
}

void MoveArm::init(double initialPosition)
{
	Requires(Robot::arm.get());

	Robot::arm->SetNewPosition(initialPosition);
}

// Called just before this Command runs the first time
void MoveArm::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void MoveArm::Execute() {
//	Robot::arm->Drive(.35*Robot::oi->getOperatorJoystick()->GetRawAxis(1));
	// Determine which button is pushed. There is a precedence here (for low values)
	if (Robot::oi->getOperatorJoystick()->GetRawAxis(2) >= .75)
	{
		// Turn off the PID if needed
		Robot::arm->EnablePID(false);
		Robot::arm->Drive(-(Robot::oi->getOperatorJoystick()->GetRawAxis(1)));
	}
	else
	{
		// Turn on the PID if needed
		Robot::arm->EnablePID(true);

		if (Robot::oi->getOperatorJoystick()->GetRawButton(4))
		{
			printf("position 60 \n");

			Robot::arm->SetNewPosition(60.);

		}
		else if(Robot::oi->getOperatorJoystick()->GetRawButton(5))
		{
			printf("position 70 \n");

			Robot::arm->SetNewPosition(20.);
		}
		else if(Robot::oi->getOperatorJoystick()->GetRawButton(6))
		{
			printf("position 40 \n");

			Robot::arm->SetNewPosition(40.);

		}
		else if(Robot::oi->getOperatorJoystick()->GetRawButton(7))
		{
			printf("position 20 \n");

			Robot::arm->SetNewPosition(10.);

		}
		else if(Robot::oi->getOperatorJoystick()->GetRawButton(8))
		{
			printf("position -3 \n");

			Robot::arm->SetNewPosition(-10.);

		}
		else
		{
			// Do nothing
		}
	}

	Robot::arm->SetNewRelativePosition(Robot::oi->getOperatorJoystick().get());
}

// Make this return true when this Command no longer needs to run execute()
bool MoveArm::IsFinished() {
    return false;
}

// Called once after isFinished returns true
void MoveArm::End() {
//	Robot::arm->Drive(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void MoveArm::Interrupted() {

}
