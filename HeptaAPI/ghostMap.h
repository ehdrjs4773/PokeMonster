#pragma once
#include "gameNode.h"
#include "stageManager.h"

class ghostMap : public stageManager
{
private:
	image* _background;	//���̴� ���
	image* _gymLeader;	//ü���� ���� �̹���


	float _x, _y;			//ü���� ���� x,y
	RECT _gymLeaderRc;		//ü���� ���� ��Ʈ
	bool _isWin;			//���� �̰�����
public:
	ghostMap();
	~ghostMap();

	HRESULT init();
	void release();
	void update();
	void render();
};

