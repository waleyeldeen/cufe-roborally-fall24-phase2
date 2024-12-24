#pragma once
#include "Action.h"
#include "Grid.h"
#include "Input.h"
#include "Output.h"
#include "Player.h"

class UseConsumableAction : public Action
{
private:
	Consumable consumable;
    Consumable list[CONSUMABLE_COUNT];
    bool validParam;
public:
    UseConsumableAction(ApplicationManager* pApp);

    virtual void ReadActionParameters();

    virtual void Execute();

    virtual ~UseConsumableAction();
};

