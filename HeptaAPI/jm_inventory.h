#pragma once
#include "gameNode.h"
#include <vector>

#define ITEM_KIND 4

#define INVEN_MENU_START_X 60
#define INVEN_MENU_START_Y 25
#define INVEN_MENU_WITDH 50
#define INVEN_MENU_HEIGHT 50
#define INVEN_MENU_MOVE 120

#define INVEN_MIDDLE_START_X 120
#define INVEN_MIDDLE_START_Y 108
#define INVEN_MIDDLE_WITDH 228
#define INVEN_MIDDLE_HEIGHT 67
#define INVEN_MIDDLE_LEFTANDRIGHT_MOVE 240
#define INVEN_MIDDLE_UPANDDOWN_MOVE 74

#define INVEN_DOWN_START_X 420
#define INVEN_DOWN_START_Y 330
#define INVEN_DOWN_WITDH 116
#define INVEN_DOWN_HEIGHT 43

enum INVENTORYSTATE
{
	INVEN_TOOL,			//도구
	INVEN_POSTION,		//포션
	INVEN_BALL,			//볼
	INVEN_MACHINE		//머신?
};

enum INVENTORYITEMKIND
{
	INVEN_ITEM_TOOL,
	INVEN_ITEM_POSTION,
	INVEN_ITEM_BALL,
	INVEN_ITEM_MACHINE
};

enum SELECTBOX
{
	INVEN_UP,
	INVEN_MIDDLE,
	INVEN_DOWN
};

struct tagItemKindBox
{
	image* image;
	RECT rc;
	float x, y;
	INVENTORYITEMKIND kind;
};

class jm_itemManager;


class jm_inventory : public gameNode
{
private:
	//인벤상태 (포션 , 도구 같은거)
	INVENTORYSTATE _invenState;
	//선택박스
	SELECTBOX _selectBox;

	jm_itemManager* _im;	

private:

	//도구, 포션 뭐 그런 종류 선택 "당하는거"
	tagItemKindBox _item_kind_box[ITEM_KIND];

	//도구, 포션 뭐 그런 종류 선택 "하는거"
	tagItemKindBox _select_item_kind_box;
	float _x, _y;
	float _width, _height;

private:
	int _currentFrameY_1, _currentFrameY_2, _currentFrameY_3, _currentFrameY_4;
	

public:
	jm_inventory();
	~jm_inventory();

	HRESULT init();
	void release();
	void update();
	void render();

	void draw();
	void keykontrol();
	void selectKind();
};

