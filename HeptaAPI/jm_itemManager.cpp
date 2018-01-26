#include "stdafx.h"
#include "jm_itemManager.h"



jm_itemManager::jm_itemManager()
{
}


jm_itemManager::~jm_itemManager()
{
}

HRESULT jm_itemManager::init()
{
	IMAGEMANAGER->addImage("item_postion", ".\\bmps\\items\\item_hpPostion.bmp", 29, 40, false, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("item_bike", ".\\bmps\\items\\item_bike.bmp", 40, 40, false, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("item_monsterBall", ".\\bmps\\items\\item_monsterBall.bmp", 40, 40, false, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("item_machine", ".\\bmps\\items\\item_machine_1.bmp", 40, 40, false, true, RGB(255, 0, 255));

	return S_OK;
}
void jm_itemManager::release()
{

}
void jm_itemManager::update() 
{

}
void jm_itemManager::render() 
{

}

void jm_itemManager::imageDraw_tool(float x, float y)
{
	_x = x;
	_y = y;

	//도구
	for (_viItem_tool = _vItem_tool.begin(); _viItem_tool != _vItem_tool.end(); ++_viItem_tool)
	{	
		RECT _item;
		(*_viItem_tool)->setRect(_item = RectMake(_x, _y, 50, 50));
		(*_viItem_tool)->getItemInfo().image->render(getMemDC(), _x, _y);	

		TextOut(getMemDC(), _x + 60, _y, (*_viItem_tool)->getItemInfo().itemName.c_str(),
			strlen((*_viItem_tool)->getItemInfo().itemName.c_str()));
		TextOut(getMemDC(), _x + 60, _y + 15, (*_viItem_tool)->getItemInfo().dis.c_str(), 
			strlen((*_viItem_tool)->getItemInfo().dis.c_str()));
		
	}

}

void jm_itemManager::imageDraw_postion(float x, float y)
{
	_x = x;
	_y = y;

	//포션
	for (_viItem_postion = _vItem_postion.begin(); _viItem_postion != _vItem_postion.end(); ++_viItem_postion)
	{
		RECT _item;
		(*_viItem_postion)->setRect(_item = RectMake(_x, _y, 50, 50));
		(*_viItem_postion)->getItemInfo().image->render(getMemDC(), _x, _y);

		TextOut(getMemDC(), _x + 60, _y, (*_viItem_postion)->getItemInfo().itemName.c_str(),
			strlen((*_viItem_postion)->getItemInfo().itemName.c_str()));
		TextOut(getMemDC(), _x + 60, _y + 15, (*_viItem_postion)->getItemInfo().dis.c_str(),
			strlen((*_viItem_postion)->getItemInfo().dis.c_str()));
	}
}

void jm_itemManager::imageDraw_ball(float x, float y)
{
	_x = x;
	_y = y;

	//몬스터볼
	for (_viItem_ball = _vItem_ball.begin(); _viItem_ball != _vItem_ball.end(); ++_viItem_ball)
	{
		RECT _item;
		(*_viItem_ball)->setRect(_item = RectMake(_x, _y, 50, 50));
		(*_viItem_ball)->getItemInfo().image->render(getMemDC(), _x, _y);

		TextOut(getMemDC(), _x + 60, _y, (*_viItem_ball)->getItemInfo().itemName.c_str(),
			strlen((*_viItem_ball)->getItemInfo().itemName.c_str()));
		TextOut(getMemDC(), _x + 60, _y + 15, (*_viItem_ball)->getItemInfo().dis.c_str(),
			strlen((*_viItem_ball)->getItemInfo().dis.c_str()));
	}
}

void jm_itemManager::imageDraw_machine(float x, float y)
{
	_x = x;
	_y = y;

	//머신
	for (_viItem_machine = _vItem_machine.begin(); _viItem_machine != _vItem_machine.end(); ++_viItem_machine)
	{
		RECT _item;
		(*_viItem_machine)->setRect(_item = RectMake(_x, _y, 50, 50));
		(*_viItem_machine)->getItemInfo().image->render(getMemDC(), _x, _y);

		TextOut(getMemDC(), _x + 60, _y, (*_viItem_machine)->getItemInfo().itemName.c_str(),
			strlen((*_viItem_machine)->getItemInfo().itemName.c_str()));
		TextOut(getMemDC(), _x + 60, _y + 15, (*_viItem_machine)->getItemInfo().dis.c_str(),
			strlen((*_viItem_machine)->getItemInfo().dis.c_str()));
	}
}

void jm_itemManager::addItem_tool()
{
	items* tool_item;
	tool_item = new tool;
	tool_item->init("item_bike", ITEM_TOOL, "-자전거-", "장착시 이속증가", 5, 50, 101);

	_vItem_tool.push_back(tool_item);
}
void jm_itemManager::addItem_postion()
{
	items* postion_item;
	postion_item = new postion;
	postion_item->init("item_postion", ITEM_POSITON, "-HP포션-", "마시면 HP가 회복", 30, 50, 201);

	_vItem_postion.push_back(postion_item);
}
void jm_itemManager::addItem_ball()	  
{
	items* ball_item;
	ball_item = new ball;
	ball_item->init("item_monsterBall", ITEM_BALL, "-몬스터볼-", "가랏! 몬스터볼!", NULL , 100, 301);

	_vItem_ball.push_back(ball_item);
}
void jm_itemManager::addItem_machine()
{
	items* machine_item;
	machine_item = new postion;
	machine_item->init("item_machine", ITEM_MACHINE, "-기계 머신-", "??????", NULL , 300, 401);

	_vItem_machine.push_back(machine_item);
}

