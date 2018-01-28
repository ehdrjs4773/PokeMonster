#pragma once
#include "gameNode.h"
#include "stageManager.h"

class fighterMap : public stageManager
{
private:
	image * _background;	//���̴� ���
	


	float _x, _y;			//ü���� ���� x,y
	RECT _gymLeaderRc;		//ü���� ���� ��Ʈ
	bool _isWin;			//���� �̰�����
public:
	fighterMap();
	~fighterMap();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
};

