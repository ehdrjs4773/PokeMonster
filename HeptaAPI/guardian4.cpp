#include "stdafx.h"
#include "guardian4.h"



guardian4::guardian4()
{
}


guardian4::~guardian4()
{
}

HRESULT guardian4::init()
{
	stageManager::init();
	_background = IMAGEMANAGER->addImage("��õ��4��", ".\\bmps\\map\\��õ��4_��.bmp", 0, 0, WINSIZEX, WINSIZEY, false, true, MAGENTA);
	_gymLeader = IMAGEMANAGER->addImage("��õ��4_��NPC", ".\\bmps\\map\\��õ��4_��NPC.bmp", 25, 28, false, true, MAGENTA);
	_player->setCurrentStage(12); //���� �������� ���� �Ѱ��ش�

	_x = 227;
	_y = 90;

	_gymLeaderRc = RectMakeCenter(_x, _y, _gymLeader->getFrameWidth(), _gymLeader->getFrameHeight());


	if (SCENEMANAGER->getLastSceneName() == "��������13")
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

void guardian4::release()
{

}

void guardian4::update()
{
	stageManager::update();
	_gymLeaderRc = RectMakeCenter(_x, _y, _gymLeader->getFrameWidth(), _gymLeader->getFrameHeight());
	if (_player->getPlayerRc().top >= WINSIZEY)
	{
		SCENEMANAGER->changeScene("��������11");
		SCENEMANAGER->init("��������11");
	}
	if (_player->getPlayerRc().bottom <= 0)
	{
		SCENEMANAGER->changeScene("��������13");
		SCENEMANAGER->init("��������13");
	}
}

void guardian4::render()
{
	IMAGEMANAGER->findImage("��õ��4��")->render(getMemDC());
	IMAGEMANAGER->findImage("��õ��4_��NPC")->render(getMemDC(), _x, _y);
	stageManager::render();

}