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
			!_player->isAllDie())
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
