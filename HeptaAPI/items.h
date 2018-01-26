#pragma once
#include "gameNode.h"


enum ITEMKIND
{
	ITEM_TOOL,
	ITEM_POSITON,
	ITEM_BALL,
	ITEM_MACHINE
};

struct tagItem
{
	image* image;		//이미지
	ITEMKIND kind;		//종류
	string itemName;	//이름
	string dis;			//설명
	RECT rc;
	float x, y;
	int ability;		//능력
	int price;			//가격
	int itemNum;		//고유 번호
};

class items : public gameNode
{
protected:
	tagItem _item;
	float _x, _y;

public:
	items();
	~items();

	virtual HRESULT init();
	//이미지이름, 아이템종류 , 아이템이름 , 아이템설명 , 아이템능력 , 아이템가격 , 아이템번호
	virtual HRESULT init(string imageName , ITEMKIND itemKind , string itemName , string itemDis, int ability , int price , int itemNum);
	virtual void release();
	virtual void update();
	virtual void render();

	virtual void rectDraw(float x, float y , float width , float height);
	
	void setRect(RECT item) { _item.rc = item; }

	tagItem getItemInfo() { return _item; }
	RECT getItemRect() { return _item.rc; }
};

