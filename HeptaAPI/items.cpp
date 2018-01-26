#include "stdafx.h"
#include "items.h"


items::items()
{
}


items::~items()
{
}

HRESULT items::init()
{
	

	return S_OK;
}
HRESULT items::init(string imageName, ITEMKIND itemKind, string itemName, string itemDis, int ability, int price, int itemNum)
{
	_item.image = IMAGEMANAGER->findImage(imageName);
	_item.kind = (ITEMKIND)itemKind;
	_item.itemName = (string)itemName;
	_item.dis = (string)itemDis;
	_item.ability = ability;
	_item.price = price;
	_item.itemNum = itemNum;
	//_item.rc = RectMake(_item.image->getFrameX(), _item.image->getFrameY(), _item.image->getFrameWidth(),
	//	_item.image->getFrameHeight());
	

	return S_OK;
}
void items::release()
{

}
void items::update()
{

}
void items::render()
{

}

void items::rectDraw(float x, float y ,float width , float height)
{
	_item.rc = RectMake(x, y, width, height);
}
