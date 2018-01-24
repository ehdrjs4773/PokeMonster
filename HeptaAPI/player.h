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

	//�÷��̾� ���� ������,������
	playerDirection getPlayerDirection(void) { return _playerDirection; }
	void setPlayerDirection(playerDirection direction) { _playerDirection = direction; }

	//�÷��̾� ��� ������,������
	animation* getPlayerMotion(void) { return _playerMotion; }
	void setPlayerMotion(animation* ani) { _playerMotion = ani; }
};

