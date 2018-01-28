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

// �� Ÿ�� (�߻�, Ʈ���̳�)
enum ENEMY_TYPE
{
	ENEMY_WILD,
	ENEMY_TRAINNER,
	ENEMY_TYPE_END
};

// ������ ������ ����� �̳ѹ�	
enum DAMAGE_JUDGEMENT
{
	DAMAGE_NONE,		// ȿ�� ����(������ 0)
	DAMAGE_HALF,		// ȿ�� ����(������ ����)
	DAMAGE_NORMAL,		// ����	   (������ �״��)
	DAMAGE_DOUBLE,		// ȿ�� ����(������ �� ��)
	DAMAGE_END
};

enum BATTLE_SEQUENCE
{
	BATTLE_INTRO,		// �÷��̾�, �� ����
	BATTLE_BALLTHROW,	// ���ͺ� ������ ������
	BATTLE_SELECT,		// ����� ��ų ���� ������
	BATTLE_FIGHT,		// ���ͳ��� �ο�� ������
	BATTLE_END,			// ���� �� �� �� ������ ���� ������
	BATTLE_FINAL		// ��� ���� ���� ������
};

enum FIGHT_SEQUENCE
{
	PLAYER_ATTACK,
	PLAYER_CHANGE,
	ENEMY_ATTACK,
	ENEMY_CHANGE,
	FIGHT_END
};

enum END_SEQUENCE
{
	ENEMY_DIE,
	PLAYER_DIE,
	END_CHANGE,
	END_END
};

// ��Ʋ �� ������ ����
// ��Ʈ��(��, �÷��̾� ���� ������, ���ʿ��� ����)
// �� ���ο�(���� Ʈ���̳��� ���� �߻��� ��� �ٸ���, �÷��̾�� �� ������ ���� Ÿ�Կ����� �����ų� ���ų�)
// ����Ʈ(���⼭ ��ų ����, ����, ���ϸ� ��ü, ����ġ�� ����)
// ����Ʈ(���� ������ ���� ���� ���������� ������ ���� ����)
// �ص�(��, �÷��̾� ���� �� �� ������ ���� ������
// ���̳�(��, �÷��̾� �� �� ���̶� ��� ���Ͱ� ���� ������)

class battleScene : public gameNode
{
private:
	vector<pokemon*>* _playerPokemon;
	vector<pokemon*>* _enemyPokemon;

	BATTLE_SEQUENCE _sequence;
	FIGHT_SEQUENCE _fight;
	END_SEQUENCE _end;

	RECT _playerImageRect;
	RECT _enemyImageRect;

	int _playerCurrentPokemon;
	int _enemyCurrentPokemon;

	battleSceneUI* _UI;

	ENEMY_TYPE _enemyType;

	int _introTime;
	int _frameTime;
	int _frameX;

	bool _isGetEXP;

	// ü���� �� ���, ü���� �� ���ϸ� ��ȣ
	int _playerChangePokemonNum;
	int _enemyChangePokemonNum;

	// ���α׷�����
	progressBar* _enemyHPBar;
	progressBar* _playerHPBar;
	progressBar* _playerEXPBar;

	// ���� �� �׾�����, �÷��̾ �� �׾�����
	bool _enemyIsDie;
	bool _playerIsDie;

public:
	battleScene();
	~battleScene();

	HRESULT init();
	void release();
	void update();
	void render();

	void frameUpdate();
	string elementString(ELEMENT el);

	// ��Ʋ�� �� �������� ��� �ؾ��ϳ� �������ִ� �Լ�
	DAMAGE_JUDGEMENT judgement(ELEMENT attackerSkill, ELEMENT defencer);
	int calcDamage(pokemon* p, skill* s, pokemon* d);

	inline BATTLE_SEQUENCE getSequence() { return _sequence; }
	inline void setSequence(BATTLE_SEQUENCE se) { _sequence = se; }
	inline pokemon* getCurrentPlayerPokemon() { return (*_playerPokemon)[_playerCurrentPokemon]; }
	inline int getCurrentPlayerNum() { return _playerCurrentPokemon; }
	inline pokemon* getCurrentEnemyPokemon() { return (*_enemyPokemon)[_enemyCurrentPokemon]; }

	inline void setPlayerChangeNum(int num) { _playerChangePokemonNum = num; }
	inline void setEnemyChangeNum(int num) { _enemyChangePokemonNum = num; }

	inline void setEnemyType(ENEMY_TYPE type) { _enemyType = type; }
};

