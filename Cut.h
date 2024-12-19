#pragma once
#include "Action.h"

class Cut : public Action {
    CellPosition sourceCell; // The position of the cell from which the object will be cut

public:
    Cut(ApplicationManager* pApp);
    virtual void ReadActionParameters();
    virtual void Execute();
     ~Cut();
};
