#include "stdafx.h"
#include "bugMap.h"

#include "player.h"
#include "battleScene.h"


bugMap::bugMap()
{
}


bugMap::~bugMap()
{
}

HRESULT bugMap::init()
{
	stageManager::init();
	_background = IMAGEMANAGER->addImage("¹ú·¹¸Ê", ".\\bmps\\map\\¹ú·¹.bmp", 0, 0, WINSIZEX, WINSIZEY, false, true, MAGENTA);
	_gymLeader = IMAGEMANAGER->addImage("¹ú·¹NPC", ".\\bmps\\map\\¹ú·¹NPC.bmp", 25, 28, false, true, MAGENTA);
	_player->setCurrentStage(6); //ÇöÀç ½ºÅ×ÀÌÁö Á¤º¸ ³Ñ°ÜÁØ´Ù

	_x = WINSIZEX / 2;
	_y = 15;

	_gymLeaderRc = RectMake(_x, _y, _gymLeader->getWidth(), _gymLeader->getHeight());


	_isWin = false;
	return S_OK;
}

void bugMap::release()
{

}

void bugMap::update()
{
	stageManager::update();
	_gymLeaderRc = RectMake(_x, _y, _gymLeader->getWidth(), _gymLeader->getHeight());

	if (_player->getPlayerRc().top >= WINSIZEY)
	{
		SCENEMANAGER->changeScene("¿ùµå¸Ê¾À");
		SCENEMANAGER->init("¿ùµå¸Ê¾À");
	}
}

void bugMap::render()
{
	
	IMAGEMANAGER->findImage("¹ú·¹¸Ê")->render(getMemDC());
	if (!_isWin)
	{
		IMAGEMANAGER->findImage("¹ú·¹NPC")->render(getMemDC(), _x, _y);
	}
	stageManager::render();
}

void bugMap::collision()
{
	RECT temp;
	if (IntersectRect(&temp, &_gymLeaderRc, &_player->getPlayerRc()) && _isWin == false)
	{
		int tempWidth = temp.right - temp.left;
		int tempHeight = temp.bottom - temp.top;

		// °¡·ÎÃæµ¹
		if (tempHeight > tempWidth)
		{
			//¿À¸¥ÂÊ Ãæµ¹
			if (temp.left == _player->getPlayerRc().left)
			{
				_player->setPlayerPt(PointMake(_gymLeaderRc.right + (_player->getPlayerRc().right - _player->getPlayerRc().left) / 2,
					(_player->getPlayerRc().bottom + _player->getPlayerRc().top) / 2));
			}
			//¿ŞÂÊÃæµ¹
			if (temp.right == _player->getPlayerRc().right)
			{
				_player->setPlayerPt(PointMake(_gymLeaderRc.left - (_player->getPlayerRc().right - _player->getPlayerRc().left) / 2,
					(_player->getPlayerRc().bottom + _player->getPlayerRc().top) / 2));
			}
		}
		else
		{
			//¾Æ·¡Ãæµ¹
			if (temp.top == _player->getPlayerRc().top)
			{
				_player->setPlayerPt(PointMake((_player->getPlayerRc().right + _player->getPlayerRc().left) / 2,
					temp.bottom + (_player->getPlayerRc().bottom - _player->getPlayerRc().top) / 2));
			}
		}
		if (KEYMANAGER->isOnceKeyDown(PLAYER_SELECT_KEY))
		{
			// ¿©±â¶û
			SCENEMANAGER->changeScene("battleScene");
			battleScene* tempBattle = (battleScene*)SCENEMANAGER->findScene("battleScene");
			tempBattle->setEnemyType(ENEMY_TRAINNER);
			tempBattle->setDestScene("½ºÅ×ÀÌÁö6");
			tempBattle->init(6);
		}
	}
}
