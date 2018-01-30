#pragma once
#include "gameNode.h"


class Ending : public gameNode
{
private : 
	int _x, _y;


public:
	Ending();
	~Ending();


	virtual HRESULT init();
	virtual void release(void);
	virtual void update(void);
	virtual void render(void);

};

