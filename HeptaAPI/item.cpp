#include "stdafx.h"
#include "item.h"



item::item()
{
}


item::~item()
{
}

HRESULT item::init()
{


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

void  item::render(HDC hdc, int destX, int destY)
{
	TextOut(hdc, destX, destY, "�� �� �� ��", strlen("�� �� �� ��"));
}
