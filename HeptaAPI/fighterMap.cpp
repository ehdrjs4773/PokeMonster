#include "stdafx.h"
#include "fighterMap.h"
fighterMap::fighterMap()

{
}
fighterMap::~fighterMap()
{
}

HRESULT fighterMap::init()
{
	stageManager::init();
	_background = IMAGEMANAGER->addImage("°ÝÅõ¸Ê", ".\\bmps\\map\\°ÝÅõ¸Ê.bmp", WINSIZEX, WINSIZEY, false, true, MAGENTA);
	_gymLeader = IMAGEMANAGER->addImage("°ÝÅõNPC", ".\\bmps\\map\\°ÝÅõNPC.bmp", 25, 28, false, true, MAGENTA);

	_player->setCurrentStage(2);

	_x = WINSIZEX / 2 - 17;
	_y = 15;

	_gymLeaderRc = RectMakeCenter(_x, _y, _gymLeader->getFrameWidth(), _gymLeader->getFrameHeight());

	_isWin = false;

	return S_OK;
}
void fighterMap::release()
{

}
void fighterMap::update()
{
	stageManager::update();
	_gymLeaderRc = RectMakeCenter(_x, _y, _gymLeader->getFrameWidth(), _gymLeader->getFrameHeight());

	if (_player->getPlayerRc().top >= WINSIZEY)
	{
		SCENEMANAGER->changeScene("¿ùµå¸Ê¾À");
	}

}
void fighterMap::render()
{
	IMAGEMANAGER->findImage("°ÝÅõ¸Ê")->render(getMemDC());
	IMAGEMANAGER->findImage("°ÝÅõNPC")->render(getMemDC(), _x, _y);
	stageManager::render();
	//IMAGEMANAGER->findImage("npc")->frameRender(getMemDC(), _x, _y, 4, 0);
}