#include "stdafx.h"
#include "skill.h"



skill::skill()
{
}


skill::~skill()
{
}

HRESULT skill::init(string name)
{
	_skillName = DATABASE->getSkillsData(name)->name;
	_element = (ELEMENT)DATABASE->getSkillsData(name)->element;
	_type = (SKILL_TYPE)DATABASE->getSkillsData(name)->type;
	_power = DATABASE->getSkillsData(name)->power;
	_acc = DATABASE->getSkillsData(name)->acc;
	_currentPP = _maxPP = DATABASE->getSkillsData(name)->pp;
	
	return S_OK;
}

void skill::setSkill(string name, int cp)
{
	_skillName = DATABASE->getSkillsData(name)->name;
	_element = (ELEMENT)DATABASE->getSkillsData(name)->element;
	_type = (SKILL_TYPE)DATABASE->getSkillsData(name)->type;
	_power = DATABASE->getSkillsData(name)->power;
	_acc = DATABASE->getSkillsData(name)->acc;
	_maxPP = DATABASE->getSkillsData(name)->pp;
	_currentPP = cp;
}