#include "Flag.h"

int Flag::count = 0;

Flag::Flag(const CellPosition & flagposition) : GameObject(flagposition)
{
  ClassName = "Flag";
  Flag::PutOnGrid();
}

void Flag::PutOnGrid() {
	count++;
}

void Flag::RemoveFromGrid() {
	count--;
}


bool Flag::IsOnGrid() {
	if (count >= 1)
		return true;
	return false;
}

void Flag::Draw(Output* pOut) const
{
	pOut->DrawFlag(position);
}

void Flag::Apply(Grid* pGrid, Player* pPlayer)
{

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below
	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- Print a message "You have reached a flag. Click to continue ..." and wait mouse click

	// 2- Apply the flag's effect by ending the game
	//    Review the "pGrid" functions and decide which function can be used for that
}
GameObject* Flag::Clone() const {
	return new Flag(*this);
}
Flag::~Flag()
{
	Flag::RemoveFromGrid();
}