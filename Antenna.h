#pragma once
#include "GameObject.h"
class Antenna :public GameObject
{
private:
	static int count;
public:
	Antenna(const CellPosition & antennaPosition);

	static void PutOnGrid();

	static void RemoveFromGrid();

	static bool IsOnGrid();

	virtual void Draw(Output* pOut) const; // Draws an antenna

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applys the effect of the antenna by deciding the players turns


	virtual ~Antenna();
};

