#pragma once
#include "Action.h"
class PasteAction : public Action
{
	CellPosition targetCell;
public:
	PasteAction(ApplicationManager* pApp);
	~PasteAction();
	virtual void ReadActionParameters();
	virtual void Execute();


};

