#pragma once
#include "gameNode.h"
#include "pokemon.h"
#include "battleSceneUI.h"

// 데미지 판정에 사용할 이넘문	
enum DAMAGE_JUDGEMENT
{
	DAMAGE_NONE,		// 효과 없음(데미지 0)
	DAMAGE_HALF,		// 효과 부족(데미지 절반)
	DAMAGE_NORMAL,		// 보통	   (데미지 그대로)
	DAMAGE_DOUBLE,		// 효과 좋음(데미지 두 배)
	DAMAGE_END
};

class battleScene : public gameNode
{
private:
	vector<pokemon*>* _playerPokemon;
	vector<pokemon*>* _enemyPokemon;

	int _playerCurrentPokemon;
	int _enemyCurrentPokemon;

	bool _isPlayerTurn;

	battleSceneUI* _UI;

public:
	battleScene();
	~battleScene();

	HRESULT init();
	void release();
	void update();
	void render();

	// 배틀할 때 데미지를 어떻게 해야하나 판정해주는 함수
	DAMAGE_JUDGEMENT judgement(ELEMENT attackerSkill, ELEMENT defencer);
};

