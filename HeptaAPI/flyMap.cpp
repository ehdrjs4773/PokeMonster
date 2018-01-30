#include "stdafx.h"
#include "flyMap.h"
#include "player.h"
#include "battleScene.h"

flyMap::flyMap()
{
	_isWin = false;
}
flyMap::~flyMap()
{

}

HRESULT flyMap::init()
{
	stageManager::init();

	_background = IMAGEMANAGER->addImage("비행맵", ".\\bmps\\map\\비행.bmp", WINSIZEX, WINSIZEY, false, true, MAGENTA);
	_gymLeader = IMAGEMANAGER->addImage("비행NPC", ".\\bmps\\map\\비행NPC.bmp", 25, 28, false, true, MAGENTA);

	_player->setCurrentStage(7); //현재 스테이지 정보 넘겨준다

	_x = WINSIZEX / 2 - 12;
	_y = 15;

	_gymLeaderRc = RectMake(_x, _y, _gymLeader->getWidth(), _gymLeader->getHeight());


	

	// 여기랑
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
			temp[i]->init("구구", level);
			tempSkill = new skill;
			tempSkill->init("몸통박치기");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("고무고무난타");
			temp[i]->addSkill(tempSkill);
		}
		else if (i == 1)
		{
			temp[i]->init("깨비참", level);
		}
		else if (i == 2)
		{
			temp[i]->init("피죤", level);
		}
		else if (i == 3)
		{
			temp[i]->init("깨비드릴조", level);
		}
		else if (i == 4)
		{
			temp[i]->init("피죤투", level);
		}
		else if (i == 5)
		{
			temp[i]->init("파오리", level);
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
void flyMap::release()
{

}
void flyMap::update()
{
	stageManager::update();
	this->collision();
	_gymLeaderRc = RectMake(_x, _y, _gymLeader->getWidth(), _gymLeader->getHeight());

	if (_player->getPlayerRc().top >= WINSIZEY)
	{
		SCENEMANAGER->changeScene("월드맵씬");
		SCENEMANAGER->init("월드맵씬");
	}

}
void flyMap::render()
{
	IMAGEMANAGER->findImage("비행맵")->render(getMemDC());
	if (!_isWin)
	{
		IMAGEMANAGER->findImage("비행NPC")->render(getMemDC(), _x, _y);
	}
	stageManager::render();
	//IMAGEMANAGER->findImage("npc")->frameRender(getMemDC(), _x, _y, 0, 0);
	//Rectangle(getMemDC(), _gymLeaderRc.left, _gymLeaderRc.top, _gymLeaderRc.right, _gymLeaderRc.bottom);
}

void flyMap::collision()
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
			tempBattle->setDestScene("스테이지7");
			tempBattle->init(7);
		}
	}
}
