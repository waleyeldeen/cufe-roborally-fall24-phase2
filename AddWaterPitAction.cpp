#include "AddWaterPitAction.h"

AddWaterPitAction:: AddWaterPitAction(ApplicationManager* pApp) : Action() {}


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
    //GameObject* pWaterPit = new GameObject(); // Replace with actual WaterPit class
    //pManager->GetGrid()->AddObjectToCell(pWaterPit, position);
    //pManager->GetOutput()->PrintMessage("Added Water Pit at (" + std::to_string(position.vCell) + ", " + std::to_string(position.hCell) + ")");
}