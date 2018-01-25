#include "stdafx.h"
#include "drHouseScene.h"



drHouseScene::drHouseScene()
{
}


drHouseScene::~drHouseScene()
{
}

HRESULT drHouseScene::init()
{
	_background = IMAGEMANAGER->addImage("drOHouse", ".\\bmps\\drHouseScene\\drOHouse.bmp", WINSIZEX, WINSIZEY, false, true, MAGENTA);
	_pixel = IMAGEMANAGER->addImage("drOHousePixel", ".\\bmps\\drHouseScene\\drOHousePixel.bmp", WINSIZEX, WINSIZEY, false, true, MAGENTA);
	_drO = IMAGEMANAGER->addFrameImage("drO", ".\\bmps\\drHouseScene\\drO.bmp", 68, 24, 4, 1, false, true, MAGENTA);

	_x = 240;
	_y = 115;

	_drRc = RectMakeCenter(_x, _y, _drO->getFrameWidth(), _drO->getFrameHeight());

	_player = new player;
	_player->init();
	return S_OK;
}
void drHouseScene::release()
{

}
void drHouseScene::update()
{
	_player->update();
}
void drHouseScene::render()
{
	IMAGEMANAGER->findImage("drOHouse")->render(getMemDC());
	IMAGEMANAGER->findImage("drO")->frameRender(getMemDC(), _x, _y);
	_player->render();
}