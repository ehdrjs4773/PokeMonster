#pragma once
#include "gameNode.h"
#include "stageManager.h"

class drOHouse : public stageManager 
{

private:
	image * _background;	//보이는 배경
	image* _drO;			//오박사 이미지

	float _x, _y;			//오박사 x,y
	RECT _drORc;		//오박사 렉트

	

public:
	drOHouse();
	~drOHouse();

	HRESULT init();
	void release();
	void update();
	void render();

	void collision();
};

