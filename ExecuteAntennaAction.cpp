#include "ExecuteAntennaAction.h"


ExecuteAntennaAction::ExecuteAntennaAction(ApplicationManager* pApp) :Action(pApp)
{


}

void ExecuteAntennaAction::ReadActionParameter()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	pOut->PrintMessage("Please click on a cell");
	AntennaPos=pIn->GetCellClicked();

	pOut->ClearStatusBar();
	

}

void ExecuteAntennaAction::Execute()
{
	ReadActionParameter();
	Antenna* An = new Antenna(AntennaPos);

	Grid* pGrid = pManager->GetGrid();
	bool Ad = pGrid->AddObjectToCell(An);
	if (!Ad)
	{
		pGrid->PrintErrorMessage("Please choose another cell");
		delete An;
	}
	
}
ExecuteAntennaAction:: ~ExecuteAntennaAction()
{

}

