#include "stdafx.h"
#include "battleSceneUI.h"
#include "battleScene.h"



battleSceneUI::battleSceneUI()
{
}


battleSceneUI::~battleSceneUI()
{
}

HRESULT battleSceneUI::init()
{
	// ��Ʋ�� ��ü���� ��� �� ������
	IMAGEMANAGER->addImage("battleFrame", ".\\bmps\\battleScene\\UI\\battleFrame.bmp", WINSIZEX, WINSIZEY, false, true, MAGENTA);

	// ��ư ���ÿ� ������
	IMAGEMANAGER->addImage("selectIcon", ".\\bmps\\battleScene\\UI\\selectIcon.bmp", 7, 7, false, true, MAGENTA);

	// ��ų ���� �� ����� ������
	IMAGEMANAGER->addImage("battleSkillFrame", ".\\bmps\\battleScene\\UI\\battleSkillFrame.bmp", 320, 138, false, true, MAGENTA);

	// �ο��, ����, ���ϸ�, ���� ���ÿ� ��Ʈ
	_selectSequenceRect[0][0] = RectMake(246, 270, 45, 14);
	_selectSequenceRect[0][1] = RectMake(246, 293, 45, 14);
	_selectSequenceRect[1][0] = RectMake(327, 270, 45, 14);
	_selectSequenceRect[1][1] = RectMake(327, 293, 45, 14);

	// �ο�� ���� ����
	_skillPrintRect[0] = RectMake(107, 215, 60, 14);
	_skillPrintRect[1] = RectMake(107, 236, 60, 14);
	_skillPrintRect[2] = RectMake(107, 257, 60, 14);
	_skillPrintRect[3] = RectMake(107, 278, 60, 14);

	// ���� ȭ��ǥ�� �ϴ� �ο�� ���ʿ�
	_selectArrowPoint.x = 0;
	_selectArrowPoint.y = 0;
	_skillSelectNum = 0;

	_isFightSelect = false;
	_isBagSelect = false;
	_isPokemonSelect = false;
	_isRunAwaySelect = false;

	return S_OK;
}

void battleSceneUI::release()
{

}

void battleSceneUI::update() 
{
	switch (_battleScene->getSequence())
	{
		case BATTLE_INTRO:
		break;
		
		case BATTLE_BALLTHROW:
		break;
		
		case BATTLE_SELECT:
			this->keyControl();
		break;
		
		case BATTLE_FIGHT:
		break;
		
		case BATTLE_END:
		break;
		
		case BATTLE_FINAL:
		break;
	}
}

void battleSceneUI::render() 
{
	IMAGEMANAGER->findImage("battleFrame")->render(getMemDC());

	switch (_battleScene->getSequence())
	{
		case BATTLE_INTRO:
		break;
		
		case BATTLE_BALLTHROW:
		break;
		
		case BATTLE_SELECT:
			if (!_isFightSelect &&
				!_isPokemonSelect &&
				!_isBagSelect &&
				!_isRunAwaySelect)
			{
				TextOut(getMemDC(), _selectSequenceRect[0][0].left, _selectSequenceRect[0][0].top, "�ο��", strlen("�ο��"));
				TextOut(getMemDC(), _selectSequenceRect[0][1].left, _selectSequenceRect[0][1].top, "���ϸ�", strlen("���ϸ�"));
				TextOut(getMemDC(), _selectSequenceRect[1][0].left, _selectSequenceRect[1][0].top, "����", strlen("����"));
				TextOut(getMemDC(), _selectSequenceRect[1][1].left, _selectSequenceRect[1][1].top, "����", strlen("����"));

				IMAGEMANAGER->findImage("selectIcon")->render(getMemDC(), _selectSequenceRect[_selectArrowPoint.x][_selectArrowPoint.y].left - 7, _selectSequenceRect[_selectArrowPoint.x][_selectArrowPoint.y].top + 4);
			}
			else if (_isFightSelect)
			{
				IMAGEMANAGER->findImage("battleSkillFrame")->render(getMemDC(), LIMIT_X_LEFT, 189);
				IMAGEMANAGER->findImage("selectIcon")->render(getMemDC(), _skillPrintRect[_skillSelectNum].left - 7, _skillPrintRect[_skillSelectNum].top + 4);

				for (int i = 0; i < 4; ++i)
				{
					if (i < _battleScene->getCurrentPlayerPokemon()->getVSkill().size())
					{
						TextOut(getMemDC(), _skillPrintRect[i].left, _skillPrintRect[i].top, _battleScene->getCurrentPlayerPokemon()->getVSkill()[i]->getName().c_str(), strlen(_battleScene->getCurrentPlayerPokemon()->getVSkill()[i]->getName().c_str()));
					}
					else
						TextOut(getMemDC(), _skillPrintRect[i].left, _skillPrintRect[i].top, "---------------", strlen("---------------"));
				}

				this->printElement(_battleScene->getCurrentPlayerPokemon()->getVSkill()[_skillSelectNum]->getElement());
			}
		break;
		
		case BATTLE_FIGHT:
		break;
		
		case BATTLE_END:
		break;
		
		case BATTLE_FINAL:
		break;
	}
}

void battleSceneUI::keyControl()
{
	if (KEYMANAGER->isOnceKeyDown(VK_LEFT))
	{
		if (!_isFightSelect &&
			!_isPokemonSelect &&
			!_isBagSelect &&
			!_isRunAwaySelect)
			_selectArrowPoint.x = (1 - _selectArrowPoint.x) % 2;
	}
	if (KEYMANAGER->isOnceKeyDown(VK_RIGHT))
	{
		if (!_isFightSelect &&
			!_isPokemonSelect &&
			!_isBagSelect &&
			!_isRunAwaySelect)
			_selectArrowPoint.x = (1 + _selectArrowPoint.x) % 2;
	}
	if (KEYMANAGER->isOnceKeyDown(VK_UP))
	{
		if (!_isFightSelect &&
			!_isPokemonSelect &&
			!_isBagSelect &&
			!_isRunAwaySelect)
			_selectArrowPoint.y = (1 - _selectArrowPoint.y) % 2;
		else if (_isFightSelect)
		{
			_skillSelectNum--;
			if (_skillSelectNum < 0)
				_skillSelectNum = _battleScene->getCurrentPlayerPokemon()->getVSkill().size() - 1;
		}
	}
	if (KEYMANAGER->isOnceKeyDown(VK_DOWN))
	{
		if (!_isFightSelect &&
			!_isPokemonSelect &&
			!_isBagSelect &&
			!_isRunAwaySelect)
			_selectArrowPoint.y = (1 + _selectArrowPoint.y) % 2;
		else if (_isFightSelect)
		{
			_skillSelectNum++;
			if (_skillSelectNum > _battleScene->getCurrentPlayerPokemon()->getVSkill().size() - 1)
				_skillSelectNum = 0;
		}
	}

	if (KEYMANAGER->isOnceKeyDown('X'))
	{
		if (!_isFightSelect &&
			!_isPokemonSelect &&
			!_isBagSelect &&
			!_isRunAwaySelect)
		{
			if (_selectArrowPoint.x == 0 && _selectArrowPoint.y == 0)
			{
				_isFightSelect = true;
				_skillSelectNum = 0;
			}
			else if (_selectArrowPoint.x == 0 && _selectArrowPoint.y == 1)
			{
				_isPokemonSelect = true;
			}
			else if (_selectArrowPoint.x == 1 && _selectArrowPoint.y == 0)
			{
				_isBagSelect = true;
			}
			else if (_selectArrowPoint.x == 1 && _selectArrowPoint.y == 1)
			{
				_isRunAwaySelect = true;
			}
		}
		else if (_isFightSelect)
		{
			_enemySkillNum = RND->getInt(_battleScene->getCurrentEnemyPokemon()->getVSkill().size());
			// test
			_enemySkillNum = 0;
			_battleScene->setSequence(BATTLE_FIGHT);
			DIALOGUE->loadingTextFile(".\\textData\\battleScene_fight.txt");
			DIALOGUE->replaceAll("@", _battleScene->getCurrentPlayerPokemon()->getName());
			DIALOGUE->replaceAll("#", _battleScene->getCurrentPlayerPokemon()->getVSkill()[_skillSelectNum]->getName());
		}
	}

	if (KEYMANAGER->isOnceKeyDown('C'))
	{
		if (_isFightSelect ||
			_isPokemonSelect ||
			_isBagSelect ||
			_isRunAwaySelect)
			this->selectReset();
	}
}

void battleSceneUI::selectReset()
{
	_isFightSelect = false;
	_isPokemonSelect = false;
	_isBagSelect = false;
	_isRunAwaySelect = false;
}

void battleSceneUI::printElement(ELEMENT el)
{
	string temp;
	switch (el)
	{
		case ELEMENT_NORMAL:
			temp = "�븻";
		break;

		case ELEMENT_FIRE:
			temp = "��";
		break;

		case ELEMENT_WATER:
			temp = "��";
		break;

		case ELEMENT_ELECTRIC:
			temp = "����";
		break;

		case ELEMENT_PLANT:
			temp = "Ǯ";
		break;

		case ELEMENT_ICE:
			temp = "����";
		break;

		case ELEMENT_FIGHT:
			temp = "����";
		break;

		case ELEMENT_POISON:
			temp = "��";
		break;

		case ELEMENT_EARTH:
			temp = "��";
		break;

		case ELEMENT_WING:
			temp = "����";
		break;

		case ELEMENT_ESPER:
			temp = "������";
		break;

		case ELEMENT_INSECT:
			temp = "����";
		break;

		case ELEMENT_ROCK:
			temp = "����";
		break;

		case ELEMENT_GHOST:
			temp = "����";
		break;

		case ELEMENT_DRAGON:
			temp = "��";
		break;

		case ELEMENT_DARK:
			temp = "��";
		break;

		case ELEMENT_STEEL:
			temp = "��ö";
		break;
	}

	TextOut(getMemDC(), 327, 300, temp.c_str(), strlen(temp.c_str()));
}