#include "Player.h"

#include "GameObject.h"

Player::Player(Cell * pCell, int playerNum) : stepCount(0), health(10), playerNum(playerNum), currDirection(RIGHT)
{
	this->pCell = pCell;
	this->isHacked = false; // player is not hacked by default
	this->bagCount = 0;
	// set all slots in bag to empty
	for (int i = 0; i < MaxCarriedConsumables; i++)
	{
		bag[i] = EMPTY_BAG;
	}
	// Make all the needed initialization or validations
}

// ====== Setters and Getters ======

void Player::SetCell(Cell * cell)
{
	pCell = cell;
}

Cell* Player::GetCell() const
{
	return pCell;
}

void Player::SetHealth(int h)
{
	this->health = h;
	///TODO: Do any needed validations
}

int Player::GetHealth()
{
	return this->health;
}

bool Player::GetIsHacked()
{
	return this->isHacked;
}

void Player::Hack() {
	isHacked = true;
}

void Player::UnHack() {
	isHacked = false;
}

Consumable* Player::GetBag() {
	return this->bag;
}


bool Player::AddToBag(Consumable newConsumable)
{
	if (bagCount < MaxCarriedConsumables) // if there is space in bag
	{
		bag[bagCount++] = newConsumable;
		return true;
	}
	else if (bagCount >= MaxCarriedConsumables) // bag is full
	{
		return false;
	}
	else
		return false;
}

bool Player::RemoveFromBag(Consumable removeConsumable)
{
	for (int i = 0; i < MaxCarriedConsumables; i++)
	{
		if (bag[i] == removeConsumable)
		{
			// switch with last non empty slot
			Consumable last = bag[bagCount - 1];
			bag[i] = last;
			bag[bagCount - 1] = EMPTY_BAG;
			this->bagCount--;
			return true;
		}
	}

	return false; // incase no match is found
}

// ====== Drawing Functions ======

void Player::Draw(Output* pOut) const
{
	color playerColor = UI.PlayerColors[playerNum];


	///TODO: use the appropriate output function to draw the player with "playerColor"

}

void Player::ClearDrawing(Output* pOut) const
{
	///TODO: Modify the cellColor to draw the correct cellColor (hint: if cell contains non-default cellColor)
	color cellColor = UI.CellColor;
	
	
	///TODO: use the appropriate output function to draw the player with "cellColor" (to clear it)

}

// ====== Game Functions ======

void Player::Move(Grid * pGrid, Command moveCommands[])
{

	///TODO: Implement this function using the guidelines mentioned below

	// - If a player has 5 (could have less) saved moveCommands, the robot will execute the first saved command,
	//		then wait for a mouse click (display a message "Click anywhere to execute the next command").
	//		After executing all the 5 saved commands, the game object effect at the final destination cell will
	//		be applied.
	// 
	// - Use the CellPosition class to help you calculate the destination cell using the current cell
	// - Use the Grid class to update pCell
	// - Don't forget to apply game objects at the final destination cell and check for game ending

}

void Player::Rotate(bool clockwise)
{
	Direction clockwiseOrder[5] = { UP, RIGHT, DOWN, LEFT, UP };
	Direction antiClockwiseOrder[5] = { UP, LEFT, DOWN, RIGHT, UP };

	for (int i = 0; i < 5; i++)
	{
		if (this->currDirection == clockwiseOrder[i])
		{
			if (clockwise)
				currDirection = clockwiseOrder[i + 1];
			else
				currDirection = antiClockwiseOrder[i + 1];
			return;
		}
	}
}

void Player::AppendPlayerInfo(string & playersInfo) const
{
	// TODO: Modify the Info as needed
	playersInfo += "P" + to_string(playerNum) + "(" ;
	playersInfo += to_string(currDirection) + ", ";
	playersInfo += to_string(health) + ")";

}
void Player::Reset()
{
	health = 10;
	stepCount = 0;
	currDirection = RIGHT;
	if (pCell)
	{
		pCell = nullptr;
	}
}