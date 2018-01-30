#include "stdafx.h"
#include "Ending.h"



Ending::Ending()
{
	
}


Ending::~Ending()
{

}


HRESULT Ending::init()
{
	IMAGEMANAGER->addImage("ending", ".\\bmps\\ending.bmp", 480, 2000, false, true, MAGENTA);

	_x = 0;
	_y = 0;

	return S_OK;
}


void Ending::release(void)
{

}


void Ending::update(void) 
{
	_y += 1;
}


void Ending::render(void) 
{
	IMAGEMANAGER->findImage("ending")->loopRender(getMemDC(), &RectMake(0,0,WINSIZEX, WINSIZEY), 0, _y);
}

