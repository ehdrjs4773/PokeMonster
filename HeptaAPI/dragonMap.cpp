#include "stdafx.h"
#include "dragonMap.h"



dragonMap::dragonMap()
{
}


dragonMap::~dragonMap()
{
}

HRESULT dragonMap::init()
{
	stageManager::init();
	_background = IMAGEMANAGER->addImage("�巡���", ".\\bmps\\map\\�巡��.bmp", 0, 0, WINSIZEX, WINSIZEY, false, true, MAGENTA);
	_gymLeader = IMAGEMANAGER->addImage("�巡��NPC", ".\\bmps\\map\\�巡��NPC.bmp", 25, 28, false, true, MAGENTA);
	_player->setCurrentStage(5); //���� �������� ���� �Ѱ��ش�

	_x = WINSIZEX / 2;
	_y = 15;

	_gymLeaderRc = RectMakeCenter(_x, _y, _gymLeader->getFrameWidth(), _gymLeader->getFrameHeight());


	_isWin = false;

	return S_OK;
}

void dragonMap::release()
{

}

void dragonMap::update()
{
	stageManager::update();
	_gymLeaderRc = RectMakeCenter(_x, _y, _gymLeader->getFrameWidth(), _gymLeader->getFrameHeight());

	if (_player->getPlayerRc().top >= WINSIZEY)
	{
		SCENEMANAGER->changeScene("����ʾ�");
	}
}

void dragonMap::render()
{
	
	IMAGEMANAGER->findImage("�巡���")->render(getMemDC());
	IMAGEMANAGER->findImage("�巡��NPC")->render(getMemDC(), _x, _y);
	stageManager::render();
}