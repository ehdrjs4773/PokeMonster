#include "stdafx.h"
#include "normalMap.h"



normalMap::normalMap()
{
}


normalMap::~normalMap()
{
}

HRESULT normalMap::init()
{
	stageManager::init();
	_background = IMAGEMANAGER->addImage("노말맵", ".\\bmps\\map\\노말.bmp", 0, 0, WINSIZEX, WINSIZEY, false, true, MAGENTA);
	_gymLeader = IMAGEMANAGER->addImage("노말NPC", ".\\bmps\\map\\노말NPC.bmp", 25, 28, false, true, MAGENTA);
	_player->setCurrentStage(4); //현재 스테이지 정보 넘겨준다

	_x = WINSIZEX / 2 - 12;
	_y = 30;

	_gymLeaderRc = RectMakeCenter(_x, _y, _gymLeader->getFrameWidth(), _gymLeader->getFrameHeight());


	_isWin = false;
	return S_OK;
}

void normalMap::release()
{

}

void normalMap::update()
{
	stageManager::update();
	_gymLeaderRc = RectMakeCenter(_x, _y, _gymLeader->getFrameWidth(), _gymLeader->getFrameHeight());

	if (_player->getPlayerRc().top >= WINSIZEY)
	{
		SCENEMANAGER->changeScene("월드맵씬");
	}
}

void normalMap::render()
{
	IMAGEMANAGER->findImage("노말맵")->render(getMemDC());
	IMAGEMANAGER->findImage("노말NPC")->render(getMemDC(), _x, _y);
	stageManager::render();

}
