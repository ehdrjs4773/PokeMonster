#include "stdafx.h"
#include "bugMap.h"
#include "player.h"
#include "battleScene.h"


bugMap::bugMap()
{
	_isWin = false;
}


bugMap::~bugMap()
{
}

HRESULT bugMap::init()
{
	stageManager::init();
	_background = IMAGEMANAGER->addImage("벌레맵", ".\\bmps\\map\\벌레.bmp", 0, 0, WINSIZEX, WINSIZEY, false, true, MAGENTA);
	_gymLeader = IMAGEMANAGER->addImage("벌레NPC", ".\\bmps\\map\\벌레NPC.bmp", 25, 28, false, true, MAGENTA);
	_player->setCurrentStage(6); //현재 스테이지 정보 넘겨준다

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
			temp[i]->init("뿔충이", level);
			tempSkill = new skill;
			tempSkill->init("시그널빔");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("실뿜기");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("스피드스타");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("뿔드릴");
			temp[i]->addSkill(tempSkill);
		}
		else if (i == 1)
		{
			temp[i]->init("단데기", level);
			tempSkill = new skill;
			tempSkill->init("시그널빔");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("실뿜기");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("스피드스타");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("흡수");
			temp[i]->addSkill(tempSkill);
		}
		else if (i == 2)
		{
			temp[i]->init("도나리", level);
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
			tempSkill->init("흡수");
			temp[i]->addSkill(tempSkill);
		}
		else if (i == 3)
		{
			temp[i]->init("독침붕", level);
			tempSkill = new skill;
			tempSkill->init("시그널빔");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("실뿜기");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("스피드스타");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("마구찌르기");
			temp[i]->addSkill(tempSkill);
		}
		else if (i == 4)
		{
			temp[i]->init("버터플", level);
			tempSkill = new skill;
			tempSkill->init("시그널빔");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("실뿜기");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("스피드스타");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("꽃잎댄스");
			temp[i]->addSkill(tempSkill);
		}
		else if (i == 5)
		{
			temp[i]->init("스라크", level);
			tempSkill = new skill;
			tempSkill->init("시그널빔");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("실뿜기");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("스피드스타");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("마구찌르기");
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

void bugMap::release()
{

}

void bugMap::update()
{
	stageManager::update();
	collision();
	_gymLeaderRc = RectMake(_x, _y, _gymLeader->getWidth(), _gymLeader->getHeight());

	if (_player->getPlayerRc().top >= WINSIZEY)
	{
		SCENEMANAGER->changeScene("월드맵씬");
		SCENEMANAGER->init("월드맵씬");
	}
}

void bugMap::render()
{
	
	IMAGEMANAGER->findImage("벌레맵")->render(getMemDC());
	if (!_isWin)
	{
		IMAGEMANAGER->findImage("벌레NPC")->render(getMemDC(), _x, _y);
	}
	stageManager::render();
}

void bugMap::collision()
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
			tempBattle->setDestScene("스테이지6");
			tempBattle->init(6);
		}
	}
}
