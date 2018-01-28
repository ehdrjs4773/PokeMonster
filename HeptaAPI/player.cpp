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
	//¼öÅ×ÀÌÁö ÇÈ¼¿Ãæµ¹ ÀÌ¹ÌÁö
	IMAGEMANAGER->addImage("ÇÈ¼¿Ãæµ¹0", ".\\bmps\\map\\ÇÈ¼¿Ãæµ¹0.bmp", 480, 360, false, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("ÇÈ¼¿Ãæµ¹1", ".\\bmps\\map\\ÇÈ¼¿Ãæµ¹1.bmp", 480, 360, false, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("ÇÈ¼¿Ãæµ¹2", ".\\bmps\\map\\ÇÈ¼¿Ãæµ¹2.bmp", 480, 360, false, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("ÇÈ¼¿Ãæµ¹3", ".\\bmps\\map\\ÇÈ¼¿Ãæµ¹3.bmp", 480, 360, false, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("ÇÈ¼¿Ãæµ¹4", ".\\bmps\\map\\ÇÈ¼¿Ãæµ¹4.bmp", 480, 360, false, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("ÇÈ¼¿Ãæµ¹5", ".\\bmps\\map\\ÇÈ¼¿Ãæµ¹5.bmp", 480, 360, false, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("ÇÈ¼¿Ãæµ¹6", ".\\bmps\\map\\ÇÈ¼¿Ãæµ¹6.bmp", 480, 360, false, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("ÇÈ¼¿Ãæµ¹7", ".\\bmps\\map\\ÇÈ¼¿Ãæµ¹7.bmp", 480, 360, false, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("ÇÈ¼¿Ãæµ¹8", ".\\bmps\\map\\ÇÈ¼¿Ãæµ¹8.bmp", 480, 360, false, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("ÇÈ¼¿Ãæµ¹9", ".\\bmps\\map\\ÇÈ¼¿Ãæµ¹9.bmp", 480, 360, false, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("ÇÈ¼¿Ãæµ¹10", ".\\bmps\\map\\ÇÈ¼¿Ãæµ¹10.bmp", 480, 360, false, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("ÇÈ¼¿Ãæµ¹11", ".\\bmps\\map\\ÇÈ¼¿Ãæµ¹11.bmp", 480, 360, false, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("ÇÈ¼¿Ãæµ¹12", ".\\bmps\\map\\ÇÈ¼¿Ãæµ¹12.bmp", 480, 360, false, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("ÇÈ¼¿Ãæµ¹13", ".\\bmps\\map\\ÇÈ¼¿Ãæµ¹13.bmp", 480, 360, false, true, RGB(255, 0, 255));

	_currentStage = 0;

	_x = 265;
	_y = 330;

	_playerRc = RectMakeCenter(_x, _y, _player->getFrameWidth(), _player->getFrameHeight());

	_speed = 1.5f;

	_playerDirection = GOLD_BACK_STOP;

	int rightStop[] = { 0 };
	KEYANIMANAGER->addArrayFrameAnimation("¿À¸¥ÂÊ", "°ñµå", rightStop, 1, 6, true);

	int leftStop[] = { 5 };
	KEYANIMANAGER->addArrayFrameAnimation("¿ÞÂÊ", "°ñµå", leftStop, 1, 6, true);

	int frontStop[] = { 10 };
	KEYANIMANAGER->addArrayFrameAnimation("¾Õ", "°ñµå", frontStop, 1, 6, true);

	int backStop[] = { 15 };
	KEYANIMANAGER->addArrayFrameAnimation("µÚ", "°ñµå", backStop, 1, 6, true);

	int rightMove[] = { 1, 2, 3, 4 };
	KEYANIMANAGER->addArrayFrameAnimation("¿À¸¥ÂÊ¹«ºê", "°ñµå", rightMove, 4,10, true);

	int leftMove[] = { 6, 7, 8, 9 };
	KEYANIMANAGER->addArrayFrameAnimation("¿ÞÂÊ¹«ºê", "°ñµå", leftMove, 4, 10, true);

	int frontMove[] = { 11, 12, 13, 14 };
	KEYANIMANAGER->addArrayFrameAnimation("¾Õ¹«ºê", "°ñµå", frontMove, 4, 10, true);

	int backMove[] = { 16, 17, 18, 19 };
	KEYANIMANAGER->addArrayFrameAnimation("µÚ¹«ºê", "°ñµå", backMove, 4, 10, true);

	//È­¸é Ã³À½ ¸ð¼ÇÀº µÚµ¹¾Æº¸°íÀÖ´Â IDLE»óÅÂ
	_playerMotion = KEYANIMANAGER->findAnimation("µÚ");

	SCENEMANAGER->init("UI");
	SCENEMANAGER->init("PokeInfo");
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
	if (KEYMANAGER->isOnceKeyUp(VK_RIGHT))
	{
		_playerDirection = GOLD_RIGHT_STOP;
		_playerMotion = KEYANIMANAGER->findAnimation("¿À¸¥ÂÊ");
		_playerMotion->start();
	}
	if (KEYMANAGER->isOnceKeyDown(VK_LEFT))
	{
		_playerDirection = GOLD_LEFT_MOVE;
		_playerMotion = KEYANIMANAGER->findAnimation("¿ÞÂÊ¹«ºê");
		_playerMotion->start();
	}
	if (KEYMANAGER->isOnceKeyUp(VK_LEFT))
	{
		_playerDirection = GOLD_LEFT_STOP;
		_playerMotion = KEYANIMANAGER->findAnimation("¿ÞÂÊ");
		_playerMotion->start();
	}
	if (KEYMANAGER->isOnceKeyDown(VK_UP))
	{
		_playerDirection = GOLD_BACK_MOVE;
		_playerMotion = KEYANIMANAGER->findAnimation("µÚ¹«ºê");
		_playerMotion->start();
	}
	if (KEYMANAGER->isOnceKeyUp(VK_UP))
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
	if (KEYMANAGER->isOnceKeyUp(VK_DOWN))
	{
		_playerDirection = GOLD_FRONT_STOP;
		_playerMotion = KEYANIMANAGER->findAnimation("¾Õ");
		_playerMotion->start();
	}

	//--------------------------------------------------------
	//ÇÈ¼¿Ãæµ¹
	//--------------------------------------------------------

	_speed = 1.5f;

	char temp[32];
	sprintf(temp, "ÇÈ¼¿Ãæµ¹%d", _currentStage);

	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		bool isProbe = false;
		//ÇÈ¼¿ ¿À¸¥ÂÊ Å½»ö
		for (int i = _playerRc.top; i < _playerRc.bottom && !isProbe; i += _player->getFrameHeight() / 3)
		{
			for (int j = _playerRc.right - 3; j <= _playerRc.right + 3; ++j)
			{
				COLORREF color = GetPixel(IMAGEMANAGER->findImage(temp)->getMemDC(), j, i);

				if (GetRValue(color) == 255 &&
					GetGValue(color) == 0 &&
					GetBValue(color) == 0)
				{
					_speed = 0.0f;
					_playerRc.right = j - _player->getFrameWidth() / 2;
					isProbe = true;
					break;
				}
			}
		}
	}

	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		bool isProbe = false;
		//ÇÈ¼¿ ¿ÞÂÊ Å½»ö
		for (int i = _playerRc.top; i < _playerRc.bottom && !isProbe; i += _player->getFrameHeight() / 2)
		{
			for (int j = _playerRc.left - 3; j <= _playerRc.left ; j++)
			{
				COLORREF color = GetPixel(IMAGEMANAGER->findImage(temp)->getMemDC(), j, i);

				if (GetRValue(color) == 255 &&
					GetGValue(color) == 0 &&
					GetBValue(color) == 0)
				{
					_speed = 0.0f;
					_playerRc.left = j + _player->getFrameWidth() / 2 ;
					isProbe = true;
					break;
				}
			}
		}
	}

	if (KEYMANAGER->isStayKeyDown(VK_UP))
	{
		bool isProbe = false;
		//ÇÈ¼¿ À§ÂÊ Å½»ö
		for (int i = _playerRc.left; i < _playerRc.right && !isProbe; i += _player->getFrameWidth() / 2)
		{
			for (int j = _playerRc.top - 3; j <= _playerRc.top; j++)
			{
				COLORREF color = GetPixel(IMAGEMANAGER->findImage(temp)->getMemDC(), i, j);

				if (GetRValue(color) == 255 &&
					GetGValue(color) == 0 &&
					GetBValue(color) == 0)
				{
					_speed = 0.0f;
					_playerRc.top = i + _player->getFrameHeight() / 2;
					isProbe = true;
					break;
				}
			}
		}
	}
	if (KEYMANAGER->isStayKeyDown(VK_DOWN))
	{
		bool isProbe = false;
		//ÇÈ¼¿ ¾Æ·¡ÂÊ Å½»ö
		for (int i = _playerRc.left; i < _playerRc.right && !isProbe; i += _player->getFrameWidth() / 2)
		{
			for (int j = _playerRc.bottom - 3; j <= _playerRc.bottom; j++)
			{
				COLORREF color = GetPixel(IMAGEMANAGER->findImage(temp)->getMemDC(), i, j);

				if (GetRValue(color) == 255 &&
					GetGValue(color) == 0 &&
					GetBValue(color) == 0)
				{
					_speed = 0.0f;
					_playerRc.bottom = i - _player->getFrameHeight() / 2;
					isProbe = true;
					break;
				}
			}
		}
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

	if (KEYMANAGER->isOnceKeyDown('P'))
	{
		SCENEMANAGER->changeScene("UI");
	}
}

void player::render()
{
	_player->aniRender(getMemDC(), _playerRc.left, _playerRc.top, _playerMotion);
}

//void player::_rightStop(void* obj)
//{
//	player* k = (player*)obj;
//
//	k->setPlayerDirection(GOLD_RIGHT_STOP);
//	k->setPlayerMotion(KEYANIMANAGER->findAnimation("¿À¸¥ÂÊ"));
//	k->getPlayerMotion()->start();
//}
//void player::_leftStop(void* obj)
//{
//	player* k = (player*)obj;
//
//	k->setPlayerDirection(GOLD_LEFT_STOP);
//	k->setPlayerMotion(KEYANIMANAGER->findAnimation("¿ÞÂÊ"));
//	k->getPlayerMotion()->start();
//}
//void player::_frontStop(void* obj)
//{
//	player* k = (player*)obj;
//
//	k->setPlayerDirection(GOLD_FRONT_STOP);
//	k->setPlayerMotion(KEYANIMANAGER->findAnimation("¾Õ"));
//	k->getPlayerMotion()->start();
//}
//void player::_backStop(void* obj)
//{
//	player* k = (player*)obj;
//
//	k->setPlayerDirection(GOLD_BACK_STOP);
//	k->setPlayerMotion(KEYANIMANAGER->findAnimation("µÚ"));
//	k->getPlayerMotion()->start();
//}