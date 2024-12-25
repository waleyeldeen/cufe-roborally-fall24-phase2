#include "Antenna.h"
#include"Player.h"


int Antenna::count = 0;

Antenna::Antenna(const CellPosition & antennaPosition):GameObject(antennaPosition)
{
	ClassName = "Antenna";
	Antenna::PutOnGrid();
}

void Antenna::PutOnGrid() {
	count++;
}

void Antenna::RemoveFromGrid() {
	count--;
}


bool Antenna::IsOnGrid() {
	if (count >= 1)
		return true;
	return false;
}

void Antenna::Draw(Output * pOut) const
{
	pOut->DrawAntenna(position);
}

void Antenna::Apply(Grid* pGrid, Player* pPlayer)
{
	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	pOut->PrintMessage("The antenn will decide the turn of plyers.Click to continue...");
	pIn->GetCellClicked();
	
	int play[MaxPlayerCount];
	int playingorder[MaxPlayerCount];
	for (int j = 0; j < MaxPlayerCount; j++)
	{
		Player* ppPlayer = pGrid->GetPlayer(j);
		Cell* pCell = ppPlayer->GetCell();
		CellPosition playerPosition = pCell->GetCellPosition();

		double xDist = abs(playerPosition.HCell() - position.HCell());
		double yDist = abs(playerPosition.VCell() - position.VCell());

		double distance = sqrt(xDist * xDist + yDist * yDist);

		///[+]TODO: SET PLAYER DATA MEMBER DISTANCE FROM ANTENNA
		pPlayer->setDistanceFromAntenna(distance);
	}
}


GameObject* Antenna::Clone() const {
	return new Antenna(*this);
}

Antenna::~Antenna()
{
	Antenna::RemoveFromGrid();
}
