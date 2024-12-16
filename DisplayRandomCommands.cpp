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

    const char* AvailableCommands[4] = {
        "Move Forward", "Move Backward", "Rotate Left", "Rotate Right"
    };

 
   
    Command savedCommands[5];  
    string CommandItemImages[COMMANDS_COUNT] = {
      "images\\commands\\NoCommand.jpg",
      "images\\commands\\MoveForwardOneStep.jpg",
      "images\\commands\\MoveBackwardOneStep.jpg",
      "images\\commands\\MoveForwardTwoSteps.jpg",
      "images\\commands\\MoveBackwardTwoSteps.jpg",
      "images\\commands\\MoveForwardThreeSteps.jpg",
      "images\\commands\\MoveBackwardThreeSteps.jpg",
      "images\\commands\\RotateClockwise.jpg",
      "images\\commands\\RotateCounterClockwise.jpg"
    };


  
    for (int i = 0; i < numOfCommandsExc; ++i) {
       int randomIndex = rand() % COMMANDS_COUNT;  
       if (randomIndex == 0) savedCommands[i] = NO_COMMAND;
       else if (randomIndex == 1) savedCommands[i] = MOVE_FORWARD_ONE_STEP;
       else if (randomIndex == 2) savedCommands[i] = MOVE_BACKWARD_ONE_STEP;
       else if (randomIndex == 3) savedCommands[i] = MOVE_FORWARD_TWO_STEPS;
       else if (randomIndex == 4) savedCommands[i] = MOVE_BACKWARD_TWO_STEPS;
       else if (randomIndex == 5) savedCommands[i] = MOVE_FORWARD_THREE_STEPS;
       else if (randomIndex == 6) savedCommands[i] = MOVE_BACKWARD_THREE_STEPS;
       else if (randomIndex == 7) savedCommands[i] = ROTATE_CLOCKWISE;
       else if (randomIndex == 8) savedCommands[i] = ROTATE_COUNTERCLOCKWISE;
    }

    Output* pOut = pGrid->GetOutput();


    pOut->DrawSavedCommands(savedCommands, numOfCommandsExc, CommandItemImages);

    pOut->PrintMessage("Random commands have been displayed!");
}
