#pragma once
#include "gameNode.h"
#include "skill.h"
#include <vector>

#define LEVEL_MAX	100		// 최대 레벨

class pokemon : public gameNode
{
private:
	ELEMENT _element;	// 포켓몬의 속성
	int _level;			// 레벨

	// 레벨에 영향을 받는 능력치들
	// 기본 능력치에 레벨을 넣은 공식으로 처리
	// 아직 공식은 모르겠다
	int _atk;		// 공격력
	int _def;		// 방어력
	int _agi;		// 민첩(선공 결정)
	int _currentHP;	// 현재 체력
	int _maxHP;		// 최대 체력

	vector<skill*>				_vSkills;		// 스킬 벡터
	vector<skill*>::iterator	_vSkillsIter;	// 스킬 벡터 이터레이터

public:
	pokemon();
	~pokemon();

	inline ELEMENT getElement() { return _element; }
	inline int getAgi() { return _agi; }
	inline int getCurrentHP() { return _currentHP; }
};

