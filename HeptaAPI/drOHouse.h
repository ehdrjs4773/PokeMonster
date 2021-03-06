#pragma once
#include "gameNode.h"
#include "stageManager.h"

class drOHouse : public stageManager 
{

private:
	image * _background;	//보이는 배경
	image* _drO;			//오박사 이미지
	image* _shopNPC;

	float _x, _y;			//오박사 x,y
	RECT _gymLeaderRc;		//오박사 렉트

	RECT _shopNPCRc;
	float _x1, _y1;
	
	bool _isMonsterSelect;
	string _startingMonster[3];
	int _selectNum;

	int _dialogueTime;

public:
	drOHouse();
	~drOHouse();

	HRESULT init();
	void release();
	void update();
	void render();

	void collision();
};

