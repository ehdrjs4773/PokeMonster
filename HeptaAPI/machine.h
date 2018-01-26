#pragma once
#include "items.h"

class machine : public items
{
public:
	machine();
	~machine();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	virtual void rectDraw(float x, float y);

	virtual void useItem();
};

