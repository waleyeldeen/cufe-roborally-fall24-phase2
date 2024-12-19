#pragma once
#include "Action.h"
class DisplayPlayersInfo : public Action
{
public:
	DisplayPlayersInfo(ApplicationManager* pApp);
	virtual void ReadActionParameters();          
	virtual void Execute();
	~DisplayPlayersInfo();
};

