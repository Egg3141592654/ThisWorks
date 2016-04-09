// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.




#include "Collector.h"
#include "../RobotMap.h"

#include "../Commands/MoveCollector.h"

Collector::Collector() : Subsystem("Collector") {
    collector = RobotMap::collectorMotor;
}

void Collector::InitDefaultCommand() {
    // Set the default command for a subsystem here.
    // SetDefaultCommand(new MySpecialCommand());
	SetDefaultCommand(new MoveCollector());
}

void Collector::In()
{
	collector->Set(.75);
}

void Collector::Out()
{
	collector->Set(-.75);
}

void Collector::Stop()
{
	collector->Set(0);
}

void Collector::Hold()
{
	collector->Set(.25);
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

