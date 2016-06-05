#ifndef WheelShooter_H
#define WheelShooter_H

#include "WPILib.h"
#include "../Robot.h"

class WheelShooter: public Command
{
public:
	WheelShooter();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
