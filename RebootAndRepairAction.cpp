#include "RebootAndRepairAction.h"
#include"Action.h"
#include"ApplicationManager.h"
#include"Grid.h"
#include"output.h"

RebootAndRepairAction::RebootAndRepairAction(ApplicationManager* pApp):Action(pApp)
{
}

void RebootAndRepairAction::ReadActionParameters()
{
}

void RebootAndRepairAction::Execute()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Player* pCurrentPlayer = pGrid->GetCurrentPlayer();
	if (pCurrentPlayer) {
		pCurrentPlayer->SetHealth(10);
		pOut->PrintMessage("current player repaired to full health");
	}
	else {
		pOut->PrintMessage("no current player found");
	}
}
