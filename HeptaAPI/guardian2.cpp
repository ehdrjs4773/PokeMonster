#include "stdafx.h"
#include "guardian2.h"



guardian2::guardian2()
{
}


guardian2::~guardian2()
{
}

HRESULT guardian2::init()
{
	stageManager::init();
	_background = IMAGEMANAGER->addImage("사천왕2맵", ".\\bmps\\map\\사천왕2_독.bmp", 0, 0, WINSIZEX, WINSIZEY, false, true, MAGENTA);
	_gymLeader = IMAGEMANAGER->addImage("사천왕2_독NPC", ".\\bmps\\map\\사천왕2_독NPC.bmp", 25, 28, false, true, MAGENTA);
	_player->setCurrentStage(10); //현재 스테이지 정보 넘겨준다

	_x = WINSIZEX / 2 - 14;
	_y = 50;

	_gymLeaderRc = RectMakeCenter(_x, _y, _gymLeader->getFrameWidth(), _gymLeader->getFrameHeight());

	
	_isWin = false;
	return S_OK;
}

void guardian2::release()
{

}

void guardian2::update()
{
	stageManager::update();
	_gymLeaderRc = RectMakeCenter(_x, _y, _gymLeader->getFrameWidth(), _gymLeader->getFrameHeight());

	if (_player->getPlayerRc().top >= WINSIZEY)
	{
		SCENEMANAGER->changeScene("스테이지9");
		SCENEMANAGER->init("스테이지9");
	}
	if (_player->getPlayerRc().bottom <= 0)
	{
		SCENEMANAGER->changeScene("스테이지11");
		SCENEMANAGER->init("스테이지11");
	}
}

void guardian2::render()
{
	IMAGEMANAGER->findImage("사천왕2맵")->render(getMemDC());
	IMAGEMANAGER->findImage("사천왕2_독NPC")->render(getMemDC(), _x, _y);
	stageManager::render();

}