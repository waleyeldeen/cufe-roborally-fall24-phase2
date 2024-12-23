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

	if (!validParam)
		return;

	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	Player* pCurrentPlayer = pGrid->GetCurrentPlayer();
	Player* pNonCurrentPlayer = pGrid->GetNonCurrentPlayer();

	bool applied = false; // indicates if consumable is found in bag and used
	bool consumableExistInBag;

	int health = pCurrentPlayer->GetHealth();

	// check if consumable is in bag and remove it if so
	consumableExistInBag = pCurrentPlayer->RemoveFromBag(consumable);

	if (consumableExistInBag) // if consumable exist do the following
	{
		if (consumable == TOOLKIT)
		{
			if (health == 10) { // player already on max health
				pOut->PrintMessage("You already are on maximum health! Click anywhere to continue...");
				pIn->GetCellClicked();
				pOut->ClearStatusBar();
				return;
			}
			else
			{
				pCurrentPlayer->SetHealth(10);
				pOut->PrintMessage("Your health is restored to maximum value! Click anywhere to continue...");
				applied = true;
			}

		}
		else if (consumable == HACKDEVICE)
		{
			pNonCurrentPlayer->Hack();
			applied = true;
		}
	}
	else if (!consumableExistInBag)
	{
		pOut->PrintMessage("The choosed consumable is not available in your bag! Try to acquire it when langing in Workshop. Click Anywhere to continue...");
		pIn->GetCellClicked();
		pOut->ClearStatusBar();
		return;
	}

	if (applied) {
		pOut->PrintMessage("You succefully used the choosed consumable! Click Anywhere to Coninue...");
		pIn->GetCellClicked();
		pOut->ClearStatusBar();
	}
}

UseConsumableAction::~UseConsumableAction() {

}