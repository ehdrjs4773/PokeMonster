#include "stdafx.h"
#include "normalMap.h"



normalMap::normalMap()
{
}


normalMap::~normalMap()
{
}

HRESULT normalMap::init()
{
	stageManager::init();
	_background = IMAGEMANAGER->addImage("�븻��", ".\\bmps\\map\\�븻.bmp", 0, 0, WINSIZEX, WINSIZEY, false, true, MAGENTA);
	_gymLeader = IMAGEMANAGER->addImage("�븻NPC", ".\\bmps\\map\\�븻NPC.bmp", 25, 28, false, true, MAGENTA);
	_player->setCurrentStage(4); //���� �������� ���� �Ѱ��ش�

	_x = WINSIZEX / 2 - 12;
	_y = 30;

	_gymLeaderRc = RectMake(_x, _y, _gymLeader->getWidth(), _gymLeader->getHeight());


	_isWin = false;
	return S_OK;
}

void normalMap::release()
{

}

void normalMap::update()
{
	stageManager::update();
	_gymLeaderRc = RectMake(_x, _y, _gymLeader->getWidth(), _gymLeader->getHeight());

	if (_player->getPlayerRc().top >= WINSIZEY)
	{
		SCENEMANAGER->changeScene("����ʾ�");
		SCENEMANAGER->init("����ʾ�");
	}
}

void normalMap::render()
{
	IMAGEMANAGER->findImage("�븻��")->render(getMemDC());
	IMAGEMANAGER->findImage("�븻NPC")->render(getMemDC(), _x, _y);
	stageManager::render();

}
void normalMap::collision()
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
			SCENEMANAGER->changeScene("battleScene");
			SCENEMANAGER->init("battleScene");
			SCENEMANAGER->findScene("battleScene")->setDestScene("��������1");
		}
	}
}

