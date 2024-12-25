#include "SwitchToPlayMode.h"
#include "ApplicationManager.h"
#include "Grid.h"
#include "Output.h"
SwitchToPlayMode::SwitchToPlayMode(ApplicationManager* pApp)
    : Action(pApp) {}
void SwitchToPlayMode::ReadActionParameters() {
   
}
void SwitchToPlayMode::Execute()
{
    Grid* pGrid = pManager->GetGrid();
    Output* pOut = pGrid->GetOutput();

    if (pOut) {
        pOut->CreatePlayModeToolBar();
        pOut->ClearStatusBar();
        pOut->PrintMessage("switched to play mode");
    }

    pManager->setNextAction(START_ROUND_ACTION);
}
SwitchToPlayMode::~SwitchToPlayMode() {}