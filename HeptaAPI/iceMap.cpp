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

	_background = IMAGEMANAGER->addImage("������", ".\\bmps\\map\\����.bmp", 0, 0, WINSIZEX, WINSIZEY, false, true, MAGENTA);
	_gymLeader = IMAGEMANAGER->addImage("����NPC", ".\\bmps\\map\\����NPC.bmp", 25, 28, false, true, MAGENTA);
	_player->setCurrentStage(8); //���� �������� ���� �Ѱ��ش�

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
		SCENEMANAGER->changeScene("����ʾ�");
	}
}

void iceMap::render()
{
	
	IMAGEMANAGER->findImage("������")->render(getMemDC());
	IMAGEMANAGER->findImage("����NPC")->render(getMemDC(), _x, _y);
	stageManager::render();
}

