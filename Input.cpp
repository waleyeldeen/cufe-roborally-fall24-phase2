#include "Input.h"
using namespace std;
#include <iostream>
#include<string>
#include "Output.h"

//======================================================================================//
//								General Functions									    //
//======================================================================================//

Input::Input(window* pW)
{
	pWind = pW; // point to the passed window
}

////////////////////////////////////////////////////////////////////////////////////////// 

void Input::GetPointClicked(int& x, int& y) const
{
	pWind->WaitMouseClick(x, y); // Note: x and y of WaitMouseClick are sent by reference
}

////////////////////////////////////////////////////////////////////////////////////////// 

string Input::GetSrting(Output* pO) const
{
	string Label;
	char Key;
	while (1)
	{
		pWind->WaitKeyPress(Key);
		if (Key == 27)	// ESCAPE key is pressed
			return "";	// returns nothing as user has cancelled label
		if (Key == 13)	// ENTER key is pressed
			return Label;
		if ((Key == 8) && (Label.size() >= 1))	// BackSpace is pressed
			Label.resize(Label.size() - 1);
		else
			Label += Key;
		if (pO)
			pO->PrintMessage(Label);
	}
}

////////////////////////////////////////////////////////////////////////////////////////// 

int Input::GetInteger(Output* pO) const
{
	///TODO: [+]implement the GetInteger function as described in Input.h file 
	// using function GetString() defined above and function stoi()
	int numInput;
	string strInput;
	strInput = GetSrting(pO);
	if (strInput == "")
		return -1;
	numInput = stoi(strInput);
	// Note: stoi(s) converts string s into its equivalent integer (for example, "55" is converted to 55)
	return numInput; // this line should be changed with your implementation
}

//======================================================================================//
//								Game  Functions									        //
//======================================================================================//

ActionType Input::GetUserAction() const
{
	int x = -1, y = -1;
	GetPointClicked(x, y);

	//  ============ GUI in the Design mode ============
	if (UI.InterfaceMode == MODE_DESIGN)
	{
		// [1] If user clicks on the Toolbar
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			// Check which Menu item was clicked
			// ==> This assumes that menu items are lined up horizontally <==

			int clickedItemOrder = (x / UI.MenuItemWidth);

			// Divide x coord of the point clicked by the menu item width (integer division)
			// If division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (clickedItemOrder)
			{
			case ITM_EXIT_DESIGN_MODE: return EXIT;
			case ITM_SWITCH_TO_PLAY_MODE: return TO_PLAY_MODE;
			case ITM_LOAD: return LOAD;
			case ITM_DELETE: return DELETE_;
			case ITM_SAVE: return SAVE;
			case ITM_CUT: return CUT;
			case ITM_COPY: return COPY;
			case ITM_PASTE: return PASTE;
			case ITM_SET_FLAG_CELL: return SET_FLAG_CELL;
			case ITM_ADD_ANTENNA:return ADD_ANTENNA;
			case ITM_ADD_BELT: return ADD_BELT;
			case ITM_ADD_DANGER_ZONE:return ADD_DANGER_ZONE;
			case ITM_ADD_WATER_PIT:return ADD_WATER_PIT;
			case ITM_ADD_ROTATING_GEAR:return ADD_ROTATING_GEAR;
			case ITM_ADD_WORKSHOP:return ADD_WORKSHOP;

				///TODO: Add cases for the other items of Design Mode
			default: return EMPTY;	// A click on empty place in toolbar
			}
		}

		// [2] User clicks on the grid area
		if ((y >= UI.ToolBarHeight) && (y < UI.height - UI.StatusBarHeight))
		{
			return GRID_AREA;
		}

		// [3] User clicks on the status bar
		return STATUS;
	}
	// ============ GUI in the Play mode ============
	else if (UI.InterfaceMode == MODE_PLAY)
	{
		// [1] If user clicks on the Toolbar
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			// Check which Menu item was clicked
			// ==> This assumes that menu items are lined up horizontally <==

			int clickedItemOrder = (x / UI.MenuItemWidth);

			// Divide x coord of the point clicked by the menu item width (integer division)
			// If division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (clickedItemOrder)
			{
			case ITM_EXIT_PLAY_MODE: return EXIT;
			case ITM_SWITCH_TO_DESIGN_MODE: return TO_DESIGN_MODE;
			case ITM_NEW_GAME: return NEW_GAME;
			case ITM_EXECUTE_COMMANDS: return EXECUTE_COMMANDS;
			case ITM_SELECT_COMMAND: return SELECT_COMMAND;
			case ITM_REBOOT_AND_REPAIR: return REBOOT_AND_REPAIR;
			case ITM_USE_CONSUMABLE: return USE_CONSUMABLE;

				///[+]TODO: Add cases for the other items of Design Mode
			default: return EMPTY;	// A click on empty place in toolbar
			}
		}


		if ((y >= UI.ToolBarHeight) && (y < UI.height - UI.StatusBarHeight))
		{
			return GRID_AREA;
		}
		///[+]TODO:
		// perform checks similar to Design mode checks above for the Play Mode
		// and return the corresponding ActionType

		return STATUS;	// just for now ==> This should be updated
	}

}

////////////////////////////////////////////////////////////////////////////////////////// 

CellPosition Input::GetCellClicked() const
{
	int x, y;
	pWind->WaitMouseClick(x, y);	// Get the coordinates of the user click
	//cout << "X: " << x << ", Y: " << y << endl;

	CellPosition cellPos;
	int cellWidth = UI.CellWidth;
	int cellHeight = UI.CellHeight;

	if (UI.InterfaceMode == MODE_DESIGN)
	{
		if (y >= UI.ToolBarHeight && y <= (UI.height - UI.StatusBarHeight - UI.CommandsBarHeight))
		{
			// get VCell
			y = y - UI.ToolBarHeight; // remove toolbar height so that y is mearsure from top
			if (y > cellHeight * 4)
				cellPos.SetVCell(4);
			else if (y > cellHeight * 3)
				cellPos.SetVCell(3);
			else if (y > cellHeight * 2)
				cellPos.SetVCell(2);
			else if (y > cellHeight * 1)
				cellPos.SetVCell(1);
			else
				cellPos.SetVCell(0);

			// get HCell
			if (x > cellWidth * 10)
				cellPos.SetHCell(10);
			else if (x > cellWidth * 9)
				cellPos.SetHCell(9);
			else if (x > cellWidth * 8)
				cellPos.SetHCell(8);
			else if (x > cellWidth * 7)
				cellPos.SetHCell(7);
			else if (x > cellWidth * 6)
				cellPos.SetHCell(6);
			else if (x > cellWidth * 5)
				cellPos.SetHCell(5);
			else if (x > cellWidth * 4)
				cellPos.SetHCell(4);
			else if (x > cellWidth * 3)
				cellPos.SetHCell(3);
			else if (x > cellWidth * 2)
				cellPos.SetHCell(2);
			else if (x > cellWidth * 1)
				cellPos.SetHCell(1);
			else
				cellPos.SetHCell(0);
		}

	}
	return cellPos;
}

//////////////////////////////////////////////////////////////////////////////////////////

int Input::GetSelectedCommandIndex() const
{
	int x = -1, y = -1;
	GetPointClicked(x, y);

	if ((y >= UI.height - UI.StatusBarHeight - UI.CommandsBarHeight - UI.AvailableCommandsYOffset) && (y < UI.height - UI.StatusBarHeight))
	{
		if (x < UI.AvailableCommandsXOffset || x > UI.AvailableCommandsXOffset + (UI.CommandItemWidth / 2) * MaxAvailableCommands)
			return -1;

		return (x - UI.AvailableCommandsXOffset) / (UI.CommandItemWidth / 2);;
	}

	return -1;
}

//////////////////////////////////////////////////////////////////////////////////////////