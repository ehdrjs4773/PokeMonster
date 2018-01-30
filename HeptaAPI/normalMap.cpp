#include "stdafx.h"
#include "normalMap.h"

#include "player.h"
#include "battleScene.h"


normalMap::normalMap()
{
	_isWin = false;
}


normalMap::~normalMap()
{
}

HRESULT normalMap::init()
{
	stageManager::init();
	_background = IMAGEMANAGER->addImage("노말맵", ".\\bmps\\map\\노말.bmp", 0, 0, WINSIZEX, WINSIZEY, false, true, MAGENTA);
	_gymLeader = IMAGEMANAGER->addImage("노말NPC", ".\\bmps\\map\\노말NPC.bmp", 25, 28, false, true, MAGENTA);
	_player->setCurrentStage(4); //현재 스테이지 정보 넘겨준다

	_x = WINSIZEX / 2 - 12;
	_y = 30;

	_gymLeaderRc = RectMake(_x, _y, _gymLeader->getWidth(), _gymLeader->getHeight());

	int level = 5 + 5 * _player->getBadgeCount();
	_vPokemon.clear();
	//메타몽 , 냐옹 , 레트라 , 럭키 , 켄타우로스 , 캥카
	pokemon* temp[6];
	skill* tempSkill;
	for (int i = 0; i < 6; ++i)
	{
		temp[i] = new pokemon;

		if (i == 0)
		{
			temp[i]->init("메타몽", level);
			tempSkill = new skill;
			tempSkill->init("고무고무난타");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("할퀴기");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("몸통박치기");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("불꽃펀치");
			temp[i]->addSkill(tempSkill);
		}
		else if (i == 1)
		{
			temp[i]->init("냐옹", level);
			tempSkill = new skill;
			tempSkill->init("고무고무난타");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("할퀴기");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("몸통박치기");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("고양이돈받기");
			temp[i]->addSkill(tempSkill);
		}
		else if (i == 2)
		{
			temp[i]->init("레트라", level);
			tempSkill = new skill;
			tempSkill->init("고무고무난타");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("할퀴기");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("몸통박치기");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("필살앞니");
			temp[i]->addSkill(tempSkill);
		}
		else if (i == 3)
		{
			temp[i]->init("럭키", level);
			tempSkill = new skill;
			tempSkill->init("고무고무난타");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("할퀴기");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("몸통박치기");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("알폭탄");
			temp[i]->addSkill(tempSkill);
		}
		else if (i == 4)
		{
			temp[i]->init("켄타우로스", level);
			tempSkill = new skill;
			tempSkill->init("고무고무난타");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("할퀴기");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("몸통박치기");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("돌진");
			temp[i]->addSkill(tempSkill);
		}
		else if (i == 5)
		{
			temp[i]->init("캥카", level);
			tempSkill = new skill;
			tempSkill->init("고무고무난타");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("할퀴기");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("몸통박치기");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("잼잼펀치");
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

void normalMap::release()
{

}

void normalMap::update()
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

void normalMap::render()
{
	IMAGEMANAGER->findImage("노말맵")->render(getMemDC());
	if (!_isWin)
	{
		IMAGEMANAGER->findImage("노말NPC")->render(getMemDC(), _x, _y);
	}
	stageManager::render();

}
void normalMap::collision()
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
			tempBattle->setDestScene("스테이지4");
			tempBattle->init(4);
		}
	}
}

