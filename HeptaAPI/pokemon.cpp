#include "stdafx.h"
#include "pokemon.h"



pokemon::pokemon()
{
}


pokemon::~pokemon()
{
}


bool pokemon::addSkill(skill* sk)
{
	if (_vSkills.size() >= 4)
		return false;
	else
	{
		_vSkills.push_back(sk);
		return true;
	}
}

void pokemon::hitDamager(int damage)
{
	_currentHP -= damage;

	if (_currentHP < 0)
		_currentHP = 0;
}