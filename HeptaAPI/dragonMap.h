#pragma once
#include "gameNode.h"
#include "stageManager.h"

class dragonMap : public stageManager
{
private:
	image* _background;	//보이는 배경
	image* _gymLeader;	//체육관 관장 이미지


	float _x, _y;			//체육관 관장 x,y
	RECT _gymLeaderRc;		//체육관 관장 렉트
	bool _isWin;			//관장 이겼을때

public:
	dragonMap();
	~dragonMap();

	HRESULT init();
	void release();
	void update();
	void render();
};

