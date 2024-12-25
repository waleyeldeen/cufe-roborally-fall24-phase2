#include "DisplayRandomCommands.h"
#include <iostream>
#include "Grid.h"
#include "Player.h"
#include "Output.h"
#include <cstdlib>  

DisplayRandomCommands::DisplayRandomCommands(ApplicationManager* pApp) : Action(pApp) {}

void DisplayRandomCommands::ReadActionParameters() {
   
}

void DisplayRandomCommands::Execute() {
  
    Grid* pGrid = pManager->GetGrid();
    Player* pPlayer = pGrid->GetCurrentPlayer();

    if (!pPlayer) {
        pGrid->PrintErrorMessage("Error: Player doesn't exist");
        return;
    }

  
    int health = pPlayer->GetHealth();
    int numOfCommandsExc = 5; 
    if (health < 5) {
        numOfCommandsExc = health; 
    }

    Command enums[8] = { MOVE_FORWARD_ONE_STEP, MOVE_BACKWARD_ONE_STEP , MOVE_FORWARD_TWO_STEPS , MOVE_BACKWARD_TWO_STEPS , MOVE_FORWARD_THREE_STEPS
        , MOVE_BACKWARD_THREE_STEPS , ROTATE_CLOCKWISE ,  ROTATE_COUNTERCLOCKWISE };

    const char* AvailableCommands[4] = {
        "Move Forward", "Move Backward", "Rotate Left", "Rotate Right"
    };

    Command save[5] = { MOVE_FORWARD_ONE_STEP, MOVE_BACKWARD_ONE_STEP , MOVE_FORWARD_TWO_STEPS , MOVE_BACKWARD_TWO_STEPS , MOVE_FORWARD_THREE_STEPS };

    Command available[10];
    int numAvailable = 10;
    for (int i = 0; i < 10; i++) {
        available[i] = NO_COMMAND;
    }

    for (int i = 0; i < 10; i++) {
        int randomIndex = rand() % 8;
        available[i] = enums[randomIndex];
    }

  
    //for (int i = 0; i < numOfCommandsExc; ++i) {
    //   int randomIndex = rand() % COMMANDS_COUNT;  
    //   if (randomIndex == 0) savedCommands[i] = NO_COMMAND;
    //   else if (randomIndex == 1) savedCommands[i] = MOVE_FORWARD_ONE_STEP;
    //   else if (randomIndex == 2) savedCommands[i] = MOVE_BACKWARD_ONE_STEP;
    //   else if (randomIndex == 3) savedCommands[i] = MOVE_FORWARD_TWO_STEPS;
    //   else if (randomIndex == 4) savedCommands[i] = MOVE_BACKWARD_TWO_STEPS;
    //   else if (randomIndex == 5) savedCommands[i] = MOVE_FORWARD_THREE_STEPS;
    //   else if (randomIndex == 6) savedCommands[i] = MOVE_BACKWARD_THREE_STEPS;
    //   else if (randomIndex == 7) savedCommands[i] = ROTATE_CLOCKWISE;
    //   else if (randomIndex == 8) savedCommands[i] = ROTATE_COUNTERCLOCKWISE;
    //}

    Output* pOut = pGrid->GetOutput();


    pOut->CreateCommandsBar(save, 5, available, 10);

    pOut->PrintMessage("Random commands have been displayed!");
}
