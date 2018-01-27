#pragma once
#include "singletonBase.h"
#include <vector>
#include <map>

class pokemon;

class elements
{
public:
	string name;
	int element;
	int hp;
	int atk;
	int def;
	int speed;
	int special;

	elements() {};
	~elements() {};
};

class skills
{
public:
	// 이름, 속성, 분류, 위력, 명중률, pp
	string name;
	int element;
	int type;
	int power;
	int acc;
	int pp;

	skills() {};
	~skills() {};
};

//내부 싱글톤 DB 만들어둔다
class database : public singletonBase <database>
{
private:
	typedef vector<pokemon*> vPokemon;
	typedef vector<pokemon*>::iterator viPokemon;

	typedef vector<string> arrElements;
	typedef vector<string>::iterator iterElements;

	typedef map<string, elements*> arrElement;
	typedef map<string, elements*>::iterator iterElement;

private:
	vPokemon* _vPlayerPokemon;
	vPokemon* _vEnemyPokemon;

	// 포켓몬 종족값 등록한 맵
	arrElement _mTotalElement;
	map<string, skills*> _mTotalSkill;

public:
	HRESULT init();
	void release();

	void loadDatabasePokemon(string name);
	void loadDatabaseSkill(string name);

	//속성에 대한 접근자
	elements* getElementData(string str) { return _mTotalElement.find(str)->second; }
	skills* getSkillsData(string str) { return _mTotalSkill.find(str)->second; }

	database();
	~database();

	inline vPokemon* getVPlayerPokemon() { return _vPlayerPokemon; }
	inline vPokemon* getVEnemyPokemon() { return _vEnemyPokemon; }
	inline void setVPlayerPokemon(vPokemon* poke) { _vPlayerPokemon = poke; }
	inline void setVEnemyPokemon(vPokemon* poke) { _vEnemyPokemon = poke; }
};

