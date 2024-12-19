#include "AddWorkshopAction.h"

AddWorkshopAction::AddWorkshopAction(ApplicationManager* pApp) : Action(pApp) {}


void AddWorkshopAction::ReadActionParameters() {
	// Get a Pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// Read the waterPitPos parameter
	pOut->PrintMessage("New Workshop: Click on Target Cell");
	workshopPos = pIn->GetCellClicked();
}


void AddWorkshopAction::Execute() {
	ReadActionParameters();

	Workshop* pWorkshop = new Workshop(workshopPos);

	Grid* pGrid = pManager->GetGrid(); // We get a pointer to the Grid from the ApplicationManager
	Output* pOut = pGrid->GetOutput();

	bool added = pGrid->AddObjectToCell(pWorkshop);

	// if the GameObject cannot be added
	if (!added)
	{
		// Print an appropriate message
		pGrid->PrintErrorMessage("Error: Cell already has an object ! Click to continue ...");
	}

	pOut->PrintMessage("Added Workshop at (" + to_string(workshopPos.VCell()) + ", " + to_string(workshopPos.HCell()) + ")");
}