// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.




#include "Arm.h"
#include "../RobotMap.h"
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
#include "../Commands/MoveArm.h"
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS

Arm::Arm() : PIDSubsystem("Arm", 0.1, 0.0, 0.0) {
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
    aRM_MOTOR_1 = RobotMap::armARM_MOTOR_1;
    aRM_MOTOR_2 = RobotMap::armARM_MOTOR_2;
    encoder = RobotMap::encoder;
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS

	// ALWAYS SET A PID SYSTEM TO A START POINT!
	setPoint = 0;
	SetSetpoint(setPoint);

	Enable();

}

void Arm::InitDefaultCommand() {
    // Set the default command for a subsystem here.
    // SetDefaultCommand(new MySpecialCommand());
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND

        SetDefaultCommand(new MoveArm());
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
}

double Arm::ReturnPIDInput(){
	printf("Arm Current Position: %f\n", encoder->GetDistance());
	return encoder->GetDistance();
}

void Arm::UsePIDOutput(double output){
	// Use output to drive your system, like a motor
	// e.g. yourMotor->Set(output);

	// Cap the values at 1 so nothing strange happens
	if (output > .3)
	{
		output = .3;
	}

	// Limit lower values as well
	if (output < -.3)
	{
		output = -.3;
	}

	// Write speed to the motors. Note that we don't have to reverse them since we took care of that already.
	aRM_MOTOR_1->Set((float)output);
	aRM_MOTOR_2->Set((float)output);
}

/*
void Arm::Drive(float speed) {
	aRM_MOTOR_1->Set(speed);
	aRM_MOTOR_2->Set(-speed);
}
*/

// Put methods for controlling this subsystem
// here. Call these from Commands.

void Arm::SetNewPosition(double newTarget, bool isRelative)
{
	printf("set new target arm position %f\n", newTarget);

	if (newTarget > 80)
	{
		newTarget = 80;
	}

	if (newTarget < -18)
	{
		newTarget = -18;
	}

	if (!isRelative)
	{
		setPoint = newTarget;
	}

	SetSetpoint(newTarget);
}

void Arm::SetNewRelativePosition(Joystick * stick)
{
	double newPosition = setPoint -
			(8. * stick->GetRawAxis(1));

	// printf("Joystick values %f\n", stick->GetRawAxis(1));
	printf("new relative position %f\n", newPosition);

	this->SetNewPosition(newPosition, true);
}

double Arm::GetTarget()
{
	return setPoint;
}
