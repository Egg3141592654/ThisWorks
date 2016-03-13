// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "TankDrive.h"

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

TankDrive::TankDrive(): Command("TankDrive") {
        // Use requires() here to declare subsystem dependencies
    // eg. requires(chassis);
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES

	Requires(Robot::drive.get());
	isAutonomous = false;
	this->speed = 0.;
}
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

TankDrive::TankDrive(double speed) : Command("TankDrive")
{
	Requires(Robot::drive.get());
	isAutonomous = true;
	this->speed = speed;
}

// Called just before this Command runs the first time
void TankDrive::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void TankDrive::Execute() {

	if (!isAutonomous)
	{
		Robot::drive->MyDrive(-Robot::oi->getLeftJoystick()->GetRawAxis(1), Robot::oi->getRightJoystick()->GetRawAxis(1));
	}
	else
	{
		Robot::drive->MyDrive(speed, -speed);
	}

}

// Make this return true when this Command no longer needs to run execute()
bool TankDrive::IsFinished() {
    return false;
}

// Called once after isFinished returns true
void TankDrive::End() {
Robot::drive->MyDrive(0.,0.);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void TankDrive::Interrupted() {

}
