#include "Flag.h"
Flag::Flag(const CellPosition & flagposition) : GameObject(flagposition)
{

}

void Flag::Draw(Output* pOut) const
{
	pOut->DrawFlag(position);
}

void Flag::Apply(Grid* pGrid, Player* pPlayer)
{
	Output* pOut;
	pOut->PrintMessage("You have reached a flag .click to continue");
	
	pGrid->GetInput()->GetCellClicked();
	
	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below
	// == Here are some guideline steps (numbered below) to implement this function ==
	pOut->PrintMessage("End");
	pGrid->SetEndGame(true);
	// 1- Print a message "You have reached a flag. Click to continue ..." and wait mouse click

	// 2- Apply the flag's effect by ending the game
	//    Review the "pGrid" functions and decide which function can be used for that
}

Flag::~Flag()
{

}