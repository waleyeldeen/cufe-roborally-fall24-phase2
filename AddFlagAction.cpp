#include "AddFlagAction.h"



AddFlagAction::AddFlagAction(ApplicationManager *pApp) : Action(pApp)
{
	isParamRead = true;
	// Initializes the pManager pointer of Action with the passed pointer
}


void AddFlagAction::ReadActionParameters()
{
	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below
	Grid* pGrid = pManager->GetGrid();
	Output* pOut=pGrid->GetOutput();
	Input* pIn = pGrid->GetInput() ;
	
	// == Here are some guideline steps (numbered below) to implement this function ==
	flagPos = pIn->GetCellClicked();
	// 1- Get a Pointer to the Input / Output Interfaces
	
	// 2- Read the flagPos

	// 4- Make the needed validations on the read parameters
	pOut->ClearStatusBar();
	// 5- Clear status bar
}

void AddFlagAction::Execute()
{
	Grid* pGrid = pManager->GetGrid(); 
	// The first line of any Action Execution is to read its parameter first 
	// and hence initializes its data members
	ReadActionParameters();
	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below
	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1-Create a flag object
	Flag* newFlag = new Flag(flagPos);

	bool isAdded = pGrid->AddObjectToCell(newFlag);

	if (!isAdded) 
	{
		pGrid->PrintErrorMessage("A flag Already Exists on Grid! Click anywhere to continue...");
		delete newFlag;
	}
	// 2-get a pointer to the Grid from the ApplicationManager
	// 3-Add the flag object to the GameObject of its Cell:
	// 4-Check if the flag was added and print an errror message if flag couldn't be added
	
}

AddFlagAction::~AddFlagAction()
{
}