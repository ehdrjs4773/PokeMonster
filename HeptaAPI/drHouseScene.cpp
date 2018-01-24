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
	_background = IMAGEMANAGER->addImage("오박사하우스", ".\\bmps\\drHouseScene\\drOHouse.bmp", WINSIZEX, WINSIZEY, false, true, RGB(255,0,255));
	_drO = IMAGEMANAGER->addFrameImage("오박사", ".\\bmps\\drHouseScene\\drO.bmp", 68, 24, 4, 1, false, true, MAGENTA);

	_x = 240;
	_y = 115;

	_drRc = RectMakeCenter(_x, _y, _drO->getFrameWidth(), _drO->getFrameHeight());

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
	IMAGEMANAGER->findImage("오박사하우스")->render(getMemDC());
	IMAGEMANAGER->findImage("오박사")->frameRender(getMemDC(), _x, _y);
	_player->render();
}