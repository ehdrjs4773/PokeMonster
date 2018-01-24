#pragma once
#include "gameNode.h"

const int Opening_Speed  = 3;


enum OpeningSin
{
	Opening_One,
	Opening_Two,
	Opening_Three,
	Opening_Four
};

class Opening : public gameNode
{
private :
	
	OpeningSin _opening;


	// OPENING �� ��ǥ //
	int _x, _y;
	//================//


	// OPENING2 ���� ��ǥ//
	int _loopx, _loopy;
	//==================//
	

	// Player1, Player2 ��ǥ//

	float _p1x, _p1y;
	float _p2x, _p2y;
	//======================//

	// SIN ��ǥ //

	int _sin1x, _sin1y, _sin2x, _sin2y, _sin3x, _sin3y;



public:
	Opening();
	~Opening();


	virtual HRESULT init(void);
	virtual void render(void);
	virtual void update(void);
	virtual void release(void);

};

