#pragma once
#include "gameNode.h"
#include "stageManager.h"

class flyMap : public stageManager
{
private:
	image * _background;	//���̴� ���
	image* _pixel;			//�ȼ��浹�� �̹���

	float _x, _y;			//ü���� ���� x,y
	RECT _gymLeaderRc;		//ü���� ���� ��Ʈ
	bool _isWin;			//���� �̰�����

public:
	flyMap();
	~flyMap();

	HRESULT init();
	void release();
	void update();
	void render();
};
