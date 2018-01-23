#include "stdafx.h"
#include "Opening.h"



Opening::Opening()
{

}


Opening::~Opening()
{

}



HRESULT Opening::init(void)
{
	IMAGEMANAGER->addImage("openingBackGround", ".\\bmps\\opening\\openingBackGround.bmp", WINSIZEX, WINSIZEY, false, true, MAGENTA);
	IMAGEMANAGER->addImage("openingBackGroundSun", ".\\bmps\\opening\\openingSun.bmp", 64, 64, false, true, MAGENTA);
	IMAGEMANAGER->addImage("openingBackGround2", ".\\bmps\\opening\\openingBackGround2.bmp", WINSIZEX, WINSIZEY, false, true, MAGENTA);
	IMAGEMANAGER->addImage("openingBackGround3", ".\\bmps\\opening\\openingBackGround3.bmp", WINSIZEX, WINSIZEY, false, true, MAGENTA);
	IMAGEMANAGER->addImage("openingBackGround3Grass", ".\\bmps\\opening\\openingBackGroundPlayerSin.bmp", 480, 35, false, true, MAGENTA);
	IMAGEMANAGER->addImage("openingBackGroundPlayer1", ".\\bmps\\opening\\openingBackGroundPlayerM.bmp", 57, 135, false, true, MAGENTA);
	IMAGEMANAGER->addImage("openingBackGroundPlayer2", ".\\bmps\\opening\\openingBackGroundPlayerF.bmp", 62, 140, false, true, MAGENTA);
	IMAGEMANAGER->addImage("openingBakcGroundSin1", ".\\bmps\\opening\\openingBackGroundSin1.bmp", 480, 120, false, true, MAGENTA);
	IMAGEMANAGER->addImage("openingBakcGroundSin2", ".\\bmps\\opening\\openingBackGroundSin2.bmp", 480, 120, false, true, MAGENTA);
	IMAGEMANAGER->addImage("openingBakcGroundSin3", ".\\bmps\\opening\\openingBackGroundSin3.bmp", 480, 120, false, true, MAGENTA);

	_x = WINSIZEX / 2 - 32;
	_y = WINSIZEY / 2 + 50;
	_loopx = 0;
	_loopy = 0;

	_p1x = -100;
	_p1y = WINSIZEY - 135;

	_p2x = WINSIZEX + 100;
	_p2y = WINSIZEY - 135;

	_sin1x = -480;
	_sin1y = 0;

	_sin2x = WINSIZEX;
	_sin2y = 120;

	_sin3x = -480;
	_sin3y = 240;


	_opening = Opening_One;


	return S_OK;
}

void Opening::release(void)
{

}

void Opening::update(void) 
{
	if (_opening == Opening_One)
	{
		_y -= 1;
	}

	if (_y == WINSIZEY / 2 - 100)
	{
		_y = 0;
		_opening = Opening_Two;
	}


	if (_opening == Opening_Two)
	{
		_loopy -= 10;
	}

	if (_loopy == -2000)
	{
		_loopy = 0;
		_opening = Opening_Three;
	}


	if (_opening == Opening_Three)
	{
		if (_p1x < 100)
		{
			_p1x += 3;
		}

		if (_p2x > WINSIZEX - 120)
		{
			_p2x -= 3;
		}

		else _opening = Opening_Four;
	}

//if (_p2x <= WINSIZEX - 120)
//{
//	_opening = Opening_Four;
//}
	

	if (_opening == Opening_Four)
	{
		if (_sin1x <= 0)
		{
			_sin1x += 3;

		}

		if (_sin2x >= 0 && _sin1x >= 0)
		{
			_sin2x -= 3;
		}

		if (_sin2x <= 0 && _sin3x <=0)
		{
			_sin3x +=3;
		}
	}





	render();
}


void Opening::render(void)
{
	if(_opening == Opening_One)
	{
		IMAGEMANAGER->findImage("openingBackGround")->render(getMemDC());
		IMAGEMANAGER->findImage("openingBackGroundSun")->render(getMemDC(), _x, _y);
	}

	if (_opening == Opening_Two)
	{
		IMAGEMANAGER->findImage("openingBackGround2")->loopRender(getMemDC(), &RectMake(0,0, WINSIZEX, WINSIZEY), _loopx, _loopy);
	}

	if (_opening == Opening_Three || _opening == Opening_Four)
	{
		IMAGEMANAGER->findImage("openingBackGround3")->render(getMemDC());
		IMAGEMANAGER->findImage("openingBackGroundPlayer1")->render(getMemDC(), _p1x, _p1y);
		IMAGEMANAGER->findImage("openingBackGroundPlayer2")->render(getMemDC(), _p2x, _p2y);
		IMAGEMANAGER->findImage("openingBackGround3Grass")->render(getMemDC(), 0, WINSIZEY - 35);

		IMAGEMANAGER->findImage("openingBakcGroundSin1")->render(getMemDC(), _sin1x, _sin1y);
		IMAGEMANAGER->findImage("openingBakcGroundSin2")->render(getMemDC(), _sin2x, _sin2y);
		IMAGEMANAGER->findImage("openingBakcGroundSin3")->render(getMemDC(), _sin3x, _sin3y);
	}


}