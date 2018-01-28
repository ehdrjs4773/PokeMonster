#include "stdafx.h"
#include "dragonMap.h"



dragonMap::dragonMap()
{
}


dragonMap::~dragonMap()
{
}

HRESULT dragonMap::init()
{
	stageManager::init();
	_background = IMAGEMANAGER->addImage("µå·¡°ï¸Ê", ".\\bmps\\map\\µå·¡°ï.bmp", 0, 0, WINSIZEX, WINSIZEY, false, true, MAGENTA);
	_gymLeader = IMAGEMANAGER->addImage("µå·¡°ïNPC", ".\\bmps\\map\\µå·¡°ïNPC.bmp", 25, 28, false, true, MAGENTA);
	_player->setCurrentStage(5); //ÇöÀç ½ºÅ×ÀÌÁö Á¤º¸ ³Ñ°ÜÁØ´Ù

	_x = WINSIZEX / 2;
	_y = 15;

	_gymLeaderRc = RectMakeCenter(_x, _y, _gymLeader->getFrameWidth(), _gymLeader->getFrameHeight());


	_isWin = false;

	return S_OK;
}

void dragonMap::release()
{

}

void dragonMap::update()
{
	stageManager::update();
	_gymLeaderRc = RectMakeCenter(_x, _y, _gymLeader->getFrameWidth(), _gymLeader->getFrameHeight());

	if (_player->getPlayerRc().top >= WINSIZEY)
	{
		SCENEMANAGER->changeScene("¿ùµå¸Ê¾À");
	}
}

void dragonMap::render()
{
	
	IMAGEMANAGER->findImage("µå·¡°ï¸Ê")->render(getMemDC());
	IMAGEMANAGER->findImage("µå·¡°ïNPC")->render(getMemDC(), _x, _y);
	stageManager::render();
}