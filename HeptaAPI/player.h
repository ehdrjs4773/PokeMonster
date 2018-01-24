#pragma once
#include "gameNode.h"
enum playerDirection
{
	GOLD_RIGHT_IDLE,
	GOLD_LEFT_IDLE,
	GOLD_FRONT_IDLE,
	GOLD_BACK_IDLE,
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

	animation* _playerMotion;


public:
	player();
	~player();

	HRESULT init();
	void release();
	void update();
	void render();

	//플레이어 방향 접근자,설정자
	playerDirection getPlayerDirection(void) { return _playerDirection; }
	void setPlayerDirection(playerDirection direction) { _playerDirection = direction; }

	//플레이어 모션 접근자,설정자
	animation* getPlayerMotion(void) { return _playerMotion; }
	void setPlayerMotion(animation* ani) { _playerMotion = ani; }
};

