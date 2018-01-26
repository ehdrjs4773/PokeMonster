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