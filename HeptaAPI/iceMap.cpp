#include "stdafx.h"
#include "iceMap.h"

#include "player.h"
#include "battleScene.h"


iceMap::iceMap()
{
	_isWin = false;
}


iceMap::~iceMap()
{
}

HRESULT iceMap::init()
{
	stageManager::init();

	_background = IMAGEMANAGER->addImage("¾óÀ½¸Ê", ".\\bmps\\map\\¾óÀ½.bmp", 0, 0, WINSIZEX, WINSIZEY, false, true, MAGENTA);
	_gymLeader = IMAGEMANAGER->addImage("¾óÀ½NPC", ".\\bmps\\map\\¾óÀ½NPC.bmp", 25, 28, false, true, MAGENTA);
	_player->setCurrentStage(8); //ÇöÀç ½ºÅ×ÀÌÁö Á¤º¸ ³Ñ°ÜÁØ´Ù

	_x = WINSIZEX / 2 - 12;
	_y = 15;

	_gymLeaderRc = RectMake(_x, _y, _gymLeader->getWidth(), _gymLeader->getHeight());

	int level = 5 + 5 * _player->getBadgeCount();
	_vPokemon.clear();
	// ±¸±¸, ±úºñÂü, ÇÇÁ¸, ±úºñµå¸±Á¶, ÇÇÁ¸Åõ, ÆÄ¿À¸®
	pokemon* temp[6];
	skill* tempSkill;
	for (int i = 0; i < 6; ++i)
	{
		temp[i] = new pokemon;

		if (i == 0)
		{
			temp[i]->init("ÁêÁê", level);
			tempSkill = new skill;
			tempSkill->init("¸öÅë¹ÚÄ¡±â");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("´«º¸¶ó");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("¿À·Î¶óºö");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("³Ãµ¿ºö");
			temp[i]->addSkill(tempSkill);
		}
		else if (i == 1)
		{
			temp[i]->init("½©", level);
			tempSkill = new skill;
			tempSkill->init("¸öÅë¹ÚÄ¡±â");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("´«º¸¶ó");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("¿À·Î¶óºö");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("³Ãµ¿ºö");
			temp[i]->addSkill(tempSkill);
		}
		else if (i == 2)
		{
			temp[i]->init("Áê·¹°ï", level);
			tempSkill = new skill;
			tempSkill->init("¸öÅë¹ÚÄ¡±â");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("´«º¸¶ó");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("¿À·Î¶óºö");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("³Ãµ¿ºö");
			temp[i]->addSkill(tempSkill);
		}
		else if (i == 3)
		{
			temp[i]->init("½©·¯", level);
			tempSkill = new skill;
			tempSkill->init("¸öÅë¹ÚÄ¡±â");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("´«º¸¶ó");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("¿À·Î¶óºö");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("³Ãµ¿ºö");
			temp[i]->addSkill(tempSkill);
		}
		else if (i == 4)
		{
			temp[i]->init("¶óÇÁ¶ó½º", level);
			tempSkill = new skill;
			tempSkill->init("¸öÅë¹ÚÄ¡±â");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("´«º¸¶ó");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("¿À·Î¶óºö");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("³Ãµ¿ºö");
			temp[i]->addSkill(tempSkill);
		}
		else if (i == 5)
		{
			temp[i]->init("·çÁê¶ó", level);
			tempSkill = new skill;
			tempSkill->init("¸öÅë¹ÚÄ¡±â");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("´«º¸¶ó");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("¿À·Î¶óºö");
			temp[i]->addSkill(tempSkill);
			tempSkill = new skill;
			tempSkill->init("³Ãµ¿ºö");
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

void iceMap::release()
{

}

void iceMap::update()
{
	stageManager::update();
	_gymLeaderRc = RectMake(_x, _y, _gymLeader->getWidth(), _gymLeader->getHeight());

	if (_player->getPlayerRc().top >= WINSIZEY)
	{
		SCENEMANAGER->changeScene("¿ùµå¸Ê¾À");
		SCENEMANAGER->init("¿ùµå¸Ê¾À");
	}
}

void iceMap::render()
{
	
	IMAGEMANAGER->findImage("¾óÀ½¸Ê")->render(getMemDC());
	if (!_isWin)
	{
		IMAGEMANAGER->findImage("¾óÀ½NPC")->render(getMemDC(), _x, _y);
	}
	stageManager::render();
}
void iceMap::collision()
{
	RECT temp;
	if (IntersectRect(&temp, &_gymLeaderRc, &_player->getPlayerRc()) && _isWin == false)
	{
		int tempWidth = temp.right - temp.left;
		int tempHeight = temp.bottom - temp.top;

		// °¡·ÎÃæµ¹
		if (tempHeight > tempWidth)
		{
			//¿À¸¥ÂÊ Ãæµ¹
			if (temp.left == _player->getPlayerRc().left)
			{
				_player->setPlayerPt(PointMake(_gymLeaderRc.right + (_player->getPlayerRc().right - _player->getPlayerRc().left) / 2,
					(_player->getPlayerRc().bottom + _player->getPlayerRc().top) / 2));
			}
			//¿ÞÂÊÃæµ¹
			if (temp.right == _player->getPlayerRc().right)
			{
				_player->setPlayerPt(PointMake(_gymLeaderRc.left - (_player->getPlayerRc().right - _player->getPlayerRc().left) / 2,
					(_player->getPlayerRc().bottom + _player->getPlayerRc().top) / 2));
			}
		}
		else
		{
			//¾Æ·¡Ãæµ¹
			if (temp.top == _player->getPlayerRc().top)
			{
				_player->setPlayerPt(PointMake((_player->getPlayerRc().right + _player->getPlayerRc().left) / 2,
					temp.bottom + (_player->getPlayerRc().bottom - _player->getPlayerRc().top) / 2));
			}
		}
		if (KEYMANAGER->isOnceKeyDown(PLAYER_SELECT_KEY))
		{
			// ¿©±â¶û
			SCENEMANAGER->changeScene("battleScene");
			battleScene* tempBattle = (battleScene*)SCENEMANAGER->findScene("battleScene");
			tempBattle->setEnemyType(ENEMY_TRAINNER);
			tempBattle->setDestScene("½ºÅ×ÀÌÁö8");
			tempBattle->init(8);
		}
	}
}

