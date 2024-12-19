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

	bool added = pGrid->AddObjectToCell(pWaterPit);

	// if the GameObject cannot be added
	if (!added)
	{
		// Print an appropriate message
		pGrid->PrintErrorMessage("Error: Cell already has an object ! Click to continue ...");
	}
	// Here, the belt is created and added to the GameObject of its Cell, so we finished executing the AddBeltAction

    //pManager->GetGrid()->AddObjectToCell(pWaterPit, position);
    //pManager->GetOutput()->PrintMessage("Added Water Pit at (" + std::to_string(position.vCell) + ", " + std::to_string(position.hCell) + ")");
}