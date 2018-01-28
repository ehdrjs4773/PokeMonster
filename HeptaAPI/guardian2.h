#pragma once
#include "gameNode.h"
#include "stageManager.h"

class guardian2 : public stageManager
{
private:
	image* _background;	//���̴� ���
	image* _gymLeader;	//ü���� ���� �̹���


	float _x, _y;			//ü���� ���� x,y
	RECT _gymLeaderRc;		//ü���� ���� ��Ʈ
	bool _isWin;			//���� �̰�����

public:
	guardian2();
	~guardian2();

	HRESULT init();
	void release();
	void update();
	void render();
};
