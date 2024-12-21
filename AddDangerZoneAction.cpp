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

	DangerZone* pWaterPit = new DangerZone(dangerZonePos);

	Grid* pGrid = pManager->GetGrid(); // We get a pointer to the Grid from the ApplicationManager
	Output* pOut = pGrid->GetOutput();

	if (!pGrid)
		return;

	if (!dangerZonePos.IsValidCell()) {
		pGrid->PrintErrorMessage("Error: Invalid Cell Clicked, click anywhere to continue...");
		return;
	}

	bool added = pGrid->AddObjectToCell(pWaterPit);

	// if the GameObject cannot be added
	if (!added)
	{
		// Print an appropriate message
		pGrid->PrintErrorMessage("Error: Cell already has an object ! Click to continue ...");
	}

	pOut->PrintMessage("Added Danger Zone at (" + to_string(dangerZonePos.VCell()) + ", " + to_string(dangerZonePos.HCell()) + ")");
}