#include "stdafx.h"
#include "iceMap.h"



iceMap::iceMap()
{
}


iceMap::~iceMap()
{
}

HRESULT iceMap::init()
{
	stageManager::init();

	_background = IMAGEMANAGER->addImage("얼음맵", ".\\bmps\\map\\얼음.bmp", 0, 0, WINSIZEX, WINSIZEY, false, true, MAGENTA);
	_gymLeader = IMAGEMANAGER->addImage("얼음NPC", ".\\bmps\\map\\얼음NPC.bmp", 25, 28, false, true, MAGENTA);
	_player->setCurrentStage(8); //현재 스테이지 정보 넘겨준다

	_x = WINSIZEX / 2 - 12;
	_y = 15;

	_gymLeaderRc = RectMakeCenter(_x, _y, _gymLeader->getFrameWidth(), _gymLeader->getFrameHeight());


	_isWin = false;
	return S_OK;
}

void iceMap::release()
{

}

void iceMap::update()
{
	stageManager::update();
	_gymLeaderRc = RectMakeCenter(_x, _y, _gymLeader->getFrameWidth(), _gymLeader->getFrameHeight());

	if (_player->getPlayerRc().top >= WINSIZEY)
	{
		SCENEMANAGER->changeScene("월드맵씬");
	}
}

void iceMap::render()
{
	
	IMAGEMANAGER->findImage("얼음맵")->render(getMemDC());
	IMAGEMANAGER->findImage("얼음NPC")->render(getMemDC(), _x, _y);
	stageManager::render();
}

