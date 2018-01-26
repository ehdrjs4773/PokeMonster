#pragma once
#include "items.h"

class postion : public items
{
private:

public:
	postion();
	~postion();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	virtual void rectDraw(float x, float y);

	virtual void useItem();
};

