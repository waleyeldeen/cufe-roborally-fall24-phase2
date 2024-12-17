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
    Output* pOutpoint = pManager->GetGrid()->GetOutput();
    if (pOutpoint) {
        pOutpoint->CreatePlayModeToolBar();
        pOutpoint->ClearStatusBar();
        pOutpoint->PrintMessage("switched to play mode");
    }

}
SwitchToPlayMode::~SwitchToPlayMode() {}