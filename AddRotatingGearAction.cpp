#include "AddRotatingGearAction.h"

AddRotatingGearAction::AddRotatingGearAction(ApplicationManager * pApp):Action(pApp)
{
	clockwise = false;
}

void AddRotatingGearAction::ReadActionParameters()
{
	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- Get a Pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// 2- Read the gearPos
	pOut->PrintMessage("New rotating gear: Click on Target Cell");
	gearPos = pIn->GetCellClicked();

	// 3- Read whether the direction will be clockwise or not
	pOut->PrintMessage("Enter 0 for CCW or 1 for CW");
	clockwise = pIn->GetInteger(pOut);

	// 4- Make the needed validations on the read parameters


	// 5- Clear status bar
	pOut->ClearStatusBar();
}

void AddRotatingGearAction::Execute()
{
	// The first line of any Action Execution is to read its parameter first 
	// and hence initializes its data members
	ReadActionParameters();
	///[+]TODO: Implement this function as mentioned in the guideline steps (numbered below) below
	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1-Create a rotating gear object
	RotatingGear* pGear = new RotatingGear(gearPos, clockwise);
	// 2-get a pointer to the Grid from the ApplicationManager
	Grid* pGrid = pManager->GetGrid();
	// 3-Add the rotating object to the GameObject of its Cell:
	bool added = pGrid->AddObjectToCell(pGear);
	// 4-Check if the rotating gear was added and print an errror message if flag couldn't be added
	if (!added)
	{
		// Print an appropriate message
		pGrid->PrintErrorMessage("Error: Cell already has an object ! Click to continue ...");
	}
}

AddRotatingGearAction::~AddRotatingGearAction()
{
}
