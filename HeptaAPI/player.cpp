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
	IMAGEMANAGER->addImage("textBox", ".\\bmps\\map\\UI\\textBox.bmp", 320, 66, false, true, MAGENTA);

	_player = IMAGEMANAGER->addFrameImage("골드", ".\\bmps\\player\\골드.bmp", 105, 104, 5, 4, false, true, RGB(255, 0, 255));
	//수테이지 픽셀충돌 이미지
	IMAGEMANAGER->addImage("픽셀충돌0", ".\\bmps\\map\\픽셀충돌0.bmp", 480, 360, false, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("픽셀충돌1", ".\\bmps\\map\\픽셀충돌1.bmp", 480, 360, false, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("픽셀충돌2", ".\\bmps\\map\\픽셀충돌2.bmp", 480, 360, false, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("픽셀충돌3", ".\\bmps\\map\\픽셀충돌3.bmp", 480, 360, false, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("픽셀충돌4", ".\\bmps\\map\\픽셀충돌4.bmp", 480, 360, false, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("픽셀충돌5", ".\\bmps\\map\\픽셀충돌5.bmp", 480, 360, false, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("픽셀충돌6", ".\\bmps\\map\\픽셀충돌6.bmp", 480, 360, false, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("픽셀충돌7", ".\\bmps\\map\\픽셀충돌7.bmp", 480, 360, false, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("픽셀충돌8", ".\\bmps\\map\\픽셀충돌8.bmp", 480, 360, false, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("픽셀충돌9", ".\\bmps\\map\\픽셀충돌9.bmp", 480, 360, false, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("픽셀충돌10", ".\\bmps\\map\\픽셀충돌10.bmp", 480, 360, false, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("픽셀충돌11", ".\\bmps\\map\\픽셀충돌11.bmp", 480, 360, false, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("픽셀충돌12", ".\\bmps\\map\\픽셀충돌12.bmp", 480, 360, false, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("픽셀충돌13", ".\\bmps\\map\\픽셀충돌13.bmp", 480, 360, false, true, RGB(255, 0, 255));

	_currentStage = 0;	//맨처음은 오박사집 픽셀이미지로 해둘게요 아마 이건 상관없을거에요

	_x = 240;		//플레이어 맨처음 있는 좌표
	_y = 340;		//플레이어 맨처음 있는 좌표
	

	_playerRc = RectMakeCenter(_x, _y, _player->getFrameWidth(), _player->getFrameHeight());

	

	_speed = 1.5f;

	_playerDirection = GOLD_BACK_STOP;

	int rightStop[] = { 0 };
	KEYANIMANAGER->addArrayFrameAnimation("오른쪽", "골드", rightStop, 1, 6, true);

	int leftStop[] = { 5 };
	KEYANIMANAGER->addArrayFrameAnimation("왼쪽", "골드", leftStop, 1, 6, true);

	int frontStop[] = { 10 };
	KEYANIMANAGER->addArrayFrameAnimation("앞", "골드", frontStop, 1, 6, true);

	int backStop[] = { 15 };
	KEYANIMANAGER->addArrayFrameAnimation("뒤", "골드", backStop, 1, 6, true);

	int rightMove[] = { 1, 2, 3, 4 };
	KEYANIMANAGER->addArrayFrameAnimation("오른쪽무브", "골드", rightMove, 4,10, true);

	int leftMove[] = { 6, 7, 8, 9 };
	KEYANIMANAGER->addArrayFrameAnimation("왼쪽무브", "골드", leftMove, 4, 10, true);

	int frontMove[] = { 11, 12, 13, 14 };
	KEYANIMANAGER->addArrayFrameAnimation("앞무브", "골드", frontMove, 4, 10, true);

	int backMove[] = { 16, 17, 18, 19 };
	KEYANIMANAGER->addArrayFrameAnimation("뒤무브", "골드", backMove, 4, 10, true);

	//화면 처음 모션은 뒤돌아보고있는 IDLE상태
	_playerMotion = KEYANIMANAGER->findAnimation("뒤");

	DATABASE->setVPlayerPokemon(&_vPokemon);

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
		_playerMotion = KEYANIMANAGER->findAnimation("오른쪽무브");
		_playerMotion->start();
	}
	if (KEYMANAGER->isOnceKeyUp(VK_RIGHT))
	{
		_playerDirection = GOLD_RIGHT_STOP;
		_playerMotion = KEYANIMANAGER->findAnimation("오른쪽");
		_playerMotion->start();
	}
	if (KEYMANAGER->isOnceKeyDown(VK_LEFT))
	{
		_playerDirection = GOLD_LEFT_MOVE;
		_playerMotion = KEYANIMANAGER->findAnimation("왼쪽무브");
		_playerMotion->start();
	}
	if (KEYMANAGER->isOnceKeyUp(VK_LEFT))
	{
		_playerDirection = GOLD_LEFT_STOP;
		_playerMotion = KEYANIMANAGER->findAnimation("왼쪽");
		_playerMotion->start();
	}
	if (KEYMANAGER->isOnceKeyDown(VK_UP))
	{
		_playerDirection = GOLD_BACK_MOVE;
		_playerMotion = KEYANIMANAGER->findAnimation("뒤무브");
		_playerMotion->start();
	}
	if (KEYMANAGER->isOnceKeyUp(VK_UP))
	{
		_playerDirection = GOLD_BACK_STOP;
		_playerMotion = KEYANIMANAGER->findAnimation("뒤");
		_playerMotion->start();
	}
	if (KEYMANAGER->isOnceKeyDown(VK_DOWN))
	{
		_playerDirection = GOLD_FRONT_MOVE;
		_playerMotion = KEYANIMANAGER->findAnimation("앞무브");
		_playerMotion->start();
	}
	if (KEYMANAGER->isOnceKeyUp(VK_DOWN))
	{
		_playerDirection = GOLD_FRONT_STOP;
		_playerMotion = KEYANIMANAGER->findAnimation("앞");
		_playerMotion->start();
	}

	//--------------------------------------------------------
	//픽셀충돌
	//--------------------------------------------------------

	_speed = 1.5f;

	char temp[32];
	sprintf(temp, "픽셀충돌%d", _currentStage);

	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		bool isProbe = false;
		//픽셀 오른쪽 탐색
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
		//픽셀 왼쪽 탐색
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
		//픽셀 위쪽 탐색
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
		//픽셀 아래쪽 탐색
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

	//-------------------- 이거 UI에요 ---------------------------
	if (KEYMANAGER->isOnceKeyDown('P'))
	{
		SCENEMANAGER->changeScene("UI");
		char tempStage[32];
		sprintf(tempStage, "스테이지%d", _currentStage);
		SCENEMANAGER->findScene("UI")->setDestScene(tempStage);
		SCENEMANAGER->init("UI");
		SCENEMANAGER->init("PokeInfo");
	}

}

//그리는거......
void player::render()
{
	_player->aniRender(getMemDC(), _playerRc.left, _playerRc.top, _playerMotion);
}

//void player::_rightStop(void* obj)
//{
//	player* k = (player*)obj;
//
//	k->setPlayerDirection(GOLD_RIGHT_STOP);
//	k->setPlayerMotion(KEYANIMANAGER->findAnimation("오른쪽"));
//	k->getPlayerMotion()->start();
//}
//void player::_leftStop(void* obj)
//{
//	player* k = (player*)obj;
//
//	k->setPlayerDirection(GOLD_LEFT_STOP);
//	k->setPlayerMotion(KEYANIMANAGER->findAnimation("왼쪽"));
//	k->getPlayerMotion()->start();
//}
//void player::_frontStop(void* obj)
//{
//	player* k = (player*)obj;
//
//	k->setPlayerDirection(GOLD_FRONT_STOP);
//	k->setPlayerMotion(KEYANIMANAGER->findAnimation("앞"));
//	k->getPlayerMotion()->start();
//}
//void player::_backStop(void* obj)
//{
//	player* k = (player*)obj;
//
//	k->setPlayerDirection(GOLD_BACK_STOP);
//	k->setPlayerMotion(KEYANIMANAGER->findAnimation("뒤"));
//	k->getPlayerMotion()->start();
//}