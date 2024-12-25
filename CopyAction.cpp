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
    if (pGameObject->GetClassName() == "Belt")
    {
        pGrid->PrintErrorMessage("Can't Copy Belt");
        return;
    }
    if (pGameObject->GetClassName() == "Antenna")
    {
        pGrid->PrintErrorMessage("Can't Copy Antenna");
        return;
    }
    if (pGameObject->GetClassName() == "Flag")
    {
        pGrid->PrintErrorMessage("Can't Copy Flag");
        return;
    }
    pGrid->SetClipboard(pGameObject);
    pGrid->PrintErrorMessage("Game object copied successfully. Click anywhere to continue...");
}