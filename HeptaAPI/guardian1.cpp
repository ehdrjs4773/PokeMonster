#include "stdafx.h"
#include "guardian1.h"

#include "player.h"
#include "battleScene.h"


guardian1::guardian1()
{
	_isWin = false;
}


guardian1::~guardian1()
{

}

HRESULT guardian1::init()
{
	stageManager::init();
	_background = IMAGEMANAGER->addImage("��õ��1��", ".\\bmps\\map\\��õ��1_����.bmp", 0, 0, WINSIZEX, WINSIZEY, false, true, MAGENTA);
	_gymLeader = IMAGEMANAGER->addImage("��õ��1_����NPC", ".\\bmps\\map\\��õ��1_����NPC.bmp", 25, 28, false, true, MAGENTA);
	_player->setCurrentStage(9); //���� �������� ���� �Ѱ��ش�

	_x = WINSIZEX / 2 - 13;
	_y = 60;

	_gymLeaderRc = RectMake(_x, _y, _gymLeader->getWidth(), _gymLeader->getHeight());


	if (SCENEMANAGER->getLastSceneName() == "��������10")
	{
		_player->setPlayerPt(PointMake(240, 0));
	}
	else
	{
		_player->setPlayerPt(PointMake(240, 340));
	}

	// �����
	int level = 50;
	_vPokemon.clear();
	// ����, ������, ����, ����帱��, ������, �Ŀ���
	pokemon* temp[6];
	skill* tempSkill;
	for (int i = 0; i < 6; ++i)
	{
		temp[i] = new pokemon;

		if (i == 0)
		{
			temp[i]->init("�����", level);
			tempSkill = new skill;
			tempSkill->init("�ĵ�ź");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("��������");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("����");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("�ӱ�");
			temp[i]->addSkill(tempSkill);
		}
		else if (i == 1)
		{
			temp[i]->init("������", level);
			tempSkill = new skill;
			tempSkill->init("�ĵ�ź");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("��������");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("������ȭ");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("���ӻ�ġ��");
			temp[i]->addSkill(tempSkill);
		}
		else if (i == 2)
		{
			temp[i]->init("������", level);
			tempSkill = new skill;
			tempSkill->init("�ĵ�ź");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("��������");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("����");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("������ġ");
			temp[i]->addSkill(tempSkill);
		}
		else if (i == 3)
		{
			temp[i]->init("ȫ����", level);
			tempSkill = new skill;
			tempSkill->init("�ĵ�ź");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("��������");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("������ġ");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("�Ҳ���ġ");
			temp[i]->addSkill(tempSkill);
		}
		else if (i == 4)
		{
			temp[i]->init("�ö�Ҹ�", level);
			tempSkill = new skill;
			tempSkill->init("�ĵ�ź");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("����ű");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("��������");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("�ް���ű");
			temp[i]->addSkill(tempSkill);
		}
		else if (i == 5)
		{
			temp[i]->init("���¸�", level);
			tempSkill = new skill;
			tempSkill->init("�ĵ�ź");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("����������");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("����");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("�±Ǵ��");
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

void guardian1::release()
{

}

void guardian1::update()
{
	stageManager::update();
	collision();
	_gymLeaderRc = RectMake(_x, _y, _gymLeader->getWidth(), _gymLeader->getHeight());

	if (_player->getPlayerRc().top >= WINSIZEY)
	{
		SCENEMANAGER->changeScene("����ʾ�");
		SCENEMANAGER->init("����ʾ�");
	}

	if (_player->getPlayerRc().bottom < -10)
	{
		SCENEMANAGER->changeScene("��������10");
		SCENEMANAGER->init("��������10");
	
	}
}

void guardian1::render()
{
	IMAGEMANAGER->findImage("��õ��1��")->render(getMemDC());
	if (!_isWin)
	{
		IMAGEMANAGER->findImage("��õ��1_����NPC")->render(getMemDC(), _x, _y);
	}
	stageManager::render();

}
void guardian1::collision()
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

		if (KEYMANAGER->isOnceKeyDown(PLAYER_SELECT_KEY) &&
			DATABASE->getPlayerMemory()->isAllDie())
		{
			// �����
			SCENEMANAGER->changeScene("battleScene");
			battleScene* tempBattle = (battleScene*)SCENEMANAGER->findScene("battleScene");
			tempBattle->setEnemyType(ENEMY_TRAINNER);
			tempBattle->setDestScene("��������9");
			tempBattle->init(9);
		}
	}
}
