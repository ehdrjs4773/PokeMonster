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
	

	_player->setCurrentStage(0);

	_x = 240;
	_y = 28;

	_gymLeaderRc = RectMakeCenter(_x, _y, 25, 28);

	_isWin = false;

	SCENEMANAGER->init("¿ùµå¸Ê¾À");

	return S_OK;
}
void drOHouse::release()
{

}
void drOHouse::update()
{
	stageManager::update();
	_gymLeaderRc = RectMakeCenter(_x, _y, 25, 28);
	

	if (_player->getPlayerRc().top >= WINSIZEY)
	{
		SCENEMANAGER->changeScene("¿ùµå¸Ê¾À");
	}

}
void drOHouse::render()
{
	IMAGEMANAGER->findImage("¿À¹Ú»ç¸Ê")->render(getMemDC());
	stageManager::render();
	//IMAGEMANAGER->findImage("npc")->frameRender(getMemDC(), _x, _y, 4, 0);
}