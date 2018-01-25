#pragma once
#include "gameNode.h"
#include "itemManager.h"

#define ITEM_MAX 6

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
	INDEX_BUTTON_END

};

struct SelectButton
{
	RECT rc;
	POINT pt;
	bool isSelect; // ���� �����Ҽ� �ִ� ��ư�� ��������
	bool Selected; // ���õ� ��
};

class shopScene : public gameNode
{
private:

	SelectButton _selectMenu[BUTTON_END];
	SelectButton _selectItem[INDEX_BUTTON_END]; //�����۱���â
	int SelectNum; //mainmenu selectNum
	int IndexSelectNum; //�����۱���â

	itemManager* _item;

public:
	HRESULT init();
	void release();
	void update();
	void render();

	void shopMainMenuDraw();
	void shopBuyMenuDraw();
	void MenuSelectMove(); //�޴�
	void ShopelectMove();

	shopScene();
	~shopScene();
};

