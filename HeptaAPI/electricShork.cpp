#include "stdafx.h"
#include "electricShork.h"



electricShork::electricShork()
{
}


electricShork::~electricShork()
{
}

HRESULT electricShork::init()
{
	_skillName = "Àü±â¼îÅ©";
	_element = ELEMENT_ELECTRIC;
	_type = SKILL_SPECIAL;
	_power = 40;
	_acc = 100;
	_currentPP = _maxPP = 30;

	return S_OK;
}
