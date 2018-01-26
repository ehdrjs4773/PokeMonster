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

	// ��Ʋ�� �� �������� ��� �ؾ��ϳ� �������ִ� �Լ�
	DAMAGE_JUDGEMENT judgement(ELEMENT attackerSkill, ELEMENT defencer);

	inline BATTLE_SEQUENCE getSequence() { return _sequence; }
	inline void setSequence(BATTLE_SEQUENCE se) { _sequence = se; }
	inline pokemon* getCurrentPlayerPokemon() { return (*_playerPokemon)[_playerCurrentPokemon]; }
};

