#include "stdafx.h"
#include "champion.h"

#include "player.h"
#include "battleScene.h"


champion::champion()
{
	_isWin = false;
}


champion::~champion()
{
}

HRESULT champion::init()
{
	stageManager::init();
	_background = IMAGEMANAGER->addImage("è�Ǿ��", ".\\bmps\\map\\è�Ǿ�.bmp", 0, 0, WINSIZEX, WINSIZEY, false, true, MAGENTA);
	_gymLeader = IMAGEMANAGER->addImage("è�Ǿ�NPC", ".\\bmps\\map\\è�Ǿ�NPC.bmp", 25, 28, false, true, MAGENTA);
	_player->setCurrentStage(13); //���� �������� ���� �Ѱ��ش�

	_x = 226;
	_y = 78;

	_gymLeaderRc = RectMake(_x, _y, _gymLeader->getWidth(), _gymLeader->getHeight());


	
	

	return S_OK;
}

void champion::release()
{

}

void champion::update()
{
	stageManager::update();
	_gymLeaderRc = RectMake(_x, _y, _gymLeader->getWidth(), _gymLeader->getHeight());

	if (_player->getPlayerRc().top >= WINSIZEY)
	{
		SCENEMANAGER->changeScene("��������12");
		SCENEMANAGER->init("��������12");
	}
	

	if (_player->getPlayerRc().top >= WINSIZEY)
	{
		SCENEMANAGER->changeScene("��������12");
		SCENEMANAGER->init("��������12");
	}
	if (_player->getPlayerRc().top >= WINSIZEY && _isWin == true)
	{
		SCENEMANAGER->changeScene("����ʾ�");
		SCENEMANAGER->init("����ʾ�");
	}
}

void champion::render()
{

	IMAGEMANAGER->findImage("è�Ǿ��")->render(getMemDC());
	if (!_isWin)
	{
		IMAGEMANAGER->findImage("è�Ǿ�NPC")->render(getMemDC(), _x, _y);
	}
	stageManager::render();
}

void champion::collision()
{
	RECT temp;
	if (IntersectRect(&temp, &_gymLeaderRc, &_player->getPlayerRc()) && _isWin == false)
	{
		int tempWidth = temp.right - temp.left;
		int tempHeight = temp.bottom - temp.top;

		// �����浹
		if (tempHeight > tempWidth)
		{
			//������ �浹
			if (temp.left == _player->getPlayerRc().left)
			{
				_player->setPlayerPt(PointMake(_gymLeaderRc.right + (_player->getPlayerRc().right - _player->getPlayerRc().left) / 2,
					(_player->getPlayerRc().bottom + _player->getPlayerRc().top) / 2));
			}
			//�����浹
			if (temp.right == _player->getPlayerRc().right)
			{
				_player->setPlayerPt(PointMake(_gymLeaderRc.left - (_player->getPlayerRc().right - _player->getPlayerRc().left) / 2,
					(_player->getPlayerRc().bottom + _player->getPlayerRc().top) / 2));
			}
		}
		else
		{
			//�Ʒ��浹
			if (temp.top == _player->getPlayerRc().top)
			{
				_player->setPlayerPt(PointMake((_player->getPlayerRc().right + _player->getPlayerRc().left) / 2,
					temp.bottom + (_player->getPlayerRc().bottom - _player->getPlayerRc().top) / 2));
			}
		}

		if (KEYMANAGER->isOnceKeyDown(PLAYER_SELECT_KEY))
		{
			// �����
			SCENEMANAGER->changeScene("battleScene");
			battleScene* tempBattle = (battleScene*)SCENEMANAGER->findScene("battleScene");
			tempBattle->setEnemyType(ENEMY_TRAINNER);
			tempBattle->setDestScene("��������13");
			tempBattle->init(13);
		}
	}
}
