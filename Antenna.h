#pragma once
#include "GameObject.h"
class Antenna :public GameObject
{
	string filepath;
public:
	Antenna(const CellPosition & antennaPosition);
	virtual void Draw(Output* pOut) const; // Draws an antenna

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applys the effect of the antenna by deciding the players turns

	virtual GameObject* Clone() const override;
	void setFilePath(const string& path);
	string GetFilePath()const;
	virtual ~Antenna();
};

