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

	//================================= 오프닝 이미지 초기화 =============================================================================//
	IMAGEMANAGER->addImage("openingBackGround", ".\\bmps\\opening\\openingBackGround.bmp", WINSIZEX, WINSIZEY, false, true, MAGENTA);
	IMAGEMANAGER->addImage("openingBackGroundSun", ".\\bmps\\opening\\openingSun.bmp", 64, 64, false, true, MAGENTA);
	IMAGEMANAGER->addImage("openingBackGround2", ".\\bmps\\opening\\openingBackGround2.bmp", WINSIZEX, WINSIZEY, false, true, MAGENTA);
	IMAGEMANAGER->addImage("openingBackGround3", ".\\bmps\\opening\\openingBackGround3.bmp", WINSIZEX, WINSIZEY, false, true, MAGENTA);
	IMAGEMANAGER->addImage("openingBackGround3Grass", ".\\bmps\\opening\\openingBackGroundPlayerSin.bmp", 480, 35, false, true, MAGENTA);
	IMAGEMANAGER->addImage("openingBackGroundPlayer1", ".\\bmps\\opening\\openingBackGroundPlayerM.bmp", 57, 135, false, true, MAGENTA);
	IMAGEMANAGER->addImage("openingBackGroundPlayer2", ".\\bmps\\opening\\openingBackGroundPlayerF.bmp", 62, 140, false, true, MAGENTA);
	IMAGEMANAGER->addImage("openingBackGroundSin1", ".\\bmps\\opening\\openingBackGroundSin1.bmp", 480, 120, false, true, MAGENTA);
	IMAGEMANAGER->addImage("openingBackGroundSin2", ".\\bmps\\opening\\openingBackGroundSin2.bmp", 480, 120, false, true, MAGENTA);
	IMAGEMANAGER->addImage("openingBackGroundSin3", ".\\bmps\\opening\\openingBackGroundSin3.bmp", 480, 120, false, true, MAGENTA);
	IMAGEMANAGER->addImage("openingStart", ".\\bmps\\opening\\openingStart.bmp", WINSIZEX, WINSIZEY, false, false, MAGENTA);
	IMAGEMANAGER->addImage("openingStartButten", ".\\bmps\\opening\\touchToStart.bmp", 228, 49, true, true, MAGENTA);
	


	//==================================================================================================================================//

	//============== 사운드 초기화======================//
	SOUNDMANAGER->addSound("오프닝 사운드", ".\\sounds\\pokemonBGM\\opening.mp3", false, true);


	SOUNDMANAGER->play("오프닝 사운드", 1.0F);
	//=================================================//

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

	_alpha = 0;


	_opening = Opening_One;


	return S_OK;
}

void Opening::release(void)
{

}

void Opening::update(void) 
{
	if (KEYMANAGER->isOnceKeyDown(VK_RETURN))
	{
		_opening = Opening_Five;
	}

	switch (_opening)
	{
	case Opening_One:
		_y -= 1;



		if (_y == WINSIZEY / 2 - 100)
		{
			_opening = Opening_Two;
		}

		break;
	case Opening_Two:
		_y = 0;
		_loopy -= 10;

		if (_loopy == -2000)
		{
			_opening = Opening_Three;
		}

		break;
	case Opening_Three:
		_loopy = 0;

		if (_p1x < 100)
		{
			_p1x += Opening_Speed;
		}

		if (_p2x > WINSIZEX - 120)
		{
			_p2x -= 3;
		}

		else _opening = Opening_Four;
		break;
	case Opening_Four:

		if (_sin1x <= 0)
		{
			_sin1x += Opening_Speed;
		}

		if (_sin2x >= 0 && _sin1x >= 0)
		{
			_sin1x = 0;
			_sin2x -= Opening_Speed;

		}

		if (_sin2x <= 0 && _sin3x <= 0)
		{
			_sin2x = 0;//
			_sin3x += Opening_Speed;
		}

		if (_sin3x >= 0)
		{
			_sin1x = 0;
			_sin2x = 0;
			_sin3x = 0;
			_opening = Opening_Five;
		}
		break;

	case Opening_Five :

		if (_alpha >= 255)
		{
			_alpha = 0;
		}

		_alpha += 5;
		break;

	default:
		break;
	}



	if (_opening == Opening_Five)
	{
		if (KEYMANAGER->isOnceKeyDown(PLAYER_SELECT_KEY))
		{	
			SOUNDMANAGER->stop("오프닝 사운드");
			DIALOGUE->loadingTextFile(".\\textData\\opening_sin.txt");
			DIALOGUE->setPoint(PointMake(100, WINSIZEY - 50));
			SCENEMANAGER->changeScene("SelectScene");
			SCENEMANAGER->init("SelectScene");
		}
	}


	render();
}


void Opening::render(void)
{
	switch (_opening)
	{
	case Opening_One:
		IMAGEMANAGER->findImage("openingBackGround")->render(getMemDC());
		IMAGEMANAGER->findImage("openingBackGroundSun")->render(getMemDC(), _x, _y);
		break;
	case Opening_Two:
		IMAGEMANAGER->findImage("openingBackGround2")->loopRender(getMemDC(), &RectMake(0, 0, WINSIZEX, WINSIZEY), _loopx, _loopy);
		break;
	case Opening_Three: case Opening_Four:
		IMAGEMANAGER->findImage("openingBackGround3")->render(getMemDC());
		IMAGEMANAGER->findImage("openingBackGroundPlayer1")->render(getMemDC(), _p1x, _p1y);
		IMAGEMANAGER->findImage("openingBackGroundPlayer2")->render(getMemDC(), _p2x, _p2y);
		IMAGEMANAGER->findImage("openingBackGround3Grass")->render(getMemDC(), 0, WINSIZEY - 35);

		IMAGEMANAGER->findImage("openingBackGroundSin1")->render(getMemDC(), _sin1x, _sin1y);
		IMAGEMANAGER->findImage("openingBackGroundSin2")->render(getMemDC(), _sin2x, _sin2y);
		IMAGEMANAGER->findImage("openingBackGroundSin3")->render(getMemDC(), _sin3x, _sin3y);
		break;
	case Opening_Five:
		IMAGEMANAGER->findImage("openingStart")->render(getMemDC());
		IMAGEMANAGER->findImage("openingStartButten")->alphaRender(getMemDC(), WINSIZEX / 2 - 114, WINSIZEY - 96, _alpha);
		break;
	case Opening_END:
		break;
	default:
		break;
	}


}