#include "Shooter.h"
#include "../RobotMap.h"
#include "../Commands/WheelShooter.h"

Shooter::Shooter() :
		Subsystem("Shooter")
{
	driveR3 = RobotMap::driveDriveMotorR3;
	driveL3 = RobotMap::driveDriveMotorL3;
}

void Shooter::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	SetDefaultCommand(new WheelShooter());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
void Shooter::Shoot(float speed)
{
	driveR3->Set(speed);
	driveL3->Set(-speed);
}

void Shooter::DontShoot()
{
	driveR3->StopMotor();
	driveL3->StopMotor();
}
