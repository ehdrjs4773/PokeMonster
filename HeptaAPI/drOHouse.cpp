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
	_background = IMAGEMANAGER->addImage("���ڻ��", ".\\bmps\\map\\���ڻ�.bmp", WINSIZEX, WINSIZEY, false, true, MAGENTA);
	

	_player->setCurrentStage(0);

	_x = 240;
	_y = 28;

	_gymLeaderRc = RectMakeCenter(_x, _y, 25, 28);

	_isWin = false;

	SCENEMANAGER->init("����ʾ�");

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
		SCENEMANAGER->changeScene("����ʾ�");
	}

}
void drOHouse::render()
{
	IMAGEMANAGER->findImage("���ڻ��")->render(getMemDC());
	stageManager::render();
	//IMAGEMANAGER->findImage("npc")->frameRender(getMemDC(), _x, _y, 4, 0);
}