#pragma once
#include "gameNode.h"
#include "skill.h"
#include <vector>
#include <math.h>

#define LEVEL_MAX	100		// 최대 레벨

class pokemon : public gameNode
{
protected:
	ELEMENT _element;	// 포켓몬의 속성
	string _pokemonName;	// 포켓몬 이름(종류)

	// 자... 이제 시작이야...
	// 1세대 기준
	// 일단 종족값
	USHORT _racialHP;
	USHORT _racialATK;
	USHORT _racialDEF;
	USHORT _racialSPECIAL;
	USHORT _racialSPEED;

	// 다음은 개체값인데... 이게 랜덤이래...
	USHORT _individualATK;			// 0~15의 16가지 숫자가 랜덤으로 부여
	USHORT _individualDEF;			// 
	USHORT _individualSPECIAL;		// 
	USHORT _individualSPEED;		// 
	USHORT _individualHP;			// 공격이 홀수면 +8, 방어가 홀수면 +4, 특수가 홀수면 +2, 스피드가 홀수면 +1
								// 따라서 모두 홀수면 15, 모두 짝수면 0

	// 마지막으로 노력치
	// 최초(몬스터 처음으로 잡음, 알 부화 등등)에는 0
	// 적 잡으면 얻을 노력치들
	USHORT _evsHP;
	USHORT _evsATK;
	USHORT _evsDEF;
	USHORT _evsSPECIAL;
	USHORT _evsSPEED;

	// 얻은 노력치들
	USHORT _evsExpHP;
	USHORT _evsExpATK;
	USHORT _evsExpDEF;
	USHORT _evsExpSPECIAL;
	USHORT _evsExpSPEED;

	// 그에 따른 노력치 레벨
	USHORT _evsLvHP;
	USHORT _evsLvATK;
	USHORT _evsLvDEF;
	USHORT _evsLvSPECIAL;
	USHORT _evsLvSPEED;

	USHORT _level;			// 레벨

	// 위의 것을 종합한 실제 능력치
	USHORT _maxHP;
	USHORT _currentHP;
	USHORT _atk;
	USHORT _def;
	USHORT _special;
	USHORT _speed;

	// 경험치는 간단히 모든 포켓몬에 중간빠름공식 채택
	// 레벨 N이 되기 까지 총 필요 경험치는 N^3
	// 따라서 지금 레벨에서 다음 레벨까지 필요한 경험치는
	// (현재레벨 + 1)^3 - 현재레벨^3
	USHORT _maxEXP;
	USHORT _currentEXP;

	// 적을 잡으면 얻는 경험치
	USHORT _exp;

	vector<skill*>				_vSkills;		// 스킬 벡터
	vector<skill*>::iterator	_vSkillsIter;	// 스킬 벡터 이터레이터

public:
	pokemon();
	~pokemon();

	HRESULT init(string name, int level);

	bool addSkill(skill* sk);

	void hitDamager(int damage);
	void expPlus(int exp);
	void levelUp();


	inline int getSpeed() { return _speed; }
	inline int getCurrentHP() { return _currentHP; }
	inline void setCurrentHP(int num)
	{
		_currentHP = num;
		if (_currentHP > _maxHP)
			_currentHP = _maxHP;
	}
	inline int getMaxHP() { return _maxHP; }
	inline int getCurrentEXP() { return _currentEXP; }
	inline int setCurrentEXP(int exp) { _currentEXP = exp; }
	inline int getMaxEXP() { return _maxEXP; }
	inline string getName() { return _pokemonName; }
	inline vector<skill*> getVSkill() { return _vSkills; }

	inline int getIHP() { return _individualHP; }
	inline int getIATK() { return _individualATK; }
	inline int getIDEF() { return _individualDEF; }
	inline int getISPECIAL() { return _individualSPECIAL; }
	inline int getISPEED() { return _individualSPEED; }

	inline int getAtk() { return _atk; }
	inline int getDef() { return _def; }
	inline int getSpecial() { return _special; }
	inline int getLevel() { return _level; }
	inline ELEMENT getElement() { return _element; }

	void setStatus(string name, int lv, int iH, int iA, int iD, int iSpec, int iS, int cH);
};

