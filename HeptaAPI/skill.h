#pragma once
#include "gameNode.h"

// ���ϸ��� ���� �� �ִ� �Ӽ���
enum ELEMENT
{
	ELEMENT_NORMAL,		// �븻
	ELEMENT_FIRE,		// ��
	ELEMENT_WATER,		// ��
	ELEMENT_ELECTRIC,	// ����
	ELEMENT_PLANT,		// Ǯ
	ELEMENT_ICE,		// ����
	ELEMENT_FIGHT,		// ����
	ELEMENT_POISON,		// ��
	ELEMENT_EARTH,		// ��
	ELEMENT_WING,		// ����
	ELEMENT_ESPER,		// ������
	ELEMENT_INSECT,		// ����
	ELEMENT_ROCK,		// ����
	ELEMENT_GHOST,		// ����
	ELEMENT_DRAGON,		// �巡��
	ELEMENT_DARK,		// ����
	ELEMENT_STEEL,		// ��ö
	ELEMENT_END
};

enum SKILL_TYPE
{
	SKILL_PHYSIC,
	SKILL_SPECIAL,
	SKILL_CHANGE,
	SKILL_TYPE_END
};

class skill
{
protected:
	string _skillName;
	ELEMENT _element;
	SKILL_TYPE _type;
	int _power;
	int _acc;
	int _maxPP;
	int _currentPP;

public:
	skill();
	~skill();

	virtual HRESULT init() = 0;

	inline ELEMENT getElement() { return _element; }
	inline int getCurrentPP() { return _currentPP; }
	inline void setCurrentPP(int pp) { _currentPP = pp; }
	inline int getMaxPP() { return _maxPP; }
	inline int getPower() { return _power; }
	inline int getAcc() { return _acc; }
	inline string getName() { return _skillName; }
	inline SKILL_TYPE getType() { return _type; }
};

