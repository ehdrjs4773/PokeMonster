#include "stdafx.h"
#include "stageScene.h"



stageScene::stageScene()
{
}


stageScene::~stageScene()
{
}

HRESULT stageScene::init()
{
	_stage = DR_O_HOUSE;

	_player = new player;
	_player->init();

	_drOHouse = IMAGEMANAGER->addImage("drOHouse", ".\\bmps\\drHouseScene\\drOHouse.bmp", WINSIZEX, WINSIZEY, false, true, MAGENTA);
	_drOHousePixel = IMAGEMANAGER->addImage("drOHousePixel", ".\\bmps\\drHouseScene\\drOHousePixel.bmp", WINSIZEX, WINSIZEY, false, true, MAGENTA);
	_drO = IMAGEMANAGER->addFrameImage("drO", ".\\bmps\\drHouseScene\\drO.bmp", 68, 24, 4, 1, false, true, MAGENTA);
	
	//오박사 x,y 좌표
	_x = 240;
	_y = 115;

	//오박사 렉트
	_drRc = RectMakeCenter(_x, _y, _drO->getFrameWidth(), _drO->getFrameHeight());



	return S_OK;
}

void stageScene::release()
{

}

void stageScene::update()
{
	

	_player->update();
}

void stageScene::render()
{

	switch (_stage)
	{
	case DR_O_HOUSE:
		IMAGEMANAGER->findImage("drOHouse")->render(getMemDC());
		IMAGEMANAGER->findImage("drO")->frameRender(getMemDC(), _x, _y);
		break;
	case GYM_WING:
		break;
	case GYM_NOMAL:
		break;
	case GYM_ICE:
		break;
	case GYM_DRAGON:
		break;
	case GYM_GHOST:
		break;
	case GYM_BUG:
		break;
	case GYM_FIGHT:
		break;
	case GYM_STEEL:
		break;
	case CHAMPION_ROAD:
		break;
	default:
		break;
	}
	_player->render();
}