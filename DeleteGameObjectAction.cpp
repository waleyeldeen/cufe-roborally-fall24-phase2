#include "DeleteGameObjectAction.h"
#include "CutAction.h"
#include "Grid.h"
#include "Cell.h"
#include "GameObject.h"

DeleteGameObjectAction::DeleteGameObjectAction(ApplicationManager* pApp) :Action(pApp) {}
DeleteGameObjectAction::~DeleteGameObjectAction() {}

void DeleteGameObjectAction::ReadActionParameters() {
    Grid* pGrid = pManager->GetGrid();
    Output* pOut = pGrid->GetOutput();
    Input* pIn = pGrid->GetInput();

    pOut->PrintMessage("Click on the cell containing the object you want to delete.");
    sourceCell = pIn->GetCellClicked();
    pOut->ClearStatusBar();
}
void DeleteGameObjectAction::Execute() {
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

    pGrid->RemoveObjectFromCell(sourceCell);
    pGrid->PrintErrorMessage("Game object deleted successfully. Click anywhere to continue...");
}