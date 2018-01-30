#include "stdafx.h"
#include "champion.h"

#include "player.h"
#include "battleScene.h"


champion::champion()
{
	_isWin = false;
}


champion::~champion()
{
}

HRESULT champion::init()
{
	stageManager::init();
	_background = IMAGEMANAGER->addImage("챔피언맵", ".\\bmps\\map\\챔피언.bmp", 0, 0, WINSIZEX, WINSIZEY, false, true, MAGENTA);
	_gymLeader = IMAGEMANAGER->addImage("챔피언NPC", ".\\bmps\\map\\챔피언NPC.bmp", 25, 28, false, true, MAGENTA);
	_player->setCurrentStage(13); //현재 스테이지 정보 넘겨준다

	_x = 226;
	_y = 78;

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
			temp[i]->init("피카츄", level);
			tempSkill = new skill;
			tempSkill->init("10만볼트");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("전광석화");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("전기쇼크");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("번개");
			temp[i]->addSkill(tempSkill);
		}
		else if (i == 1)
		{
			temp[i]->init("리자몽", level);
			tempSkill = new skill;
			tempSkill->init("불대문자");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("지구던지기");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("메가톤펀치");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("드래곤크루");
			temp[i]->addSkill(tempSkill);
		}
		else if (i == 2)
		{
			temp[i]->init("이상해꽃", level);
			tempSkill = new skill;
			tempSkill->init("하드플랜트");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("덩굴채찍");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("솔라빔");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("메가드레인");
			temp[i]->addSkill(tempSkill);
		}
		else if (i == 3)
		{
			temp[i]->init("거북왕", level);
			tempSkill = new skill;
			tempSkill->init("하이드로펌프");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("냉동펀치");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("파도타기");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("지진");
			temp[i]->addSkill(tempSkill);
		}
		else if (i == 4)
		{
			temp[i]->init("라프라스", level);
			tempSkill = new skill;
			tempSkill->init("파도타기");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("냉동빔");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("하이드로펌프");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("스피드스타");
			temp[i]->addSkill(tempSkill);
		}
		else if (i == 5)
		{
			temp[i]->init("잠만보", level);
			tempSkill = new skill;
			tempSkill->init("파괴광선");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("괴력");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("누르기");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("스톤샤워");
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

void champion::release()
{

}

void champion::update()
{
	stageManager::update();
	_gymLeaderRc = RectMake(_x, _y, _gymLeader->getWidth(), _gymLeader->getHeight());

	if (_player->getPlayerRc().top >= WINSIZEY)
	{
		SCENEMANAGER->changeScene("스테이지12");
		SCENEMANAGER->init("스테이지12");
	}
	

	if (_player->getPlayerRc().top >= WINSIZEY)
	{
		SCENEMANAGER->changeScene("스테이지12");
		SCENEMANAGER->init("스테이지12");
	}
	if (_player->getPlayerRc().top >= WINSIZEY && _isWin == true)
	{
		SCENEMANAGER->changeScene("월드맵씬");
		SCENEMANAGER->init("월드맵씬");
	}
}

void champion::render()
{

	IMAGEMANAGER->findImage("챔피언맵")->render(getMemDC());
	if (!_isWin)
	{
		IMAGEMANAGER->findImage("챔피언NPC")->render(getMemDC(), _x, _y);
	}
	stageManager::render();
}

void champion::collision()
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
			tempBattle->setDestScene("스테이지13");
			tempBattle->init(13);
		}
	}
}
