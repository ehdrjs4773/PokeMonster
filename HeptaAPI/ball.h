#pragma once
#include "items.h"

class ball : public items
{
public:
	ball();
	~ball();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	virtual void rectDraw(float x, float y);

	virtual void useItem();
};

