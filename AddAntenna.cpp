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
	if (!AntennaPos.IsValidCell())
	{
		pOut->PrintMessage("Invalid position for antenna");
	}

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
		Output* p;
		p->PrintMessage("Antenna is not added to cell");
		delete A;

	}


}
AddAntenna::~AddAntenna() 
{

}
