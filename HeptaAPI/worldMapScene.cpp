#include "stdafx.h"
#include "worldMapScene.h"


worldMapScene::worldMapScene()
{
}


worldMapScene::~worldMapScene()
{
}


HRESULT worldMapScene::init()
{
	IMAGEMANAGER->addImage("배경", "worldmap1.bmp", WINSIZEX, WINSIZEY, true, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("표시", "select.bmp", 50, 78, true, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("clear", "clear.bmp", 101, 42, true, true, RGB(255, 0, 255));

	//체육관 좌표 초기화
	_select[GYM_0].pt.x = 70;
	_select[GYM_0].pt.y = 5;

	_select[GYM_1].pt.x = 35;
	_select[GYM_1].pt.y = 70;

	_select[GYM_2].pt.x = 60;
	_select[GYM_2].pt.y = 170;

	_select[GYM_3].pt.x = 205;
	_select[GYM_3].pt.y = 165;

	_select[GYM_4].pt.x = 265;
	_select[GYM_4].pt.y = 155;

	_select[GYM_5].pt.x = 360;
	_select[GYM_5].pt.y = 155;


	_select[GYM_6].pt.x =400;
	_select[GYM_6].pt.y = 250;

	_select[GYM_7].pt.x = 300;
	_select[GYM_7].pt.y = 20;

	_select[GYM_8].pt.x = 230;
	_select[GYM_8].pt.y = 90;

	//처음체육관 초기화
	SelectNum = 0;
	_select[0].isSelect = true;

	return S_OK;
}
void worldMapScene::release()	  
{

}
void worldMapScene::update()	 
{
	selectMove();
}
void worldMapScene::render()	
{
	IMAGEMANAGER->findImage("배경")->render(getMemDC(), 0, 0);

	for (int i = 0; i < GYM_MAX; i++)
	{
		if (_select[i].isSelect == true)
		{
			IMAGEMANAGER->findImage("표시")->render(getMemDC(), _select[i].pt.x, _select[i].pt.y);
		}
	}

	for (int i = 0; i < GYM_MAX; i++)
	{
		if (_isClear[i] == true)
		{
			IMAGEMANAGER->findImage("clear")->render(getMemDC(), _select[i].pt.x, _select[i].pt.y+50);
		}
	}


}

void worldMapScene::selectMove()
{
	if (KEYMANAGER->isOnceKeyDown(VK_UP))
	{
		SelectNum = (SelectNum + (GYM_MAX-1)) % GYM_MAX;
		for (int i = 0; i < GYM_MAX; i++)
		{
			if (SelectNum == i)
			{
				_select[i].isSelect = true;	
			}
			else
			{
				_select[i].isSelect = false;			
			}
		}
	}

	if (KEYMANAGER->isOnceKeyDown(VK_DOWN))
	{
		SelectNum = (SelectNum + 1) % GYM_MAX;
		for (int i = 0; i < GYM_MAX; i++)
		{
			if (SelectNum == i)
			{
				_select[i].isSelect = true;
				_isClear[i] = true;

			}
			else
			{
				_select[i].isSelect = false;
	
			}
		}
	}
}