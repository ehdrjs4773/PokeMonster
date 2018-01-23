#pragma once
#include "singletonBase.h"
#include <vector>
#include <map>

class pokemon;

//³»ºÎ ½Ì±ÛÅæ DB ¸¸µé¾îµÐ´Ù
class database : public singletonBase <database>
{
private:
	typedef vector<pokemon*> vPokemon;
	typedef vector<pokemon*>::iterator viPokemon;

private:
	vPokemon * _vPlayerPokemon;
	vPokemon* _vEnemyPokemon;

public:
	HRESULT init();
	void release();

	void loadDatabase(string name);

	database();
	~database();

	inline vPokemon* getVPlayerPokemon() { return _vPlayerPokemon; }
	inline vPokemon* getVEnemyPokemon() { return _vEnemyPokemon; }
	inline void setVPlayerPokemon(vPokemon* poke) { _vPlayerPokemon = poke; }
	inline void setVEnemyPokemon(vPokemon* poke) { _vEnemyPokemon = poke; }
};

