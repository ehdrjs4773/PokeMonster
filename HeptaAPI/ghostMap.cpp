#include "stdafx.h"
#include "ghostMap.h"



ghostMap::ghostMap()
{
}


ghostMap::~ghostMap()
{
}

HRESULT ghostMap::init()
{
	stageManager::init();
	_background = IMAGEMANAGER->addImage("고스트맵", ".\\bmps\\map\\고스트.bmp", 0, 0, WINSIZEX, WINSIZEY, false, true, MAGENTA);
	_gymLeader = IMAGEMANAGER->addImage("고스트NPC", ".\\bmps\\map\\고스트NPC.bmp", 25, 28, false, true, MAGENTA);
	_player->setCurrentStage(3); //현재 스테이지 정보 넘겨준다

	_x = WINSIZEX / 2 - 17;
	_y = 60;

	_gymLeaderRc = RectMakeCenter(_x, _y, _gymLeader->getFrameWidth(), _gymLeader->getFrameHeight());


	_isWin = false;
	return S_OK;
}

void ghostMap::release()
{

}

void ghostMap::update()
{
	stageManager::update();
	_gymLeaderRc = RectMakeCenter(_x, _y, _gymLeader->getFrameWidth(), _gymLeader->getFrameHeight());

	if (_player->getPlayerRc().top >= WINSIZEY)
	{
		SCENEMANAGER->changeScene("월드맵씬");
	}
}

void ghostMap::render()
{
	
	IMAGEMANAGER->findImage("고스트맵")->render(getMemDC());
	IMAGEMANAGER->findImage("고스트NPC")->render(getMemDC(), _x, _y);
	stageManager::render();

}


