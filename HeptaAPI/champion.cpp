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

	int level = 5 + 5 * _player->getBadgeCount();
	_vPokemon.clear();
	// ����, ������, ����, ����帱��, ������, �Ŀ���
	pokemon* temp[6];
	skill* tempSkill;
	for (int i = 0; i < 6; ++i)
	{
		temp[i] = new pokemon;

		if (i == 0)
		{
			temp[i]->init("��ī��", level);
			tempSkill = new skill;
			tempSkill->init("10����Ʈ");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("������ȭ");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("�����ũ");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("����");
			temp[i]->addSkill(tempSkill);
		}
		else if (i == 1)
		{
			temp[i]->init("���ڸ�", level);
			tempSkill = new skill;
			tempSkill->init("�Ҵ빮��");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("����������");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("�ް�����ġ");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("�巡��ũ��");
			temp[i]->addSkill(tempSkill);
		}
		else if (i == 2)
		{
			temp[i]->init("�̻��ز�", level);
			tempSkill = new skill;
			tempSkill->init("�ϵ��÷�Ʈ");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("����ä��");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("�ֶ��");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("�ް��巹��");
			temp[i]->addSkill(tempSkill);
		}
		else if (i == 3)
		{
			temp[i]->init("�źϿ�", level);
			tempSkill = new skill;
			tempSkill->init("���̵������");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("�õ���ġ");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("�ĵ�Ÿ��");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("����");
			temp[i]->addSkill(tempSkill);
		}
		else if (i == 4)
		{
			temp[i]->init("������", level);
			tempSkill = new skill;
			tempSkill->init("�ĵ�Ÿ��");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("�õ���");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("���̵������");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("���ǵ彺Ÿ");
			temp[i]->addSkill(tempSkill);
		}
		else if (i == 5)
		{
			temp[i]->init("�Ḹ��", level);
			tempSkill = new skill;
			tempSkill->init("�ı�����");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("����");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("������");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("�������");
			temp[i]->addSkill(tempSkill);
		}
		_vPokemon.push_back(temp[i]);
	}

	vector<pokemon*>* realPokemonVector = new vector<pokemon*>;
	switch (_player->getBadgeCount())
	{
	case 0:
		realPokemonVector->push_back(_vPokemon[0]);
		break;

	case 1:
		realPokemonVector->push_back(_vPokemon[0]);
		realPokemonVector->push_back(_vPokemon[1]);
		break;

	case 2:
		realPokemonVector->push_back(_vPokemon[0]);
		realPokemonVector->push_back(_vPokemon[1]);
		realPokemonVector->push_back(_vPokemon[2]);
		break;

	case 3:
		realPokemonVector->push_back(_vPokemon[0]);
		realPokemonVector->push_back(_vPokemon[1]);
		realPokemonVector->push_back(_vPokemon[2]);
		realPokemonVector->push_back(_vPokemon[3]);
		break;

	case 4:
		realPokemonVector->push_back(_vPokemon[0]);
		realPokemonVector->push_back(_vPokemon[1]);
		realPokemonVector->push_back(_vPokemon[2]);
		realPokemonVector->push_back(_vPokemon[3]);
		realPokemonVector->push_back(_vPokemon[4]);
		break;

	default:
		realPokemonVector->push_back(_vPokemon[0]);
		realPokemonVector->push_back(_vPokemon[1]);
		realPokemonVector->push_back(_vPokemon[2]);
		realPokemonVector->push_back(_vPokemon[3]);
		realPokemonVector->push_back(_vPokemon[4]);
		realPokemonVector->push_back(_vPokemon[5]);
		break;
	}
	DATABASE->setVEnemyPokemon(realPokemonVector);
	
	

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
