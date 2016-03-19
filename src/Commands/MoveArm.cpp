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

MoveArm::MoveArm(): Command("MoveArm") {
        // Use requires() here to declare subsystem dependencies
    // eg. requires(chassis);
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES


    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES

	// Init to origin plane
	Requires(Robot::arm.get());
	this->position = 0.0;
	isAutonomous = false;
}
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

MoveArm::MoveArm(double position) : Command("MoveArm")
{
	// Init to some other point.
	Requires(Robot::arm.get());
	this->position = position;
	isAutonomous = true;
}

// Called just before this Command runs the first time
void MoveArm::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void MoveArm::Execute() {
//	Robot::arm->Drive(.35*Robot::oi->getOperatorJoystick()->GetRawAxis(1));
	// Determine which button is pushed. There is a precedence here (for low values)
	if (isAutonomous)
	{
		Robot::arm->EnablePID(true);
		Robot::arm->SetNewPosition(position);
		return;
	}

	if (Robot::oi->getOperatorJoystick()->GetRawAxis(2) >= .75)
	{
		// Turn off the PID if needed
		Robot::arm->EnablePID(false);
		Robot::arm->Drive(-(Robot::oi->getOperatorJoystick()->GetRawAxis(1) * .3));
	}
	else
	{
		// Turn on the PID if needed
		Robot::arm->EnablePID(true);

		if (Robot::oi->getOperatorJoystick()->GetRawButton(4))
		{
			printf("To climb mode\n");

			Robot::arm->SetNewPosition(85.);

		}
		else if(Robot::oi->getOperatorJoystick()->GetPOV(0)== 0)
		{
			//printf("position 70 \n");

			Robot::arm->SetNewPosition(20.);
		}
		else if(Robot::oi->getOperatorJoystick()->GetPOV(0)== 90)
		{
			//printf("position 40 \n");

			Robot::arm->SetNewPosition(25.);

		}
		else if(Robot::oi->getOperatorJoystick()->GetPOV(0)== 270)
		{
			//printf("position 20 \n");

			Robot::arm->SetNewPosition(10.);

		}
		else if(Robot::oi->getOperatorJoystick()->GetPOV(0) == 180)
				{
			//printf("position -3 \n");

			Robot::arm->SetNewPosition(-12.);

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
	if (isAutonomous)
	{
		if (Robot::arm->AtPosition())
		{
			printf("Finished arm code with value %f\n", Robot::arm->GetTarget());
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

// Called once after isFinished returns true
void MoveArm::End() {
//	Robot::arm->Drive(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void MoveArm::Interrupted() {

}
