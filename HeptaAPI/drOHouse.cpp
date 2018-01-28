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
	_background = IMAGEMANAGER->addImage("오박사맵", ".\\bmps\\map\\오박사.bmp", WINSIZEX, WINSIZEY, false, true, MAGENTA);
	

	_player->setCurrentStage(0);

	_x = 240;
	_y = 28;

	_gymLeaderRc = RectMakeCenter(_x, _y, 25, 28);

	_isWin = false;

	return S_OK;
}
void drOHouse::release()
{

}
void drOHouse::update()
{
	stageManager::update();
	_gymLeaderRc = RectMakeCenter(_x, _y, 25, 28);

}
void drOHouse::render()
{
	IMAGEMANAGER->findImage("오박사맵")->render(getMemDC());
	stageManager::render();
	//IMAGEMANAGER->findImage("npc")->frameRender(getMemDC(), _x, _y, 4, 0);
}