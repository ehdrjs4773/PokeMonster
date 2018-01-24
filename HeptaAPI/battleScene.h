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
	BATTLE_INTRO,	// �÷��̾ ���ͼ� ���ͺ� ������ ������
	BATTLE_FIGHT,	// ���ͳ��� �ο�� ������
	BATTLE_FINAL,	// �� ���� �װ� ���� ���� ���� ������
	BATTLE_END		// ��� ���� ���� ������
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

	// ��Ʋ�� �� �������� ��� �ؾ��ϳ� �������ִ� �Լ�
	DAMAGE_JUDGEMENT judgement(ELEMENT attackerSkill, ELEMENT defencer);
};

