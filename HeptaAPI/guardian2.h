#pragma once
#include "gameNode.h"
#include "stageManager.h"

class guardian2 : public stageManager
{
private:
	image* _background;	//보이는 배경
	image* _gymLeader;	//체육관 관장 이미지


	float _x, _y;			//체육관 관장 x,y
	RECT _gymLeaderRc;		//체육관 관장 렉트

public:
	guardian2();
	~guardian2();

	HRESULT init();
	void release();
	void update();
	void render();

	void collision();
};
