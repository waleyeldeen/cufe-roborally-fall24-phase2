#include "AddAntennaAction.h"

AddAntennaAction::AddAntennaAction(ApplicationManager* pApp):Action(pApp)
{
	isParamRead = true;
}
void AddAntennaAction::ReadActionParameters()
{
	Grid *pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	if (Antenna::IsOnGrid()) {
		isParamRead = false;
		pGrid->PrintErrorMessage("An Antenna Already Exists on Grid! Click anywhere to continue...");
		return;
	}

	pOut->PrintMessage("New Antenna pit: Click on Target Cell");
	AntennaPos = pIn->GetCellClicked();
	
	//pOut->ClearStatusBar();
}

void AddAntennaAction::Execute()
{
	ReadActionParameters();

	if (!isParamRead)
		return;

	Antenna* pAntenna= new Antenna(AntennaPos);

	Grid* pGrid = pManager->GetGrid();

	bool add = pGrid->AddObjectToCell(pAntenna);

	if (!add)
	{
		pGrid->PrintErrorMessage("Error: Cell already has an object! Click Anywhere to continue...");
		delete pAntenna;
		return;
	}

	Antenna::PutOnGrid();
}

AddAntennaAction::~AddAntennaAction() 
{

}
