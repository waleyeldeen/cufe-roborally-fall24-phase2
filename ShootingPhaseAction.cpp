//#include "ShootingPhaseAction.h"
//#include "Player.h"
//#include "Cell.h"
//#include "Grid.h"
//#include "Output.h"
//#include "Input.h"
//
//ShootingPhaseAction::ShootingPhaseAction(Grid* grid) : pGrid(grid) {}
//
//bool ShootingPhaseAction::IsFacingOtherPlayer(const CellPosition& shooterPos, Direction shooterDir, const CellPosition& targetPos) const {
//    if (shooterDir == RIGHT && shooterPos.VCell() == targetPos.VCell() && shooterPos.HCell() < targetPos.HCell()) {
//        return true; // Shooter faces right , target is to the right
//    }
//    else if (shooterDir == LEFT && shooterPos.VCell() == targetPos.VCell() && shooterPos.HCell() > targetPos.HCell()) {
//        return true; // Shooter faces left , target is to the left
//    }
//    else if (shooterDir == UP && shooterPos.HCell() == targetPos.HCell() && shooterPos.VCell() > targetPos.VCell()) {
//        return true; // Shooter faces up , target is above
//    }
//    else if (shooterDir == DOWN && shooterPos.HCell() == targetPos.HCell() && shooterPos.VCell() < targetPos.VCell()) {
//        return true; // Shooter faces down , target is below
//    }
//    return false;
//}
//
//void ShootingPhaseAction::Execute() {
//    for (int i = 0; i < MaxPlayerCount; i++) {
//        Player* shooter = pGrid->GetPlayer(i);
//        if (!shooter)
//            continue;
//
//        CellPosition shooterPos = shooter->GetCell()->GetCellPosition();
//        Direction shooterDir = shooter->GetDirection();
//
//        for (int j = 0; j < MaxPlayerCount; j++) {
//            if (i == j)
//                continue;
//
//            Player* target = pGrid->GetPlayer(j);
//            if (!target)
//                continue;
//
//            CellPosition targetPos = target->GetCell()->GetCellPosition();
//
//           
//            if (IsFacingOtherPlayer(shooterPos, shooterDir, targetPos)) {
//
//               
//                int damage;
//                if (shooter->HasDoubleLaser())
//                {
//                    damage = 2;
//                }
//                else
//                {
//                    damage = 1;
//                }
//
//              
//                target->SetHealth(target->GetHealth() - damage);
//
//               
//                pGrid->GetOutput()->PrintMessage("You shot the other player, click to continue.");
//                int x = shooterPos.HCell();
//                int y = shooterPos.VCell();
//                pGrid->GetInput()->GetPointClicked(x, y);
//
//                
//                return;
//            }
//        }
//    }
//}
