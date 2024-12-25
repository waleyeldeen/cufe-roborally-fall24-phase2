#include "Workshop.h"



Workshop::Workshop(const CellPosition& workshopPosition) :GameObject(workshopPosition)
{
	ClassName = "Workshop";
	this->inv[0] = TOOLKIT; this->inv[1] = HACKDEVICE;
}


void Workshop::Draw(Output * pOut) const
{
	pOut->DrawWorkshop(position);
}

void Workshop::Apply(Grid * pGrid, Player * pPlayer)
{
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// terminate function if player bag is full
	if (pPlayer->IsBagFull())
	{
		pOut->PrintMessage("Your bag is already full, you can visit us later! Click anywhere to continue");
		pIn->GetCellClicked();
		pOut->ClearStatusBar();
		return;
	}

	Consumable choosen;
	int choosenInt;

	pOut->PrintMessage("You have reached a Workshop, You will be prompted to acquire one of the availbe consumables! Click to continue ...");
	pIn->GetCellClicked();
	pOut->ClearStatusBar();

	pOut->PrintMessage("Choose between the available items (use number to choose): (0)Toolkit (1)Hack Device");
	choosenInt = pIn->GetInteger(pOut);

	if (choosenInt == 0 || choosenInt == 1)
	{
		choosen = this->inv[choosenInt];
		bool addedToBag = pPlayer->AddToBag(choosen);
		if (addedToBag) // we already verified that the bag is not full, this is just a backup
			pOut->PrintMessage("You succussfully acquired the chosen item " + to_string(choosenInt) + " in your bag! Click anywhere to continue");
		return;
	}
	else
	{
		pOut->PrintMessage("This item is not available in our inventory! Click anywhere to continue...");
		pIn->GetCellClicked();
		pOut->ClearStatusBar();
		return;
	}
}
GameObject* Workshop::Clone() const {
	return new Workshop(*this);
}

void Workshop::Save(ofstream &outfile)
{
	
	
	outfile << position.GetCellNum();
	
}
Workshop::~Workshop()
{
}
