#pragma once
#include "gameNode.h"
#include "stageManager.h"

class drOHouse : public stageManager 
{

private:
	image * _background;	//���̴� ���
	image* _drO;			//���ڻ� �̹���

	float _x, _y;			//���ڻ� x,y
	RECT _drORc;		//���ڻ� ��Ʈ

	

public:
	drOHouse();
	~drOHouse();

	HRESULT init();
	void release();
	void update();
	void render();

	void collision();
};

