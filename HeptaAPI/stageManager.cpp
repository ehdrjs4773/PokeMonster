#include "stdafx.h"
#include "stageManager.h"
#include "player.h"
#include "battleScene.h"

stageManager::stageManager()
	: _player(NULL)
{
}
stageManager::~stageManager()
{
}


HRESULT stageManager::init()
{
	_gymLeader = IMAGEMANAGER->addFrameImage("npc", ".\\bmps\\map\\인게임npc.bmp", 325, 28, 13, 1, false, true, MAGENTA);
	this->setPlayerAddressLink(DATABASE->getPlayerMemory());
	_player->init();
	_regenTime = 1;

	return S_OK;
}
void stageManager::release()
{

}
void stageManager::update()	
{
	_player->update();
	if (_player->getCurrengStage() != 9 &&
		_player->getCurrengStage() != 10 &&
		_player->getCurrengStage() != 11 &&
		_player->getCurrengStage() != 12 &&
		_player->getCurrengStage() != 13)
	{
		if (_isWin)
		{
			if (_player->getPlayerDirection() == GOLD_RIGHT_MOVE ||
				_player->getPlayerDirection() == GOLD_LEFT_MOVE ||
				_player->getPlayerDirection() == GOLD_FRONT_MOVE ||
				_player->getPlayerDirection() == GOLD_BACK_MOVE)
				_regenTime++;

			if (_regenTime % 200 == 0)
			{
				this->regenPokemon();
			}
		}
	}
}
void stageManager::render()	
{
	_player->render();

}

void stageManager::regenPokemon()
{
	pokemon* regenPokemon = new pokemon;
	int rnd = RND->getInt(_vPokemon.size());
	int rndLevel = RND->getFromIntTo(_player->getMaxLevel() - 3, _player->getMaxLevel() + 3);
	regenPokemon->init(_vPokemon[rnd]->getName(), rndLevel);
	skill* tempSkill;
	for (int i = 0; i < _vPokemon[rnd]->getVSkill().size(); ++i)
	{
		tempSkill = new skill;
		tempSkill->init(_vPokemon[rnd]->getVSkill()[i]->getName());
		regenPokemon->addSkill(tempSkill);
	}
	vector<pokemon*>* tempEnemyPokemon = new vector<pokemon*>;
	tempEnemyPokemon->push_back(regenPokemon);
	DATABASE->setVEnemyPokemon(tempEnemyPokemon);
	char temp[32];
	sprintf(temp, "스테이지%d", _player->getCurrengStage());

	// 여기랑
	SCENEMANAGER->changeScene("battleScene");
	battleScene* tempBattle = (battleScene*)SCENEMANAGER->findScene("battleScene");
	tempBattle->setEnemyType(ENEMY_WILD);
	tempBattle->setDestScene(temp);
	tempBattle->init(_player->getCurrengStage());
	_regenTime = 1;
}