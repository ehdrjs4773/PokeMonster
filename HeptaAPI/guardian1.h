#pragma once
#include "gameNode.h"
#include "stageManager.h"

class guardian1 : public stageManager
{
private:
	image* _background;	//���̴� ���
	image* _gymLeader;	//ü���� ���� �̹���


	float _x, _y;			//ü���� ���� x,y
	RECT _gymLeaderRc;		//ü���� ���� ��Ʈ

public:
	guardian1();
	~guardian1();

	HRESULT init();
	void release();
	void update();
	void render();

	void collision();
};

