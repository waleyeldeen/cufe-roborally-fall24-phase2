#include "CellPosition.h"
#include "UI_Info.h"

CellPosition::CellPosition()
{
	// (-1) indicating an invalid cell (uninitialized by the user)
	vCell = -1;
	hCell = -1;
}

CellPosition::CellPosition(int v, int h)
{
	// (-1) indicating an invalid cell (uninitialized by the user)
	vCell = -1;
	hCell = -1;

	SetVCell(v);
	SetHCell(h);
}

CellPosition::CellPosition(int cellNum)
{
	(*this) = GetCellPositionFromNum(cellNum); // the function call with build a cell position (vCell and hCell)
	// from the passed (cellNum)
	// (*this) = ... --> this will copy the returned (vCell and hCell)
	//                   to the data members (vCell and hCell)
}

bool CellPosition::SetVCell(int v)
{
	///[+]TODO: Implement this function as described in the .h file (don't forget the validation)

	//Validation
	if (v > 4 || v < 0)
		return false;

	vCell = v;
	return true;
}

bool CellPosition::SetHCell(int h)
{
	///[+]TODO: Implement this function as described in the .h file (don't forget the validation)

	//Validation
	if (h > 10 || h < 0)
		return false;

	hCell = h;
	return true;
}

int CellPosition::VCell() const
{
	return vCell;
}

int CellPosition::HCell() const
{
	return hCell;
}

bool CellPosition::IsValidCell() const
{
	///[+]TODO: Implement this function as described in the .h file

	if (VCell() > 4 || VCell() < 0 || HCell() > 10 || HCell() < 0)
		return false;

	return true;
}

int CellPosition::GetCellNum() const
{
	return GetCellNumFromPosition(*this); // (*this) is the calling object of GetCellNum
	// which means the object of the current data members (vCell and hCell)
}

int CellPosition::GetCellNumFromPosition(const CellPosition& cellPosition)
{
	// Note:
	// this is a static function (do NOT need a calling object so CANNOT use the data members of the calling object, vCell&hCell)
	// just define an integer that represents cell number and calculate it using the passed cellPosition then return it

	///[+]TODO: Implement this function as described in the .h file
	int cellNum;
	int vCell = cellPosition.VCell();
	int hCell = cellPosition.HCell();

	int numComleteRows = (4 - vCell) * 11;
	cellNum = numComleteRows + (hCell + 1);

	return cellNum;
}

CellPosition CellPosition::GetCellPositionFromNum(int cellNum)
{
	// this is a static function (do NOT need a calling object so CANNOT use the data members of the calling object, vCell&hCell)

	CellPosition position;

	/// [+]TODO: Implement this function as described in the .h file

	// Note: use the passed cellNum to set the vCell and hCell of the "position" variable declared inside the function
	//       I mean: position.SetVCell(...) and position.SetHCell(...) then return it

	int vCell, hCell, numOfCompleteRows = 0;

	for (int i = 0; i <= 4; i++) {
		cellNum -= 11;
		if (cellNum > 0)
			numOfCompleteRows++;
		else
			cellNum += 11;
	}

	position.SetVCell(4 - numOfCompleteRows);
	position.SetHCell(cellNum - 1);
	return position;
}

void CellPosition::AddCellNum(int addedNum, Direction direction)
{
	/// [+]TODO: Implement this function as described in the .h file
	/// TODO: Validation
	// Note: this function updates the data members (vCell and hCell) of the calling object
	int newCellNum;
	if (direction == UP) {
		newCellNum = GetCellNum() + addedNum * 11;
		// if it exceeds the grid it will stop at last row
		if (newCellNum <= 55) {
			SetVCell(GetCellPositionFromNum(newCellNum).VCell());
		}
		else if (newCellNum > 55)
			SetVCell(0);

	}
	else if (direction == DOWN) {
		newCellNum = GetCellNum() - addedNum * 11;
		// if it exceeds the grid it will stop at last row
		if (newCellNum >= 1) {
			SetVCell(GetCellPositionFromNum(newCellNum).VCell());
		}
		else if (newCellNum < 1) {
			SetVCell(4);
		}
	}
	else if (direction == RIGHT) {
		int maxAddCellNum = 11 - HCell() - 1;
		newCellNum = GetCellNum() + addedNum;
		if (addedNum > maxAddCellNum) {
			SetHCell(10);
		}
		else if (addedNum <= maxAddCellNum) {
			SetHCell(GetCellPositionFromNum(newCellNum).HCell());
		}
	}
	else if (direction == LEFT) {
		int maxAddCellNum = 11 - (11 - HCell() - 1) - 1;
		newCellNum = GetCellNum() - addedNum;
		if (addedNum > maxAddCellNum) {
			SetHCell(0);
		}
		else if (addedNum <= maxAddCellNum) {
			SetHCell(GetCellPositionFromNum(newCellNum).HCell());
		}
	}
}