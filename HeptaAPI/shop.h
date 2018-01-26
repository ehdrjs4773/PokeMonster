#pragma once
#include "gameNode.h"


enum SHOPSTATE
{
	SHOP_MENU,
	SHOP_KIND_SELECT,
	SHOP_SHOPPING,
	SHOP_SELL,
	SHOP_BUYITEM
};

enum SHOP_ITEM_KIND
{
	SHOP_ITEM_TOOL,
	SHOP_ITEM_POSTION,
	SHOP_ITEM_BALL,
	SHOP_ITEM_MACHINE
};

enum SHOP_SELECT_POSTION
{
	SHOP_UP,
	SHOP_MIDDLE,
	SHOP_DOWN
};

struct SHOP_MENU_RC
{
	RECT rc;
	float x, y;
	int width, height;
	SHOP_ITEM_KIND kind;
};

class jm_itemManager;

class shop : public gameNode
{
private:
	jm_itemManager* _im;

private:
	//상점 띄워주는 상태
	SHOPSTATE _state;

	//위 중간 아래
	SHOP_SELECT_POSTION _pos;
	//아이템 종류
	SHOP_ITEM_KIND _kind;

//변수보관함
private:
	int _currentFrameY_1, _currentFrameY_2, _currentFrameY_3, _currentFrameY_4;


//렉트 보관함
private:
	//선택박스
	RECT _selectBox;
	float _x, _y;
	int _width, _height;

	//사러간다 , 팔러간다 , 나간다
	SHOP_MENU_RC _select_menu[3];

	//도구 , 포션 , 볼 , 머신
	SHOP_MENU_RC _select_item_kind[4];

public:
	shop();
	~shop();

	HRESULT init();
	void release();
	void update();
	void render();

	void drawRect_shop();
	void drawRect_select();
	void drawScreen();
	void select_rect_move();
	void shopUpdate();

	//선택박스 초기화 startX , startY , 가로크기 , 세로크기
	void selectBoxInit(float x, float y, int width, int height);
	
};

