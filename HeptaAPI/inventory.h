#pragma once
#include "gameNode.h"
#include "itemManager.h"
#include "item.h"
#include <vector>
#include <map>

#define ITEMSLOT_FIRSTX 5
#define ITEMSLOT_FIRSTY 75
#define ITEMSLOT_SECONDX 245
#define ITEMSLOT_SECONDY 75
#define ITEMSLOT_THIRDX  5
#define ITEMSLOT_THIRDY 150
#define ITEMSLOT_FORTHX 245
#define ITEMSLOT_FORTHY 150
#define ITEMSLOT_FIFTHX 5
#define ITEMSLOT_FIFTHY 225
#define ITEMSLOT_SIXTHX 245
#define ITEMSLOT_SIXTHY 225
#define SLOT_MAX 6

class item;
class itemManager;

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

struct InvenSlot
{
	string key;
	item* itm;
	int number;
	POINT pt;
	bool slotUse;

};


class inventory : public gameNode
{
private:
	typedef vector<item*> vItem;
	typedef vector<item*>::iterator viItem;

	typedef map<string, item*> mapItemList;
	typedef map<string, item*>::iterator mapItemIter;


private:
	mapItemList _mInvenList;	
	mapItemIter _mInvenIter;
	itemManager* _item;

	vItem _vInventory;
	viItem _viInventory;
	SelectButtonS _selectMenu[BUTTONS_END];
	SelectButtonS _selectItem[INDEXS_BUTTON_END]; //�����۱���â

	InvenSlot _invenSlot_UTIL[SLOT_MAX];
	InvenSlot _invenSlot_BALL[SLOT_MAX];
	InvenSlot _invenSlot_POTION[SLOT_MAX];
	InvenSlot _invenSlot_MACHINE[SLOT_MAX];

	item* _currentItem;

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

	void buyItems(string strKey, item* itm);	//������ ����� �Լ�
	void renderItem(string strKey, WINDOWSTATUSS ws, int num);					//�����ͼ� �κ��丮�� �׷��ִ� �Լ�
	mapItemIter findNum(int arrNum);

	item* getCurrentItem() { return _currentItem; }
	
	inline void changeWS(int WS) { _WS = WS; }



};

