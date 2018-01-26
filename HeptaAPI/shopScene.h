#pragma once
#include "gameNode.h"
#include "itemManager.h"
#include "inventory.h"

#define ITEM_MAX 6
#define ITEMSLOT_FIRSTX 60
#define ITEMSLOT_FIRSTY 80


enum WINDOWSTATUS //현재화면의 상태값
{
	WS_MAIN,
	WS_BUY,
	WS_SELL,
	WS_CANCEL,
	WS_END
};


enum CHOICEBUTTON
{
	BUTTON_BUY,
	BUTTON_SELL,
	BUTTON_CANCEL,
	BUTTON_END
};

enum INDEXBUTTON
{
	INDEX_BUTTON_0, INDEX_BUTTON_1,
	INDEX_BUTTON_2, INDEX_BUTTON_3,
	INDEX_BUTTON_4, INDEX_BUTTON_5,
	INDEX_BUTTON_CANCEL,
	INDEX_BUTTON_END

};

struct SelectButton
{
	RECT rc;
	POINT pt;
	bool isSelect; // 현재 선택할수 있는 버튼이 무엇인지
	bool Selected; // 선택된 것
};

class shopScene : public gameNode
{
private:
	typedef vector<item*> vItem;
	typedef vector<item*>::iterator viItem;

private:
	vItem _vInventory;
	viItem _viInventory;
	SelectButton _selectMenu[BUTTON_END];
	SelectButton _selectItem[INDEX_BUTTON_END]; //아이템구매창

	int _WS; //스위치용 상태 값

	int SelectNum; //mainmenu selectNum
	int IndexSelectNum; //아이템구매창

	itemManager* _item;
	inventory* _inven;

public:
	HRESULT init();
	void release();
	void update();
	void render();

	void shopMainMenuDraw();
	void shopBuyMenuDraw();
	void KeyControl();

	inline void changeWS(int WS) { _WS = WS; }

	shopScene();
	~shopScene();
};

