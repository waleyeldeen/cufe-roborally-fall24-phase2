#include "NewGame.h"
#include "ApplicationManager.h"
#include "Grid.h"
#include "Player.h"
#include "Output.h"
NewGame::NewGame(ApplicationManager* pApp) : Action(pApp) {}

NewGame::~NewGame() {}
void NewGame::ReadActionParameters() {}
void NewGame::Execute() {
  
    Grid* pGrid = pManager->GetGrid();
    if (!pGrid) {
        return;
    }
    pGrid->ClearGrid();
    pGrid->ResetPlayers();
    string PlayersInfo="";
    for (int i = 0; i < MaxPlayerCount; ++i) {
        Player* pPlayer = pGrid->GetPlayer(i);
        if (pPlayer) {
            pPlayer->AppendPlayerInfo(PlayersInfo);
        }
    }
    Output* pOut = pGrid->GetOutput();
    if (pOut) {
        pOut->ClearGridArea();
        pOut->ClearStatusBar();
        pOut->PrintMessage("New Game has started!");
    }
      }