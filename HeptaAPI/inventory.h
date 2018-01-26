#pragma once
#include "gameNode.h"
#include "item.h"
#include <vector>

#define ITEM_MAX 6

enum WINDOWSTATUSS //현재화면의 상태값
{
	WSS_UTIL,	
	WSS_POTION,
	WSS_BALL,
	WSS_MACHINE,
	WSS_CANCEL,
	WSS_END
};


enum CHOICEBUTTONS
{
	BUTTONS_UTIL,
	BUTTONS_POTION,
	BUTTONS_BALL,
	BUTTONS_MACHINE,
	BUTTONS_CANCEL,
	BUTTONS_END
};

enum INDEXBUTTONS
{
	INDEXS_BUTTON_0, INDEXS_BUTTON_1,
	INDEXS_BUTTON_2, INDEXS_BUTTON_3,
	INDEXS_BUTTON_4, INDEXS_BUTTON_5,
	INDEXS_BUTTON_CANCEL,
	INDEXS_BUTTON_END

};

struct SelectButtonS
{
	RECT rc;
	POINT pt;
	bool isSelect; // 현재 선택할수 있는 버튼이 무엇인지
	bool Selected; // 선택된 것
};

class inventory : public gameNode
{
private:
	typedef vector<item*> vItem;
	typedef vector<item*>::iterator viItem;

private:
	vItem _vInventory;
	viItem _viInventory;
	SelectButtonS _selectMenu[BUTTONS_END];
	SelectButtonS _selectItem[INDEXS_BUTTON_END]; //아이템구매창

	int _WS; //스위치용 상태 값

	int SelectNum; //mainmenu selectNum
	int IndexSelectNum; //아이템구매창

public:
	inventory();
	~inventory();

	HRESULT init();
	void update();
	void release();
	void render();

	void KeyControl();
	void UtilMenuDraw();
	void PotionMenuDraw();
	void BallMenuDraw();
	void MachineMenuDraw();

	void buyItem(vector<item*>::iterator buyingItem);
	void itemPrint();


	vItem& getCurrentItem() { return _vInventory; }
	viItem& getCurrentItemIter() { return _viInventory; }


};

