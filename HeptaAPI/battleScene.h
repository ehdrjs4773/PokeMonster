#pragma once
#include "gameNode.h"
#include "pokemon.h"
#include "battleSceneUI.h"

#define LIMIT_X_LEFT		80
#define LIMIT_X_RIGHT		400
#define LIMIT_Y_BOTTOM		266
#define LIMIT_Y_TOP			36

#define POKEMON_WIDTH		120
#define POKEMON_HEIGHT		120

// 데미지 판정에 사용할 이넘문	
enum DAMAGE_JUDGEMENT
{
	DAMAGE_NONE,		// 효과 없음(데미지 0)
	DAMAGE_HALF,		// 효과 부족(데미지 절반)
	DAMAGE_NORMAL,		// 보통	   (데미지 그대로)
	DAMAGE_DOUBLE,		// 효과 좋음(데미지 두 배)
	DAMAGE_END
};

enum BATTLE_SEQUENCE
{
	BATTLE_INTRO,	// 플레이어가 나와서 몬스터볼 던지는 시퀀스
	BATTLE_FIGHT,	// 몬스터끼리 싸우는 시퀀스
	BATTLE_FINAL,	// 적 몬스터 죽고 적이 몬스터 고르는 시퀀스
	BATTLE_END		// 모든 적을 죽인 시퀀스
};

class battleScene : public gameNode
{
private:
	vector<pokemon*>* _playerPokemon;
	vector<pokemon*>* _enemyPokemon;

	BATTLE_SEQUENCE _sequence;

	RECT _playerImageRect;
	RECT _enemyImageRect;

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

