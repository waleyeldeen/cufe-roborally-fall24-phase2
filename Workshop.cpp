#include "Workshop.h"



Workshop::Workshop(const CellPosition & workshopPosition):GameObject( workshopPosition)
{
	ClassName = "Workshop";
}


void Workshop::Draw(Output * pOut) const
{
	pOut->DrawWorkshop(position);
}

void Workshop::Apply(Grid * pGrid, Player * pPlayer)
{
}
GameObject* Workshop::Clone() const {
	return new Workshop(*this);
}
Workshop::~Workshop()
{
}
