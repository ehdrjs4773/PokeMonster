#pragma once
#include "gameNode.h"

class battleSceneUI : public gameNode
{
private:

public:
	battleSceneUI();
	~battleSceneUI();

	HRESULT init();
	void release();
	void update();
	void render();
};

