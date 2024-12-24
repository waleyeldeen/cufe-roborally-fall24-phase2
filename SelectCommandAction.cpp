#include "SelectCommandAction.h"
#include "Grid.h"

SelectCommandAction::SelectCommandAction(ApplicationManager * pApp) : Action(pApp)
{

}

void SelectCommandAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	pOut->PrintMessage("You are going to select from the available commands to be in saved! Click anywhere to continue...");
	pIn->GetCellClicked();
	pOut->ClearStatusBar();

	pIn->GetSelectedCommandIndex();
}

void SelectCommandAction::Execute()
{
	
}

SelectCommandAction::~SelectCommandAction()
{

}