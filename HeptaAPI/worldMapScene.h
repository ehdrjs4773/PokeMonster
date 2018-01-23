#pragma once
#include "gameNode.h"

#define GYM_MAX 9

enum GYM
{
	GYM_0 = 0,
	GYM_1,
	GYM_2,
	GYM_3,
	GYM_4,
	GYM_5,
	GYM_6,
	GYM_7,
	GYM_8,
	GYM_END
};

struct select
{
	RECT rc;
	POINT pt;
	bool isSelect;
};

class worldMapScene : public gameNode
{
private:
	select _select[GYM_END];
	int SelectNum;
	int _isClear[GYM_END];

public:
	HRESULT init();
	void release();
	void update();
	void render();
	void selectMove();

	worldMapScene();
	~worldMapScene();
};
