// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "Robot.h"

std::shared_ptr<Drive> Robot::drive;
std::shared_ptr<WheelieBar> Robot::wheelieBar;
std::shared_ptr<Finger> Robot::finger;
std::shared_ptr<Elevator> Robot::elevator;
std::shared_ptr<Pneumatics> Robot::pneumatics;
std::shared_ptr<Arm> Robot::arm;
std::shared_ptr<Collector> Robot::collector;
std::unique_ptr<OI> Robot::oi;
std::shared_ptr<DigitalInput> Robot::lowBarPin;
std::shared_ptr<DigitalInput> Robot::moatPin;
std::shared_ptr<DigitalInput> Robot::portcullisPin;
std::shared_ptr<DigitalInput> Robot::roughTerrainPin;
std::shared_ptr<DigitalInput> Robot::rampartPin;
std::shared_ptr<DigitalInput> Robot::rockwallPin;
std::shared_ptr<DigitalInput> Robot::chevaldefrisePin;

void Robot::RobotInit() {
	RobotMap::init();

	// Initialize all of the subsystems on the robot
    drive.reset(new Drive());
    wheelieBar.reset(new WheelieBar());
    finger.reset(new Finger());
    elevator.reset(new Elevator());
    pneumatics.reset(new Pneumatics());
    arm.reset(new Arm());
    collector.reset(new Collector());

	// This MUST be here. If the OI creates Commands (which it very likely
	// will), constructing it during the construction of CommandBase (from
	// which commands extend), subsystems are not guaranteed to be
	// yet. Thus, their requires() statements may grab null pointers. Bad
	// news. Don't move it.
	oi.reset(new OI());

	// Initialize the autonomous inputs
	lowBarPin.reset(new DigitalInput(AUTO_LOWBAR_PIN));
	moatPin.reset(new DigitalInput(AUTO_MOAT_PIN));
	portcullisPin.reset(new DigitalInput(AUTO_PORTC_PIN));
	roughTerrainPin.reset(new DigitalInput(AUTO_ROUGHT_PIN));
	rampartPin.reset(new DigitalInput(AUTO_RAMPART_PIN));
	rockwallPin.reset(new DigitalInput(AUTO_ROCKWALL_PIN));
	chevaldefrisePin.reset(new DigitalInput(AUTO_CHEVAL_PIN));
	// Default autonomous is defense creep
	autoCommand = new DefenseCreep();
  }

/**
 * This function is called when the disabled button is hit.
 * You can use it to reset subsystems before shutting down.
 */
void Robot::DisabledInit(){
	printf("State of autonomous pins:\n");
	printf("LowBarState: %d\n", lowBarPin->Get());
	printf("MoatState: %d\n", moatPin->Get());
	printf("PortcullisState: %d\n", portcullisPin->Get());
	printf("RoughTerrainPin: %d\n", roughTerrainPin->Get());

	if (autoCommand != nullptr)
	{
		delete autoCommand;
	}

	// Pins pull high, invert logic
	if (!lowBarPin->Get())
	{
		printf("Selected Low Bar\n");
		autoCommand = new LowBar();
	}
	else if(!moatPin->Get())
	{
		printf("Selected Moat\n");
		autoCommand = new Moat();
	}
	else if(!portcullisPin->Get())
	{
		printf("Selected Portcullis\n");
		autoCommand = new Portcullis();
	}
	else if(!roughTerrainPin->Get())
	{
		printf("Selected RoughTerrain\n");
		autoCommand = new RoughTerrian();
	}
	else if(!rampartPin->Get())
	{
		printf("Selected Ramparts\n");
		autoCommand = new Ramparts();
	}
	else if(!rockwallPin->Get())
	{
		printf("Selected Rockwall\n");
		autoCommand = new Rockwall();
	}
	else
	{
		printf("Selected DefenseCreep\n");
		autoCommand = new DefenseCreep();
	}

	printf("Hi guys, I hope you have a good match out there - SubZero");
}

void Robot::DisabledPeriodic() {
	Scheduler::GetInstance()->Run();
}

void Robot::AutonomousInit() {
	printf("Autonomous initialized.\n");
	autoCommand->Start();
}

void Robot::AutonomousPeriodic() {
	Scheduler::GetInstance()->Run();
}

void Robot::TeleopInit() {
	// This makes sure that the autonomous stops running when
	// teleop starts running. If you want the autonomous to
	// continue until interrupted by another command, remove
	// these lines or comment it out.
	autoCommand->Cancel();
	Scheduler::GetInstance()->RemoveAll();
}

void Robot::TeleopPeriodic() {
	Scheduler::GetInstance()->Run();
}

void Robot::TestPeriodic() {
	lw->Run();
}

START_ROBOT_CLASS(Robot);

