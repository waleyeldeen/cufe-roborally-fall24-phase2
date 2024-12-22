#pragma once
#include "Action.h"
#include "Input.h"
#include "Output.h"
#include"Flag.h"

class ExecuteFlagAction:public Action
{
	CellPosition flagpos;

public:
	ExecuteFlagAction(ApplicationManager* pApp);
	virtual void ReadActionparameters();
	virtual void Execute();
	~ExecuteFlagAction();

	
};

