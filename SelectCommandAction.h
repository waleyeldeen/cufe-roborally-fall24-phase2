#pragma once
#include "Action.h"

class Player;
class SelectCommandAction :
    public Action
{
    SelectCommandAction(ApplicationManager* pApp);

    virtual void ReadActionParameters();
    virtual void Execute();

    virtual ~SelectCommandAction();
};

