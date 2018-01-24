#pragma once
#include "gameNode.h"
#include "player.h"

class drHouseScene : public gameNode
{
private:
	image* _background;
	image* _drO;
	float _x, _y;
	RECT _drRc;

	player* _player;


public:
	drHouseScene();
	~drHouseScene();

	HRESULT init();
	void release();
	void update();
	void render();
};

