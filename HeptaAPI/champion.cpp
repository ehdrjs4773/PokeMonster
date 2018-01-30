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
