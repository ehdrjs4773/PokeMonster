#pragma once
#include "gameNode.h"
#include "includePokemon.h"
#include "battleSceneUI.h"

#define LIMIT_X_LEFT		80
#define LIMIT_X_RIGHT		400
#define LIMIT_Y_BOTTOM		266
#define LIMIT_Y_TOP			36

#define POKEMON_WIDTH		120
#define POKEMON_HEIGHT		120

// 적 타입 (야생, 트레이너)
enum ENEMY_TYPE
{
	ENEMY_WILD,
	ENEMY_TRAINNER,
	ENEMY_TYPE_END
};

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
	BATTLE_INTRO,		// 플레이어, 적 등장
	BATTLE_BALLTHROW,	// 몬스터볼 던지는 시퀀스
	BATTLE_SELECT,		// 사용할 스킬 선택 시퀀스
	BATTLE_FIGHT,		// 몬스터끼리 싸우는 시퀀스
	BATTLE_END,			// 몬스터 둘 중 한 마리라도 죽은 시퀀스
	BATTLE_FINAL		// 모든 적을 죽인 시퀀스
};

// 배틀 씬 시퀀스 진행
// 인트로(적, 플레이어 각각 오른쪽, 왼쪽에서 등장)
// 볼 스로우(적이 트레이너일 경우와 야생의 경우 다른데, 플레이어는 볼 던지고 적은 타입에따라 던지거나 말거나)
// 셀렉트(여기서 스킬 고르기, 가방, 포켓몬 교체, 도망치기 선택)
// 파이트(각각 선택한 씬과 누구 선공인지를 따져서 서로 공격)
// 앤드(적, 플레이어 몬스터 중 한 마리라도 죽은 시퀀스
// 파이널(적, 플레이어 중 한 쪽이라도 모든 몬스터가 죽은 시퀀스)

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

	string _currentPlayerKey;
	string _currentEnemyKey;

	ENEMY_TYPE _enemyType;

	int _introTime;
	int _frameTime;
	int _frameX;

public:
	battleScene();
	~battleScene();

	HRESULT init();
	void release();
	void update();
	void render();

	void frameUpdate();

	// 배틀할 때 데미지를 어떻게 해야하나 판정해주는 함수
	DAMAGE_JUDGEMENT judgement(ELEMENT attackerSkill, ELEMENT defencer);

	inline BATTLE_SEQUENCE getSequence() { return _sequence; }
	inline void setSequence(BATTLE_SEQUENCE se) { _sequence = se; }
	inline pokemon* getCurrentPlayerPokemon() { return (*_playerPokemon)[_playerCurrentPokemon]; }
};

