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
	_background = IMAGEMANAGER->addImage("�����", ".\\bmps\\map\\����.bmp", WINSIZEX, WINSIZEY, false, true, MAGENTA);
	_pixel = IMAGEMANAGER->addImage("������ȼ�", ".\\bmps\\map\\������ȼ��浹.bmp", WINSIZEX, WINSIZEY, false, true, MAGENTA);
	
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
	IMAGEMANAGER->findImage("�����")->render(getMemDC());
	stageManager::render();
	//IMAGEMANAGER->findImage("npc")->frameRender(getMemDC(), _x, _y, 0, 0);
}