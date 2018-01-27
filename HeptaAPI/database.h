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

public:
	HRESULT init();
	void release();

	void loadDatabase(string name);

	//�Ӽ��� ���� ������
	elements* getElementData(string str) { return _mTotalElement.find(str)->second; }

	database();
	~database();

	inline vPokemon* getVPlayerPokemon() { return _vPlayerPokemon; }
	inline vPokemon* getVEnemyPokemon() { return _vEnemyPokemon; }
	inline void setVPlayerPokemon(vPokemon* poke) { _vPlayerPokemon = poke; }
	inline void setVEnemyPokemon(vPokemon* poke) { _vEnemyPokemon = poke; }
};

