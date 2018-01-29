#pragma once
#include "gameNode.h"
#include "stageManager.h"

class fighterMap : public stageManager
{
private:
	image * _background;	//���̴� ���
	image* _gymLeader;	//ü���� ���� �̹���


	float _x, _y;			//ü���� ���� x,y
	RECT _gymLeaderRc;		//ü���� ���� ��Ʈ

public:
	fighterMap();
	~fighterMap();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	void collision();
};

