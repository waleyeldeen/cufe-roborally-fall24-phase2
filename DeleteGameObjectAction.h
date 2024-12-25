#pragma once
#include "Action.h"
class DeleteGameObjectAction : public Action
{
        CellPosition sourceCell; // The position of the cell from which the object will be Deleted

    public:
        DeleteGameObjectAction(ApplicationManager* pApp);
        virtual void ReadActionParameters();
        virtual void Execute();
        virtual ~DeleteGameObjectAction();
};

