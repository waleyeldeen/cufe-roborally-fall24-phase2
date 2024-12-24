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
	ifstream Infile(file);
	
	if (Infile.is_open())
	{
		pGrid->PrintErrorMessage("Error");
	}

	pGrid->LoadAll(Infile);
	Infile.close();
}

LoadAction::~LoadAction()
{

 }