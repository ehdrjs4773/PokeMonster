#pragma once
#include "gameNode.h"
#include "player.h"



class stageManager : public gameNode
{
protected:
	player* _player;
	image* _gymLeader;		//ü���� ����

	bool _isWin;

public:
	stageManager();
	~stageManager();

	HRESULT init();
	void release();
	void update();
	void render();

	inline bool getIsWin() { return _isWin; }
};

