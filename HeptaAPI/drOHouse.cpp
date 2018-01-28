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
	_background = IMAGEMANAGER->addImage("¿À¹Ú»ç¸Ê", ".\\bmps\\map\\¿À¹Ú»ç.bmp", WINSIZEX, WINSIZEY, false, true, MAGENTA);
	_drO = IMAGEMANAGER->addFrameImage("drO", ".\\bmps\\drHouseScene\\drO.bmp", 68, 24, 4, 1, false, true, MAGENTA);

	_player->setCurrentStage(0);

	_x = 240;
	_y = 115;

	_drORc = RectMakeCenter(_x, _y, _drO->getFrameWidth(), _drO->getFrameHeight());

	

	SCENEMANAGER->init("¿ùµå¸Ê¾À");

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
		SCENEMANAGER->changeScene("¿ùµå¸Ê¾À");
	}

}
void drOHouse::render()
{
	IMAGEMANAGER->findImage("¿À¹Ú»ç¸Ê")->render(getMemDC());
	IMAGEMANAGER->findImage("drO")->frameRender(getMemDC(), _x, _y);
	stageManager::render();
	//IMAGEMANAGER->findImage("npc")->frameRender(getMemDC(), _x, _y, 4, 0);
}