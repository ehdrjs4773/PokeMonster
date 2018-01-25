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
	ITEM_TYPE	_itemKind;		//아이템 종류
	string	_name;			//아이템 이름
	string	_description;	//아이템 설명
	int		_ability;		//아이템 능력
	int		_price;			//아이템 가격
	int		_item_no;		//아이템 고유번호



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

