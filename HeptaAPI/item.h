#pragma once
#include "gameNode.h"
#include <string>

enum ITEM_TYPE 
{
	ITEM_NULL,	//초기화용
	ITEM_UTILS,	//item_kind_1 
	ITEM_POTION,	//item_kind_2
	ITEM_BALL,	//item_kinde_4
	ITEM_MACHINE,	//item_kind_4
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
	int		_itemNum;		//아이템 개수




public:
	item();
	~item();

	HRESULT init(int itemNum, ITEM_TYPE type, string name, string ds, int ability, int price);
	HRESULT init(int itemNum, image* img, ITEM_TYPE type, string name, string ds, int ability, int price);
	void release(void);
	void update(void);
	void render(HDC hdc);
	void render(HDC hdc, int destX, int destY, int itemNum);
	void render(HDC hdc, image* img, int destX, int destY, int itemNum);
	void InvenRender(HDC hdc, image* img, int destX, int destY);


	//item's getter setter
	int getItemNum() { return _itemNum; } // 아이템 개수 가져가는 함수
	void setItemNum(int num) { _itemNum = num; } // 아이템 개수 설정하는 함수

	image* getImg() { return _image; } // 이미지 가져가는 함수

	int getItemAbility() { return _ability; } // 아이템 능력치 가져가는 함수
	ITEM_TYPE getType() { return _itemKind; } //아이템 종류 가져가는 함수
	string getName() { return _name; }


};

