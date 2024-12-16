#pragma once
#include "Action.h"
#include <string>
class DisplayRandomCommands : public Action {
public:
    DisplayRandomCommands(ApplicationManager* pApp); 
    virtual void ReadActionParameters();             
    virtual void Execute();                          
};

