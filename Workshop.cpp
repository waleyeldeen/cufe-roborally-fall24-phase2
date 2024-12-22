#include "Workshop.h"



Workshop::Workshop(const CellPosition & workshopPosition):GameObject( workshopPosition)
{

}


void Workshop::Draw(Output * pOut) const
{
	pOut->DrawWorkshop(position);
}

void Workshop::Apply(Grid * pGrid, Player * pPlayer)
{
}
void Workshop::load(ifstream& infile, GType type) const
{
	int cellnum;
	if (type == WORKSHOP)
	{
		infile >> cellnum;
		position.GetCellPositionFromNum(cellnum);
	}
}

Workshop::~Workshop()
{
}
