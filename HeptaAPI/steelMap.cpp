#include "stdafx.h"
#include "steelMap.h"
#include "player.h"



steelMap::steelMap()
{
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


	_isWin = false;

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

	Rectangle(getMemDC(), _player->getPlayerRc().left, _player->getPlayerRc().top, _player->getPlayerRc().right, _player->getPlayerRc().bottom);
	stageManager::render();
	Rectangle(getMemDC(), _gymLeaderRc.left, _gymLeaderRc.top, _gymLeaderRc.right, _gymLeaderRc.bottom);
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

		if (KEYMANAGER->isOnceKeyDown(PLAYER_SELECT_KEY))
		{
			SCENEMANAGER->changeScene("battleScene");
			SCENEMANAGER->init("battleScene");
			SCENEMANAGER->findScene("battleScene")->setDestScene("스테이지1");
		}
	}
}
