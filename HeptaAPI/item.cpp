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
	_itemNum=0;		//������ ����
}


item::~item()
{
}

HRESULT item::init(int itemNum, ITEM_TYPE type, string name, string ds, int ability, int price)
{	
	_itemNum = itemNum;
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
	_itemNum = itemNum;
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

void  item::render(HDC hdc, int destX, int destY, int itemNum)	//shop render image empty
{

	
	SetBkMode(hdc, TRANSPARENT); //�۾��������ȭ
	TextOut(hdc, destX+60, destY+5, _name.c_str(), strlen(_name.c_str()));
	TextOut(hdc, destX+60, destY+25, _description.c_str(), strlen(_description.c_str()));

	char temp[128];
	sprintf(temp, "%d", _price);
	TextOut(hdc, destX+60, destY+45, temp, strlen(temp));
	
}

void  item::render(HDC hdc, image* img,  int destX, int destY, int itemNum) // shop render image present
{

	_image->render(hdc, destX+20, destY+20);

	SetBkMode(hdc, TRANSPARENT); //�۾��������ȭ
	TextOut(hdc, destX+60, destY+5, _name.c_str(), strlen(_name.c_str()));
	TextOut(hdc, destX+60, destY + 25, _description.c_str(), strlen(_description.c_str()));

	TextOut(hdc, destX + 60, destY + 45, "����:", strlen("����:"));
	char temp[128];
	sprintf(temp, "%d", _price);
	TextOut(hdc, destX+120, destY + 45, temp, strlen(temp));

}

void item::InvenRender(HDC hdc, image* img, int destX, int destY) //Inventory render 
{
	_image->render(hdc, destX + 20, destY + 20);

	SetBkMode(hdc, TRANSPARENT); //�۾��������ȭ
	TextOut(hdc, destX + 60, destY + 5, _name.c_str(), strlen(_name.c_str()));
	TextOut(hdc, destX + 60, destY + 25, _description.c_str(), strlen(_description.c_str()));

	/*TextOut(hdc, destX + 60, destY+45, "�ɷ�ġ:", strlen("�ɷ�ġ:"));
	char temp[128];
	sprintf(temp, "%d", _ability);
	TextOut(hdc, destX + 130, destY + 45, temp, strlen(temp));*/

	TextOut(hdc, destX + 60, destY + 45, "��������:", strlen("��������:"));
	char temp[128];
	sprintf(temp, "%d", _itemNum);
	TextOut(hdc, destX + 130, destY + 45, temp, strlen(temp));
}