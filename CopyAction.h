#pragma once
#include "Action.h"
class CopyAction : public Action
{

     CellPosition sourceCell; // The position of the cell from which the object will be CutAction

    public:
        CopyAction(ApplicationManager* pApp);
        virtual void ReadActionParameters();
        virtual void Execute();
        virtual ~CopyAction();
    };



