#pragma once
#include "Action.h"
class NewGame :public Action
{
	NewGame(ApplicationManager* pApp);
	virtual void ReadActionParameters();   
	virtual void Execute();                
	virtual ~NewGame();               
};


