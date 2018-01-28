#pragma once
#include "gameNode.h"
#include "progressBar.h"

// 전방선언
class battleScene;
class MonsterBack;
enum ELEMENT;

class battleSceneUI : public gameNode
{
private:
	battleScene* _battleScene;

	RECT _selectSequenceRect[2][2];
	RECT _skillPrintRect[4];
	POINT _selectArrowPoint;
	int _skillSelectNum;
	int _enemySkillNum;

	// BATTLE_SELECT 시퀀스에 사용될 변수들
	bool _isFightSelect;
	bool _isBagSelect;
	bool _isPokemonSelect;
	bool _isRunAwaySelect;

	// 몬스터 백
	MonsterBack* _msb;

public:
	battleSceneUI();
	~battleSceneUI();

	HRESULT init();
	void release();
	void update();
	void render();

	void keyControl();
	void selectReset();

	void printElement(ELEMENT el);
	void printPP(int current, int max);
	void printHP(int current, int max);
	void printLevel(int current, int destX, int destY);

	inline void setMemoryAddressLink(battleScene* battle) { _battleScene = battle; }

	inline int getCurrentPlayerSkill() { return _skillSelectNum; }
	inline int getCurrentEnemySkill() { return _enemySkillNum; }
	inline battleScene* getBattleScene() { return _battleScene; }
};

