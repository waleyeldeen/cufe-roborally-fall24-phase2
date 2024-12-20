#include "CutAction.h"
#include "Grid.h"
#include "Cell.h"
#include "GameObject.h"

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

    Cell* pCell = pGrid->GetCell(sourceCell);
    if (!pCell) {
        pGrid->PrintErrorMessage("Cell not found! Click anywhere to continue...");
        return;
    }

    GameObject* pGameObject = pCell->GetGameObject();
    if (!pGameObject) {
        pGrid->PrintErrorMessage("No game object found in the selected cell! Click anywhere to continue...");
        return;
    }

    pGrid->SetClipboard(pGameObject);
    pCell->SetGameObject(nullptr);
    pGrid->PrintErrorMessage("Game object cut successfully. Click anywhere to continue...");
}