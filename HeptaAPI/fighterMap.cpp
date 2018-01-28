#include "stdafx.h"
#include "fighterMap.h"
fighterMap::fighterMap()

{
}
fighterMap::~fighterMap()
{
}

HRESULT fighterMap::init()
{
	stageManager::init();
	_background = IMAGEMANAGER->addImage("������", ".\\bmps\\map\\������.bmp", WINSIZEX, WINSIZEY, false, true, MAGENTA);
	

	_player->setCurrentStage(2);

	_x = 240;
	_y = 28;

	_gymLeaderRc = RectMakeCenter(_x, _y, 25, 28);

	_isWin = false;

	return S_OK;
}
void fighterMap::release()
{

}
void fighterMap::update()
{
	stageManager::update();
	_gymLeaderRc = RectMakeCenter(_x, _y, 25, 28);

}
void fighterMap::render()
{
	IMAGEMANAGER->findImage("������")->render(getMemDC());
	stageManager::render();
	//IMAGEMANAGER->findImage("npc")->frameRender(getMemDC(), _x, _y, 4, 0);
}