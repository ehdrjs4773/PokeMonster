#include "stdafx.h"
#include "champion.h"



champion::champion()
{
}


champion::~champion()
{
}

HRESULT champion::init()
{
	stageManager::init();
	_background = IMAGEMANAGER->addImage("è�Ǿ��", ".\\bmps\\map\\è�Ǿ�.bmp", 0, 0, WINSIZEX, WINSIZEY, false, true, MAGENTA);
	_gymLeader = IMAGEMANAGER->addImage("è�Ǿ�NPC", ".\\bmps\\map\\è�Ǿ�NPC.bmp", 25, 28, false, true, MAGENTA);
	_player->setCurrentStage(13); //���� �������� ���� �Ѱ��ش�

	_x = 226;
	_y = 78;

	_gymLeaderRc = RectMakeCenter(_x, _y, _gymLeader->getFrameWidth(), _gymLeader->getFrameHeight());


	
	_isWin = false;

	return S_OK;
}

void champion::release()
{

}

void champion::update()
{
	stageManager::update();
	_gymLeaderRc = RectMakeCenter(_x, _y, _gymLeader->getFrameWidth(), _gymLeader->getFrameHeight());

	if (_player->getPlayerRc().top >= WINSIZEY)
	{
		SCENEMANAGER->changeScene("��������12");
		SCENEMANAGER->init("��������12");
	}
	

	if (_player->getPlayerRc().top >= WINSIZEY)
	{
		SCENEMANAGER->changeScene("��������12");
		SCENEMANAGER->init("��������12");
	}
	if (_player->getPlayerRc().top >= WINSIZEY && _isWin == true)
	{
		SCENEMANAGER->changeScene("����ʾ�");
		SCENEMANAGER->init("����ʾ�");
	}
}

void champion::render()
{

	IMAGEMANAGER->findImage("è�Ǿ��")->render(getMemDC());
	IMAGEMANAGER->findImage("è�Ǿ�NPC")->render(getMemDC(), _x, _y);
	stageManager::render();
}