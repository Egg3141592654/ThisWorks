// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.




#include "Drive.h"
#include "../RobotMap.h"
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
#include "../Commands/TankDrive.h"
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS

Drive::Drive() : Subsystem("Drive") {
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
    driveMotorL1 = RobotMap::driveDriveMotorL1;
    driveMotorL2 = RobotMap::driveDriveMotorL2;
    driveMotorR1 = RobotMap::driveDriveMotorR1;
    driveMotorR2 = RobotMap::driveDriveMotorR2;


    // robotDrive41 = RobotMap::driveRobotDrive41;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	// Initialize the robot drive. The constructor is documented at
	// http://first.wpi.edu/FRC/roborio/release/docs/cpp/classRobotDrive.html#a47180c144fcca9e7550f7cb906c8b79a
	drive = new RobotDrive(
		    driveMotorL1,
		    driveMotorL2,
		    driveMotorR1,
		    driveMotorR2);

	drive->SetInvertedMotor(drive->kFrontLeftMotor, false);
	drive->SetInvertedMotor(drive->kRearLeftMotor, false);
	drive->SetInvertedMotor(drive->kFrontRightMotor, true);
	drive->SetInvertedMotor(drive->kRearRightMotor, true);


}

void Drive::InitDefaultCommand() {
    // Set the default command for a subsystem here.
    // SetDefaultCommand(new MySpecialCommand());
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND

        SetDefaultCommand(new TankDrive());
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
}

void Drive::MyDrive(float left, float right)
{
	drive->TankDrive(left, right);
}

void Drive::MyDrive(Joystick * leftStick, Joystick * rightStick)
{
	drive->TankDrive(leftStick->GetY(),rightStick->GetY());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

