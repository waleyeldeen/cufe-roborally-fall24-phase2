#pragma once
#include "Action.h"
#include "Input.h"
#include "Output.h"
#include "DangerZone.h"

class AddDangerZoneAction :	public Action
{
private:
    // Always add action parameters as private data members

    // [Action Parameters]
    CellPosition dangerZonePos; // The position of the water pit

    // Note: These parameters should be read in ReadActionParameters()
public:
    AddDangerZoneAction(ApplicationManager* pApp);

    virtual void ReadActionParameters();

    virtual void Execute();

    virtual ~AddDangerZoneAction();
};

