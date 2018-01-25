#pragma once
#include "gameNode.h"
#include <string>

enum ITEM_TYPE 
{
	//ITEM_BALL,
	//ITEM_POTION,
	//ITEM_UTILS,
	//ITEM_MACHINE,
	//ITEM_END
	ITEM_NORMAL,
	ITEM_WEAPON ,
	ITEM_ARMOR,
	ITEM_ACCESORY,
	ITEM_POTION,
	ITEM_END

};



class item : public gameNode
{
private:
	image* _image;
	RECT _rc;
	ITEM_TYPE	_itemKind;		//������ ����
	string	_name;			//������ �̸�
	string	_description;	//������ ����
	int		_ability;		//������ �ɷ�
	int		_price;			//������ ����
	int		_item_no;		//������ ������ȣ



public:
	item();
	~item();

	HRESULT init(int itemNum, ITEM_TYPE type, string name, string ds, int ability, int price);
	void release(void);
	void update(void);
	void render(HDC hdc);
	void render(HDC hdc, int destX, int destY, int itemNum);
	void itemSetup(int itemNum, ITEM_TYPE type, string name, string ds, int ability, int price);


};

