#include "stdafx.h"
#include "bodyAttack.h"



bodyAttack::bodyAttack()
{
}


bodyAttack::~bodyAttack()
{
}

HRESULT bodyAttack::init()
{
	_skillName = "몸통박치기";
	_element = ELEMENT_NORMAL;
	_type = SKILL_PHYSIC;
	_power = 35;
	_acc = 95;
	_currentPP = _maxPP = 35;

	return S_OK;
}