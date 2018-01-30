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
	_background = IMAGEMANAGER->addImage("���ڻ��", ".\\bmps\\map\\���ڻ�.bmp", WINSIZEX, WINSIZEY, false, true, MAGENTA);
	_drO = IMAGEMANAGER->addFrameImage("drO", ".\\bmps\\drHouseScene\\drO.bmp", 68, 24, 4, 1, false, true, MAGENTA);

	_player->setCurrentStage(0);

	_x = 240;
	_y = 115;

	_gymLeaderRc = RectMakeCenter(_x, _y, _drO->getFrameWidth(), _drO->getFrameHeight());

	_isMonsterSelect = false;

	SCENEMANAGER->init("����ʾ�");

	return S_OK;
}
void drOHouse::release()
{

}
void drOHouse::update()
{
	stageManager::update();
	

	if (DATABASE->getVPlayerPokemon()->size() != 0)
	{
		if (_player->getPlayerRc().top >= WINSIZEY)
		{
			SCENEMANAGER->changeScene("����ʾ�");
		}
	}
	else
	{
		if (_player->getPlayerRc().bottom > WINSIZEY)
		{
			_player->setPlayerPt(PointMake((_player->getPlayerRc().right + _player->getPlayerRc().left) / 2, WINSIZEY - (_player->getPlayerRc().bottom + _player->getPlayerRc().top) / 2));
		}
	}
}
void drOHouse::render()
{
	IMAGEMANAGER->findImage("���ڻ��")->render(getMemDC());
	IMAGEMANAGER->findImage("drO")->frameRender(getMemDC(), _x, _y);
	stageManager::render();

	if (_isMonsterSelect)
	{
		IMAGEMANAGER->findImage("textBox")->render(getMemDC(), WINSIZEX / 2 - 160, WINSIZEY - 66);
		DIALOGUE->render(getMemDC());
	}
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
			if (!_isMonsterSelect)
			{
				_isMonsterSelect = true;
				if (DATABASE->getVPlayerPokemon()->size() == 0)
				{
					DIALOGUE->loadingTextFile(".\\textData\\drO.txt");
				}

			}
		}
	}
}
