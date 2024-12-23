#pragma once
#include "GameObject.h"
class Flag :public GameObject
{
public:
	Flag(const CellPosition & flagposition); // A constructor for initialization
	virtual void Draw(Output* pOut) const; // Draws a flag in a selected cell
	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applys the effect of the flag
	virtual GameObject* Clone() const override;
	void setFilePath(const string& path);
	string GetFilePath()const;

	virtual ~Flag(); // Virtual destructor
};