#include "stdafx.h"
#include "normalMap.h"



normalMap::normalMap()
{
}


normalMap::~normalMap()
{
}

HRESULT normalMap::init()
{
	stageManager::init();
	_background = IMAGEMANAGER->addImage("³ë¸»¸Ê", ".\\bmps\\map\\³ë¸».bmp", 0, 0, WINSIZEX, WINSIZEY, false, true, MAGENTA);
	_gymLeader = IMAGEMANAGER->addImage("³ë¸»NPC", ".\\bmps\\map\\³ë¸»NPC.bmp", 25, 28, false, true, MAGENTA);
	_player->setCurrentStage(4); //ÇöÀç ½ºÅ×ÀÌÁö Á¤º¸ ³Ñ°ÜÁØ´Ù

	_x = WINSIZEX / 2 - 12;
	_y = 30;

	_gymLeaderRc = RectMakeCenter(_x, _y, _gymLeader->getFrameWidth(), _gymLeader->getFrameHeight());


	_isWin = false;
	return S_OK;
}

void normalMap::release()
{

}

void normalMap::update()
{
	stageManager::update();
	_gymLeaderRc = RectMakeCenter(_x, _y, _gymLeader->getFrameWidth(), _gymLeader->getFrameHeight());

	if (_player->getPlayerRc().top >= WINSIZEY)
	{
		SCENEMANAGER->changeScene("¿ùµå¸Ê¾À");
		SCENEMANAGER->init("¿ùµå¸Ê¾À");
	}
}

void normalMap::render()
{
	IMAGEMANAGER->findImage("³ë¸»¸Ê")->render(getMemDC());
	IMAGEMANAGER->findImage("³ë¸»NPC")->render(getMemDC(), _x, _y);
	stageManager::render();

}
