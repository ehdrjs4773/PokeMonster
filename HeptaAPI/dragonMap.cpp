#include "stdafx.h"
#include "dragonMap.h"

#include "player.h"
#include "battleScene.h"


dragonMap::dragonMap()
{
	_isWin = false;
}


dragonMap::~dragonMap()
{
}

HRESULT dragonMap::init()
{
	stageManager::init();
	_background = IMAGEMANAGER->addImage("드래곤맵", ".\\bmps\\map\\드래곤.bmp", 0, 0, WINSIZEX, WINSIZEY, false, true, MAGENTA);
	_gymLeader = IMAGEMANAGER->addImage("드래곤NPC", ".\\bmps\\map\\드래곤NPC.bmp", 25, 28, false, true, MAGENTA);
	_player->setCurrentStage(5); //현재 스테이지 정보 넘겨준다

	_x = WINSIZEX / 2;
	_y = 15;

	_gymLeaderRc = RectMake(_x, _y, _gymLeader->getWidth(), _gymLeader->getHeight());

	int level = 5 + 5 * _player->getBadgeCount();
	_vPokemon.clear();
	// 구구, 깨비참, 피존, 깨비드릴조, 피존투, 파오리
	pokemon* temp[6];
	skill* tempSkill;
	for (int i = 0; i < 6; ++i)
	{
		temp[i] = new pokemon;

		if (i == 0)
		{
			temp[i]->init("미뇽", level);
			tempSkill = new skill;
			tempSkill->init("드래곤크루");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("몸통박치기");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("용의분노");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("힘껏치기");
			temp[i]->addSkill(tempSkill);
		}
		else if (i == 1)
		{
			temp[i]->init("쏘드라", level);
			tempSkill = new skill;
			tempSkill->init("드래곤크루");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("몸통박치기");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("용의분노");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("힘껏치기");
			temp[i]->addSkill(tempSkill);
		}
		else if (i == 2)
		{
			temp[i]->init("시드라", level);
			tempSkill = new skill;
			tempSkill->init("드래곤크루");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("몸통박치기");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("용의분노");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("힘껏치기");
			temp[i]->addSkill(tempSkill);
		}
		else if (i == 3)
		{
			temp[i]->init("신뇽", level);
			tempSkill = new skill;
			tempSkill->init("드래곤크루");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("몸통박치기");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("용의분노");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("힘껏치기");
			temp[i]->addSkill(tempSkill);
		}
		else if (i == 4)
		{
			temp[i]->init("프테라", level);
			tempSkill = new skill;
			tempSkill->init("드래곤크루");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("몸통박치기");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("용의분노");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("힘껏치기");
			temp[i]->addSkill(tempSkill);
		}
		else if (i == 5)
		{
			temp[i]->init("망나뇽", level);
			tempSkill = new skill;
			tempSkill->init("드래곤크루");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("몸통박치기");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("용의분노");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("힘껏치기");
			temp[i]->addSkill(tempSkill);
		}
		_vPokemon.push_back(temp[i]);
	}

	vector<pokemon*>* realPokemonVector = new vector<pokemon*>;
	switch (_player->getBadgeCount())
	{
	case 0:
		realPokemonVector->push_back(_vPokemon[0]);
		break;

	case 1:
		realPokemonVector->push_back(_vPokemon[0]);
		realPokemonVector->push_back(_vPokemon[1]);
		break;

	case 2:
		realPokemonVector->push_back(_vPokemon[0]);
		realPokemonVector->push_back(_vPokemon[1]);
		realPokemonVector->push_back(_vPokemon[2]);
		break;

	case 3:
		realPokemonVector->push_back(_vPokemon[0]);
		realPokemonVector->push_back(_vPokemon[1]);
		realPokemonVector->push_back(_vPokemon[2]);
		realPokemonVector->push_back(_vPokemon[3]);
		break;

	case 4:
		realPokemonVector->push_back(_vPokemon[0]);
		realPokemonVector->push_back(_vPokemon[1]);
		realPokemonVector->push_back(_vPokemon[2]);
		realPokemonVector->push_back(_vPokemon[3]);
		realPokemonVector->push_back(_vPokemon[4]);
		break;

	default:
		realPokemonVector->push_back(_vPokemon[0]);
		realPokemonVector->push_back(_vPokemon[1]);
		realPokemonVector->push_back(_vPokemon[2]);
		realPokemonVector->push_back(_vPokemon[3]);
		realPokemonVector->push_back(_vPokemon[4]);
		realPokemonVector->push_back(_vPokemon[5]);
		break;
	}
	DATABASE->setVEnemyPokemon(realPokemonVector);
	

	return S_OK;
}

void dragonMap::release()
{

}

void dragonMap::update()
{
	stageManager::update();
	_gymLeaderRc = RectMake(_x, _y, _gymLeader->getWidth(), _gymLeader->getHeight());

	if (_player->getPlayerRc().top >= WINSIZEY)
	{
		SCENEMANAGER->changeScene("월드맵씬");
		SCENEMANAGER->init("월드맵씬");
	}
}

void dragonMap::render()
{
	
	IMAGEMANAGER->findImage("드래곤맵")->render(getMemDC());
	if (!_isWin)
	{
		IMAGEMANAGER->findImage("드래곤NPC")->render(getMemDC(), _x, _y);
	}
	stageManager::render();
}
void dragonMap::collision()
{
	RECT temp;
	if (IntersectRect(&temp, &_gymLeaderRc, &_player->getPlayerRc()) && _isWin == false)
	{
		int tempWidth = temp.right - temp.left;
		int tempHeight = temp.bottom - temp.top;

		// 가로충돌
		if (tempHeight > tempWidth)
		{
			//오른쪽 충돌
			if (temp.left == _player->getPlayerRc().left)
			{
				_player->setPlayerPt(PointMake(_gymLeaderRc.right + (_player->getPlayerRc().right - _player->getPlayerRc().left) / 2,
					(_player->getPlayerRc().bottom + _player->getPlayerRc().top) / 2));
			}
			//왼쪽충돌
			if (temp.right == _player->getPlayerRc().right)
			{
				_player->setPlayerPt(PointMake(_gymLeaderRc.left - (_player->getPlayerRc().right - _player->getPlayerRc().left) / 2,
					(_player->getPlayerRc().bottom + _player->getPlayerRc().top) / 2));
			}
		}
		else
		{
			//아래충돌
			if (temp.top == _player->getPlayerRc().top)
			{
				_player->setPlayerPt(PointMake((_player->getPlayerRc().right + _player->getPlayerRc().left) / 2,
					temp.bottom + (_player->getPlayerRc().bottom - _player->getPlayerRc().top) / 2));
			}
		}

		if (KEYMANAGER->isOnceKeyDown(PLAYER_SELECT_KEY))
		{
			// 여기랑
			SCENEMANAGER->changeScene("battleScene");
			battleScene* tempBattle = (battleScene*)SCENEMANAGER->findScene("battleScene");
			tempBattle->setEnemyType(ENEMY_TRAINNER);
			tempBattle->setDestScene("스테이지5");
			tempBattle->init(5);
		}
	}
}
