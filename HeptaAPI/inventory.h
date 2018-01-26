#pragma once
#include "gameNode.h"
#include "item.h"
#include <vector>

#define ITEM_MAX 6

enum WINDOWSTATUSS //����ȭ���� ���°�
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
	bool isSelect; // ���� �����Ҽ� �ִ� ��ư�� ��������
	bool Selected; // ���õ� ��
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
	SelectButtonS _selectItem[INDEXS_BUTTON_END]; //�����۱���â

	int _WS; //����ġ�� ���� ��

	int SelectNum; //mainmenu selectNum
	int IndexSelectNum; //�����۱���â

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

