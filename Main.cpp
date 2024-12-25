
#include "ApplicationManager.h"
#include "UI_Info.h"

// This Main Function Must NOT be Changed

int main()
{
	ActionType ActType;

	//Create an object of ApplicationManager
	ApplicationManager AppManager;

	do
	{
		//check if nextAction is not NO_ACTION and execute it
		if (AppManager.getNextAction() != NO_ACTION) 
		{
			ActType = AppManager.getNextAction();
			AppManager.setNextAction(NO_ACTION);
		}
		else
		//Read user action in of NO_ACTION
			ActType = AppManager.GetUserAction();


		//Exexute the action
		AppManager.ExecuteAction(ActType);

		//Update the drawings of the window after executing the action
		AppManager.UpdateInterface();

	} while(ActType != EXIT);


	return 0;
}


