#include "SwitchToDesignMode.h"
#include "ApplicationManager.h"
#include "Grid.h"
#include "Output.h"

SwitchToDesignMode::SwitchToDesignMode(ApplicationManager* pApp) : Action(pApp) {}
void SwitchToDesignMode::ReadActionParameters()
{

}
void SwitchToDesignMode::Execute() {
    Output* pOutpoint = pManager->GetGrid()->GetOutput();
    if (pOutpoint) {
        pOutpoint->CreateDesignModeToolBar();
        pOutpoint->ClearStatusBar();
        pOutpoint->PrintMessage("switched to Design mode");
    }

}
SwitchToDesignMode::~SwitchToDesignMode() {
  
}