#include "stdafx.h"
#include "stageManager.h"

stageManager::stageManager()
{
}
stageManager::~stageManager()
{
}


HRESULT stageManager::init()
{
	_gymLeader = IMAGEMANAGER->addFrameImage("npc", ".\\bmps\\map\\ÀÎ°ÔÀÓnpc.bmp", 325, 28, 13, 1, false, true, MAGENTA);
	_player = new player;
	_player->init();

	return S_OK;
}
void stageManager::release()
{

}
void stageManager::update()	
{
	_player->update();

}
void stageManager::render()	
{
	_player->render();

}