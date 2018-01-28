#pragma once
#include "gameNode.h"

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

	animation* _playerMotion;


public:
	player();
	~player();

	HRESULT init();
	void release();
	void update();
	void render();

	static void _rightStop(void* obj);
	static void _leftStop(void* obj);
	static void _frontStop(void* obj);
	static void _backStop(void* obj);

	inline RECT getPlayerRc() { return _playerRc; }
	

	//�÷��̾� ���� ������,������
	playerDirection getPlayerDirection(void) { return _playerDirection; }
	void setPlayerDirection(playerDirection direction) { _playerDirection = direction; }

	//�÷��̾� ��� ������,������
	animation* getPlayerMotion(void) { return _playerMotion; }
	void setPlayerMotion(animation* ani) { _playerMotion = ani; }
};

