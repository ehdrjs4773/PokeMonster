#include "stdafx.h"
#include "shopScene.h"


shopScene::shopScene()
{
}


shopScene::~shopScene()
{
}

HRESULT shopScene::init()
{

	IMAGEMANAGER->addImage("상점오픈", "shop_open.bmp", WINSIZEX, WINSIZEY, false, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("상점메인", "shop_main.bmp", WINSIZEX, WINSIZEY, false, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("상점오픈버튼_BUY", "shop_button_buy.bmp", 252, 46, false, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("상점오픈버튼_SELL", "shop_button_sell.bmp", 252, 46, false, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("상점오픈버튼_CANCEL", "shop_button_cancel.bmp", 252, 46, false, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("상점선택", "shop_button_select.bmp", 252, 46, false, true, RGB(255, 0, 255));


	//MENU BUTTON 좌표
	_selectMenu[BUTTON_BUY].pt.x = 110;
	_selectMenu[BUTTON_BUY].pt.y = 100;

	_selectMenu[BUTTON_SELL].pt.x = 110;
	_selectMenu[BUTTON_SELL].pt.y = 180;

	_selectMenu[BUTTON_CANCEL].pt.x = 110;
	_selectMenu[BUTTON_CANCEL].pt.y = 260;


	
	//ITEM BUTTON 좌표
	_selectItem[ITEM_0].pt.x = 115;
	_selectItem[ITEM_0].pt.y = 0;

	_selectItem[ITEM_1].pt.x = 45;
	_selectItem[ITEM_1].pt.y = 90;

	_selectItem[ITEM_2].pt.x = 100;
	_selectItem[ITEM_2].pt.y = 240;

	_selectItem[ITEM_3].pt.x = 330;
	_selectItem[ITEM_3].pt.y = 250;

	_selectItem[ITEM_4].pt.x = 450;
	_selectItem[ITEM_4].pt.y = 230;

	_selectItem[ITEM_5].pt.x = 600;
	_selectItem[ITEM_5].pt.y = 230;

	for (int i = 0; i < 3; i++)
	{
	_selectMenu[i].Selected = false;
	}


	//처음 초기화
	SelectNum = 0;
	_selectMenu[0].isSelect = true;

	return S_OK;
}
void shopScene::release()
{

}

void shopScene::update()
{
	MenuSelectMove();
	if (KEYMANAGER->isOnceKeyDown(VK_F1)) SCENEMANAGER->changeScene("셀렉트씬");
}

void shopScene::render()
{
	IMAGEMANAGER->findImage("상점오픈")->render(getMemDC(), 0, 0);

	
		IMAGEMANAGER->findImage("상점오픈버튼_BUY")->render(getMemDC(), _selectMenu[BUTTON_BUY].pt.x, _selectMenu[BUTTON_BUY].pt.y);
		IMAGEMANAGER->findImage("상점오픈버튼_SELL")->render(getMemDC(), _selectMenu[BUTTON_SELL].pt.x, _selectMenu[BUTTON_SELL].pt.y);
		IMAGEMANAGER->findImage("상점오픈버튼_CANCEL")->render(getMemDC(), _selectMenu[BUTTON_CANCEL].pt.x, _selectMenu[BUTTON_CANCEL].pt.y);
	


	for (int i = 0; i <BUTTON_END; i++)
	{
		if (_selectMenu[i].isSelect == true)
		{
			IMAGEMANAGER->findImage("상점선택")->render(getMemDC(), _selectMenu[i].pt.x, _selectMenu[i].pt.y);
		}
	}


	TextOut(IMAGEMANAGER->findImage("상점오픈버튼_BUY")->getMemDC(), 80, 15, "사 러 간 다", strlen("사 러 간 다"));
	TextOut(IMAGEMANAGER->findImage("상점오픈버튼_SELL")->getMemDC(), 80, 15, "팔 러 간 다", strlen("팔 러 간 다"));
	TextOut(IMAGEMANAGER->findImage("상점오픈버튼_CANCEL")->getMemDC(), 100, 15, "취 소", strlen("취 소"));

	if (_selectMenu[0].Selected)
	{
		IMAGEMANAGER->findImage("상점메인")->render(getMemDC(), 0, 0);
	}




}


void shopScene::MenuSelectMove()
{
	if (KEYMANAGER->isOnceKeyDown(VK_UP))
	{
		SelectNum = (SelectNum + (BUTTON_END - 1)) % BUTTON_END;
		for (int i = 0; i < BUTTON_END; i++)
		{
			if (SelectNum == i)
			{
				_selectMenu[i].isSelect = true;
	
			}
			else
			{
				_selectMenu[i].isSelect = false;


			}
		}
	}

	if (KEYMANAGER->isOnceKeyDown(VK_DOWN))
	{
		SelectNum = (SelectNum + 1) % BUTTON_END;
		for (int i = 0; i < BUTTON_END; i++)
		{
			if (SelectNum == i)
			{
				_selectMenu[i].isSelect = true;
				_isClear[i] = true;


			}
			else
			{
				_selectMenu[i].isSelect = false;

			}
		}
	}
			if (KEYMANAGER->isOnceKeyDown('A'))
				{
					_selectMenu[SelectNum].Selected = true;
				}
}

void shopScene::ShopelectMove()
{
	if (KEYMANAGER->isOnceKeyDown(VK_UP))
	{
		SelectNum = (SelectNum + (BUTTON_END - 1)) % BUTTON_END;
		for (int i = 0; i < BUTTON_END; i++)
		{
			if (SelectNum == i)
			{
				_selectMenu[i].isSelect = true;

			}
			else
			{
				_selectMenu[i].isSelect = false;


			}
		}
	}

	if (KEYMANAGER->isOnceKeyDown(VK_DOWN))
	{
		SelectNum = (SelectNum + 1) % BUTTON_END;
		for (int i = 0; i < BUTTON_END; i++)
		{
			if (SelectNum == i)
			{
				_selectMenu[i].isSelect = true;
				_isClear[i] = true;


			}
			else
			{
				_selectMenu[i].isSelect = false;

			}
		}
	}
	if (KEYMANAGER->isOnceKeyDown('A'))
	{
		_selectMenu[SelectNum].Selected = true;
	}
}