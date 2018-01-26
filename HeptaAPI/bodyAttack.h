#pragma once
#include "skill.h"

// 몸통박치기

class bodyAttack : public skill
{
public:
	bodyAttack();
	~bodyAttack();

	HRESULT init();
};

