#include "Catapult.h"
#include "../RobotMap.h"
#include "../OI.h"
#include "../Robot.h"
#include "../Commands/ShootCatapult.h"

Catapult::Catapult() :
		Subsystem("Catapult")
{
	solenoidSingle = RobotMap::catapultsingledirection;
	solenoidDouble = RobotMap::catapultBidirectional;
}

void Catapult::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	SetDefaultCommand(new ShootCatapult());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
void Catapult::Shoot()
{
	solenoidSingle->Set(DoubleSolenoid::Value::kReverse);
	solenoidDouble->Set(DoubleSolenoid::Value::kReverse);
}

void Catapult::Retract()
{
	solenoidSingle->Set(DoubleSolenoid::Value::kForward);
	solenoidDouble->Set(DoubleSolenoid::Value::kForward);
}
