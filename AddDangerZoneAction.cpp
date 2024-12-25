#include "AddDangerZoneAction.h"

AddDangerZoneAction::AddDangerZoneAction(ApplicationManager* pApp) : Action(pApp) {}


void AddDangerZoneAction::ReadActionParameters() {
	// Get a Pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// Read the waterPitPos parameter
	pOut->PrintMessage("New water pit: Click on Target Cell");
	dangerZonePos = pIn->GetCellClicked();
}


void AddDangerZoneAction::Execute() {
	ReadActionParameters();

	DangerZone* pDangerZone = new DangerZone(dangerZonePos);

	Grid* pGrid = pManager->GetGrid(); // We get a pointer to the Grid from the ApplicationManager
	Output* pOut = pGrid->GetOutput();

	if (!pGrid)
		return;

	if (!dangerZonePos.IsValidCell()) {
		pGrid->PrintErrorMessage("Error: Invalid Cell Clicked, click anywhere to continue...");
		return;
	}

	bool added = pGrid->AddObjectToCell(pDangerZone);

	// if the GameObject cannot be added
	if (!added)
	{
		// Print an appropriate message
		pGrid->PrintErrorMessage("Error: Cell already has an object ! Click to continue...");
		delete pDangerZone;
		return;
	}


	pOut->PrintMessage("Added Water Pit at VCell: "
		+ to_string(dangerZonePos.VCell()) + ", HCell: "
		+ to_string(dangerZonePos.HCell()) + ", Click anywhere to continue...");
}

AddDangerZoneAction::~AddDangerZoneAction()
{
}