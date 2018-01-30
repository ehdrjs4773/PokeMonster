#include "stdafx.h"
#include "guardian2.h"

#include "player.h"
#include "battleScene.h"


guardian2::guardian2()
{
	_isWin = false;
}


guardian2::~guardian2()
{
}

HRESULT guardian2::init()
{
	stageManager::init();
	_background = IMAGEMANAGER->addImage("��õ��2��", ".\\bmps\\map\\��õ��2_��.bmp", 0, 0, WINSIZEX, WINSIZEY, false, true, MAGENTA);
	_gymLeader = IMAGEMANAGER->addImage("��õ��2_��NPC", ".\\bmps\\map\\��õ��2_��NPC.bmp", 25, 28, false, true, MAGENTA);
	_player->setCurrentStage(10); //���� �������� ���� �Ѱ��ش�

	_x = WINSIZEX / 2 - 14;
	_y = 50;

	_gymLeaderRc = RectMake(_x, _y, _gymLeader->getWidth(), _gymLeader->getHeight());

	if (SCENEMANAGER->getLastSceneName() == "��������11")
	{
		_player->setPlayerPt(PointMake(240, 0));
	}
	else
	{
		_player->setPlayerPt(PointMake(240, 340));
	}
	
	
	return S_OK;
}

void guardian2::release()
{

}

void guardian2::update()
{
	stageManager::update();
	collision();
	_gymLeaderRc = RectMake(_x, _y, _gymLeader->getWidth(), _gymLeader->getHeight());

	if (_player->getPlayerRc().top >= WINSIZEY)
	{
		SCENEMANAGER->changeScene("��������9");
		SCENEMANAGER->init("��������9");
	}
	if (_player->getPlayerRc().bottom <= 0)
	{
		SCENEMANAGER->changeScene("��������11");
		SCENEMANAGER->init("��������11");
	}
}

void guardian2::render()
{
	IMAGEMANAGER->findImage("��õ��2��")->render(getMemDC());
	if (!_isWin)
	{
		IMAGEMANAGER->findImage("��õ��2_��NPC")->render(getMemDC(), _x, _y);
	}
	stageManager::render();

}
void guardian2::collision()
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
			tempBattle->setDestScene("��������10");
			tempBattle->init(10);
		}
	}
}
