#include "CutAction.h"
#include "Grid.h"
#include "Cell.h"
#include "GameObject.h"
#include"Antenna.h"
#include"Belt.h"

CutAction::CutAction(ApplicationManager* pApp) :Action(pApp) {}
CutAction::~CutAction() {}

void CutAction::ReadActionParameters() {
    Grid* pGrid = pManager->GetGrid();
    Output* pOut = pGrid->GetOutput();
    Input* pIn = pGrid->GetInput();

    pOut->PrintMessage("Click on the cell containing the object you want to cut.");
    sourceCell = pIn->GetCellClicked();
    pOut->ClearStatusBar();
}
void CutAction::Execute() {
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
        pGrid->PrintErrorMessage("Cannot Cut an Antenna. Click anywhere to continue...");
        return;
    }
    Belt* Beltptr = dynamic_cast<Belt*>(pGameObject);
    if (Beltptr != nullptr) {
        pGrid->PrintErrorMessage("Cannot Cut a Belt. Click anywhere to continue...");
        return;
    }

    pGrid->SetClipboard(pGameObject);
    pGrid->RemoveObjectFromCell(sourceCell);
    pGrid->PrintErrorMessage("Game object cut successfully. Click anywhere to continue...");
}