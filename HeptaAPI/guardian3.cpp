#include "stdafx.h"
#include "guardian3.h"
#include "player.h"
#include "battleScene.h"


guardian3::guardian3()
{
	_isWin = false;
}


guardian3::~guardian3()
{
}

HRESULT guardian3::init()
{
	stageManager::init();
	_background = IMAGEMANAGER->addImage("사천왕3맵", ".\\bmps\\map\\사천왕3_에스퍼.bmp", 0, 0, WINSIZEX, WINSIZEY, false, true, MAGENTA);
	_gymLeader = IMAGEMANAGER->addImage("사천왕3_에스퍼NPC", ".\\bmps\\map\\사천왕3_에스퍼NPC.bmp", 25, 28, false, true, MAGENTA);
	_player->setCurrentStage(11); //현재 스테이지 정보 넘겨준다

	_x = WINSIZEX / 2 - 12;
	_y = 25;

	_gymLeaderRc = RectMake(_x, _y, _gymLeader->getWidth(), _gymLeader->getHeight());

	if (SCENEMANAGER->getLastSceneName() == "스테이지12")
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
			temp[i]->init("고라파덕", level);
			tempSkill = new skill;
			tempSkill->init("숟가락휘기");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("염동력");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("지진");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("돌진");
			temp[i]->addSkill(tempSkill);
		}
		else if (i == 1)
		{
			temp[i]->init("골덕", level);
			tempSkill = new skill;
			tempSkill->init("숟가락휘기");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("염동력");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("지진");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("돌진");
			temp[i]->addSkill(tempSkill);
		}
		else if (i == 2)
		{
			temp[i]->init("슬리퍼", level);
			tempSkill = new skill;
			tempSkill->init("숟가락휘기");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("염동력");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("지진");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("돌진");
			temp[i]->addSkill(tempSkill);
		}
		else if (i == 3)
		{
			temp[i]->init("슬리프", level);
			tempSkill = new skill;
			tempSkill->init("숟가락휘기");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("염동력");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("지진");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("돌진");
			temp[i]->addSkill(tempSkill);
		}
		else if (i == 4)
		{
			temp[i]->init("윤겔라", level);
			tempSkill = new skill;
			tempSkill->init("숟가락휘기");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("염동력");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("지진");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("돌진");
			temp[i]->addSkill(tempSkill);
		}
		else if (i == 5)
		{
			temp[i]->init("후딘", level);
			tempSkill = new skill;
			tempSkill->init("숟가락휘기");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("염동력");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("지진");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("돌진");
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

void guardian3::release()
{

}

void guardian3::update()
{
	stageManager::update();
	collision();
	_gymLeaderRc = RectMake(_x, _y, _gymLeader->getWidth(), _gymLeader->getHeight());

	if (_player->getPlayerRc().top >= WINSIZEY)
	{
		SCENEMANAGER->changeScene("스테이지10");
		SCENEMANAGER->init("스테이지10");
	}
	if (_player->getPlayerRc().bottom <= 0)
	{
		SCENEMANAGER->changeScene("스테이지12");
		SCENEMANAGER->init("스테이지12");
	}
}

void guardian3::render()
{
	IMAGEMANAGER->findImage("사천왕3맵")->render(getMemDC());
	if (!_isWin)
	{
		IMAGEMANAGER->findImage("사천왕3_에스퍼NPC")->render(getMemDC(), _x, _y);
	}
	stageManager::render();

}
void guardian3::collision()
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
			tempBattle->setDestScene("스테이지11");
			tempBattle->init(11);
		}
	}
}
