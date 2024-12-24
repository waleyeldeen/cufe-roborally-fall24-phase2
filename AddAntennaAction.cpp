#include "AddAntennaAction.h"

AddAntennaAction::AddAntennaAction(ApplicationManager* pApp):Action(pApp)
{

}
void AddAntennaAction::ReadActionParameters()
{
	Grid *pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("Click on the cell to place antenna");
	AntennaPos = pIn->GetCellClicked();
	

	pOut->ClearStatusBar();
}

void AddAntennaAction::Execute()
{
	ReadActionParameters();
	Antenna* A= new Antenna(AntennaPos);
	Grid* pGrid = pManager->GetGrid();
	bool Add = pGrid->AddObjectToCell(A);
	if (!Add) 
	{
		pGrid->PrintErrorMessage("Error plese choose another cell");
		delete A;

	}

	
}
AddAntennaAction::~AddAntennaAction() 
{

}
