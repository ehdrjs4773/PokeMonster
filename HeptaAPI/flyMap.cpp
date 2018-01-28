#include "stdafx.h"
#include "flyMap.h"

flyMap::flyMap()
{
}
flyMap::~flyMap()
{

}

HRESULT flyMap::init()
{
	stageManager::init();
	_background = IMAGEMANAGER->addImage("�����", ".\\bmps\\map\\����.bmp", WINSIZEX, WINSIZEY, false, true, MAGENTA);
	_gymLeader = IMAGEMANAGER->addImage("����NPC", ".\\bmps\\map\\����NPC.bmp", 25, 28, false, true, MAGENTA);

	_player->setCurrentStage(7); //���� �������� ���� �Ѱ��ش�

	_x = WINSIZEX / 2 - 12;
	_y = 15;

	_gymLeaderRc = RectMakeCenter(_x, _y, _gymLeader->getFrameWidth(), _gymLeader->getFrameHeight());


	_isWin = false;

	return S_OK;
}
void flyMap::release()
{

}
void flyMap::update()
{
	stageManager::update();
	_gymLeaderRc = RectMakeCenter(_x, _y, _gymLeader->getFrameWidth(), _gymLeader->getFrameHeight());

	if (_player->getPlayerRc().top >= WINSIZEY)
	{
		SCENEMANAGER->changeScene("����ʾ�");
	}

}
void flyMap::render()
{
	IMAGEMANAGER->findImage("�����")->render(getMemDC());
	IMAGEMANAGER->findImage("����NPC")->render(getMemDC(), _x, _y);
	stageManager::render();
	//IMAGEMANAGER->findImage("npc")->frameRender(getMemDC(), _x, _y, 0, 0);
}