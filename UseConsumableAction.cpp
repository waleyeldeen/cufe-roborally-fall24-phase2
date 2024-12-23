#include "UseConsumableAction.h"

UseConsumableAction::UseConsumableAction(ApplicationManager* pApp) : Action(pApp)
{ 
	consumable = EMPTY_BAG;
	list[0] = TOOLKIT; list[1] = HACKDEVICE; list[2] = EMPTY_BAG;
	validParam = false;
}

//enum Consumable
//{
//	TOOLKIT,
//	HACKDEVICE,
//	NONE,
//  CONSUMABLE_COUNT
//};

void UseConsumableAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	int userInput;

	pOut->PrintMessage("You choose to use one you your consumables, click anywhere to continue...");
	pIn->GetCellClicked();

	pOut->PrintMessage("Which consumable do you want to use: (0)Toolkit, (1)Hackdevice");
	userInput = pIn->GetInteger(pOut);

	if (userInput < 0 || userInput > 1)
	{
		pGrid->PrintErrorMessage("Choosen consumable is out of range! Click anywhere to continur...");
		validParam = false;
	}
	else
	{
		consumable = list[userInput];
		validParam = true;
	}
}

void UseConsumableAction::Execute() {
	ReadActionParameters();


}

UseConsumableAction::~UseConsumableAction() {

}