#pragma once
#include "gameNode.h"
#include "tool.h"
#include "postion.h"
#include "machine.h"
#include "ball.h"
#include <vector>


class jm_itemManager : public gameNode
{
private:
	typedef vector<items*> vItem;
	typedef vector<items*>::iterator viItem;

private:
	//도구
	vItem _vItem_tool;
	viItem _viItem_tool;
	//포션
	vItem _vItem_postion;
	viItem _viItem_postion;
	//몬스터볼
	vItem _vItem_ball;
	viItem _viItem_ball;
	//머신
	vItem _vItem_machine;
	viItem _viItem_machine;

private:
	float _x, _y;

public:
	jm_itemManager();
	~jm_itemManager();

	HRESULT init();
	void release();
	void update();
	void render();

	void imageDraw_tool(float x ,float y);
	void imageDraw_postion(float x, float y);
	void imageDraw_ball(float x, float y);
	void imageDraw_machine(float x, float y);

	void addItem_tool();
	void addItem_postion();
	void addItem_ball();
	void addItem_machine();

	//접근자
	vector<items*> getVItem_tool() { return _vItem_tool; }
	vector<items*>::iterator getVIItem_tool() { return _viItem_tool; }

	vector<items*> getVItem_postion() { return _vItem_postion; }
	vector<items*>::iterator getVIItem_postion() { return _viItem_postion; }

	vector<items*> getVItem_ball() { return _vItem_ball; }
	vector<items*>::iterator getVIItem_ball() { return _viItem_ball; }

	vector<items*> getVItem_machine() { return _vItem_machine; }
	vector<items*>::iterator getVIItem_machine() { return _viItem_machine; }
};

