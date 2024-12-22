#include "LoadAction.h"

LoadAction::LoadAction(ApplicationManager* pApp) :Action(pApp)
{

}


void LoadAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	file = pIn->GetSrting(pOut);
	pOut->ClearStatusBar();
}
void LoadAction::Execute()
{
	ReadActionParameters();
	Grid* pGrid;

	pGrid = pManager->GetGrid();
	ifstream infile(file);
	
	if (infile.is_open())
	{
		pGrid->PrintErrorMessage("Error");
	}

	pGrid->LoadAll(infile, FLAG);
	pGrid->LoadAll(infile, WATER_PIT);
	pGrid->LoadAll(infile, DANGER_ZONE);
	pGrid->LoadAll(infile, BELT);
	pGrid->LoadAll(infile, WORKSHOP);
	pGrid->LoadAll(infile, ANTENNA);
	pGrid->LoadAll(infile, ROTATING_GEAR);

	infile.close();
}

LoadAction::~LoadAction()
{

 }