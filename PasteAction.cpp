#include "PasteAction.h"
#include "Grid.h"
#include "Cell.h"
#include "GameObject.h"

PasteAction::PasteAction(ApplicationManager* pApp) : Action(pApp) {}

PasteAction::~PasteAction() {}

void PasteAction::ReadActionParameters() {
    Grid* pGrid = pManager->GetGrid();
    Output* pOut = pGrid->GetOutput();
    Input* pIn = pGrid->GetInput();

    pOut->PrintMessage("Click on the cell where you want to paste the object.");
    targetCell = pIn->GetCellClicked();
    pOut->ClearStatusBar();
}

void PasteAction::Execute() {
    ReadActionParameters();

    Grid* pGrid = pManager->GetGrid();
    if (!pGrid) {
        return;
    }

    if (!targetCell.IsValidCell()) {
        pGrid->PrintErrorMessage("Invalid cell! Click anywhere to continue...");
        return;
    }


    GameObject* pClipboardObject = pGrid->GetClipboard();
    if (!pClipboardObject) {
        pGrid->PrintErrorMessage("Clipboard is empty! no object found to cut ,Click anywhere to continue...");
        return;
    }

    
    pClipboardObject->SetPositon(targetCell);

    pGrid->AddObjectToCell(pClipboardObject);

  
    pGrid->SetClipboard(nullptr);
    pGrid->PrintErrorMessage("Game object pasted successfully. Click anywhere to continue...");
}