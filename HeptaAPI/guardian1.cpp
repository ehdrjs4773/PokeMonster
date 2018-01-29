#include "stdafx.h"
#include "guardian1.h"



guardian1::guardian1()
{
}


guardian1::~guardian1()
{

}

HRESULT guardian1::init()
{
	stageManager::init();
	_background = IMAGEMANAGER->addImage("��õ��1��", ".\\bmps\\map\\��õ��1_����.bmp", 0, 0, WINSIZEX, WINSIZEY, false, true, MAGENTA);
	_gymLeader = IMAGEMANAGER->addImage("��õ��1_����NPC", ".\\bmps\\map\\��õ��1_����NPC.bmp", 25, 28, false, true, MAGENTA);
	_player->setCurrentStage(9); //���� �������� ���� �Ѱ��ش�

	_x = WINSIZEX / 2 - 13;
	_y = 60;

	_gymLeaderRc = RectMakeCenter(_x, _y, _gymLeader->getFrameWidth(), _gymLeader->getFrameHeight());


	if (SCENEMANAGER->getLastSceneName() == "��������10")
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

void guardian1::release()
{

}

void guardian1::update()
{
	stageManager::update();
	_gymLeaderRc = RectMakeCenter(_x, _y, _gymLeader->getFrameWidth(), _gymLeader->getFrameHeight());

	if (_player->getPlayerRc().top >= WINSIZEY)
	{
		SCENEMANAGER->changeScene("����ʾ�");
		SCENEMANAGER->init("����ʾ�");
	}

	if (_player->getPlayerRc().bottom < -10)
	{
		SCENEMANAGER->changeScene("��������10");
		SCENEMANAGER->init("��������10");
	
	}
}

void guardian1::render()
{
	IMAGEMANAGER->findImage("��õ��1��")->render(getMemDC());
	IMAGEMANAGER->findImage("��õ��1_����NPC")->render(getMemDC(), _x, _y);
	stageManager::render();

}
