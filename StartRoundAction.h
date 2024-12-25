#pragma once
#include "Action.h"
class StartRoundAction :
    public Action
{
    int startPlayer;
public:
    StartRoundAction(ApplicationManager* pApp);

    virtual void ReadActionParameters();
    virtual void Execute();

    virtual ~StartRoundAction();

};

