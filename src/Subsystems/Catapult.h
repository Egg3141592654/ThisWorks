#ifndef Catapult_H
#define Catapult_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class Catapult: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	std::shared_ptr<DoubleSolenoid> solenoidDouble;
	std::shared_ptr<DoubleSolenoid> solenoidSingle;
public:
	Catapult();
	void InitDefaultCommand();
	void Shoot();
	void Retract();
};

#endif
