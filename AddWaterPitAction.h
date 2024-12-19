#pragma once
#include "Action.h"
#include "Input.h"
#include "Output.h"
#include "Belt.h"

class AddWaterPitAction : public Action {
private:
    // Always add action parameters as private data members

    // [Action Parameters]
    CellPosition waterPitPos; // The position of the water pit

    // Note: These parameters should be read in ReadActionParameters()
public:
    AddWaterPitAction(ApplicationManager* pApp);

    virtual void ReadActionParameters();

    virtual void Execute();
};
