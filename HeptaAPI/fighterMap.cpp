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
	_background = IMAGEMANAGER->addImage("°ÝÅõ¸Ê", ".\\bmps\\map\\°ÝÅõ¸Ê.bmp", WINSIZEX, WINSIZEY, false, true, MAGENTA);
	//_pixel = IMAGEMANAGER->addImage("°ÝÅõ¸ÊÇÈ¼¿", ".\\bmps\\map\\°ÝÅõ¸ÊÇÈ¼¿Ãæµ¹.bmp", WINSIZEX, WINSIZEY, false, true, MAGENTA);

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
	IMAGEMANAGER->findImage("°ÝÅõ¸Ê")->render(getMemDC());
	stageManager::render();
	//IMAGEMANAGER->findImage("npc")->frameRender(getMemDC(), _x, _y, 4, 0);
}