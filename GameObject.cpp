#include "GameObject.h"


GameObject::GameObject(const CellPosition & pos)
{
	position = pos; // Sets Position
}

CellPosition GameObject::GetPosition() const
{
	return position;
}

void GameObject::SetPositon(CellPosition newPos)
{
	position = newPos;
}
string GameObject::GetClassName()const {
	return ClassName;
}

GameObject::~GameObject()
{
}