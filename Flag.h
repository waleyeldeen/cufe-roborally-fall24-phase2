#pragma once
#include "GameObject.h"
class Flag :public GameObject
{
private:
	static int count;
public:
	Flag(const CellPosition & flagposition); // A constructor for initialization

	static void PutOnGrid();

	static void RemoveFromGrid();

	static bool IsOnGrid();

	virtual void Draw(Output* pOut) const; // Draws a flag in a selected cell
	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applys the effect of the flag
	virtual GameObject* Clone() const;



	virtual ~Flag(); // Virtual destructor
};