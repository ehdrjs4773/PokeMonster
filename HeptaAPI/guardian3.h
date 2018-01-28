#pragma once
#include "gameNode.h"
#include "stageManager.h"

class guardian3 : public stageManager
{
private:
	image* _background;	//���̴� ���
	image* _gymLeader;	//ü���� ���� �̹���


	float _x, _y;			//ü���� ���� x,y
	RECT _gymLeaderRc;		//ü���� ���� ��Ʈ
	bool _isWin;			//���� �̰�����

public:
	guardian3();
	~guardian3();

	HRESULT init();
	void release();
	void update();
	void render();
};
