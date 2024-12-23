#include "ShootingPhaseAction.h"
#include "Player.h"
#include "Cell.h"
#include "Grid.h"
#include "Output.h"
#include "Input.h"

ShootingPhaseAction::ShootingPhaseAction(Grid* grid, ApplicationManager* pApp)
    : pGrid(grid), Action(pApp) {}

ShootingPhaseAction::~ShootingPhaseAction() {}

void ShootingPhaseAction::Execute() {
for (int i = 0; i < MaxPlayerCount; i++) {
Player* shooter = pGrid->GetPlayer(i);
if (shooter != nullptr) {
CellPosition shooterPos = shooter->GetCell()->GetCellPosition();
for (int j = 0; j < MaxPlayerCount; j++) {
    if (i != j) {
Player* target = pGrid->GetPlayer(j);
if (target != nullptr) {
CellPosition targetPos = target->GetCell()->GetCellPosition();
if (shooter->IsFacingOtherPlayer(targetPos)) {
int damage;
if (shooter->HasDoubleLaser()) {
    damage = 2;
     }
    else {
    damage = 1;
                            }
    int cellWidth = UI.CellWidth;
    int cellHeight = UI.CellHeight;
    int toolBarH = UI.ToolBarHeight;
    int shooterRow = shooterPos.VCell();
    int shooterCol = shooterPos.HCell();
    int shooterLeft = shooterCol * cellWidth;
    int shooterTop = toolBarH + (shooterRow * cellHeight);
    int shooterRight = shooterLeft + cellWidth;
    int shooterBottom = shooterTop + cellHeight;
    int x1 = (shooterLeft + shooterRight) / 2;
    int y1 = (shooterTop + shooterBottom) / 2;
    int targetRow = targetPos.VCell();
    int targetCol = targetPos.HCell();
    int targetLeft = targetCol * cellWidth;
    int targetTop = toolBarH + (targetRow * cellHeight);
    int targetRight = targetLeft + cellWidth;
    int targetBottom = targetTop + cellHeight;
    int x2 = (targetLeft + targetRight) / 2;
    int y2 = (targetTop + targetBottom) / 2;
    bool shooterGear = shooter->GetReflectiveGear();
    bool targetGear = target->GetReflectiveGear();
          if (shooterGear && targetGear) {
               target->SetReflectiveGear(false);
                shooter->SetReflectiveGear(false);
                    target->SetHealth(target->GetHealth() - damage);
                  pGrid->GetOutput()->DrawLine(x1, y1, x2, y2, RED, 4);
                pGrid->GetOutput()->DrawLine(x2, y2, x1, y1, BLUE, 4);
             pGrid->GetOutput()->DrawLine(x1, y1, x2, y2, GREEN, 4);
            pGrid->GetOutput()->PrintMessage("Both have reflexive gear! Double reflection. Target is severely hit. Click to continue...");
    int clickX, clickY;
             pGrid->GetInput()->GetPointClicked(clickX, clickY);
             pGrid->UpdateInterface();
             pGrid->GetOutput()->ClearStatusBar();
          return;
            }
    else if (!shooterGear && targetGear) {
         target->SetReflectiveGear(false);
          shooter->SetHealth(shooter->GetHealth() - damage);
           pGrid->GetOutput()->DrawLine(x1, y1, x2, y2, RED, 4);
            pGrid->GetOutput()->DrawLine(x2, y2, x1, y1, BLUE, 4);
        pGrid->GetOutput()->PrintMessage("Target reflected the shot! Shooter is hit. Click to continue...");
    int clickX, clickY;
        pGrid->GetInput()->GetPointClicked(clickX, clickY);
        pGrid->UpdateInterface();
        pGrid->GetOutput()->ClearStatusBar();
       return;
     }
    else {
    target->SetHealth(target->GetHealth() - damage);
     pGrid->GetOutput()->DrawLine(x1, y1, x2, y2, RED, 4);
    pGrid->GetOutput()->PrintMessage("You shot the other player. Click to continue...");
     int clickX, clickY;
    pGrid->GetInput()->GetPointClicked(clickX, clickY);
    pGrid->UpdateInterface();
     pGrid->GetOutput()->ClearStatusBar();
    return;
       }
          }
int cellWidth = UI.CellWidth;
int cellHeight = UI.CellHeight;
int toolBarH = UI.ToolBarHeight;
int shooterRow = shooterPos.VCell();
int shooterCol = shooterPos.HCell();
 int shooterLeft = shooterCol * cellWidth;
  int shooterTop = toolBarH + (shooterRow * cellHeight);
 int shooterRight = shooterLeft + cellWidth;
int shooterBottom = shooterTop + cellHeight;
int x1 = (shooterLeft + shooterRight) / 2;
 int y1 = (shooterTop + shooterBottom) / 2;
int targetRow = targetPos.VCell();
int targetCol = targetPos.HCell();
int targetLeft = targetCol * cellWidth;
int targetTop = toolBarH + (targetRow * cellHeight);
 int targetRight = targetLeft + cellWidth;
int targetBottom = targetTop + cellHeight;
int x2 = (targetLeft + targetRight) / 2;
int y2 = (targetTop + targetBottom) / 2;
pGrid->GetOutput()->DrawLine(x1, y1, x2, y2, RED, 4);
 pGrid->GetOutput()->PrintMessage("Player shot!  Click to continue...");
int cx, cy;
pGrid->GetInput()->GetPointClicked(cx, cy);
 pGrid->UpdateInterface();
                    }
                }
            }
        }
    }
}
