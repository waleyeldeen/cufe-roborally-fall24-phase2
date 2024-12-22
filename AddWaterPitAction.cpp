#include "AddWaterPitAction.h"

AddWaterPitAction:: AddWaterPitAction(ApplicationManager* pApp) : Action(pApp) {}


void AddWaterPitAction::ReadActionParameters() {
	// Get a Pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// Read the waterPitPos parameter
	pOut->PrintMessage("New water pit: Click on Target Cell");
	waterPitPos = pIn->GetCellClicked();
}


void AddWaterPitAction::Execute() {
    ReadActionParameters();

    WaterPit* pWaterPit = new WaterPit(waterPitPos);

	Grid* pGrid = pManager->GetGrid(); // We get a pointer to the Grid from the ApplicationManager
	Output* pOut = pGrid->GetOutput();

	if (!pGrid)
		return;

	if (!waterPitPos.IsValidCell()) {
		pGrid->PrintErrorMessage("Error: Invalid Cell Clicked, click anywhere to continue...");
		return;
	}

	bool added = pGrid->AddObjectToCell(pWaterPit);

	// if the GameObject cannot be added
	if (!added)
		// Print an appropriate message
		pGrid->PrintErrorMessage("Error: Cell already has an object! Click to continue...");

    pOut->PrintMessage("Added Water Pit at VCell: "
		+ to_string(waterPitPos.VCell()) + ", HCell: " 
		+ to_string(waterPitPos.HCell()) + ", Click anywhere to continue...");
}

AddWaterPitAction::~AddWaterPitAction()
{
}