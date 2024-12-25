#include "StartRoundAction.h"
#include "Player.h"
#include "Antenna.h"

StartRoundAction::StartRoundAction(ApplicationManager* pApp) : Action(pApp)
{

}

void StartRoundAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	pOut->PrintMessage("A new round is starting now! Click anywhere to continue...");
	
}

void StartRoundAction::Execute()
{
	ReadActionParameters();
	Round* pRound = pManager->GetRound();
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	Antenna* pAntenna = pGrid->GetAntenna();
	pAntenna->Apply(pGrid);
}

StartRoundAction::~StartRoundAction()
{

}