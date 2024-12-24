#include "RotatingGear.h"




RotatingGear::RotatingGear(const CellPosition & gearposition,bool clockwise) : GameObject(gearposition)
{
	isClockWise = clockwise;
	ClassName = "Rotating Gear";
}

void RotatingGear::Draw(Output* pOut) const
{
	pOut->DrawRotatingGear(position, isClockWise);
}

void RotatingGear::Apply(Grid* pGrid, Player* pPlayer)
{

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below
	// == Here are some guideline steps (numbered below) to implement this function ==
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// 1- Print a message and change the message according to direction of rotation "You have reached a rotating gear, you will rotate (clockwise/ anti-clockwise) Click to continue ..." and wait mouse click
	string clockwiseStr = (isClockWise) ? "Clockwise" : "Anti-Clockwise";
	pOut->PrintMessage("You have reached a rotating gear, you will rotate " + clockwiseStr + "Click to continue ...");
	pIn->GetCellClicked();
	pOut->ClearStatusBar();

	//2- Apply the roating gear's effect by rotating the player according to the direction
	pPlayer->Rotate(isClockWise);
}
bool RotatingGear::GetisClockWise() const
{
	return isClockWise;
}

RotatingGear::~RotatingGear()
{
}

GameObject* RotatingGear::Clone() const {
	return new RotatingGear(*this);
}