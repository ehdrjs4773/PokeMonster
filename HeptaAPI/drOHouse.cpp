#include "stdafx.h"
#include "drOHouse.h"



drOHouse::drOHouse()
{
}


drOHouse::~drOHouse()
{
}

HRESULT drOHouse::init()
{
	stageManager::init();
	_background = IMAGEMANAGER->addImage("���ڻ��", ".\\bmps\\map\\���ڻ�.bmp", WINSIZEX, WINSIZEY, false, true, MAGENTA);
	_drO = IMAGEMANAGER->addFrameImage("drO", ".\\bmps\\drHouseScene\\drO.bmp", 68, 24, 4, 1, false, true, MAGENTA);

	_player->setCurrentStage(0);

	_x = 240;
	_y = 115;

	_drORc = RectMakeCenter(_x, _y, _drO->getFrameWidth(), _drO->getFrameHeight());

	

	SCENEMANAGER->init("����ʾ�");

	return S_OK;
}
void drOHouse::release()
{

}
void drOHouse::update()
{
	stageManager::update();
	_drORc = RectMakeCenter(_x, _y, _drO->getFrameWidth(), _drO->getFrameHeight());
	

	if (_player->getPlayerRc().top >= WINSIZEY)
	{
		SCENEMANAGER->changeScene("����ʾ�");
	}

}
void drOHouse::render()
{
	IMAGEMANAGER->findImage("���ڻ��")->render(getMemDC());
	IMAGEMANAGER->findImage("drO")->frameRender(getMemDC(), _x, _y);
	stageManager::render();
	//IMAGEMANAGER->findImage("npc")->frameRender(getMemDC(), _x, _y, 4, 0);
}

void drOHouse::collision()
{
	RECT temp;
	if (IntersectRect(&temp, &_gymLeaderRc, &_player->getPlayerRc()) && _isWin == false)
	{
		int tempWidth = temp.right - temp.left;
		int tempHeight = temp.bottom - temp.top;

		// �����浹
		if (tempHeight > tempWidth)
		{
			//������ �浹
			if (temp.left == _player->getPlayerRc().left)
			{
				_player->setPlayerPt(PointMake(_gymLeaderRc.right + (_player->getPlayerRc().right - _player->getPlayerRc().left) / 2,
					(_player->getPlayerRc().bottom + _player->getPlayerRc().top) / 2));
			}
			//�����浹
			if (temp.right == _player->getPlayerRc().right)
			{
				_player->setPlayerPt(PointMake(_gymLeaderRc.left - (_player->getPlayerRc().right - _player->getPlayerRc().left) / 2,
					(_player->getPlayerRc().bottom + _player->getPlayerRc().top) / 2));
			}
		}
		else
		{
			//�Ʒ��浹
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
			SCENEMANAGER->findScene("battleScene")->setDestScene("��������1");
		}
	}
}
