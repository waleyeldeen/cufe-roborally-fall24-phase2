#pragma once
#include "GameObject.h"
class Workshop :
	public GameObject
{
private:
	Consumable inv[2];
public:
	Workshop(const CellPosition & workshopPosition);
	virtual void Draw(Output* pOut) const; // Draws workshop

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applys the effect of the workshop
	virtual GameObject* Clone() const;
	

	~Workshop();
};

