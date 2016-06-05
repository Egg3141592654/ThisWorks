#include "ShootCatapult.h"

ShootCatapult::ShootCatapult()
{
	// Use Requires() here to declare subsystem dependencies
	Requires(Robot::catapult.get());
}

// Called just before this Command runs the first time
void ShootCatapult::Initialize()
{
}

// Called repeatedly when this Command is scheduled to run
void ShootCatapult::Execute()
{
	if (Robot::oi->getLeftJoystick()->GetRawButton(1))
	{
		printf("Shooting catapult!\n");
		Robot::catapult->Retract();
	}
	else
	{
		Robot::catapult->Shoot();
	}
}

// Make this return true when this Command no longer needs to run execute()
bool ShootCatapult::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void ShootCatapult::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ShootCatapult::Interrupted()
{

}
