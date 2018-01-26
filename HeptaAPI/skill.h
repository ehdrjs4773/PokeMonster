#pragma once
#include "gameNode.h"

// 포켓몬이 가질 수 있는 속성들
enum ELEMENT
{
	ELEMENT_NORMAL,		// 노말
	ELEMENT_FIRE,		// 불
	ELEMENT_WATER,		// 물
	ELEMENT_ELECTRIC,	// 전기
	ELEMENT_PLANT,		// 풀
	ELEMENT_ICE,		// 얼음
	ELEMENT_FIGHT,		// 격투
	ELEMENT_POISON,		// 독
	ELEMENT_EARTH,		// 땅
	ELEMENT_WING,		// 비행
	ELEMENT_ESPER,		// 에스퍼
	ELEMENT_INSECT,		// 곤충
	ELEMENT_ROCK,		// 바위
	ELEMENT_GHOST,		// 유령
	ELEMENT_DRAGON,		// 드래곤
	ELEMENT_DARK,		// 암흑
	ELEMENT_STEEL,		// 강철
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

