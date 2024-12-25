#pragma once
#include "Action.h"
#include "ApplicationManager.h"
#include "Player.h"
class RebootAndRepairAction :public Action
{
private:
public:
	RebootAndRepairAction(ApplicationManager* pApp);
	void ReadActionParameters();
	void Execute();
};

