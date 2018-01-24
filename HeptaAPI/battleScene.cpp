#include "stdafx.h"
#include "battleScene.h"



battleScene::battleScene()
	: _UI(NULL)
{
}


battleScene::~battleScene()
{
}

HRESULT battleScene::init()
{
	if (DATABASE->getVPlayerPokemon()->size() == 0) return E_FAIL;

	_playerPokemon = DATABASE->getVPlayerPokemon();
	_enemyPokemon = DATABASE->getVEnemyPokemon();

	// �÷��̾ �� ó�� ������ ���ϸ� ����
	// �� ó������ ���ʷ� ���鼭 HP�� 0 �Ʒ��� �ƴ� ���ϸ��� ã��
	_playerCurrentPokemon = 0;
	while ((*_playerPokemon)[_playerCurrentPokemon]->getCurrentHP() <= 0)
	{
		_playerCurrentPokemon++;

		// �÷��̾� ���ϸ��� ���ʷ� 0���� 5���� ����
		// ���� �÷��̾� ���ϸ��� 6�̻��̶�� ��� ���ϸ��� �׾��ִٴ� �� �̹Ƿ� ������ ������
		if (_playerCurrentPokemon >= 6)
			return E_FAIL;

		// ���� �� ó�� �������� ���ϸ��� ���� ������� ũ�ų� ���ٸ� ���� ��� ���ϸ��� �׾��ִٴ� ���̹Ƿ� ����!!!!
		if (_playerCurrentPokemon >= _playerPokemon->size())
			return E_FAIL;
	}

	// ���� �ݵ�� �� ó�� ���ͺ��� ����(ü���� ������� �÷��̾ �̱��� ���� ä�� ������ ������ ��� ���ϸ� ü���� �ʱ�ȭ�ǹǷ�)
	_enemyCurrentPokemon = 0;

	// ���� ��ø�� �÷��̾� ���� ���ϸ��� �� ũ�� �÷��̾���� ����
	if ((*_playerPokemon)[_playerCurrentPokemon]->getAgi() >= (*_enemyPokemon)[_enemyCurrentPokemon]->getAgi())
		_isPlayerTurn = true;
	else
		_isPlayerTurn = false;

	_sequence = BATTLE_INTRO;

	// UI �ʱ�ȭ
	if (_UI == NULL)
		_UI = new battleSceneUI;
	_UI->init();

	// �׽�Ʈ��
	IMAGEMANAGER->addFrameImage("pikachu_back", ".\\bmps\\battleScene\\pikachu_back.bmp", POKEMON_WIDTH * 2, POKEMON_HEIGHT, 2, 1, false, true, MAGENTA);
	IMAGEMANAGER->addFrameImage("pikachu_front", ".\\bmps\\battleScene\\pikachu_front.bmp", POKEMON_WIDTH * 2, POKEMON_HEIGHT, 2, 1, false, true, MAGENTA);
	_playerImageRect = RectMakeCenter(LIMIT_X_LEFT - POKEMON_WIDTH / 2, LIMIT_Y_BOTTOM - POKEMON_HEIGHT / 2, POKEMON_WIDTH, POKEMON_HEIGHT);
	_enemyImageRect = RectMakeCenter(LIMIT_X_RIGHT + POKEMON_WIDTH / 2, LIMIT_Y_TOP + POKEMON_HEIGHT / 2, POKEMON_WIDTH, POKEMON_HEIGHT);

	return S_OK;
}

void battleScene::release()
{

}

void battleScene::update()
{
	switch (_sequence)
	{
		case BATTLE_INTRO:
			if (_playerImageRect.left < LIMIT_X_LEFT)
			{
				_playerImageRect.left++;
				_playerImageRect.right++;
			}
			if (_enemyImageRect.right > LIMIT_X_RIGHT)
			{
				_enemyImageRect.left--;
				_enemyImageRect.right--;
			}
			else
			{
				_sequence = BATTLE_FIGHT;
				DIALOGUE->setPoint(PointMake(WINSIZEX / 2, WINSIZEY / 2));
			}
		break;

		case BATTLE_FIGHT:
			DIALOGUE->update();
		break;
	}
	_UI->update();
}

void battleScene::render()
{
	// �׽�Ʈ��
	//Rectangle(getMemDC(), _playerImageRect.left, _playerImageRect.top, _playerImageRect.right, _playerImageRect.bottom);
	//Rectangle(getMemDC(), _enemyImageRect.left, _enemyImageRect.top, _enemyImageRect.right, _enemyImageRect.bottom);
	IMAGEMANAGER->findImage("pikachu_back")->frameRender(getMemDC(), _playerImageRect.left, _playerImageRect.top);
	IMAGEMANAGER->findImage("pikachu_front")->frameRender(getMemDC(), _enemyImageRect.left, _enemyImageRect.top);
	_UI->render();

	if (_sequence == BATTLE_FIGHT)
		DIALOGUE->render(getMemDC());
}

// ��Ʋ�� �� �������� ��� �ؾ��ϳ� �������ִ� �Լ�
DAMAGE_JUDGEMENT battleScene::judgement(ELEMENT attackerSkill, ELEMENT defencer)
{
	// ����Ŀ�� �� ��ų�� �Ӽ��� ����ϴ� ���ϸ��� �Ӽ��� ���� �ٸ� ���� ����
	// ����
	// ������ �� ��
	// ������ ����
	// ������ ����
	// �����ڷ� : ���ϰ� �÷��� �Ӽ� ǥ
	switch (attackerSkill)
	{
		case ELEMENT_NORMAL:
			if (defencer == ELEMENT_ROCK ||
				defencer == ELEMENT_STEEL)
				return DAMAGE_HALF;

			else if (defencer == ELEMENT_GHOST)
				return DAMAGE_NONE;
		break;
		
		case ELEMENT_FIRE:
			if (defencer == ELEMENT_PLANT ||
				defencer == ELEMENT_ICE ||
				defencer == ELEMENT_INSECT ||
				defencer == ELEMENT_STEEL)
				return DAMAGE_DOUBLE;

			 else if (defencer == ELEMENT_FIRE ||
				defencer == ELEMENT_WATER ||
				defencer == ELEMENT_ROCK ||
				defencer == ELEMENT_DRAGON)
				return DAMAGE_HALF;
		break;
		
		case ELEMENT_WATER:
			if (defencer == ELEMENT_FIRE ||
				defencer == ELEMENT_EARTH ||
				defencer == ELEMENT_ROCK)
				return DAMAGE_DOUBLE;

			else if (defencer == ELEMENT_WATER ||
				defencer == ELEMENT_PLANT ||
				defencer == ELEMENT_DRAGON)
				return DAMAGE_HALF;
		break;
		
		case ELEMENT_ELECTRIC:
			if (defencer == ELEMENT_WATER ||
				defencer == ELEMENT_WING)
				return DAMAGE_DOUBLE;

			else if (defencer == ELEMENT_ELECTRIC ||
				defencer == ELEMENT_PLANT ||
				defencer == ELEMENT_DRAGON)
				return DAMAGE_HALF;

			else if (defencer == ELEMENT_EARTH)
				return DAMAGE_NONE;
		break;
		
		case ELEMENT_PLANT:
			if (defencer == ELEMENT_WATER ||
				defencer == ELEMENT_EARTH ||
				defencer == ELEMENT_ROCK)
				return DAMAGE_DOUBLE;

			else if (defencer == ELEMENT_FIRE ||
				defencer == ELEMENT_PLANT ||
				defencer == ELEMENT_POISON ||
				defencer == ELEMENT_WING ||
				defencer == ELEMENT_INSECT ||
				defencer == ELEMENT_DRAGON ||
				defencer == ELEMENT_STEEL)
				return DAMAGE_HALF;
		break;
		
		case ELEMENT_ICE:
			if (defencer == ELEMENT_PLANT ||
				defencer == ELEMENT_EARTH ||
				defencer == ELEMENT_WING ||
				defencer == ELEMENT_DRAGON)
				return DAMAGE_DOUBLE;

			else if (defencer == ELEMENT_FIRE ||
				defencer == ELEMENT_WATER ||
				defencer == ELEMENT_ICE ||
				defencer == ELEMENT_STEEL)
				return DAMAGE_HALF;
		break;
		
		case ELEMENT_FIGHT:
			if (defencer == ELEMENT_NORMAL ||
				defencer == ELEMENT_ICE ||
				defencer == ELEMENT_ROCK ||
				defencer == ELEMENT_DARK ||
				defencer == ELEMENT_STEEL)
				return DAMAGE_DOUBLE;

			else if (defencer == ELEMENT_POISON ||
				defencer == ELEMENT_WING ||
				defencer == ELEMENT_ESPER ||
				defencer == ELEMENT_INSECT)
				return DAMAGE_HALF;

			else if (defencer == ELEMENT_GHOST)
				return DAMAGE_NONE;
		break;
		
		case ELEMENT_POISON:
			if (defencer == ELEMENT_PLANT)
				return DAMAGE_DOUBLE;

			else if (defencer == ELEMENT_POISON ||
				defencer == ELEMENT_EARTH ||
				defencer == ELEMENT_ROCK ||
				defencer == ELEMENT_GHOST)
				return DAMAGE_HALF;

			else if (defencer == ELEMENT_STEEL)
				return DAMAGE_NONE;
		break;
		
		case ELEMENT_EARTH:
			if (defencer == ELEMENT_FIRE ||
				defencer == ELEMENT_ELECTRIC ||
				defencer == ELEMENT_POISON ||
				defencer == ELEMENT_ROCK ||
				defencer == ELEMENT_STEEL)
				return DAMAGE_DOUBLE;

			else if (defencer == ELEMENT_PLANT ||
				defencer == ELEMENT_INSECT)
				return DAMAGE_HALF;

			else if (defencer == ELEMENT_WING)
				return DAMAGE_NONE;
		break;
		
		case ELEMENT_WING:
			if (defencer == ELEMENT_PLANT ||
				defencer == ELEMENT_FIGHT ||
				defencer == ELEMENT_INSECT)
				return DAMAGE_DOUBLE;

			else if (defencer == ELEMENT_ELECTRIC ||
				defencer == ELEMENT_ROCK ||
				defencer == ELEMENT_STEEL)
				return DAMAGE_HALF;
		break;
		
		case ELEMENT_ESPER:
			if (defencer == ELEMENT_FIGHT ||
				defencer == ELEMENT_POISON)
				return DAMAGE_DOUBLE;

			else if (defencer == ELEMENT_ESPER ||
				defencer == ELEMENT_STEEL)
				return DAMAGE_HALF;

			else if (defencer == ELEMENT_DARK)
				return DAMAGE_NONE;
		break;
		
		case ELEMENT_INSECT:
			if (defencer == ELEMENT_PLANT ||
				defencer == ELEMENT_ESPER ||
				defencer == ELEMENT_DARK)
				return DAMAGE_DOUBLE;

			else if (defencer == ELEMENT_FIRE ||
				defencer == ELEMENT_FIGHT ||
				defencer == ELEMENT_POISON ||
				defencer == ELEMENT_WING ||
				defencer == ELEMENT_GHOST ||
				defencer == ELEMENT_STEEL)
				return DAMAGE_HALF;
		break;
		
		case ELEMENT_ROCK:
			if (defencer == ELEMENT_FIRE ||
				defencer == ELEMENT_ICE ||
				defencer == ELEMENT_WING ||
				defencer == ELEMENT_INSECT)
				return DAMAGE_DOUBLE;

			else if (defencer == ELEMENT_FIGHT ||
				defencer == ELEMENT_EARTH ||
				defencer == ELEMENT_STEEL)
				return DAMAGE_HALF;
		break;
		
		case ELEMENT_GHOST:
			if (defencer == ELEMENT_ESPER ||
				defencer == ELEMENT_GHOST)
				return DAMAGE_DOUBLE;

			else if (defencer == ELEMENT_DARK ||
				defencer == ELEMENT_STEEL)
				return DAMAGE_HALF;

			else if (defencer == ELEMENT_NORMAL)
				return DAMAGE_NONE;
		break;
		
		case ELEMENT_DRAGON:
			if (defencer == ELEMENT_DRAGON)
				return DAMAGE_DOUBLE;

			else if (defencer == ELEMENT_STEEL)
				return DAMAGE_HALF;
		break;
		
		case ELEMENT_DARK:
			if (defencer == ELEMENT_ESPER ||
				defencer == ELEMENT_GHOST)
				return DAMAGE_DOUBLE;

			else if (defencer == ELEMENT_FIGHT ||
				defencer == ELEMENT_DARK ||
				defencer == ELEMENT_STEEL)
				return DAMAGE_HALF;
		break;
		
		case ELEMENT_STEEL:
			if (defencer == ELEMENT_ICE ||
				defencer == ELEMENT_ROCK)
				return DAMAGE_DOUBLE;

			else if (defencer == ELEMENT_FIRE ||
				defencer == ELEMENT_WATER ||
				defencer == ELEMENT_ELECTRIC ||
				defencer == ELEMENT_STEEL)
				return DAMAGE_HALF;
		break;
	}

	// �� ����ġ���� ��� Ư���� ���(������ ����, ������ ����, ������ �� ��)�� ó��
	// �������� ���� �Ϲ� ������
	return DAMAGE_NORMAL;
}