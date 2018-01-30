#include "stdafx.h"
#include "guardian1.h"

#include "player.h"
#include "battleScene.h"


guardian1::guardian1()
{
	_isWin = false;
}


guardian1::~guardian1()
{

}

HRESULT guardian1::init()
{
	stageManager::init();
	_background = IMAGEMANAGER->addImage("사천왕1맵", ".\\bmps\\map\\사천왕1_격투.bmp", 0, 0, WINSIZEX, WINSIZEY, false, true, MAGENTA);
	_gymLeader = IMAGEMANAGER->addImage("사천왕1_격투NPC", ".\\bmps\\map\\사천왕1_격투NPC.bmp", 25, 28, false, true, MAGENTA);
	_player->setCurrentStage(9); //현재 스테이지 정보 넘겨준다

	_x = WINSIZEX / 2 - 13;
	_y = 60;

	_gymLeaderRc = RectMake(_x, _y, _gymLeader->getWidth(), _gymLeader->getHeight());


	if (SCENEMANAGER->getLastSceneName() == "스테이지10")
	{
		_player->setPlayerPt(PointMake(240, 0));
	}
	else
	{
		_player->setPlayerPt(PointMake(240, 340));
	}

	// 여기랑
	int level = 50;
	_vPokemon.clear();
	// 구구, 깨비참, 피존, 깨비드릴조, 피존투, 파오리
	pokemon* temp[6];
	skill* tempSkill;
	for (int i = 0; i < 6; ++i)
	{
		temp[i] = new pokemon;

		if (i == 0)
		{
			temp[i]->init("내루미", level);
			tempSkill = new skill;
			tempSkill->init("파동탄");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("돌떨구기");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("돌진");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("핥기");
			temp[i]->addSkill(tempSkill);
		}
		else if (i == 1)
		{
			temp[i]->init("성원숭", level);
			tempSkill = new skill;
			tempSkill->init("파동탄");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("돌떨구기");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("전광석화");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("연속뺨치기");
			temp[i]->addSkill(tempSkill);
		}
		else if (i == 2)
		{
			temp[i]->init("데구리", level);
			tempSkill = new skill;
			tempSkill->init("파동탄");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("돌떨구기");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("돌진");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("연속펀치");
			temp[i]->addSkill(tempSkill);
		}
		else if (i == 3)
		{
			temp[i]->init("홍수몬", level);
			tempSkill = new skill;
			tempSkill->init("파동탄");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("돌떨구기");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("연속펀치");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("불꽃펀치");
			temp[i]->addSkill(tempSkill);
		}
		else if (i == 4)
		{
			temp[i]->init("시라소몬", level);
			tempSkill = new skill;
			tempSkill->init("파동탄");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("점프킥");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("돌려차기");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("메가톤킥");
			temp[i]->addSkill(tempSkill);
		}
		else if (i == 5)
		{
			temp[i]->init("괴력몬", level);
			tempSkill = new skill;
			tempSkill->init("파동탄");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("지구던지기");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("괴력");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("태권당수");
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

void guardian1::release()
{

}

void guardian1::update()
{
	stageManager::update();
	collision();
	_gymLeaderRc = RectMake(_x, _y, _gymLeader->getWidth(), _gymLeader->getHeight());

	if (_player->getPlayerRc().top >= WINSIZEY)
	{
		SCENEMANAGER->changeScene("월드맵씬");
		SCENEMANAGER->init("월드맵씬");
	}

	if (_player->getPlayerRc().bottom < -10)
	{
		SCENEMANAGER->changeScene("스테이지10");
		SCENEMANAGER->init("스테이지10");
	
	}
}

void guardian1::render()
{
	IMAGEMANAGER->findImage("사천왕1맵")->render(getMemDC());
	if (!_isWin)
	{
		IMAGEMANAGER->findImage("사천왕1_격투NPC")->render(getMemDC(), _x, _y);
	}
	stageManager::render();

}
void guardian1::collision()
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
			DATABASE->getPlayerMemory()->isAllDie())
		{
			// 여기랑
			SCENEMANAGER->changeScene("battleScene");
			battleScene* tempBattle = (battleScene*)SCENEMANAGER->findScene("battleScene");
			tempBattle->setEnemyType(ENEMY_TRAINNER);
			tempBattle->setDestScene("스테이지9");
			tempBattle->init(9);
		}
	}
}
