#include "WheelShooter.h"

WheelShooter::WheelShooter()
{
	// Use Requires() here to declare subsystem dependencies
	Requires(Robot::shooter.get());
}

// Called just before this Command runs the first time
void WheelShooter::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void WheelShooter::Execute()
{
	if (Robot::oi->getRightJoystick()->GetRawButton(1))
	{
		printf("Shooting catapult with power %f!\n", Robot::oi->getRightJoystick()->GetRawAxis(3));
		Robot::shooter->Shoot(Robot::oi->getRightJoystick()->GetRawAxis(3));
	}
	else
	{
		Robot::shooter->DontShoot();
	}
}

// Make this return true when this Command no longer needs to run execute()
bool WheelShooter::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void WheelShooter::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void WheelShooter::Interrupted()
{

}
