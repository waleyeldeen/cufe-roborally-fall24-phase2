#include "AddAntenna.h"

AddAntenna::AddAntenna(ApplicationManager* pApp):Action(pApp)
{

}
void AddAntenna::ReadActionParameters()
{
	Grid *pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("Click on the cell to place antenna");
	AntennaPos = pIn->GetCellClicked();
	

	pOut->ClearStatusBar();
}

void AddAntenna::Execute()
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
AddAntenna::~AddAntenna() 
{

}
