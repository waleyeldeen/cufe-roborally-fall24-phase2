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

void Workshop::Save(ofstream &outfile)
{
	
	
	outfile << position.GetCellNum();
	
}
Workshop::~Workshop()
{
}
