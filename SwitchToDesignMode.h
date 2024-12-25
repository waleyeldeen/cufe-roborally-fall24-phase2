#pragma once
#include "Action.h"
class SwitchToDesignMode :
    public Action
{
public:
    SwitchToDesignMode(ApplicationManager* pApp);

    virtual void ReadActionParameters();          
    virtual void Execute();                       

     ~SwitchToDesignMode();               
};


