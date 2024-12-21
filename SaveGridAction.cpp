#include "SaveGridAction.h"
using namespace std;
#include<fstream>

SaveGridAction::SaveGridAction(ApplicationManager* pApp) :Action(pApp) 
{

}
void SaveGridAction::ReadActionParameters()
{
	Grid *pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	pOut->PrintMessage("Please enter name of file");
	file = pIn->GetSrting(pOut);
	pOut->ClearStatusBar();

}
void SaveGridAction::Execute()
{
	ReadActionParameters();
	
	ofstream outfile(file);
	if (!outfile.is_open())
	{
		Grid* pGrid;
		pGrid->PrintErrorMessage("Error");
	}
	Grid* pGrid = pManager->GetGrid();

	


}