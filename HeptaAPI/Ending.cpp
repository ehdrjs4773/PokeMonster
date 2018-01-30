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
	if (_y > 2000 - WINSIZEY)
		_y = 2000 - WINSIZEY;
}


void Ending::render(void) 
{
	IMAGEMANAGER->findImage("ending")->render(getMemDC(), 0, 0, _x, _y, WINSIZEX, WINSIZEY);
}

