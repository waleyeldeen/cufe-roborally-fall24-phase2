#pragma once

#include "Grid.h"
#include "Cell.h"

class Player
{
	Cell * pCell;		   // pointer to the current Cell of the player

	const int playerNum;   // the player number (from 0 to MaxPlayerCount-1)
	                       // player number does NOT change after construction (const.)

	int stepCount;		   // step count which is the same as his cellNum: from 1 to NumVerticalCells*NumHorizontalCells
	Direction currDirection; // Current Direction of the player
	int health;				// Player's current health points

	Command savedCommands[5];
	int savedCommandsCount;

	// owned equipments
	Consumable bag[MaxCarriedConsumables];// carried consumables
	int bagCount;
	// carried laser type (default, double laser)
	bool isHacked;// isHacked (to indicate whether the player is blocked to play the round, as a result of the opponent using a hacking device)
	
	double distanceFromAntenna;
public:

	Player(Cell * pCell, int playerNum); // Constructor making any needed initializations

	// ====== Setters and Getters ======

	void SetCell(Cell * cell);		// A setter for the pCell
	Cell* GetCell() const;			// A getter for the pCell

	void SetHealth(int h);			// A setter for the health points
	int GetHealth();				// A getter for the health points

  
	void setDistanceFromAntenna(double newDistance);
	double getDistanceFromAntenna() const;
	bool GetIsHacked();
	void Hack();
	void UnHack();

	bool AddSavedCommand(Command newCommand);

	//
	Consumable* GetBag();

	// returns false if bag is full
	// returns true if item added to last empty index
	bool AddToBag(Consumable newConsumable);

	// used when player uses a consumable
	// returns true if consumable is found and removed
	// returns false if consumable does not exist in players bag
	bool RemoveFromBag(Consumable removeConsumable);

	bool IsBagFull();
	///TODO: You can add setters and getters for data members here (if needed)

	// ====== Drawing Functions ======

	void Draw(Output* pOut) const;			// Draws the Player's Triangle on its current cell

	void ClearDrawing(Output* pOut) const;	// Clears the Player's Triangle from its current cell

	// ====== Game Functions ======

	void Move(Grid * pGrid, Command moveCommands[]);	// Moves the Player with the passed move command
														// and Applies the Game Object's effect (if any) of the end reached cell 
	void Rotate(bool clockwise);													// for example, if the end cell contains a belt, take it
	
	void AppendPlayerInfo(string & playersInfo) const; // Appends player's info to the input string, 
	                                                   // for example: P0(Direction, health)
	void Reset();
};

