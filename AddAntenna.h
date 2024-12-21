#pragma once
#include "Action.h"
#include "Input.h"
#include "Output.h"
#include"Antenna.h"
class AddAntenna:public Action
{
	CellPosition AntennaPos;

public:
	AddAntenna(ApplicationManager* pApp);
  virtual void Execute();
   virtual void ReadActionParameters();
   ~AddAntenna();


};

