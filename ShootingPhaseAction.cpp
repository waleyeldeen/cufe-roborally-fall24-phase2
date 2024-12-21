#include "ShootingPhaseAction.h"
#include "Player.h"
#include "Cell.h"
#include "Grid.h"
#include "Output.h"
#include "Input.h"

ShootingPhaseAction::ShootingPhaseAction(Grid* grid) : pGrid(grid) {}
ShootingPhaseAction::~ShootingPhaseAction() {};
void ShootingPhaseAction::Execute()
{
    for (int i = 0; i < MaxPlayerCount; i++)
    {
   Player* shooter = pGrid->GetPlayer(i);
    if (shooter != nullptr)
    {
   CellPosition shooterPos = shooter->GetCell()->GetCellPosition();
    for (int j = 0; j < MaxPlayerCount; j++)
            {
    if (i != j)
    {
    Player* target = pGrid->GetPlayer(j);
    if (target != nullptr)
     {
  CellPosition targetPos = target->GetCell()->GetCellPosition();
    if (shooter->IsFacingOtherPlayer(targetPos))
                        {
     int damage;
    if (shooter->HasDoubleLaser())
    damage = 2;
    else
    damage = 1;
    target->SetHealth(target->GetHealth() - damage);
    pGrid->GetOutput()->PrintMessage("You shot the other player, click to continue.");
    int x = 0, y = 0;
    pGrid->GetInput()->GetPointClicked(x, y);
    return;
                        }
    // bonus
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

    pGrid->GetOutput()->PrintMessage("Player shot! Click to continue...");
    int cx, cy;
    pGrid->GetInput()->GetPointClicked(cx, cy);
    pGrid->UpdateInterface();


    }
    }
    }
    }
    }
}
