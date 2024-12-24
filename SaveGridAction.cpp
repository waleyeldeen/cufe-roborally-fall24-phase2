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
	
	ofstream outfile(file);
	if (!outfile.is_open())
	{
		Output* pOut;
		pOut->PrintMessage("Error:Please try again");
		return;
	}
	
	pGrid = pManager->GetGrid();
	pGrid->SaveAll(outfile);
	

	outfile.close();
	


}
SaveGridAction::~SaveGridAction()
{

}