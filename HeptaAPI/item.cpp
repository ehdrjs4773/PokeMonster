#include "stdafx.h"
#include "item.h"



item::item()
{
	_image = NULL;
	_rc = { 0,0,0,0 };
	_itemKind = ITEM_NULL;		//������ ����
	_name = { 0 };			//������ �̸�
	_description = { 0 };	//������ ����
	_ability=0;		//������ �ɷ�
	_price=0;			//������ ����
	_item_no=0;		//������ ������ȣ
}


item::~item()
{
}

HRESULT item::init(int itemNum, ITEM_TYPE type, string name, string ds, int ability, int price)
{	
	_item_no = itemNum;
	_itemKind = type;
	_name = name;
	_description = ds;
	_ability = ability;
	_price = price;

	return S_OK;
}


HRESULT item::init(int itemNum, image* img, ITEM_TYPE type, string name, string ds, int ability, int price)
{
	_image = img;
	_item_no = itemNum;
	_itemKind = type;
	_name = name;
	_description = ds;
	_ability = ability;
	_price = price;

	return S_OK;
}

void  item::release(void)
{
	
}
void  item::update(void)
{

}
void  item::render(HDC hdc)
{

}

void  item::render(HDC hdc, int destX, int destY, int itemNum)
{

	
	SetBkMode(hdc, TRANSPARENT); //�۾��������ȭ
	TextOut(hdc, destX, destY, _name.c_str(), strlen(_name.c_str()));
	TextOut(hdc, destX, destY+20, _description.c_str(), strlen(_description.c_str()));

	char temp[128];
	sprintf(temp, "%d", _ability);
	TextOut(hdc, destX, destY+40, temp, strlen(temp));
	
}

void  item::render(HDC hdc, image* img,  int destX, int destY, int itemNum)
{

	_image->render(hdc, destX-50, destY);

	SetBkMode(hdc, TRANSPARENT); //�۾��������ȭ
	TextOut(hdc, destX, destY, _name.c_str(), strlen(_name.c_str()));
	TextOut(hdc, destX, destY + 20, _description.c_str(), strlen(_description.c_str()));

	char temp[128];
	sprintf(temp, "%d", _ability);
	TextOut(hdc, destX, destY + 40, temp, strlen(temp));

}
