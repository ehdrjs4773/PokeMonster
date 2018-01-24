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

class skill
{
private:
	string _skillName;
	ELEMENT _element;
	int _damage;
	int _maxPP;
	int _currentPP;

public:
	skill();
	~skill();

	inline ELEMENT getElement() { return _element; }
	inline int getDamage() { return _damage; }
};

