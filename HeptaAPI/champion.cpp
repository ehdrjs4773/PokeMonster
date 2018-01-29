#include "stdafx.h"
#include "champion.h"



champion::champion()
{
}


champion::~champion()
{
}

HRESULT champion::init()
{
	stageManager::init();
	_background = IMAGEMANAGER->addImage("Ã¨ÇÇ¾ğ¸Ê", ".\\bmps\\map\\Ã¨ÇÇ¾ğ.bmp", 0, 0, WINSIZEX, WINSIZEY, false, true, MAGENTA);
	_gymLeader = IMAGEMANAGER->addImage("Ã¨ÇÇ¾ğNPC", ".\\bmps\\map\\Ã¨ÇÇ¾ğNPC.bmp", 25, 28, false, true, MAGENTA);
	_player->setCurrentStage(13); //ÇöÀç ½ºÅ×ÀÌÁö Á¤º¸ ³Ñ°ÜÁØ´Ù

	_x = 226;
	_y = 78;

	_gymLeaderRc = RectMakeCenter(_x, _y, _gymLeader->getFrameWidth(), _gymLeader->getFrameHeight());


	
	_isWin = false;

	return S_OK;
}

void champion::release()
{

}

void champion::update()
{
	stageManager::update();
	_gymLeaderRc = RectMakeCenter(_x, _y, _gymLeader->getFrameWidth(), _gymLeader->getFrameHeight());

	if (_player->getPlayerRc().top >= WINSIZEY)
	{
		SCENEMANAGER->changeScene("½ºÅ×ÀÌÁö12");
		SCENEMANAGER->init("½ºÅ×ÀÌÁö12");
	}
	

	if (_player->getPlayerRc().top >= WINSIZEY)
	{
		SCENEMANAGER->changeScene("½ºÅ×ÀÌÁö12");
		SCENEMANAGER->init("½ºÅ×ÀÌÁö12");
	}
	if (_player->getPlayerRc().top >= WINSIZEY && _isWin == true)
	{
		SCENEMANAGER->changeScene("¿ùµå¸Ê¾À");
		SCENEMANAGER->init("¿ùµå¸Ê¾À");
	}
}

void champion::render()
{

	IMAGEMANAGER->findImage("Ã¨ÇÇ¾ğ¸Ê")->render(getMemDC());
	IMAGEMANAGER->findImage("Ã¨ÇÇ¾ğNPC")->render(getMemDC(), _x, _y);
	stageManager::render();
}