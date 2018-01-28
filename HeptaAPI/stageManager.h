#pragma once
#include "gameNode.h"
#include "player.h"



class stageManager : public gameNode
{
protected:
	player* _player;
	image* _gymLeader;		//체육관 관장

	

public:
	stageManager();
	~stageManager();

	HRESULT init();
	void release();
	void update();
	void render();
};

