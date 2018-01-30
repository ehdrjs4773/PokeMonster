#pragma once
#include "gameNode.h"
#include "stageManager.h"

class flyMap : public stageManager
{
private:
	image* _background;	//���̴� ���
	image* _gymLeader;	//ü���� ���� �̹���
	

	float _x, _y;			//ü���� ���� x,y
	RECT _gymLeaderRc;		//ü���� ���� ��Ʈ



public:
	flyMap();
	~flyMap();

	HRESULT init();
	void release();
	void update();
	void render();

	void collision();
};

