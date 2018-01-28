#pragma once
#include "gameNode.h"
#include "stageManager.h"

class drOHouse : public stageManager 
{

private:
	image * _background;	//보이는 배경
	

	float _x, _y;			//체육관 관장 x,y
	RECT _gymLeaderRc;		//체육관 관장 렉트
	bool _isWin;			//관장 이겼을때

public:
	drOHouse();
	~drOHouse();

	HRESULT init();
	void release();
	void update();
	void render();
};

