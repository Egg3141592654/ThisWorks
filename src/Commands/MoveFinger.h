// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#ifndef MOVEFINGER_H
#define MOVEFINGER_H


#include "Commands/Subsystem.h"
#include "../Robot.h"

/**
 * This is the class that encapsulates all of the function to move the finger effector.
 */
class MoveFinger: public Command {
public:
	/*
	 * Instantiates a new instance of the MoveFinger class. Creating this class ensures that the finger will
	 * be controlled. Only use this in teleop mode.
	 */
	MoveFinger();

	/*
	 * This method is called to run once when this command runs.
	 */
	virtual void Initialize();

	/*
	 * This is the method that will actually take in inputs from the joysticks and move the finger.
	 */
	virtual void Execute();

	/*
	 * This method determines if the arm command has actually completed. In Teleop, we should never complete
	 * this command.
	 */
	virtual bool IsFinished();

	/*
	 * This is the method called once when it is declared "finished". We do nothing here.
	 */
	virtual void End();

	/*
	 * This method gets called when another instance of the command is called and we need to let it go.
	 * We shouldn't do anything special here...
	 */
	virtual void Interrupted();
};

#endif
