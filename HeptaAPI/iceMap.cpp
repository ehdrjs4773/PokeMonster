#include "stdafx.h"
#include "iceMap.h"



iceMap::iceMap()
{
}


iceMap::~iceMap()
{
}

HRESULT iceMap::init()
{
	stageManager::init();

	_background = IMAGEMANAGER->addImage("¾óÀ½¸Ê", ".\\bmps\\map\\¾óÀ½.bmp", 0, 0, WINSIZEX, WINSIZEY, false, true, MAGENTA);
	_gymLeader = IMAGEMANAGER->addImage("¾óÀ½NPC", ".\\bmps\\map\\¾óÀ½NPC.bmp", 25, 28, false, true, MAGENTA);
	_player->setCurrentStage(8); //ÇöÀç ½ºÅ×ÀÌÁö Á¤º¸ ³Ñ°ÜÁØ´Ù

	_x = WINSIZEX / 2 - 12;
	_y = 15;

	_gymLeaderRc = RectMakeCenter(_x, _y, _gymLeader->getFrameWidth(), _gymLeader->getFrameHeight());


	_isWin = false;
	return S_OK;
}

void iceMap::release()
{

}

void iceMap::update()
{
	stageManager::update();
	_gymLeaderRc = RectMakeCenter(_x, _y, _gymLeader->getFrameWidth(), _gymLeader->getFrameHeight());

	if (_player->getPlayerRc().top >= WINSIZEY)
	{
		SCENEMANAGER->changeScene("¿ùµå¸Ê¾À");
		SCENEMANAGER->init("¿ùµå¸Ê¾À");
	}
}

void iceMap::render()
{
	
	IMAGEMANAGER->findImage("¾óÀ½¸Ê")->render(getMemDC());
	IMAGEMANAGER->findImage("¾óÀ½NPC")->render(getMemDC(), _x, _y);
	stageManager::render();
}

