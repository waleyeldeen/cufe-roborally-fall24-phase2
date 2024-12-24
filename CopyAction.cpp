#include "CopyAction.h"
#include "Grid.h"
#include "Cell.h"
#include "GameObject.h"
#include "Belt.h"
#include"Antenna.h"

CopyAction::CopyAction(ApplicationManager* pApp) :Action(pApp) {}
CopyAction::~CopyAction() {}

void CopyAction::ReadActionParameters() {
    Grid* pGrid = pManager->GetGrid();
    Output* pOut = pGrid->GetOutput();
    Input* pIn = pGrid->GetInput();

    pOut->PrintMessage("Click on the cell containing the object you want to copy.");
    sourceCell = pIn->GetCellClicked();
    pOut->ClearStatusBar();
}
void CopyAction::Execute() {
    ReadActionParameters();

    Grid* pGrid = pManager->GetGrid();
    if (!pGrid) {
        return;
    }

    if (!sourceCell.IsValidCell()) {
        pGrid->PrintErrorMessage("Invalid cell! Click anywhere to continue...");
        return;
    }

    GameObject* pGameObject = pGrid->GetGameObjectFromCellPosition(sourceCell);
    if (!pGameObject) {
        pGrid->PrintErrorMessage("No game object found in the selected cell! Click anywhere to continue...");
        return;
    }
    Antenna* antennaPtr = dynamic_cast<Antenna*>(pGameObject);
    if (antennaPtr != nullptr) {
        pGrid->PrintErrorMessage("Cannot copy an Antenna. Click anywhere to continue...");
        return;
    }
    Belt* Beltptr = dynamic_cast<Belt*>(pGameObject);
    if (Beltptr != nullptr) {
        pGrid->PrintErrorMessage("Cannot copy a Belt. Click anywhere to continue...");
        return;
    }
    pGrid->SetClipboard(pGameObject);
    pGrid->PrintErrorMessage("Game object copied successfully. Click anywhere to continue...");
}