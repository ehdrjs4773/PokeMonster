#pragma once
#include "gameNode.h"
#include "pokemon.h"
#include "battleSceneUI.h"

// ������ ������ ����� �̳ѹ�	
enum DAMAGE_JUDGEMENT
{
	DAMAGE_NONE,		// ȿ�� ����(������ 0)
	DAMAGE_HALF,		// ȿ�� ����(������ ����)
	DAMAGE_NORMAL,		// ����	   (������ �״��)
	DAMAGE_DOUBLE,		// ȿ�� ����(������ �� ��)
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

	// ��Ʋ�� �� �������� ��� �ؾ��ϳ� �������ִ� �Լ�
	DAMAGE_JUDGEMENT judgement(ELEMENT attackerSkill, ELEMENT defencer);
};

