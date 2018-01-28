#pragma once
#include "gameNode.h"
#include "stageManager.h"

class drOHouse : public stageManager 
{

private:
	image * _background;	//���̴� ���
	

	float _x, _y;			//ü���� ���� x,y
	RECT _gymLeaderRc;		//ü���� ���� ��Ʈ
	bool _isWin;			//���� �̰�����

public:
	drOHouse();
	~drOHouse();

	HRESULT init();
	void release();
	void update();
	void render();
};

