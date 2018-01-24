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
	//SelectButton _selectItem[ITEM_END];
	int SelectNum;
	//bool _isClear[ITEM_END];

public:
	HRESULT init();
	void release();
	void update();
	void render();
	void MenuSelectMove(); //�޴�
	void ShopelectMove();

	shopScene();
	~shopScene();
};

