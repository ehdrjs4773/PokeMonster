#include "stdafx.h"
#include "guardian3.h"



guardian3::guardian3()
{
}


guardian3::~guardian3()
{
}

HRESULT guardian3::init()
{
	stageManager::init();
	_background = IMAGEMANAGER->addImage("��õ��3��", ".\\bmps\\map\\��õ��3_������.bmp", 0, 0, WINSIZEX, WINSIZEY, false, true, MAGENTA);
	_gymLeader = IMAGEMANAGER->addImage("��õ��3_������NPC", ".\\bmps\\map\\��õ��3_������NPC.bmp", 25, 28, false, true, MAGENTA);
	_player->setCurrentStage(11); //���� �������� ���� �Ѱ��ش�

	_x = WINSIZEX / 2 - 12;
	_y = 25;

	_gymLeaderRc = RectMakeCenter(_x, _y, _gymLeader->getFrameWidth(), _gymLeader->getFrameHeight());

	if (SCENEMANAGER->getLastSceneName() == "��������12")
	{
		_player->setPlayerPt(PointMake(240, 0));
	}
	else
	{
		_player->setPlayerPt(PointMake(240, 340));
	}
	_isWin = false;
	return S_OK;
}

void guardian3::release()
{

}

void guardian3::update()
{
	stageManager::update();
	_gymLeaderRc = RectMakeCenter(_x, _y, _gymLeader->getFrameWidth(), _gymLeader->getFrameHeight());

	if (_player->getPlayerRc().top >= WINSIZEY)
	{
		SCENEMANAGER->changeScene("��������10");
		SCENEMANAGER->init("��������10");
	}
	if (_player->getPlayerRc().bottom <= 0)
	{
		SCENEMANAGER->changeScene("��������12");
		SCENEMANAGER->init("��������12");
	}
}

void guardian3::render()
{
	IMAGEMANAGER->findImage("��õ��3��")->render(getMemDC());
	IMAGEMANAGER->findImage("��õ��3_������NPC")->render(getMemDC(), _x, _y);
	stageManager::render();

}