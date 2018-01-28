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
	_background = IMAGEMANAGER->addImage("��Ʈ��", ".\\bmps\\map\\��Ʈ.bmp", 0, 0, WINSIZEX, WINSIZEY, false, true, MAGENTA);
	_gymLeader = IMAGEMANAGER->addImage("��ƮNPC", ".\\bmps\\map\\��ƮNPC.bmp", 25, 28, false, true, MAGENTA);
	_player->setCurrentStage(3); //���� �������� ���� �Ѱ��ش�

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
		SCENEMANAGER->changeScene("����ʾ�");
	}
}

void ghostMap::render()
{
	
	IMAGEMANAGER->findImage("��Ʈ��")->render(getMemDC());
	IMAGEMANAGER->findImage("��ƮNPC")->render(getMemDC(), _x, _y);
	stageManager::render();

}


