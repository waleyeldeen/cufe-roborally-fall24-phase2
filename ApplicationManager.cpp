#include "ApplicationManager.h"
#include "SwitchToPlayMode.h"
#include "SwitchToDesignMode.h"
#include "Grid.h"
#include "AddBeltAction.h"
#include "AddRotatingGearAction.h"
#include "AddWaterPitAction.h"
#include "AddDangerZoneAction.h"
#include "AddWorkshopAction.h"
#include "AddFlagAction.h"
#include "NewGameAction.h"
#include "AddAntennaAction.h"
#include"PasteAction.h"
#include"CutAction.h"
#include"CopyAction.h"
#include "RebootAndRepairAction.h"
#include"DeleteGameObjectAction.h"
#include "DisplayRandomCommands.h"
#include "Round.h"
#include "StartRoundAction.h"
///TODO: Add #include for all action types

ApplicationManager::ApplicationManager()
{
	// Create Input, output and Grid
	pOut = new Output();
	pIn = pOut->CreateInput();
	pGrid = new Grid(pIn, pOut);
	pRound = new Round(pGrid);

	nextAction = NO_ACTION;
}

////////////////////////////////////////////////////////////////////////////////////

ApplicationManager::~ApplicationManager()
{
	delete pGrid;
}

//==================================================================================//
//								Interface Management Functions						//
//==================================================================================//

Grid * ApplicationManager::GetGrid() const
{
	return pGrid;
}

Round* ApplicationManager::GetRound() const
{
	return pRound;
}

ActionType ApplicationManager::getNextAction() const
{
	return this->nextAction;
}

void ApplicationManager::setNextAction(ActionType next)
{
	this->nextAction = next;
}

void ApplicationManager::UpdateInterface() const
{
	pGrid->UpdateInterface();
}

//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//

ActionType ApplicationManager::GetUserAction() const
{
	// Ask the input to get the action from the user.
	return pIn->GetUserAction();
}

////////////////////////////////////////////////////////////////////////////////////

// Creates an action and executes it
void ApplicationManager::ExecuteAction(ActionType ActType) 
{
	Action* pAct = NULL;

	// According to Action Type, create the corresponding action object
	switch (ActType)
	{
	case ADD_BELT:
		pAct = new AddBeltAction(this);
		break;

	case ADD_ROTATING_GEAR:
		// create an object of AddRotatingGearAction here
		pAct = new AddRotatingGearAction(this);
		break;

	case ADD_WATER_PIT:
		pAct = new AddWaterPitAction(this);
		break;

	case ADD_DANGER_ZONE:
		pAct = new AddDangerZoneAction(this);
		break;

	case ADD_WORKSHOP:
		pAct = new AddWorkshopAction(this);
		break;

	case SET_FLAG_CELL:
		// create an object of AddFlagAction here
		pAct = new AddFlagAction(this);
		break;
	case ADD_ANTENNA:
		pAct = new AddAntennaAction(this);
		break;
	

	case EXIT:
		break;

	case TO_PLAY_MODE:					//TODO:
		pAct= new SwitchToPlayMode(this); // temporary till you made its action class (CHANGE THIS LATTER)
		break;

	

	case TO_DESIGN_MODE:				//TODO:
		pAct = new SwitchToDesignMode(this); // temporary till you made its action class (CHANGE THIS LATTER)
		break;

		///TODO: Add a case for EACH Action type in the Design mode or Play mode

	case CUT:
		pAct = new CutAction(this);
		break;
	case COPY:
		pAct = new CopyAction(this);
		break;
	case PASTE:
		pAct = new PasteAction(this);
		break;
	case DELETE_:
		pAct = new DeleteGameObjectAction(this);
		break;
	// PLAYMODE
	case NEW_GAME:
		pAct = new NewGameAction(this);
		break;
	case REBOOT_AND_REPAIR:
		pAct = new RebootAndRepairAction(this);
		break;

	case START_ROUND_ACTION:
		pAct = new StartRoundAction(this);
		break;

	case DISPLAY_COMMANDS:
		pAct = new DisplayRandomCommands(this);
		break;

		///TODO: Add a case for EACH Action type in the Design mode or Play mode
	case STATUS:	// a click on the status bar ==> no action
		return;

	}
	

	// Execute the created action
	if(pAct != NULL)
	{
		pAct->Execute(); // Execute
		delete pAct;	 // Action is not needed any more after executing ==> delete it
		pAct = NULL;
	}
}
