#ifndef ShootCatapult_H
#define ShootCatapult_H

#include "WPILib.h"

#include "../Robot.h"

class ShootCatapult: public Command
{
public:
	ShootCatapult();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
