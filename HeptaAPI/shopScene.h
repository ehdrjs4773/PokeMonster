#pragma once
#include "gameNode.h"

#define ITEM_MAX 6

enum CHOICEBUTTON
{
	BUTTON_BUY,
	BUTTON_SELL,
	BUTTON_CANCEL,
	BUTTON_END

};

enum ITEM
{
	ITEM_0,
	ITEM_1,
	ITEM_2,
	ITEM_3,
	ITEM_4,
	ITEM_5,
	ITEM_END
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

	SelectButton _selectMenu[BUTTON_END];
	SelectButton _selectItem[ITEM_END];
	int SelectNum;
	bool _isClear[ITEM_END];

public:
	HRESULT init();
	void release();
	void update();
	void render();
	void MenuSelectMove(); //메뉴
	void ShopelectMove();

	shopScene();
	~shopScene();
};

