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
	// 적 타입 가져오기 (나중에 DATABASE 이용해서 가져올 생각)
	_enemyType = ENEMY_WILD;

	// 내부저장소(메모리)에서 포켓몬 가져오기
	if (DATABASE->getVPlayerPokemon()->size() == 0) return E_FAIL;

	_playerPokemon = DATABASE->getVPlayerPokemon();
	_enemyPokemon = DATABASE->getVEnemyPokemon();

	// 플레이어가 맨 처음 내보낼 포켓몬 선택
	// 맨 처음부터 차례로 돌면서 HP가 0 아래가 아닌 포켓몬을 찾음
	_playerCurrentPokemon = 0;
	while ((*_playerPokemon)[_playerCurrentPokemon]->getCurrentHP() <= 0)
	{
		_playerCurrentPokemon++;

		// 플레이어 포켓몬은 차례로 0부터 5까지 가능
		// 현재 플레이어 포켓몬이 6이상이라면 모든 포켓몬이 죽어있다는 것 이므로 오류를 내뱉음
		if (_playerCurrentPokemon >= 6)
			return E_FAIL;

		// 또한 맨 처음 나가야할 포켓몬이 벡터 사이즈보다 크거나 같다면 역시 모든 포켓몬이 죽어있다는 뜻이므로 오류!!!!
		if (_playerCurrentPokemon >= _playerPokemon->size())
			return E_FAIL;
	}

	// 적은 반드시 맨 처음 몬스터부터 꺼냄(체육관 관장들은 플레이어가 이기지 못한 채로 전투가 끝나면 모든 포켓몬 체력이 초기화되므로)
	_enemyCurrentPokemon = 0;

	// 만약 민첩이 플레이어 현재 포켓몬이 더 크면 플레이어부터 선공
	if ((*_playerPokemon)[_playerCurrentPokemon]->getAgi() >= (*_enemyPokemon)[_enemyCurrentPokemon]->getAgi())
		_isPlayerTurn = true;
	else
		_isPlayerTurn = false;

	_sequence = BATTLE_INTRO;

	// UI 초기화
	if (_UI == NULL)
		_UI = new battleSceneUI;
	_UI->init();

	// 사용할 이미지 등록
	IMAGEMANAGER->addFrameImage("battle_player", ".\\bmps\\battleScene\\battle_player.bmp", POKEMON_WIDTH * 8, POKEMON_HEIGHT, 8, 1, false, true, MAGENTA);
	IMAGEMANAGER->addFrameImage("battle_player_ball", ".\\bmps\\battleScene\\battle_player_ball.bmp", POKEMON_WIDTH * 8, POKEMON_HEIGHT, 8, 1, false, true, MAGENTA);

	// 테스트용
	IMAGEMANAGER->addFrameImage("pikachu_back", ".\\bmps\\battleScene\\pikachu_back.bmp", POKEMON_WIDTH * 2, POKEMON_HEIGHT, 2, 1, false, true, MAGENTA);
	IMAGEMANAGER->addFrameImage("pikachu_front", ".\\bmps\\battleScene\\pikachu_front.bmp", POKEMON_WIDTH * 2, POKEMON_HEIGHT, 2, 1, false, true, MAGENTA);
	_playerImageRect = RectMakeCenter(LIMIT_X_LEFT - POKEMON_WIDTH / 2, LIMIT_Y_BOTTOM - POKEMON_HEIGHT / 2, POKEMON_WIDTH, POKEMON_HEIGHT);
	_enemyImageRect = RectMakeCenter(LIMIT_X_RIGHT + POKEMON_WIDTH / 2, LIMIT_Y_TOP + POKEMON_HEIGHT / 2, POKEMON_WIDTH, POKEMON_HEIGHT);

	_currentPlayerKey = "battle_player";
	_currentEnemyKey = "pikachu_front";

	_frameTime = 0;
	_frameX = 0;

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
				_sequence = BATTLE_BALLTHROW;

		break;
		
		case BATTLE_BALLTHROW:
			if (_playerImageRect.right > LIMIT_X_LEFT)
			{
				_playerImageRect.left--;
				_playerImageRect.right--;
			}
			if (_enemyType == ENEMY_TRAINNER)
			{
				if (_enemyImageRect.left < LIMIT_X_RIGHT)
				{
					_enemyImageRect.left++;
					_enemyImageRect.right++;
				}
			}

			this->frameUpdate();
		break;

		case BATTLE_FIGHT:
		break;
	}
	_UI->update();
}

void battleScene::render()
{
	// 테스트용
	//Rectangle(getMemDC(), _playerImageRect.left, _playerImageRect.top, _playerImageRect.right, _playerImageRect.bottom);
	//Rectangle(getMemDC(), _enemyImageRect.left, _enemyImageRect.top, _enemyImageRect.right, _enemyImageRect.bottom);
	if (_sequence == BATTLE_BALLTHROW)
		IMAGEMANAGER->findImage("battle_player_ball")->frameRender(getMemDC(), LIMIT_X_LEFT, LIMIT_Y_BOTTOM - POKEMON_HEIGHT, _frameX, 0);

	IMAGEMANAGER->findImage(_currentPlayerKey)->frameRender(getMemDC(), _playerImageRect.left, _playerImageRect.top, _frameX, 0);
	IMAGEMANAGER->findImage(_currentEnemyKey)->frameRender(getMemDC(), _enemyImageRect.left, _enemyImageRect.top);
	_UI->render();

	if (_sequence == BATTLE_FIGHT)
		DIALOGUE->render(getMemDC());
}

void battleScene::frameUpdate()
{
	_frameTime++;
	switch (_sequence)
	{
		case BATTLE_BALLTHROW:
			if (_frameTime % 12 == 0)
			{
				_frameX++;
				if (_frameX > IMAGEMANAGER->findImage(_currentPlayerKey)->getMaxFrameX())
				{
					_frameX = 0;
					_frameTime = 0;

					_sequence = BATTLE_FIGHT;
					_currentPlayerKey = "pikachu_back";

					_playerImageRect.left = LIMIT_X_LEFT;
					_playerImageRect.right = _playerImageRect.left + POKEMON_WIDTH;


					if (_enemyType == ENEMY_TRAINNER)
					{
						_enemyImageRect.right = LIMIT_X_RIGHT;
						_enemyImageRect.left = _enemyImageRect.right - POKEMON_WIDTH;
					}
				}
			}
		break;
	}
}

// 배틀할 때 데미지를 어떻게 해야하나 판정해주는 함수
DAMAGE_JUDGEMENT battleScene::judgement(ELEMENT attackerSkill, ELEMENT defencer)
{
	// 어태커가 쓴 스킬의 속성과 방어하는 포켓몬의 속성에 따라 다른 값을 리턴
	// 순서
	// 데미지 두 배
	// 데미지 절반
	// 데미지 없음
	// 참고자료 : 건하가 올려준 속성 표
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

	// 위 스위치문의 경우 특수한 경우(데미지 없음, 데미지 절반, 데미지 두 배)만 처리
	// 나머지는 전부 일반 데미지
	return DAMAGE_NORMAL;
}