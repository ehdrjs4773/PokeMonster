#include "stdafx.h"
#include "normalMap.h"

#include "player.h"
#include "battleScene.h"


normalMap::normalMap()
{
	_isWin = false;
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

	int level = 5 + 5 * _player->getBadgeCount();
	_vPokemon.clear();
	//��Ÿ�� , �Ŀ� , ��Ʈ�� , ��Ű , ��Ÿ��ν� , Ļī
	pokemon* temp[6];
	skill* tempSkill;
	for (int i = 0; i < 6; ++i)
	{
		temp[i] = new pokemon;

		if (i == 0)
		{
			temp[i]->init("��Ÿ��", level);
			tempSkill = new skill;
			tempSkill->init("����������Ÿ");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("������");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("�����ġ��");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("�Ҳ���ġ");
			temp[i]->addSkill(tempSkill);
		}
		else if (i == 1)
		{
			temp[i]->init("�Ŀ�", level);
			tempSkill = new skill;
			tempSkill->init("����������Ÿ");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("������");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("�����ġ��");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("�����̵��ޱ�");
			temp[i]->addSkill(tempSkill);
		}
		else if (i == 2)
		{
			temp[i]->init("��Ʈ��", level);
			tempSkill = new skill;
			tempSkill->init("����������Ÿ");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("������");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("�����ġ��");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("�ʻ�մ�");
			temp[i]->addSkill(tempSkill);
		}
		else if (i == 3)
		{
			temp[i]->init("��Ű", level);
			tempSkill = new skill;
			tempSkill->init("����������Ÿ");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("������");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("�����ġ��");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("����ź");
			temp[i]->addSkill(tempSkill);
		}
		else if (i == 4)
		{
			temp[i]->init("��Ÿ��ν�", level);
			tempSkill = new skill;
			tempSkill->init("����������Ÿ");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("������");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("�����ġ��");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("����");
			temp[i]->addSkill(tempSkill);
		}
		else if (i == 5)
		{
			temp[i]->init("Ļī", level);
			tempSkill = new skill;
			tempSkill->init("����������Ÿ");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("������");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("�����ġ��");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("������ġ");
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

void normalMap::release()
{

}

void normalMap::update()
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

void normalMap::render()
{
	IMAGEMANAGER->findImage("�븻��")->render(getMemDC());
	if (!_isWin)
	{
		IMAGEMANAGER->findImage("�븻NPC")->render(getMemDC(), _x, _y);
	}
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

		if (KEYMANAGER->isOnceKeyDown(PLAYER_SELECT_KEY) &&
			!_player->isAllDie())
		{
			// �����
			SCENEMANAGER->changeScene("battleScene");
			battleScene* tempBattle = (battleScene*)SCENEMANAGER->findScene("battleScene");
			tempBattle->setEnemyType(ENEMY_TRAINNER);
			tempBattle->setDestScene("��������4");
			tempBattle->init(4);
		}
	}
}

