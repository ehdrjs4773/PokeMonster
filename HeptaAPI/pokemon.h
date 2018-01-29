#pragma once
#include "gameNode.h"
#include "skill.h"
#include <vector>
#include <math.h>

#define LEVEL_MAX	100		// �ִ� ����

class pokemon : public gameNode
{
protected:
	ELEMENT _element;	// ���ϸ��� �Ӽ�
	string _pokemonName;	// ���ϸ� �̸�(����)

	// ��... ���� �����̾�...
	// 1���� ����
	// �ϴ� ������
	USHORT _racialHP;
	USHORT _racialATK;
	USHORT _racialDEF;
	USHORT _racialSPECIAL;
	USHORT _racialSPEED;

	// ������ ��ü���ε�... �̰� �����̷�...
	USHORT _individualATK;			// 0~15�� 16���� ���ڰ� �������� �ο�
	USHORT _individualDEF;			// 
	USHORT _individualSPECIAL;		// 
	USHORT _individualSPEED;		// 
	USHORT _individualHP;			// ������ Ȧ���� +8, �� Ȧ���� +4, Ư���� Ȧ���� +2, ���ǵ尡 Ȧ���� +1
								// ���� ��� Ȧ���� 15, ��� ¦���� 0

	// ���������� ���ġ
	// ����(���� ó������ ����, �� ��ȭ ���)���� 0
	// �� ������ ���� ���ġ��
	USHORT _evsHP;
	USHORT _evsATK;
	USHORT _evsDEF;
	USHORT _evsSPECIAL;
	USHORT _evsSPEED;

	// ���� ���ġ��
	USHORT _evsExpHP;
	USHORT _evsExpATK;
	USHORT _evsExpDEF;
	USHORT _evsExpSPECIAL;
	USHORT _evsExpSPEED;

	// �׿� ���� ���ġ ����
	USHORT _evsLvHP;
	USHORT _evsLvATK;
	USHORT _evsLvDEF;
	USHORT _evsLvSPECIAL;
	USHORT _evsLvSPEED;

	USHORT _level;			// ����

	// ���� ���� ������ ���� �ɷ�ġ
	USHORT _maxHP;
	USHORT _currentHP;
	USHORT _atk;
	USHORT _def;
	USHORT _special;
	USHORT _speed;

	// ����ġ�� ������ ��� ���ϸ� �߰��������� ä��
	// ���� N�� �Ǳ� ���� �� �ʿ� ����ġ�� N^3
	// ���� ���� �������� ���� �������� �ʿ��� ����ġ��
	// (���緹�� + 1)^3 - ���緹��^3
	USHORT _maxEXP;
	USHORT _currentEXP;

	// ���� ������ ��� ����ġ
	USHORT _exp;

	vector<skill*>				_vSkills;		// ��ų ����
	vector<skill*>::iterator	_vSkillsIter;	// ��ų ���� ���ͷ�����

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

