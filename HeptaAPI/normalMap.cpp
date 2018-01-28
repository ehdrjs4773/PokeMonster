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
	_background = IMAGEMANAGER->addImage("�븻��", ".\\bmps\\map\\�븻.bmp", 0, 0, WINSIZEX, WINSIZEY, false, true, MAGENTA);
	_gymLeader = IMAGEMANAGER->addImage("�븻NPC", ".\\bmps\\map\\�븻NPC.bmp", 25, 28, false, true, MAGENTA);
	_player->setCurrentStage(4); //���� �������� ���� �Ѱ��ش�

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
		SCENEMANAGER->changeScene("����ʾ�");
	}
}

void normalMap::render()
{
	IMAGEMANAGER->findImage("�븻��")->render(getMemDC());
	IMAGEMANAGER->findImage("�븻NPC")->render(getMemDC(), _x, _y);
	stageManager::render();

}
