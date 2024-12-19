#include "DisplayPlayersInfo.h"
#include "Grid.h"
#include "Player.h"
#include "Output.h"

DisplayPlayersInfo::DisplayPlayersInfo(ApplicationManager* pApp) : Action(pApp) {}

DisplayPlayersInfo::~DisplayPlayersInfo() {}

void DisplayPlayersInfo::ReadActionParameters() {}

void DisplayPlayersInfo::Execute() {
    Grid* pGrid = pManager->GetGrid();
    if (!pGrid) {
        return;
    }

   string PlayersInfo = "";
    for (int i = 0; i < MaxPlayerCount; i++) {
        Player* pPlayer = pGrid->GetPlayer(i);
        if (pPlayer) {
            pPlayer->AppendPlayerInfo(PlayersInfo);
            if (i < MaxPlayerCount - 1) {
                PlayersInfo += ", ";
            }
        }
    }

    Output* pOut = pGrid->GetOutput();
    if (pOut) {
        pOut->ClearStatusBar();
        pOut->PrintPlayersInfo(PlayersInfo);
    }
}
