#include "stdafx.h"
#include "bugMap.h"



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

	_gymLeaderRc = RectMakeCenter(_x, _y, _gymLeader->getFrameWidth(), _gymLeader->getFrameHeight());


	_isWin = false;
	return S_OK;
}

void bugMap::release()
{

}

void bugMap::update()
{
	stageManager::update();
	_gymLeaderRc = RectMakeCenter(_x, _y, _gymLeader->getFrameWidth(), _gymLeader->getFrameHeight());

	if (_player->getPlayerRc().top >= WINSIZEY)
	{
		SCENEMANAGER->changeScene("¿ùµå¸Ê¾À");
		SCENEMANAGER->init("¿ùµå¸Ê¾À");
	}
}

void bugMap::render()
{
	
	IMAGEMANAGER->findImage("¹ú·¹¸Ê")->render(getMemDC());
	IMAGEMANAGER->findImage("¹ú·¹NPC")->render(getMemDC(), _x, _y);
	stageManager::render();
}
