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
	_background = IMAGEMANAGER->addImage("��õ��2��", ".\\bmps\\map\\��õ��2_��.bmp", 0, 0, WINSIZEX, WINSIZEY, false, true, MAGENTA);
	_gymLeader = IMAGEMANAGER->addImage("��õ��2_��NPC", ".\\bmps\\map\\��õ��2_��NPC.bmp", 25, 28, false, true, MAGENTA);
	_player->setCurrentStage(10); //���� �������� ���� �Ѱ��ش�

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
		SCENEMANAGER->changeScene("��������9");
		SCENEMANAGER->init("��������9");
	}
	if (_player->getPlayerRc().bottom <= 0)
	{
		SCENEMANAGER->changeScene("��������11");
		SCENEMANAGER->init("��������11");
	}
}

void guardian2::render()
{
	IMAGEMANAGER->findImage("��õ��2��")->render(getMemDC());
	IMAGEMANAGER->findImage("��õ��2_��NPC")->render(getMemDC(), _x, _y);
	stageManager::render();

}