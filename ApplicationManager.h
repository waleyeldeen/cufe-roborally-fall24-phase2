#pragma once

#include "DEFS.h"
#include "UI_Info.h"

class Input;
class Output;
class Grid;
class Round;
// Main class that manages everything in the application.
class ApplicationManager
{
	// Pointer to the Grid
	Grid* pGrid;

	// Pointers to the Input and Output 
	Input *pIn;
	Output *pOut;
	Round* pRound;

	ActionType nextAction;

public:

	ApplicationManager();  // Constructor: where the Input, Ouput and Grid are allocated
	~ApplicationManager(); // Destructor for needed deallocations

	// ========== Interface Management Functions ==========

	Grid * GetGrid() const;    // Returns pointer to the Grid

	ActionType getNextAction() const;

	void setNextAction(ActionType next);

	Round* GetRound() const;

	void UpdateInterface() const;

	// ========== Action-Related Functions ==========

	ActionType GetUserAction() const; // Reads the input command from the user and returns the corresponding action type

	void ExecuteAction(ActionType) ;  // Creates an action of the passed actionType and executes it

};

