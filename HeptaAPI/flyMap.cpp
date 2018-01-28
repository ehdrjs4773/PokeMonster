#include "stdafx.h"
#include "flyMap.h"

flyMap::flyMap()
{
}
flyMap::~flyMap()
{

}

HRESULT flyMap::init()
{
	stageManager::init();
	_background = IMAGEMANAGER->addImage("비행맵", ".\\bmps\\map\\비행.bmp", WINSIZEX, WINSIZEY, false, true, MAGENTA);

	_player->setCurrentStage(7); //현재 스테이지 정보 넘겨준다

	_x = 240;
	_y = 28;

	_gymLeaderRc = RectMakeCenter(_x, _y, 25, 28);


	_isWin = false;

	return S_OK;
}
void flyMap::release()
{

}
void flyMap::update()
{
	stageManager::update();
	_gymLeaderRc = RectMakeCenter(_x, _y, 25, 28);

}
void flyMap::render()
{
	IMAGEMANAGER->findImage("비행맵")->render(getMemDC());
	stageManager::render();
	//IMAGEMANAGER->findImage("npc")->frameRender(getMemDC(), _x, _y, 0, 0);
}