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
	_player = IMAGEMANAGER->addFrameImage("���", ".\\bmps\\player\\���.bmp", 105, 104, 5, 4, false, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("���ڻ��ȼ��浹", ".\\bmps\\drHouseScene\\drOHousePixel.bmp", 480, 360, false, true, RGB(255, 0, 255));

	_x = 265;
	_y = 330;

	_playerRc = RectMakeCenter(_x, _y, _player->getFrameWidth(), _player->getFrameHeight());

	_speed = 1.5f;

	_playerDirection = GOLD_BACK_STOP;

	int rightStop[] = { 0 };
	KEYANIMANAGER->addArrayFrameAnimation("������", "���", rightStop, 1, 6, true);

	int leftStop[] = { 5 };
	KEYANIMANAGER->addArrayFrameAnimation("����", "���", leftStop, 1, 6, true);

	int frontStop[] = { 10 };
	KEYANIMANAGER->addArrayFrameAnimation("��", "���", frontStop, 1, 6, true);

	int backStop[] = { 15 };
	KEYANIMANAGER->addArrayFrameAnimation("��", "���", backStop, 1, 6, true);

	int rightMove[] = { 1, 2, 3, 4 };
	KEYANIMANAGER->addArrayFrameAnimation("�����ʹ���", "���", rightMove, 4,10, true);

	int leftMove[] = { 6, 7, 8, 9 };
	KEYANIMANAGER->addArrayFrameAnimation("���ʹ���", "���", leftMove, 4, 10, true);

	int frontMove[] = { 11, 12, 13, 14 };
	KEYANIMANAGER->addArrayFrameAnimation("�չ���", "���", frontMove, 4, 10, true);

	int backMove[] = { 16, 17, 18, 19 };
	KEYANIMANAGER->addArrayFrameAnimation("�ڹ���", "���", backMove, 4, 10, true);

	//ȭ�� ó�� ����� �ڵ��ƺ����ִ� IDLE����
	_playerMotion = KEYANIMANAGER->findAnimation("��");

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
		_playerMotion = KEYANIMANAGER->findAnimation("�����ʹ���");
		_playerMotion->start();
	}
	if (KEYMANAGER->isOnceKeyUp(VK_RIGHT))
	{
		_playerDirection = GOLD_RIGHT_STOP;
		_playerMotion = KEYANIMANAGER->findAnimation("������");
		_playerMotion->start();
	}
	if (KEYMANAGER->isOnceKeyDown(VK_LEFT))
	{
		_playerDirection = GOLD_LEFT_MOVE;
		_playerMotion = KEYANIMANAGER->findAnimation("���ʹ���");
		_playerMotion->start();
	}
	if (KEYMANAGER->isOnceKeyUp(VK_LEFT))
	{
		_playerDirection = GOLD_LEFT_STOP;
		_playerMotion = KEYANIMANAGER->findAnimation("����");
		_playerMotion->start();
	}
	if (KEYMANAGER->isOnceKeyDown(VK_UP))
	{
		_playerDirection = GOLD_BACK_MOVE;
		_playerMotion = KEYANIMANAGER->findAnimation("�ڹ���");
		_playerMotion->start();
	}
	if (KEYMANAGER->isOnceKeyUp(VK_UP))
	{
		_playerDirection = GOLD_BACK_STOP;
		_playerMotion = KEYANIMANAGER->findAnimation("��");
		_playerMotion->start();
	}
	if (KEYMANAGER->isOnceKeyDown(VK_DOWN))
	{
		_playerDirection = GOLD_FRONT_MOVE;
		_playerMotion = KEYANIMANAGER->findAnimation("�չ���");
		_playerMotion->start();
	}
	if (KEYMANAGER->isOnceKeyUp(VK_DOWN))
	{
		_playerDirection = GOLD_FRONT_STOP;
		_playerMotion = KEYANIMANAGER->findAnimation("��");
		_playerMotion->start();
	}

	//--------------------------------------------------------
	//�ȼ��浹
	//--------------------------------------------------------

	_speed = 1.5f;

	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		bool isProbe = false;
		//�ȼ� ������ Ž��
		for (int i = _playerRc.top; i < _playerRc.bottom && !isProbe; i += _player->getFrameHeight() / 3)
		{
			for (int j = _playerRc.right - 3; j <= _playerRc.right + 3; ++j)
			{
				COLORREF color = GetPixel(IMAGEMANAGER->findImage("���ڻ��ȼ��浹")->getMemDC(), j, i);

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
		//�ȼ� ���� Ž��
		for (int i = _playerRc.top; i < _playerRc.bottom && !isProbe; i += _player->getFrameHeight() / 2)
		{
			for (int j = _playerRc.left - 3; j <= _playerRc.left ; j++)
			{
				COLORREF color = GetPixel(IMAGEMANAGER->findImage("���ڻ��ȼ��浹")->getMemDC(), j, i);

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
		//�ȼ� ���� Ž��
		for (int i = _playerRc.left; i < _playerRc.right && !isProbe; i += _player->getFrameWidth() / 2)
		{
			for (int j = _playerRc.top - 3; j <= _playerRc.top; j++)
			{
				COLORREF color = GetPixel(IMAGEMANAGER->findImage("���ڻ��ȼ��浹")->getMemDC(), i, j);

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
		//�ȼ� �Ʒ��� Ž��
		for (int i = _playerRc.left; i < _playerRc.right && !isProbe; i += _player->getFrameWidth() / 2)
		{
			for (int j = _playerRc.bottom - 3; j <= _playerRc.bottom; j++)
			{
				COLORREF color = GetPixel(IMAGEMANAGER->findImage("���ڻ��ȼ��浹")->getMemDC(), i, j);

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
//	k->setPlayerMotion(KEYANIMANAGER->findAnimation("������"));
//	k->getPlayerMotion()->start();
//}
//void player::_leftStop(void* obj)
//{
//	player* k = (player*)obj;
//
//	k->setPlayerDirection(GOLD_LEFT_STOP);
//	k->setPlayerMotion(KEYANIMANAGER->findAnimation("����"));
//	k->getPlayerMotion()->start();
//}
//void player::_frontStop(void* obj)
//{
//	player* k = (player*)obj;
//
//	k->setPlayerDirection(GOLD_FRONT_STOP);
//	k->setPlayerMotion(KEYANIMANAGER->findAnimation("��"));
//	k->getPlayerMotion()->start();
//}
//void player::_backStop(void* obj)
//{
//	player* k = (player*)obj;
//
//	k->setPlayerDirection(GOLD_BACK_STOP);
//	k->setPlayerMotion(KEYANIMANAGER->findAnimation("��"));
//	k->getPlayerMotion()->start();
//}