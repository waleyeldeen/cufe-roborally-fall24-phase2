#include "AddRotatingGearAction.h"

AddRotatingGearAction::AddRotatingGearAction(ApplicationManager * pApp):Action(pApp)
{
	clockwise = false;
}

void AddRotatingGearAction::ReadActionParameters()
{
	///[+]TODO: Implement this function as mentioned in the guideline steps (numbered below) below

	// 1- Get a Pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// 2- Read the gearPos
	pOut->PrintMessage("New rotating gear: Click on Target Cell");
	gearPos = pIn->GetCellClicked();

	// 3- Read whether the direction will be clockwise or not
	if (gearPos.IsValidCell())
	{
		pOut->PrintMessage("Enter 0 for CCW or 1 for CW");
		string clockwiseStr = pIn->GetSrting(pOut);
		if (clockwiseStr == "0")
			clockwise = false;
		else if (clockwiseStr == "1")
			clockwise = true;
		else
		{
			gearPos.Invalidate();
			pGrid->PrintErrorMessage("Error: Invalid Direction Entered, click asnywhere to continue...");
		}
	}
	else if (!gearPos.IsValidCell())
	{
		pGrid->PrintErrorMessage("Error: Invalid Cell Clicked, click anywhere to continue...");
	}
	// 4- Make the needed validations on the read parameters


	// 5- Clear status bar
	pOut->ClearStatusBar();
}

void AddRotatingGearAction::Execute()
{
	///[+]TODO: Implement this function as mentioned in the guideline steps (numbered below) below
	ReadActionParameters();

	// 1-Create a rotating gear object
	RotatingGear* pGear = new RotatingGear(gearPos, clockwise);

	// 2-get a pointer to the Grid from the ApplicationManager
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();

	if (!pGrid)
		return;

	if (!gearPos.IsValidCell())
	{
		return;
	}

	// 3-Add the rotating object to the GameObject of its Cell:
	bool added = pGrid->AddObjectToCell(pGear);

	// 4-Check if the rotating gear was added and print an errror message if flag couldn't be added
	if (!added)
	{
		// Print an appropriate message
		pGrid->PrintErrorMessage("Error: Cell already has an object ! Click to continue ...");
		return;
	}

	pOut->PrintMessage("Added Water Pit at VCell: "
		+ to_string(gearPos.VCell()) + ", HCell: "
		+ to_string(gearPos.HCell()) + ", Click anywhere to continue...");
}

AddRotatingGearAction::~AddRotatingGearAction()
{
}
