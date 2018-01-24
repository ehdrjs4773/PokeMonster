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
	SetBkMode(hdc, TRANSPARENT);
	TextOut(hdc, destX, destY, "사 러 간 다", strlen("사 러 간 다"));
}

