#include "stdafx.h"
#include "stageManager.h"
#include "player.h"

stageManager::stageManager()
	: _player(NULL)
{
}
stageManager::~stageManager()
{
}


HRESULT stageManager::init()
{
	_gymLeader = IMAGEMANAGER->addFrameImage("npc", ".\\bmps\\map\\ÀÎ°ÔÀÓnpc.bmp", 325, 28, 13, 1, false, true, MAGENTA);
	this->setPlayerAddressLink(DATABASE->getPlayerMemory());
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