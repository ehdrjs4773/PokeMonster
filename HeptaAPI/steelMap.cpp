#include "stdafx.h"
#include "steelMap.h"
#include "player.h"
#include "battleScene.h"


steelMap::steelMap()
{
	_isWin = false;
}


steelMap::~steelMap()
{
}

HRESULT steelMap::init()
{
	stageManager::init();
	_background = IMAGEMANAGER->addImage("��ö��", ".\\bmps\\map\\��ö.bmp", 0, 0, WINSIZEX, WINSIZEY, false, true, MAGENTA);
	_gymLeader = IMAGEMANAGER->addImage("��öNPC", ".\\bmps\\map\\��öNPC.bmp", 25, 28, false, true, MAGENTA);
	_player->setCurrentStage(1); //���� �������� ���� �Ѱ��ش�

	_x = WINSIZEX / 2 - 12;
	_y = 15;

	_gymLeaderRc = RectMake(_x, _y, _gymLeader->getWidth(), _gymLeader->getHeight());


	int level = 5 + 5 * _player->getBadgeCount();
	_vPokemon.clear();
	// ���� , �������� ,����, ������ , �ս���  , �ڻѸ�
	pokemon* temp[6];
	skill* tempSkill;
	for (int i = 0; i < 6; ++i)
	{
		temp[i] = new pokemon;

		if (i == 0)
		{
			temp[i]->init("����", level);
			tempSkill = new skill;
			tempSkill->init("������ĳ��");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("��������");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("�Ҵк�");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("����������");
			temp[i]->addSkill(tempSkill);
		}
		else if (i == 1)
		{
			temp[i]->init("��������", level);
			tempSkill = new skill;
			tempSkill->init("������ĳ��");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("��������");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("�Ҵк�");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("������ȭ");
			temp[i]->addSkill(tempSkill);
		}
		else if (i == 2)
		{
			temp[i]->init("����", level);
			tempSkill = new skill;
			tempSkill->init("������ĳ��");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("��������");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("�Ҵк�");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("��������");
			temp[i]->addSkill(tempSkill);
		}
		else if (i == 3)
		{
			temp[i]->init("������", level);
			tempSkill = new skill;
			tempSkill->init("������ĳ��");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("��������");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("�Ҵк�");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("������ȭ");
			temp[i]->addSkill(tempSkill);
		}
		else if (i == 4)
		{
			temp[i]->init("�ս���", level);
			tempSkill = new skill;
			tempSkill->init("������ĳ��");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("��������");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("�Ҵк�");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("��主��");
			temp[i]->addSkill(tempSkill);
		}
		else if (i == 5)
		{
			temp[i]->init("�ڻѸ�", level);
			tempSkill = new skill;
			tempSkill->init("������ĳ��");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("��������");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("�Ҵк�");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("������");
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

void steelMap::release()
{

}

void steelMap::update()	
{
	stageManager::update();

	collision();
	_gymLeaderRc = RectMake(_x, _y, _gymLeader->getWidth(), _gymLeader->getHeight());

	if (_player->getPlayerRc().top >= WINSIZEY)
	{
		SCENEMANAGER->changeScene("����ʾ�");
		SCENEMANAGER->init("����ʾ�");
	}
}

void steelMap::render()	
{
	IMAGEMANAGER->findImage("��ö��")->render(getMemDC());
	if (_isWin == false)
	{
		IMAGEMANAGER->findImage("��öNPC")->render(getMemDC(), _gymLeaderRc.left, _gymLeaderRc.top);
	}

	//Rectangle(getMemDC(), _player->getPlayerRc().left, _player->getPlayerRc().top, _player->getPlayerRc().right, _player->getPlayerRc().bottom);
	stageManager::render();
	//Rectangle(getMemDC(), _gymLeaderRc.left, _gymLeaderRc.top, _gymLeaderRc.right, _gymLeaderRc.bottom);
}

void steelMap::collision()
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
			!_player->isAllDie())
		{
			// �����
			SCENEMANAGER->changeScene("battleScene");
			battleScene* tempBattle = (battleScene*)SCENEMANAGER->findScene("battleScene");
			tempBattle->setEnemyType(ENEMY_TRAINNER);
			tempBattle->setDestScene("��������1");
			tempBattle->init(1);
		}
	}
}
