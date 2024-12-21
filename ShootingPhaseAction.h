#pragma once
#include "Action.h"
#include "Player.h"
#include "Grid.h"
class ShootingPhaseAction :public Action
{
	Grid* pGrid;
	
public:
	ShootingPhaseAction(Grid* grid);
	void Execute();
	~ShootingPhaseAction();
};

