#include "stdafx.h"
#include "steelMap.h"



steelMap::steelMap()
{
}


steelMap::~steelMap()
{
}

HRESULT steelMap::init()
{
	stageManager::init();
	_background = IMAGEMANAGER->addImage("��ö��", ".\\bmps\\map\\��ö.bmp", 0, 0, WINSIZEX, WINSIZEY, false, true, MAGENTA);
	_gymLeader = IMAGEMANAGER->addImage("��öNPC", ".\\bmps\\map\\��öNPC.bmp", 25, 28, false, true, MAGENTA);
	_player->setCurrentStage(1); //���� �������� ���� �Ѱ��ش�

	_x = WINSIZEX / 2 - 12;
	_y = 15;

	_gymLeaderRc = RectMakeCenter(_x, _y, _gymLeader->getFrameWidth(), _gymLeader->getFrameHeight());


	_isWin = false;
	return S_OK;
}

void steelMap::release()
{

}

void steelMap::update()	
{
	stageManager::update();
	_gymLeaderRc = RectMakeCenter(_x, _y, _gymLeader->getFrameWidth(), _gymLeader->getFrameHeight());

	if (_player->getPlayerRc().top >= WINSIZEY)
	{
		SCENEMANAGER->changeScene("����ʾ�");
	}
}

void steelMap::render()	
{
	IMAGEMANAGER->findImage("��ö��")->render(getMemDC());
	IMAGEMANAGER->findImage("��öNPC")->render(getMemDC(),_x,_y);
	stageManager::render();

}
