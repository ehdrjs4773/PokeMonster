#pragma once
#include "gameNode.h"

class drHouseScene : public gameNode
{
private:
	image* _background;
	image* _drO;
	float _x, _y;
	RECT _drRc;

public:
	drHouseScene();
	~drHouseScene();

	HRESULT init();
	void release();
	void update();
	void render();
};

