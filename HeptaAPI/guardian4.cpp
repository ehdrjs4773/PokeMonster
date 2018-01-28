#include "stdafx.h"
#include "guardian4.h"



guardian4::guardian4()
{
}


guardian4::~guardian4()
{
}

HRESULT guardian4::init()
{
	stageManager::init();
	_background = IMAGEMANAGER->addImage("»çÃµ¿Õ4¸Ê", ".\\bmps\\map\\»çÃµ¿Õ4_¾Ç.bmp", 0, 0, WINSIZEX, WINSIZEY, false, true, MAGENTA);
	_gymLeader = IMAGEMANAGER->addImage("»çÃµ¿Õ4_¾ÇNPC", ".\\bmps\\map\\»çÃµ¿Õ4_¾ÇNPC.bmp", 25, 28, false, true, MAGENTA);
	_player->setCurrentStage(12); //ÇöÀç ½ºÅ×ÀÌÁö Á¤º¸ ³Ñ°ÜÁØ´Ù

	_x = WINSIZEX / 2 - 17;
	_y = 60;

	_gymLeaderRc = RectMakeCenter(_x, _y, _gymLeader->getFrameWidth(), _gymLeader->getFrameHeight());


	_isWin = false;
	return S_OK;
}

void guardian4::release()
{

}

void guardian4::update()
{
	stageManager::update();
	_gymLeaderRc = RectMakeCenter(_x, _y, _gymLeader->getFrameWidth(), _gymLeader->getFrameHeight());
	if (_player->getPlayerRc().top >= WINSIZEY)
	{
		SCENEMANAGER->changeScene("½ºÅ×ÀÌÁö11");
		SCENEMANAGER->init("½ºÅ×ÀÌÁö11");
	}
	if (_player->getPlayerRc().bottom <= 0)
	{
		SCENEMANAGER->changeScene("¿ùµå¸Ê¾À");
		SCENEMANAGER->init("¿ùµå¸Ê¾À");
	}
}

void guardian4::render()
{
	IMAGEMANAGER->findImage("»çÃµ¿Õ4¸Ê")->render(getMemDC());
	IMAGEMANAGER->findImage("»çÃµ¿Õ4_NPC")->render(getMemDC(), _x, _y);
	stageManager::render();

}