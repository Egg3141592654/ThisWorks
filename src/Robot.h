// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#ifndef _ROBOT_H
#define _ROBOT_H

#include "WPILib.h"
#include "Commands/Command.h"
#include "RobotMap.h"
#include "LiveWindow/LiveWindow.h"

//#include "Subsystems/Arm.h"
//#include "Subsystems/Collector.h"
#include "Subsystems/Catapult.h"
#include "Subsystems/Drive.h"
#include "Subsystems/Pneumatics.h"
#include "Subsystems/Shooter.h"

// Autonomous commands
//#include "Commands/LowBar.h"
//#include "Commands/Moat.h"
//#include "Commands/Portcullis.h"
//#include "Commands/RoughTerrian.h"
//#include "Commands/DefenseCreep.h"
//#include "Commands/Ramparts.h"
//#include "Commands/Rockwall.h"
//#include "Commands/ChevaldeFrise.h"

#include "OI.h"

class Robot : public IterativeRobot {
private:
	// Initialize the autonomous pins privately. Nothing should be
	// using these pins, or else things could get nasty...
public:
	/*
	 * Gets or sets the live window for smart dash-board stuff
	 */
	LiveWindow *lw = LiveWindow::GetInstance();

	/*
	 * Gets or sets the operators input pointer for control.
	 */
	static std::unique_ptr<OI> oi;

	/*
	 * Gets or sets the drive base subsystem for the robot.
	 */
    static std::shared_ptr<Drive> drive;

    /*
     * Gets or sets the pneumatics subsystem of the robot.
     */
    static std::shared_ptr<Pneumatics> pneumatics;

    /**
     *TODO WRITE STUFF HERE
     */
    static std::shared_ptr<Catapult> catapult;

    /**
     *TODO WRITE STUFF HERE
     */
    static std::shared_ptr<Shooter> shooter;

    // Required methods by IterativeRobot
    // I am too lazy to document these, go online to see detailed documentation
    // as to what each of these methods does.
    // Hint: Same place as the docs for all of the rest of WpiLib :)
	virtual void RobotInit();
	virtual void DisabledInit();
	virtual void DisabledPeriodic();
	virtual void AutonomousInit();
	virtual void AutonomousPeriodic();
	virtual void TeleopInit();
	virtual void TeleopPeriodic();
	virtual void TestPeriodic();
};
#endif
