// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "MoveElevator.h"

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

MoveElevator::MoveElevator(bool p_previousState, bool p_pushedButton): Command() {
    pushedButton = p_pushedButton;
    previousState = p_previousState;
        // Use requires() here to declare subsystem dependencies
    // eg. requires(chassis);
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::elevator.get());
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
}
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

// Called just before this Command runs the first time
void MoveElevator::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void MoveElevator::Execute() {

	pushedButton = Robot::oi->getOperatorJoystick()->GetRawButton(1)
			&& Robot::oi->getOperatorJoystick()->GetRawButton(4);
	if(pushedButton)
	{
		Robot::elevator->Up();
	}
	else
	{
		Robot::elevator->Down();
	}
}

// Make this return true when this Command no longer needs to run execute()
bool MoveElevator::IsFinished() {
    return false;
}

// Called once after isFinished returns true
void MoveElevator::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void MoveElevator::Interrupted() {

}
