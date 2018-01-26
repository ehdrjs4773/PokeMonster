#pragma once
#include "items.h"

class tool : public items
{

public:
	tool();
	~tool();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	virtual void rectDraw(float x, float y, float width, float height);

	virtual void useItem();

	tagItem getItemInfo() { return _item; }
};

