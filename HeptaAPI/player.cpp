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
	_player = IMAGEMANAGER->addFrameImage("°ñµå", ".\\bmps\\player\\°ñµå.bmp", 105, 104, 5, 4, false, true, RGB(255, 0, 255));

	_x = 265;
	_y = 330;

	_playerRc = RectMakeCenter(_x, _y, _player->getFrameWidth(), _player->getFrameHeight());

	_speed = 0.5f;

	_playerDirection = GOLD_BACK_STOP;

	int rightStop[] = { 0 };
	KEYANIMANAGER->addArrayFrameAnimation("playerRightStop", "°ñµå", rightStop, 1, 6, true);

	int leftStop[] = { 5 };
	KEYANIMANAGER->addArrayFrameAnimation("playerLeftStop", "°ñµå", leftStop, 1, 6, true);

	int frontStop[] = { 10 };
	KEYANIMANAGER->addArrayFrameAnimation("playerFrontStop", "°ñµå", frontStop, 1, 6, true);

	int backStop[] = { 15 };
	KEYANIMANAGER->addArrayFrameAnimation("playerBackStop", "°ñµå", backStop, 1, 6, true);

	int rightMove[] = { 1, 2, 3, 4 };
	KEYANIMANAGER->addArrayFrameAnimation("playerRightMove", "°ñµå", rightMove, 4, 10, true);

	int leftMove[] = { 6, 7, 8, 9 };
	KEYANIMANAGER->addArrayFrameAnimation("playerleftMove", "°ñµå", leftMove, 4, 10, true);

	int frontMove[] = { 11, 12, 13, 14 };
	KEYANIMANAGER->addArrayFrameAnimation("playerFrontMove", "°ñµå", frontMove, 4, 10, true);

	int backMove[] = { 16, 17, 18, 19 };
	KEYANIMANAGER->addArrayFrameAnimation("playerBackMove", "°ñµå", backMove, 4, 10, true);

	//È­¸é Ã³À½ ¸ğ¼ÇÀº µÚµ¹¾Æº¸°íÀÖ´Â IDLE»óÅÂ
	_playerMotion = KEYANIMANAGER->findAnimation("playerBackStop");

	return S_OK;
}
void player::release()
{
}
void player::update()
{
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		_playerDirection = GOLD_RIGHT_MOVE;
		_playerMotion = KEYANIMANAGER->findAnimation("playerRightMove");
		_playerMotion->start();
	}

	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		_playerDirection = GOLD_LEFT_MOVE;
		_playerMotion = KEYANIMANAGER->findAnimation("playerLeftMove");
		_playerMotion->start();
	}

	if (KEYMANAGER->isStayKeyDown(VK_UP))
	{
		_playerDirection = GOLD_BACK_MOVE;
		_playerMotion = KEYANIMANAGER->findAnimation("playerBackMove");
		_playerMotion->start();
	}
	if (KEYMANAGER->isStayKeyDown(VK_DOWN))
	{
		_playerDirection = GOLD_FRONT_MOVE;
		_playerMotion = KEYANIMANAGER->findAnimation("playerFrontMove");
		_playerMotion->start();
	}
	switch(_playerDirection)
	{
	case GOLD_RIGHT_MOVE:

		_x += _speed;

		_playerRc = RectMakeCenter(_x, _y, _player->getFrameWidth(), _player->getFrameHeight());

		break;
	case GOLD_LEFT_MOVE:

		_x -= _speed;

		_playerRc = RectMakeCenter(_x, _y, _player->getFrameWidth(), _player->getFrameHeight());
		break;
	case GOLD_BACK_MOVE:

		_y -= _speed;

		_playerRc = RectMakeCenter(_x, _y, _player->getFrameWidth(), _player->getFrameHeight());
		break;
	case GOLD_FRONT_MOVE:

		_y += _speed;

		_playerRc = RectMakeCenter(_x, _y, _player->getFrameWidth(), _player->getFrameHeight());
		break;
	}
	KEYANIMANAGER->update();
	//_playerRc = RectMakeCenter(_x, _y, _player->getFrameWidth(), _player->getFrameHeight());
}
void player::render()
{
	_player->aniRender(getMemDC(), _playerRc.left, _playerRc.top, _playerMotion);
}

void player::rightStop(void* obj)
{
	player* k = (player*)obj;

	k->setPlayerDirection(GOLD_RIGHT_STOP);
	k->setPlayerMotion(KEYANIMANAGER->findAnimation("playerRightStop"));
	k->getPlayerMotion()->start();
}
void player::leftStop(void* obj)
{
	player* k = (player*)obj;

	k->setPlayerDirection(GOLD_LEFT_STOP);
	k->setPlayerMotion(KEYANIMANAGER->findAnimation("playerLeftStop"));
	k->getPlayerMotion()->start();
}
void player::frontStop(void* obj)
{
	player* k = (player*)obj;

	k->setPlayerDirection(GOLD_FRONT_STOP);
	k->setPlayerMotion(KEYANIMANAGER->findAnimation("playerFrontStop"));
	k->getPlayerMotion()->start();
}
void player::backStop(void* obj)
{
	player* k = (player*)obj;

	k->setPlayerDirection(GOLD_BACK_STOP);
	k->setPlayerMotion(KEYANIMANAGER->findAnimation("playerBackStop"));
	k->getPlayerMotion()->start();
}