#pragma once
#include "GameObject.h"
class Workshop :
	public GameObject
{
public:
	Workshop(const CellPosition & workshopPosition);
	virtual void Draw(Output* pOut) const; // Draws workshop

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applys the effect of the workshop
	void Save(ofstream &outfile,GType type) const;

	~Workshop();
};

