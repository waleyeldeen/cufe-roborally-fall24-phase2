#pragma once
#include "Action.h"
#include "Input.h"
#include "Output.h"
#include"Antenna.h"

class ExecuteAntennaAction: public Action
{
	CellPosition AntennaPos;

public:
	ExecuteAntennaAction(ApplicationManager* pApp);
	virtual void ReadActionParameter();
	virtual void Execute();
	~ExecuteAntennaAction();

};

