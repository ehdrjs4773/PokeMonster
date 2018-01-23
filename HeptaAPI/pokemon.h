#pragma once
#include "gameNode.h"
#include "skill.h"
#include <vector>

#define LEVEL_MAX	100		// �ִ� ����

class pokemon : public gameNode
{
private:
	ELEMENT _element;	// ���ϸ��� �Ӽ�
	int _level;			// ����

	// ������ ������ �޴� �ɷ�ġ��
	// �⺻ �ɷ�ġ�� ������ ���� �������� ó��
	// ���� ������ �𸣰ڴ�
	int _atk;		// ���ݷ�
	int _def;		// ����
	int _agi;		// ��ø(���� ����)
	int _currentHP;	// ���� ü��
	int _maxHP;		// �ִ� ü��

	vector<skill*>				_vSkills;		// ��ų ����
	vector<skill*>::iterator	_vSkillsIter;	// ��ų ���� ���ͷ�����

public:
	pokemon();
	~pokemon();

	inline ELEMENT getElement() { return _element; }
	inline int getAgi() { return _agi; }
	inline int getCurrentHP() { return _currentHP; }
};

