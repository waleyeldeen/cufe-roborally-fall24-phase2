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
                    }
                }
            }
        }
    }
}
