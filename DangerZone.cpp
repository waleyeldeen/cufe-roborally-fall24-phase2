#include "DangerZone.h"



DangerZone::DangerZone(const CellPosition & dangerZonePosition): GameObject(dangerZonePosition)
{
	ClassName = "DangerZone";
}

void DangerZone::Draw(Output * pOut) const
{
	pOut->DrawDangerZone(position);
}

GameObject* DangerZone::Clone() const {
	return new DangerZone(*this);
}

void DangerZone::Apply(Grid * pGrid, Player * pPlayer)
{
	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below

	// test change in danger zone

	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- Print a message "You have reached a danger zone. Click to continue ..." and wait mouse click

	// 2- Apply the danger zone's effect by reducing the health of the player by 1 
	// 3- Update the players info which is displayed (check Grid class and decide which function to use)
	
}


DangerZone::~DangerZone()
{
}
