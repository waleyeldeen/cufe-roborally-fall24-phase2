#include "ExecuteFlagAction.h"

ExecuteFlagAction::ExecuteFlagAction(ApplicationManager* pApp): Action(pApp)
{

}

void ExecuteFlagAction::ReadActionparameters()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	pOut->PrintMessage("Flag position");
	flagpos = pIn->GetCellClicked();

	pOut->ClearStatusBar();

}

void ExecuteFlagAction::Execute()
{
	ReadActionParameters();
	Flag* flag = new Flag(flagpos);
	Grid* pGrid = pManager->GetGrid();

	bool add = pGrid->AddObjectToCell(flag);

	if (!add)
	{
		pGrid->PrintErrorMessage("Error please try again");

	}



}
ExecuteFlagAction::~ExecuteFlagAction()
{

}
