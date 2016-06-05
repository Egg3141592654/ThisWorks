#ifndef Shooter_H
#define Shooter_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class Shooter: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	std::shared_ptr<SpeedController> driveR3;
	std::shared_ptr<SpeedController> driveL3;

public:
	Shooter();
	void InitDefaultCommand();
	void Shoot(float);
	void DontShoot();
};

#endif
