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
	Grid* pGrid;
	pGrid = pManager->GetGrid();
	ofstream Outfile(file);
	if (!Outfile.is_open())
	{
		
		pGrid->PrintErrorMessage("Error:Please try again");
		return;
	}
	
	
	pGrid->SaveAll(Outfile);
	

	Outfile.close();
	


}
SaveGridAction::~SaveGridAction()
{

}