#pragma once
#include "pokemon.h"

class pikachu : public pokemon
{
public:
	pikachu();
	~pikachu();

	HRESULT init(int level);
};

