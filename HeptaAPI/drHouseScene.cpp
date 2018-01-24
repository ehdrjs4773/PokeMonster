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
	_background = IMAGEMANAGER->addImage("���ڻ��Ͽ콺", ".\\bmps\\drHouseScene\\drOHouse.bmp", WINSIZEX, WINSIZEY, false, true, RGB(255,0,255));
	_drO = IMAGEMANAGER->addFrameImage("���ڻ�", ".\\bmps\\drHouseScene\\drO.bmp", 68, 24, 4, 1, false, true, MAGENTA);

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
	IMAGEMANAGER->findImage("���ڻ��Ͽ콺")->render(getMemDC());
	IMAGEMANAGER->findImage("���ڻ�")->frameRender(getMemDC(), _x, _y);
	_player->render();
}