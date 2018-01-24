#include "stdafx.h"
#include "player.h"

player::player()
{
}


player::~player()
{
}

HRESULT player::init()
{
	_player = IMAGEMANAGER->addFrameImage("°ñµå", "°ñµå.bmp", 105, 104, 5, 4, false, true, RGB(255, 0, 255));
	_x = 265;
	_y = 330;
	_playerRc = RectMakeCenter(_x, _y, _player->getFrameWidth(), _player->getFrameHeight());
	_speed = 0.5f;
	_playerDirection = GOLD_BACK_IDLE;

	int rightStop[] = { 0 };
	KEYANIMANAGER->addArrayFrameAnimation("playerRightStop", "°ñµå", rightStop, 1, 6, true);


	return S_OK;
}
void player::release()
{
}
void player::update()
{
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{

	}

	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
	
	}

	if (KEYMANAGER->isStayKeyDown(VK_UP))
	{

	}
	if (KEYMANAGER->isStayKeyDown(VK_DOWN))
	{

	}
	_playerRc = RectMakeCenter(_x, _y, _player->getFrameWidth(), _player->getFrameHeight());
}
void player::render()
{
}