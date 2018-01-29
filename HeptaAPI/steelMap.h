#pragma once
#include "gameNode.h"
#include "stageManager.h"

class steelMap : public stageManager
{
private:
	image* _background;	//���̴� ���
	image* _gymLeader;	//ü���� ���� �̹���


	float _x, _y;			//ü���� ���� x,y
	RECT _gymLeaderRc;		//ü���� ���� ��Ʈ

public:
	steelMap();
	~steelMap();

	HRESULT init();
	void release();
	void update();
	void render();

	void collision();
};

