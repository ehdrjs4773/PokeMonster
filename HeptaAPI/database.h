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
	// �̸�, �Ӽ�, �з�, ����, ���߷�, pp
	string name;
	int element;
	int type;
	int power;
	int acc;
	int pp;

	skills() {};
	~skills() {};
};

//���� �̱��� DB �����д�
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

	// ���ϸ� ������ ����� ��
	arrElement _mTotalElement;
	map<string, skills*> _mTotalSkill;

public:
	HRESULT init();
	void release();

	void loadDatabasePokemon(string name);
	void loadDatabaseSkill(string name);

	//�Ӽ��� ���� ������
	elements* getElementData(string str) { return _mTotalElement.find(str)->second; }
	skills* getSkillsData(string str) { return _mTotalSkill.find(str)->second; }

	database();
	~database();

	inline vPokemon* getVPlayerPokemon() { return _vPlayerPokemon; }
	inline vPokemon* getVEnemyPokemon() { return _vEnemyPokemon; }
	inline void setVPlayerPokemon(vPokemon* poke) { _vPlayerPokemon = poke; }
	inline void setVEnemyPokemon(vPokemon* poke) { _vEnemyPokemon = poke; }
};

