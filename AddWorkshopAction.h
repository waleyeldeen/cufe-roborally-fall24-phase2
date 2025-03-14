#pragma once
#include "Action.h"
#include "Input.h"
#include "Output.h"
#include "Workshop.h"

class AddWorkshopAction :
    public Action
{
private:
    // Always add action parameters as private data members

    // [Action Parameters]
    CellPosition workshopPos; // The position of the water pit

    // Note: These parameters should be read in ReadActionParameters()
public:
    AddWorkshopAction(ApplicationManager* pApp);

    virtual void ReadActionParameters();

    virtual void Execute();

};

