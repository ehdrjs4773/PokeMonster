#pragma once
#include "gameNode.h"
#include "player.h"



class stageManager : public gameNode
{
private:
	player* _player;
	image* _gymLeader;		//Ã¼À°°ü °üÀå

	

public:
	stageManager();
	~stageManager();

	HRESULT init();
	void release();
	void update();
	void render();
};

