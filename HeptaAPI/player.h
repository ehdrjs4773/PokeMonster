#pragma once
#include "gameNode.h"
#include "pokemon.h"
#include <vector>

enum playerDirection
{
	GOLD_RIGHT_STOP = 1,
	GOLD_LEFT_STOP,
	GOLD_FRONT_STOP,
	GOLD_BACK_STOP,
	GOLD_RIGHT_MOVE,
	GOLD_LEFT_MOVE,
	GOLD_FRONT_MOVE,
	GOLD_BACK_MOVE
};

class player : public gameNode
{
private:
	image* _player;
	float _x;
	float _y;
	
	RECT _playerRc;
	float _speed;
	playerDirection _playerDirection;
	int _currentStage;
	int _badgeCount;

	animation* _playerMotion;

	vector<pokemon*> _vPokemon;
	bool _isAllDie;


public:
	player();
	~player();

	HRESULT init();
	void release();
	void update();
	void render();

	//static void _rightStop(void* obj);
	//static void _leftStop(void* obj);
	//static void _frontStop(void* obj);
	//static void _backStop(void* obj);

	inline void setPlayerPt(POINT pt)
	{
		_x = pt.x;
		_y = pt.y;
		_playerRc = RectMakeCenter(_x, _y, _player->getFrameWidth(), _player->getFrameHeight());
	}

	inline RECT getPlayerRc() { return _playerRc; }
	inline void setCurrentStage(int x) {  _currentStage = x; }


	//플레이어 방향 접근자,설정자
	inline playerDirection getPlayerDirection(void) { return _playerDirection; }
	inline void setPlayerDirection(playerDirection direction) { _playerDirection = direction; }
	inline int getCurrengStage() { return _currentStage; }

	//플레이어 모션 접근자,설정자
	animation* getPlayerMotion(void) { return _playerMotion; }
	void setPlayerMotion(animation* ani) { _playerMotion = ani; }

	inline int getBadgeCount() { return _badgeCount; }
	inline void setBadgeCount(int count) { _badgeCount = count; }
	inline bool isAllDie() { return _isAllDie; }

	inline int getMaxLevel()
	{
		int max = 0;
		for (int i = 0; i < _vPokemon.size(); ++i)
		{
			if (max < _vPokemon[i]->getLevel())
				max = _vPokemon[i]->getLevel();
		}

		return max;
	}

};

