#include "stdafx.h"
#include "pikachu.h"



pikachu::pikachu()
{
}


pikachu::~pikachu()
{
}

HRESULT pikachu::init(int level)
{
	// ����, �Ӽ�, �̸�
	_level = level;
	_element = ELEMENT_ELECTRIC;
	_pokemonName = "��ī��";

	// ������
	_racialHP		= 35;
	_racialATK		= 55;
	_racialDEF		= 30;
	_racialSPECIAL	= 50;
	_racialSPEED	= 90;

	// ��ü��
	_individualATK		= RND->getInt(16);
	_individualDEF		= RND->getInt(16);
	_individualSPECIAL	= RND->getInt(16);
	_individualSPEED	= RND->getInt(16);

	_individualHP = 0;
	if (_individualATK % 2 == 1)
		_individualHP += 8;
	if (_individualDEF % 2 == 1)
		_individualHP += 4;
	if (_individualSPECIAL % 2 == 1)
		_individualHP += 2;
	if (_individualSPEED % 2 == 1)
		_individualHP += 1;

	// ���ġ
	// �� ������ ���� ��ġ
	_evsHP		= 0;
	_evsATK		= 0;
	_evsDEF		= 0;
	_evsSPECIAL	= 0;
	_evsSPEED	= 2;

	// �ڽ��� �� ���� ��ġ
	_evsExpHP		= 0;
	_evsExpATK		= 0;
	_evsExpDEF		= 0;
	_evsExpSPECIAL	= 0;
	_evsExpSPEED	= 0;

	// �׿� ���� ����
	_evsLvHP		= 0;
	_evsLvATK		= 0;
	_evsLvDEF		= 0;
	_evsLvSPECIAL	= 0;
	_evsLvSPEED		= 0;

	// ���� ���� ������ ���� �ɷ�ġ
	_maxHP = _level * ((_racialHP + _individualHP + 50 + (_evsExpHP * pow((float)2, -11))) / 50);
	_currentHP = _maxHP;
	_atk = _level * ((_racialATK + _individualATK + 50 + (_evsExpATK * pow((float)2, -11))) / 50) + 5;
	_def = _level * ((_racialDEF + _individualDEF + 50 + (_evsExpDEF * pow((float)2, -11))) / 50) + 5;
	_special = _level * ((_racialSPECIAL + _individualSPECIAL + 50 + (_evsExpSPECIAL * pow((float)2, -11))) / 50) + 5;
	_speed = _level * ((_racialSPEED + _individualSPEED + 50 + (_evsExpSPEED * pow((float)2, -11))) / 50) + 5;

	// ����ġ ���Ŀ� ���� ����ġ
	_currentEXP = 0;
	_maxEXP = pow(_level + 1, (float)3) - pow(_level, (float)3);
	_exp = 105;

	return S_OK;
}