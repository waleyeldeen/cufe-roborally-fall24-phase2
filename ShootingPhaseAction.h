#pragma once
#include "Action.h"
#include "Player.h"
#include "Grid.h"
class ShootingPhaseAction
{
	Grid* pGrid;
	bool IsFacingOtherPlayer(const CellPosition& shooterPos, Direction shooterDir, const CellPosition& targetPos) const;
public:
	ShootingPhaseAction(Grid* grid);
	void Execute();
};

