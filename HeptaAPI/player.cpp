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

	_speed = 1.5f;

	_playerDirection = GOLD_BACK_STOP;

	int rightStop[] = { 0 };
	KEYANIMANAGER->addArrayFrameAnimation("¿À¸¥ÂÊ", "°ñµå", rightStop, 1, 6, true);

	int leftStop[] = { 5 };
	KEYANIMANAGER->addArrayFrameAnimation("¿ŞÂÊ", "°ñµå", leftStop, 1, 6, true);

	int frontStop[] = { 10 };
	KEYANIMANAGER->addArrayFrameAnimation("¾Õ", "°ñµå", frontStop, 1, 6, true);

	int backStop[] = { 15 };
	KEYANIMANAGER->addArrayFrameAnimation("µÚ", "°ñµå", backStop, 1, 6, true);

	int rightMove[] = { 1, 2, 3, 4 };
	KEYANIMANAGER->addArrayFrameAnimation("¿À¸¥ÂÊ¹«ºê", "°ñµå", rightMove, 4,10, true);

	int leftMove[] = { 6, 7, 8, 9 };
	KEYANIMANAGER->addArrayFrameAnimation("¿ŞÂÊ¹«ºê", "°ñµå", leftMove, 4, 10, true);

	int frontMove[] = { 11, 12, 13, 14 };
	KEYANIMANAGER->addArrayFrameAnimation("¾Õ¹«ºê", "°ñµå", frontMove, 4, 10, true);

	int backMove[] = { 16, 17, 18, 19 };
	KEYANIMANAGER->addArrayFrameAnimation("µÚ¹«ºê", "°ñµå", backMove, 4, 10, true);

	//È­¸é Ã³À½ ¸ğ¼ÇÀº µÚµ¹¾Æº¸°íÀÖ´Â IDLE»óÅÂ
	_playerMotion = KEYANIMANAGER->findAnimation("µÚ");

	return S_OK;
}
void player::release()
{
}
void player::update()
{
	if (KEYMANAGER->isOnceKeyDown(VK_RIGHT))
	{
		_playerDirection = GOLD_RIGHT_MOVE;
		_playerMotion = KEYANIMANAGER->findAnimation("¿À¸¥ÂÊ¹«ºê");
		_playerMotion->start();
	}
	else if (KEYMANAGER->isOnceKeyUp(VK_RIGHT))
	{
		_playerDirection = GOLD_RIGHT_STOP;
		_playerMotion = KEYANIMANAGER->findAnimation("¿À¸¥ÂÊ");
		_playerMotion->start();
	}
	if (KEYMANAGER->isOnceKeyDown(VK_LEFT))
	{
		_playerDirection = GOLD_LEFT_MOVE;
		_playerMotion = KEYANIMANAGER->findAnimation("¿ŞÂÊ¹«ºê");
		_playerMotion->start();
	}
	else if (KEYMANAGER->isOnceKeyUp(VK_LEFT))
	{
		_playerDirection = GOLD_LEFT_STOP;
		_playerMotion = KEYANIMANAGER->findAnimation("¿ŞÂÊ");
		_playerMotion->start();
	}
	if (KEYMANAGER->isOnceKeyDown(VK_UP))
	{
		_playerDirection = GOLD_BACK_MOVE;
		_playerMotion = KEYANIMANAGER->findAnimation("µÚ¹«ºê");
		_playerMotion->start();
	}
	else if (KEYMANAGER->isOnceKeyUp(VK_UP))
	{
		_playerDirection = GOLD_BACK_STOP;
		_playerMotion = KEYANIMANAGER->findAnimation("µÚ");
		_playerMotion->start();
	}
	if (KEYMANAGER->isOnceKeyDown(VK_DOWN))
	{
		_playerDirection = GOLD_FRONT_MOVE;
		_playerMotion = KEYANIMANAGER->findAnimation("¾Õ¹«ºê");
		_playerMotion->start();
	}
	else if (KEYMANAGER->isOnceKeyUp(VK_DOWN))
	{
		_playerDirection = GOLD_FRONT_STOP;
		_playerMotion = KEYANIMANAGER->findAnimation("¾Õ");
		_playerMotion->start();
	}


	switch(_playerDirection)
	{
	case GOLD_RIGHT_STOP:
		_playerRc = RectMakeCenter(_x, _y, _player->getFrameWidth(), _player->getFrameHeight());
		break;
	case GOLD_LEFT_STOP:
		_playerRc = RectMakeCenter(_x, _y, _player->getFrameWidth(), _player->getFrameHeight());
		break;
	case GOLD_FRONT_STOP:
		_playerRc = RectMakeCenter(_x, _y, _player->getFrameWidth(), _player->getFrameHeight());
		break;
	case GOLD_BACK_STOP:
		_playerRc = RectMakeCenter(_x, _y, _player->getFrameWidth(), _player->getFrameHeight());
		break;

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

void player::_rightStop(void* obj)
{
	player* k = (player*)obj;

	k->setPlayerDirection(GOLD_RIGHT_STOP);
	k->setPlayerMotion(KEYANIMANAGER->findAnimation("¿À¸¥ÂÊ"));
	k->getPlayerMotion()->start();
}
void player::_leftStop(void* obj)
{
	player* k = (player*)obj;

	k->setPlayerDirection(GOLD_LEFT_STOP);
	k->setPlayerMotion(KEYANIMANAGER->findAnimation("¿ŞÂÊ"));
	k->getPlayerMotion()->start();
}
void player::_frontStop(void* obj)
{
	player* k = (player*)obj;

	k->setPlayerDirection(GOLD_FRONT_STOP);
	k->setPlayerMotion(KEYANIMANAGER->findAnimation("¾Õ"));
	k->getPlayerMotion()->start();
}
void player::_backStop(void* obj)
{
	player* k = (player*)obj;

	k->setPlayerDirection(GOLD_BACK_STOP);
	k->setPlayerMotion(KEYANIMANAGER->findAnimation("µÚ"));
	k->getPlayerMotion()->start();
}