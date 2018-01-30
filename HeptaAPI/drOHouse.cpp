#include "stdafx.h"
#include "drOHouse.h"

#include "player.h"


drOHouse::drOHouse()
{
}


drOHouse::~drOHouse()
{
}

HRESULT drOHouse::init()
{
	stageManager::init();
	_background = IMAGEMANAGER->addImage("오박사맵", ".\\bmps\\map\\오박사.bmp", WINSIZEX, WINSIZEY, false, true, MAGENTA);
	_drO = IMAGEMANAGER->addFrameImage("drO", ".\\bmps\\drHouseScene\\drO.bmp", 68, 24, 4, 1, false, true, MAGENTA);

	IMAGEMANAGER->addImage("selectIcon", ".\\bmps\\battleScene\\UI\\selectIcon.bmp", 7, 7, false, true, MAGENTA);

	_player->setCurrentStage(0);

	_x = 240;
	_y = 115;

	_gymLeaderRc = RectMake(_x, _y, _drO->getFrameWidth(), _drO->getFrameHeight());

	_isMonsterSelect = false;

	SCENEMANAGER->init("월드맵씬");

	_startingMonster[0] = "파이리";
	_startingMonster[1] = "꼬부기";
	_startingMonster[2] = "이상해씨";

	_selectNum = 0;

	_dialogueTime = 0;

	return S_OK;
}
void drOHouse::release()
{

}
void drOHouse::update()
{
	if (!_isMonsterSelect)
	{
		stageManager::update();

		this->collision();

		if (DATABASE->getVPlayerPokemon()->size() != 0)
		{
			if (_player->getPlayerRc().top >= WINSIZEY)
			{
				SCENEMANAGER->changeScene("월드맵씬");
			}
		}
		else
		{
			if (_player->getPlayerRc().bottom > WINSIZEY)
			{
				_player->setPlayerPt(PointMake((_player->getPlayerRc().right + _player->getPlayerRc().left) / 2, WINSIZEY - (_player->getPlayerRc().bottom - _player->getPlayerRc().top) / 2));
			}
		}
	}
	else
	{
		DIALOGUE->update();

		if (DATABASE->getVPlayerPokemon()->size() == 0)
		{
			if (KEYMANAGER->isOnceKeyDown(VK_LEFT))
			{
				_selectNum--;
				if (_selectNum < 0)
					_selectNum = 2;
			}
			if (KEYMANAGER->isOnceKeyDown(VK_RIGHT))
			{
				_selectNum++;
				if (_selectNum > 2)
					_selectNum = 0;
			}

			if (KEYMANAGER->isOnceKeyDown(PLAYER_SELECT_KEY))
			{
				pokemon* temp = new pokemon;

				if (_selectNum == 0)
				{
					temp->init("파이리", 5);
					skill* tempSkill = new skill;
					tempSkill->init("불대문자");
					temp->addSkill(tempSkill);
					tempSkill = new skill;
					tempSkill->init("불대문자");
					temp->addSkill(tempSkill);
					tempSkill = new skill;
					tempSkill->init("불대문자");
					temp->addSkill(tempSkill);
					tempSkill = new skill;
					tempSkill->init("불대문자");
					temp->addSkill(tempSkill);
				}
				else if (_selectNum == 1)
				{
					temp->init("꼬부기", 5);
					skill* tempSkill = new skill;
					tempSkill->init("불대문자");
					temp->addSkill(tempSkill);
					tempSkill = new skill;
					tempSkill->init("불대문자");
					temp->addSkill(tempSkill);
					tempSkill = new skill;
					tempSkill->init("불대문자");
					temp->addSkill(tempSkill);
					tempSkill = new skill;
					tempSkill->init("불대문자");
					temp->addSkill(tempSkill);
				}
				else
				{
					temp->init("이상해씨", 5);
					skill* tempSkill = new skill;
					tempSkill->init("불대문자");
					temp->addSkill(tempSkill);
					tempSkill = new skill;
					tempSkill->init("불대문자");
					temp->addSkill(tempSkill);
					tempSkill = new skill;
					tempSkill->init("불대문자");
					temp->addSkill(tempSkill);
					tempSkill = new skill;
					tempSkill->init("불대문자");
					temp->addSkill(tempSkill);
				}

				DATABASE->getVPlayerPokemon()->push_back(temp);

				_isMonsterSelect = false;
			}
		}
		else
		{
			_dialogueTime++;
			if (_dialogueTime % 30 == 0)
			{
				_isMonsterSelect = false;
			}
		}
	}
}
void drOHouse::render()
{
	IMAGEMANAGER->findImage("오박사맵")->render(getMemDC());
	IMAGEMANAGER->findImage("drO")->frameRender(getMemDC(), _x, _y);
	stageManager::render();

	if (_isMonsterSelect)
	{
		IMAGEMANAGER->findImage("textBox")->render(getMemDC(), WINSIZEX / 2 - 160, WINSIZEY - 66);
		DIALOGUE->render(getMemDC());

		if (DATABASE->getVPlayerPokemon()->size() == 0)
		{
			for (int i = 0; i < 3; ++i)
				TextOut(getMemDC(), 110 + 90 * i, 327, _startingMonster[i].c_str(), strlen(_startingMonster[i].c_str()));
			IMAGEMANAGER->findImage("selectIcon")->render(getMemDC(), 110 + 90 * _selectNum - 7, 331);
		}
	}
}

void drOHouse::collision()
{
	RECT temp;
	if (IntersectRect(&temp, &_gymLeaderRc, &_player->getPlayerRc()))
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
			if (!_isMonsterSelect)
			{
				_isMonsterSelect = true;
				if (DATABASE->getVPlayerPokemon()->size() == 0)
				{
					DIALOGUE->loadingTextFile(".\\textData\\drO.txt");
					DIALOGUE->setPoint(PointMake(100, 307));
				}
				else
				{
					DIALOGUE->loadingTextFile(".\\textData\\drO_alreadySelect.txt");
					DIALOGUE->setPoint(PointMake(100, 307));
					_dialogueTime = 0;
				}
			}
		}
	}
}
