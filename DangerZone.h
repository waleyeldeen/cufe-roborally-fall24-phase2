#pragma once
#include "GameObject.h"
#include<iostream>
class DangerZone:public GameObject
{
public:
	DangerZone(const CellPosition & dangerZonePosition);
	virtual void Draw(Output* pOut) const; // Draws a danger zone in the cell

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applys the effect of the danger zone by reducing the robot's health by 1
	void Save(GType type) const override;


	virtual ~DangerZone();
};

