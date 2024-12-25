#pragma once
#include "Action.h"

class CutAction : public Action {
    CellPosition sourceCell; // The position of the cell from which the object will be CutAction

public:
    CutAction(ApplicationManager* pApp);
    virtual void ReadActionParameters();
    virtual void Execute();
    virtual ~CutAction();
};
