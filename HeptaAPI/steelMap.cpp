#include "stdafx.h"
#include "steelMap.h"
#include "player.h"
#include "battleScene.h"


steelMap::steelMap()
{
	_isWin = false;
}


steelMap::~steelMap()
{
}

HRESULT steelMap::init()
{
	stageManager::init();
	_background = IMAGEMANAGER->addImage("강철맵", ".\\bmps\\map\\강철.bmp", 0, 0, WINSIZEX, WINSIZEY, false, true, MAGENTA);
	_gymLeader = IMAGEMANAGER->addImage("강철NPC", ".\\bmps\\map\\강철NPC.bmp", 25, 28, false, true, MAGENTA);
	_player->setCurrentStage(1); //현재 스테이지 정보 넘겨준다

	_x = WINSIZEX / 2 - 12;
	_y = 15;

	_gymLeaderRc = RectMake(_x, _y, _gymLeader->getWidth(), _gymLeader->getHeight());


	int level = 5 + 5 * _player->getBadgeCount();
	_vPokemon.clear();
	// 코일 , 레어코일 ,코일, 꼬마돌 , 롱스톤  , 코뿌리
	pokemon* temp[6];
	skill* tempSkill;
	for (int i = 0; i < 6; ++i)
	{
		temp[i] = new pokemon;

		if (i == 0)
		{
			temp[i]->init("코일", level);
			tempSkill = new skill;
			tempSkill->init("러스터캐논");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("돌떨구기");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("소닉붐");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("구슬던지기");
			temp[i]->addSkill(tempSkill);
		}
		else if (i == 1)
		{
			temp[i]->init("레어코일", level);
			tempSkill = new skill;
			tempSkill->init("러스터캐논");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("돌떨구기");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("소닉붐");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("전광석화");
			temp[i]->addSkill(tempSkill);
		}
		else if (i == 2)
		{
			temp[i]->init("코일", level);
			tempSkill = new skill;
			tempSkill->init("러스터캐논");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("돌떨구기");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("소닉붐");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("돌떨구기");
			temp[i]->addSkill(tempSkill);
		}
		else if (i == 3)
		{
			temp[i]->init("꼬마돌", level);
			tempSkill = new skill;
			tempSkill->init("러스터캐논");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("돌떨구기");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("소닉붐");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("전광석화");
			temp[i]->addSkill(tempSkill);
		}
		else if (i == 4)
		{
			temp[i]->init("롱스톤", level);
			tempSkill = new skill;
			tempSkill->init("러스터캐논");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("돌떨구기");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("소닉붐");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("김밥말이");
			temp[i]->addSkill(tempSkill);
		}
		else if (i == 5)
		{
			temp[i]->init("코뿌리", level);
			tempSkill = new skill;
			tempSkill->init("러스터캐논");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("돌떨구기");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("소닉붐");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("누르기");
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

void steelMap::release()
{

}

void steelMap::update()	
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

void steelMap::render()	
{
	IMAGEMANAGER->findImage("강철맵")->render(getMemDC());
	if (_isWin == false)
	{
		IMAGEMANAGER->findImage("강철NPC")->render(getMemDC(), _gymLeaderRc.left, _gymLeaderRc.top);
	}

	//Rectangle(getMemDC(), _player->getPlayerRc().left, _player->getPlayerRc().top, _player->getPlayerRc().right, _player->getPlayerRc().bottom);
	stageManager::render();
	//Rectangle(getMemDC(), _gymLeaderRc.left, _gymLeaderRc.top, _gymLeaderRc.right, _gymLeaderRc.bottom);
}

void steelMap::collision()
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

		if (KEYMANAGER->isOnceKeyDown(PLAYER_SELECT_KEY) &&
			!_player->isAllDie())
		{
			// 여기랑
			SCENEMANAGER->changeScene("battleScene");
			battleScene* tempBattle = (battleScene*)SCENEMANAGER->findScene("battleScene");
			tempBattle->setEnemyType(ENEMY_TRAINNER);
			tempBattle->setDestScene("스테이지1");
			tempBattle->init(1);
		}
	}
}
