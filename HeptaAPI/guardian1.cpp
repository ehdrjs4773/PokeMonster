#include "stdafx.h"
#include "guardian1.h"



guardian1::guardian1()
{
}


guardian1::~guardian1()
{

}

HRESULT guardian1::init()
{
	stageManager::init();
	_background = IMAGEMANAGER->addImage("»çÃµ¿Õ1¸Ê", ".\\bmps\\map\\»çÃµ¿Õ1_°İÅõ.bmp", 0, 0, WINSIZEX, WINSIZEY, false, true, MAGENTA);
	_gymLeader = IMAGEMANAGER->addImage("»çÃµ¿Õ1_°İÅõNPC", ".\\bmps\\map\\»çÃµ¿Õ1_°İÅõNPC.bmp", 25, 28, false, true, MAGENTA);
	_player->setCurrentStage(9); //ÇöÀç ½ºÅ×ÀÌÁö Á¤º¸ ³Ñ°ÜÁØ´Ù

	_x = WINSIZEX / 2 - 13;
	_y = 60;

	_gymLeaderRc = RectMakeCenter(_x, _y, _gymLeader->getFrameWidth(), _gymLeader->getFrameHeight());


	if (SCENEMANAGER->getLastSceneName() == "½ºÅ×ÀÌÁö10")
	{
		_player->setPlayerPt(PointMake(240, 0));
	}
	else
	{
		_player->setPlayerPt(PointMake(240, 340));
	}

	
	_isWin = false;
	


	
	return S_OK;


}

void guardian1::release()
{

}

void guardian1::update()
{
	stageManager::update();
	_gymLeaderRc = RectMakeCenter(_x, _y, _gymLeader->getFrameWidth(), _gymLeader->getFrameHeight());

	if (_player->getPlayerRc().top >= WINSIZEY)
	{
		SCENEMANAGER->changeScene("¿ùµå¸Ê¾À");
		SCENEMANAGER->init("¿ùµå¸Ê¾À");
	}

	if (_player->getPlayerRc().bottom < -10)
	{
		SCENEMANAGER->changeScene("½ºÅ×ÀÌÁö10");
		SCENEMANAGER->init("½ºÅ×ÀÌÁö10");
	
	}
}

void guardian1::render()
{
	IMAGEMANAGER->findImage("»çÃµ¿Õ1¸Ê")->render(getMemDC());
	IMAGEMANAGER->findImage("»çÃµ¿Õ1_°İÅõNPC")->render(getMemDC(), _x, _y);
	stageManager::render();

}
