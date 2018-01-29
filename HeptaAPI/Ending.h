#pragma once
#include "gameNode.h"


class Ending : public gameNode
{
public:
	Ending();
	~Ending();


	virtual HRESULT init();
	virtual void release(void);
	virtual void update(void);
	virtual void render(void);

};

