#include "stdafx.h"
#include "drOHouse.h"

#include "player.h"


drOHouse::drOHouse()
{
	_isWin = false;
}


drOHouse::~drOHouse()
{
}

HRESULT drOHouse::init()
{
	stageManager::init();
	//����
	if (SOUNDMANAGER->isPlaySound("����� �׸���")) SOUNDMANAGER->stop("����� �׸���");

	_background = IMAGEMANAGER->addImage("���ڻ��", ".\\bmps\\map\\���ڻ�.bmp", WINSIZEX, WINSIZEY, false, true, MAGENTA);
	_drO = IMAGEMANAGER->addFrameImage("drO", ".\\bmps\\drHouseScene\\drO.bmp", 68, 24, 4, 1, false, true, MAGENTA);
	_shopNPC = IMAGEMANAGER->addImage("����NPC", ".\\bmps\\map\\����NPC.bmp", 17, 25, false, true, MAGENTA);

	IMAGEMANAGER->addImage("selectIcon", ".\\bmps\\battleScene\\UI\\selectIcon.bmp", 7, 7, false, true, MAGENTA);

	_player->setCurrentStage(0);

	_x = 240;
	_y = 115;

	_x1 = 350;
	_y1 = 250;

	_gymLeaderRc = RectMake(_x, _y, _drO->getFrameWidth(), _drO->getFrameHeight());
	_shopNPCRc = RectMake(_x1, _y1, _shopNPC->getWidth(), _shopNPC->getHeight());

	_isMonsterSelect = false;

	SCENEMANAGER->init("����ʾ�");

	_startingMonster[0] = "���ڸ�";
	_startingMonster[1] = "���α�";
	_startingMonster[2] = "�̻��ؾ�";

	_selectNum = 0;

	_dialogueTime = 0;

	SOUNDMANAGER->play("���ڻ� �׸���", 1.0f);

	return S_OK;
}
void drOHouse::release()
{

}
void drOHouse::update()
{
	if (!_isMonsterSelect)
	{
		stageManager::update();

		this->collision();

		if (DATABASE->getVPlayerPokemon()->size() != 0)
		{
			if (_player->getPlayerRc().top >= WINSIZEY)
			{
				SCENEMANAGER->changeScene("����ʾ�");
				SOUNDMANAGER->stop("���ڻ� �׸���");
			}
		}
		else
		{
			if (_player->getPlayerRc().bottom > WINSIZEY)
			{
				_player->setPlayerPt(PointMake((_player->getPlayerRc().right + _player->getPlayerRc().left) / 2, WINSIZEY - (_player->getPlayerRc().bottom - _player->getPlayerRc().top) / 2));
			}
		}
	}
	else
	{
		DIALOGUE->update();

		if (DATABASE->getVPlayerPokemon()->size() == 0)
		{
			if (KEYMANAGER->isOnceKeyDown(VK_LEFT))
			{
				_selectNum--;
				if (_selectNum < 0)
					_selectNum = 2;
			}
			if (KEYMANAGER->isOnceKeyDown(VK_RIGHT))
			{
				_selectNum++;
				if (_selectNum > 2)
					_selectNum = 0;
			}

			if (KEYMANAGER->isOnceKeyDown(PLAYER_SELECT_KEY))
			{
				pokemon* temp = new pokemon;

				if (_selectNum == 0)
				{
					temp->init("���ڸ�", 99);
					skill* tempSkill = new skill;
					tempSkill->init("�Ҵ빮��");
					temp->addSkill(tempSkill);
					tempSkill = new skill;
					tempSkill->init("�巡��ũ��");
					temp->addSkill(tempSkill);
					tempSkill = new skill;
					tempSkill->init("�ް�����ġ");
					temp->addSkill(tempSkill);
					tempSkill = new skill;
					tempSkill->init("ȸ�����Ҳ�");
					temp->addSkill(tempSkill);
				}
				else if (_selectNum == 1)
				{
					temp->init("���α�", 5);
					skill* tempSkill = new skill;
					tempSkill->init("���̵������");
					temp->addSkill(tempSkill);
					tempSkill = new skill;
					tempSkill->init("�ĵ�Ÿ��");
					temp->addSkill(tempSkill);
					tempSkill = new skill;
					tempSkill->init("����ġ��");
					temp->addSkill(tempSkill);
					tempSkill = new skill;
					tempSkill->init("�ĵ�ź");
					temp->addSkill(tempSkill);
				}
				else
				{
					temp->init("�̻��ؾ�", 5);
					skill* tempSkill = new skill;
					tempSkill->init("�ϵ��÷�Ʈ");
					temp->addSkill(tempSkill);
					tempSkill = new skill;
					tempSkill->init("Ǯ����");
					temp->addSkill(tempSkill);
					tempSkill = new skill;
					tempSkill->init("����");
					temp->addSkill(tempSkill);
					tempSkill = new skill;
					tempSkill->init("�ֶ��");
					temp->addSkill(tempSkill);
				}

				DATABASE->getVPlayerPokemon()->push_back(temp);

				_isMonsterSelect = false;
			}
		}
		else
		{
			_dialogueTime++;
			if (_dialogueTime % 30 == 0)
			{
				_isMonsterSelect = false;
			}
		}
	}
}
void drOHouse::render()
{
	IMAGEMANAGER->findImage("���ڻ��")->render(getMemDC());
	IMAGEMANAGER->findImage("drO")->frameRender(getMemDC(), _x, _y);
	IMAGEMANAGER->findImage("����NPC")->render(getMemDC(),_x1,_y1);
	stageManager::render();

	if (_isMonsterSelect)
	{
		IMAGEMANAGER->findImage("textBox")->render(getMemDC(), WINSIZEX / 2 - 160, WINSIZEY - 66);
		DIALOGUE->render(getMemDC());

		if (DATABASE->getVPlayerPokemon()->size() == 0)
		{
			for (int i = 0; i < 3; ++i)
				TextOut(getMemDC(), 110 + 90 * i, 327, _startingMonster[i].c_str(), strlen(_startingMonster[i].c_str()));
			IMAGEMANAGER->findImage("selectIcon")->render(getMemDC(), 110 + 90 * _selectNum - 7, 331);
		}
	}
}

void drOHouse::collision()
{
	RECT temp;
	if (IntersectRect(&temp, &_gymLeaderRc, &_player->getPlayerRc()))
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
			if (!_isMonsterSelect)
			{
				_isMonsterSelect = true;
				if (DATABASE->getVPlayerPokemon()->size() == 0)
				{
					DIALOGUE->loadingTextFile(".\\textData\\drO.txt");
					DIALOGUE->setPoint(PointMake(100, 307));
				}
				else
				{
					DIALOGUE->loadingTextFile(".\\textData\\drO_alreadySelect.txt");
					DIALOGUE->setPoint(PointMake(100, 307));
					_dialogueTime = 0;
				}
			}
		}
	}
			RECT temp1;
			
			if (KEYMANAGER->isOnceKeyDown(PLAYER_SELECT_KEY) && IntersectRect(&temp1, &_shopNPCRc, &_player->getPlayerRc()))
			{
				SCENEMANAGER->changeScene("������");
				SCENEMANAGER->init("������");
			}
			if (IntersectRect(&temp1, &_shopNPCRc, &_player->getPlayerRc()))
			{
				int tempWidth = temp1.right - temp1.left;
				int tempHeight = temp1.bottom - temp1.top;

				// �����浹
				if (tempHeight > tempWidth)
				{
					//������ �浹
					if (temp1.left == _player->getPlayerRc().left)
					{
						_player->setPlayerPt(PointMake(_shopNPCRc.right + (_player->getPlayerRc().right - _player->getPlayerRc().left) / 2,
							(_player->getPlayerRc().bottom + _player->getPlayerRc().top) / 2));
					}
					//�����浹
					if (temp1.right == _player->getPlayerRc().right)
					{
						_player->setPlayerPt(PointMake(_shopNPCRc.left - (_player->getPlayerRc().right - _player->getPlayerRc().left) / 2,
							(_player->getPlayerRc().bottom + _player->getPlayerRc().top) / 2));
					}
				}
				else
				{
					//�Ʒ��浹
					if (temp1.top == _player->getPlayerRc().top)
					{
						_player->setPlayerPt(PointMake((_player->getPlayerRc().right + _player->getPlayerRc().left) / 2,
							temp1.bottom + (_player->getPlayerRc().bottom - _player->getPlayerRc().top) / 2));
					}
				}
		
	}
}
