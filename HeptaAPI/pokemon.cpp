#include "stdafx.h"
#include "pokemon.h"



pokemon::pokemon()
{
}


pokemon::~pokemon()
{
}

HRESULT pokemon::init(string name, int level)
{
	if (level > LEVEL_MAX)
		level = LEVEL_MAX;

	string tempName = name + "_back";
	string filePath = ".\\bmps\\battleScene\\pokemon_back\\" + name + "_back.bmp";
	IMAGEMANAGER->addFrameImage(tempName, filePath.c_str(), 120 * 2, 120, 2, 1, false, true, MAGENTA);
	tempName = name + "_front";
	filePath = ".\\bmps\\battleScene\\pokemon_front\\" + name + "_front.bmp";
	IMAGEMANAGER->addFrameImage(tempName, filePath.c_str(), 120 * 2, 120, 2, 1, false, true, MAGENTA);
	// 레벨, 속성, 이름
	_level = level;
	_element = (ELEMENT)DATABASE->getElementData(name)->element;
	_pokemonName = name;

	// 종족값
	_racialHP = DATABASE->getElementData(name)->hp;
	_racialATK = DATABASE->getElementData(name)->atk;
	_racialDEF = DATABASE->getElementData(name)->def;
	_racialSPECIAL = DATABASE->getElementData(name)->special;
	_racialSPEED = DATABASE->getElementData(name)->speed;

	// 개체값
	_individualATK = RND->getInt(16);
	_individualDEF = RND->getInt(16);
	_individualSPECIAL = RND->getInt(16);
	_individualSPEED = RND->getInt(16);

	_individualHP = 0;
	if (_individualATK % 2 == 1)
		_individualHP += 8;
	if (_individualDEF % 2 == 1)
		_individualHP += 4;
	if (_individualSPECIAL % 2 == 1)
		_individualHP += 2;
	if (_individualSPEED % 2 == 1)
		_individualHP += 1;

	// 노력치
	// 적 잡으면 얻을 수치
	// 이건 나중에 추가하자...
	_evsHP = 0;
	_evsATK = 0;
	_evsDEF = 0;
	_evsSPECIAL = 0;
	_evsSPEED = 2;
	_exp = 105;

	// 자신이 총 얻은 수치
	_evsExpHP = 0;
	_evsExpATK = 0;
	_evsExpDEF = 0;
	_evsExpSPECIAL = 0;
	_evsExpSPEED = 0;

	// 그에 따른 레벨
	_evsLvHP = 0;
	_evsLvATK = 0;
	_evsLvDEF = 0;
	_evsLvSPECIAL = 0;
	_evsLvSPEED = 0;

	// 위의 것을 종합한 실제 능력치
	_maxHP = _level * ((_racialHP + _individualHP + 50 + (_evsExpHP * pow((float)2, -11))) / 50);
	_currentHP = _maxHP;
	_atk = _level * ((_racialATK + _individualATK + 50 + (_evsExpATK * pow((float)2, -11))) / 50) + 5;
	_def = _level * ((_racialDEF + _individualDEF + 50 + (_evsExpDEF * pow((float)2, -11))) / 50) + 5;
	_special = _level * ((_racialSPECIAL + _individualSPECIAL + 50 + (_evsExpSPECIAL * pow((float)2, -11))) / 50) + 5;
	_speed = _level * ((_racialSPEED + _individualSPEED + 50 + (_evsExpSPEED * pow((float)2, -11))) / 50) + 5;

	// 경험치 공식에 따른 경험치
	_currentEXP = 0;
	_maxEXP = pow(_level + 1, (float)3) - pow(_level, (float)3);

	return S_OK;
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
	if (damage > _currentHP)
		_currentHP = 0;
	else
		_currentHP -= damage;
}

void pokemon::expPlus(int exp)
{
	_currentEXP += exp;
}

void pokemon::levelUp()
{
	_level++;
	_maxHP = _level * ((_racialHP + _individualHP + 50 + (_evsExpHP * pow((float)2, -11))) / 50);
	_currentHP = _maxHP;
	_atk = _level * ((_racialATK + _individualATK + 50 + (_evsExpATK * pow((float)2, -11))) / 50) + 5;
	_def = _level * ((_racialDEF + _individualDEF + 50 + (_evsExpDEF * pow((float)2, -11))) / 50) + 5;
	_special = _level * ((_racialSPECIAL + _individualSPECIAL + 50 + (_evsExpSPECIAL * pow((float)2, -11))) / 50) + 5;
	_speed = _level * ((_racialSPEED + _individualSPEED + 50 + (_evsExpSPEED * pow((float)2, -11))) / 50) + 5;
	_maxEXP = pow(_level + 1, (float)3) - pow(_level, (float)3);
	_currentEXP = 0;
}

void pokemon::setStatus(string name, int lv, int iH, int iA, int iD, int iSpec, int iS, int cH)
{
	_pokemonName = name;
	_element = (ELEMENT)DATABASE->getElementData(name)->element;
	_level = lv;

	_racialHP = DATABASE->getElementData(name)->hp;
	_racialATK = DATABASE->getElementData(name)->atk;
	_racialDEF = DATABASE->getElementData(name)->def;
	_racialSPECIAL = DATABASE->getElementData(name)->special;
	_racialSPEED = DATABASE->getElementData(name)->speed;

	_individualATK = iA;
	_individualDEF = iD;
	_individualSPECIAL = iSpec;
	_individualSPEED = iS;
	_individualHP = iH;

	_maxHP = _level * ((_racialHP + _individualHP + 50 + (0 * pow((float)2, -11))) / 50);
	_currentHP = cH;
	_atk = _level * ((_racialATK + _individualATK + 50 + (0 * pow((float)2, -11))) / 50) + 5;
	_def = _level * ((_racialDEF + _individualDEF + 50 + (0 * pow((float)2, -11))) / 50) + 5;
	_special = _level * ((_racialSPECIAL + _individualSPECIAL + 50 + (0 * pow((float)2, -11))) / 50) + 5;
	_speed = _level * ((_racialSPEED + _individualSPEED + 50 + (0 * pow((float)2, -11))) / 50) + 5;

	_currentEXP = 0;
	_maxEXP = pow(_level + 1, (float)3) - pow(_level, (float)3);
}