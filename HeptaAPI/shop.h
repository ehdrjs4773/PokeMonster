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
	//���� ����ִ� ����
	SHOPSTATE _state;

	//�� �߰� �Ʒ�
	SHOP_SELECT_POSTION _pos;
	//������ ����
	SHOP_ITEM_KIND _kind;

//����������
private:
	int _currentFrameY_1, _currentFrameY_2, _currentFrameY_3, _currentFrameY_4;


//��Ʈ ������
private:
	//���ùڽ�
	RECT _selectBox;
	float _x, _y;
	int _width, _height;

	//�緯���� , �ȷ����� , ������
	SHOP_MENU_RC _select_menu[3];

	//���� , ���� , �� , �ӽ�
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

	//���ùڽ� �ʱ�ȭ startX , startY , ����ũ�� , ����ũ��
	void selectBoxInit(float x, float y, int width, int height);
	
};

