#include "stdafx.h"
#include "fighterMap.h"
#include "player.h"
#include "battleScene.h"

fighterMap::fighterMap()

{
	_isWin = false;
}
fighterMap::~fighterMap()
{
}

HRESULT fighterMap::init()
{
	stageManager::init();
	_background = IMAGEMANAGER->addImage("격투맵", ".\\bmps\\map\\격투맵.bmp", WINSIZEX, WINSIZEY, false, true, MAGENTA);
	_gymLeader = IMAGEMANAGER->addImage("격투NPC", ".\\bmps\\map\\격투NPC.bmp", 25, 28, false, true, MAGENTA);

	_player->setCurrentStage(2);

	_x = WINSIZEX / 2 - 17;
	_y = 15;

	_gymLeaderRc = RectMake(_x, _y, _gymLeader->getWidth(), _gymLeader->getHeight());

	int level = 5 + 5 * _player->getBadgeCount();
	_vPokemon.clear();
	//알통몬 , 근육맨 , 수륙챙이 , 딱구리 , 강챙이 , 망키
	pokemon* temp[6];
	skill* tempSkill;
	for (int i = 0; i < 6; ++i)
	{
		temp[i] = new pokemon;

		if (i == 0)
		{
			temp[i]->init("알통몬", level);
			tempSkill = new skill;
			tempSkill->init("파동탄");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("안다리걸기");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("몸통박치기");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("돌진");
			temp[i]->addSkill(tempSkill);
		}
		else if (i == 1)
		{
			temp[i]->init("근육맨", level);
			tempSkill = new skill;
			tempSkill->init("파동탄");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("안다리걸기");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("몸통박치기");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("지옥의바퀴");
			temp[i]->addSkill(tempSkill);
		}
		else if (i == 2)
		{
			temp[i]->init("수륙챙이", level);
			tempSkill = new skill;
			tempSkill->init("파동탄");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("안다리걸기");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("몸통박치기");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("냉동펀치");
			temp[i]->addSkill(tempSkill);
		}
		else if (i == 3)
		{
			temp[i]->init("딱구리", level);
			tempSkill = new skill;
			tempSkill->init("파동탄");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("안다리걸기");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("몸통박치기");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("카운터");
			temp[i]->addSkill(tempSkill);
		}
		else if (i == 4)
		{
			temp[i]->init("강챙이", level);
			tempSkill = new skill;
			tempSkill->init("파동탄");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("안다리걸기");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("몸통박치기");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("로케트박치기");
			temp[i]->addSkill(tempSkill);
		}
		else if (i == 5)
		{
			temp[i]->init("망키", level);
			tempSkill = new skill;
			tempSkill->init("파동탄");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("안다리걸기");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("몸통박치기");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("막치기");
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
void fighterMap::release()
{

}
void fighterMap::update()
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
void fighterMap::render()
{
	IMAGEMANAGER->findImage("격투맵")->render(getMemDC());
	if (!_isWin)
	{
		IMAGEMANAGER->findImage("격투NPC")->render(getMemDC(), _x, _y);
	}
	stageManager::render();
	//IMAGEMANAGER->findImage("npc")->frameRender(getMemDC(), _x, _y, 4, 0);
}

void fighterMap::collision()
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
			tempBattle->setDestScene("스테이지2");
			tempBattle->init(2);
		}
	}
}
