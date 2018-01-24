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
	//상점입장시메인메뉴 이미지 등록
	IMAGEMANAGER->addImage("상점오픈", ".\\bmps\\shopScene\\shop_open.bmp", WINSIZEX, WINSIZEY, false, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("상점오픈버튼_BUY", ".\\bmps\\shopScene\\shop_button_buy.bmp", 252, 46, false, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("상점오픈버튼_SELL", ".\\bmps\\shopScene\\shop_button_sell.bmp", 252, 46, false, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("상점오픈버튼_CANCEL", ".\\bmps\\shopScene\\shop_button_cancel.bmp", 252, 46, false, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("상점선택", ".\\bmps\\shopScene\\shop_button_select.bmp", 252, 46, false, true, RGB(255, 0, 255));

	//사러가기 선택시 이미지등록
	IMAGEMANAGER->addImage("상점메인", ".\\bmps\\shopScene\\shop_main.bmp", WINSIZEX, WINSIZEY, false, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("상점사러가기선택", ".\\bmps\\shopScene\\shop_main_select.bmp", 232, 69, false, true, RGB(255, 0, 255));
	ITEMMANAGER->addItem("몬스터볼");

	//MENU BUTTON 좌표
	_selectMenu[BUTTON_BUY].pt.x = 110;
	_selectMenu[BUTTON_BUY].pt.y = 100;

	_selectMenu[BUTTON_SELL].pt.x = 110;
	_selectMenu[BUTTON_SELL].pt.y = 180;

	_selectMenu[BUTTON_CANCEL].pt.x = 110;
	_selectMenu[BUTTON_CANCEL].pt.y = 260;

	//ITEM INDEX BUTTON 좌표
	_selectItem[INDEX_BUTTON_0].pt.x = 5;
	_selectItem[INDEX_BUTTON_0].pt.y = 75;

	_selectItem[INDEX_BUTTON_1].pt.x = 45;
	_selectItem[INDEX_BUTTON_1].pt.y = 90;

	_selectItem[INDEX_BUTTON_2].pt.x = 5;
	_selectItem[INDEX_BUTTON_2].pt.y = 150;

	_selectItem[INDEX_BUTTON_3].pt.x = 330;
	_selectItem[INDEX_BUTTON_3].pt.y = 250;

	_selectItem[INDEX_BUTTON_4].pt.x = 5;
	_selectItem[INDEX_BUTTON_4].pt.y = 225;

	_selectItem[INDEX_BUTTON_5].pt.x = 600;
	_selectItem[INDEX_BUTTON_5].pt.y = 230;

	for (int i = 0; i < BUTTON_END; i++)
	{
	_selectMenu[i].Selected = false;
	}

	for (int i = 0; i < INDEX_BUTTON_END; i++)
	{
		_selectItem[i].Selected = false;
	}

	//처음 초기화
	SelectNum = 0;
	_selectMenu[0].isSelect = true;

	IndexSelectNum = 0;
	_selectItem[0].isSelect = true;


	return S_OK;
}
void shopScene::release()
{

}

void shopScene::update()
{
	MenuSelectMove(); //상점입장메인메뉴 선택 화면 무브함수
	ShopelectMove();
}

void shopScene::render()
{
	
	shopMainMenuDraw(); //상점입장메인메뉴
	//shopBuyMenuDraw();
	ITEMMANAGER->findItem("몬스터볼")->render(IMAGEMANAGER->findImage("상점메인")->getMemDC(), 100, 100);

}

void shopScene::shopMainMenuDraw() //상점 입장시 Main Menu 그려주는 함수
{
	IMAGEMANAGER->findImage("상점오픈")->render(getMemDC(), 0, 0);
	IMAGEMANAGER->findImage("상점오픈버튼_BUY")->render(getMemDC(), _selectMenu[BUTTON_BUY].pt.x, _selectMenu[BUTTON_BUY].pt.y);
	IMAGEMANAGER->findImage("상점오픈버튼_SELL")->render(getMemDC(), _selectMenu[BUTTON_SELL].pt.x, _selectMenu[BUTTON_SELL].pt.y);
	IMAGEMANAGER->findImage("상점오픈버튼_CANCEL")->render(getMemDC(), _selectMenu[BUTTON_CANCEL].pt.x, _selectMenu[BUTTON_CANCEL].pt.y);

	TextOut(IMAGEMANAGER->findImage("상점오픈버튼_BUY")->getMemDC(), 80, 15, "사 러 간 다", strlen("사 러 간 다"));
	TextOut(IMAGEMANAGER->findImage("상점오픈버튼_SELL")->getMemDC(), 80, 15, "팔 러 간 다", strlen("팔 러 간 다"));
	TextOut(IMAGEMANAGER->findImage("상점오픈버튼_CANCEL")->getMemDC(), 100, 15, "취 소", strlen("취 소"));
	
	for (int i = 0; i <BUTTON_END; i++)
	{
		if (_selectMenu[i].isSelect == true)
		{
			IMAGEMANAGER->findImage("상점선택")->render(getMemDC(), _selectMenu[i].pt.x, _selectMenu[i].pt.y);
		}
	}

	if (_selectMenu[BUTTON_BUY].Selected) //사러가기 버튼 선택시 
	{
		IMAGEMANAGER->findImage("상점메인")->render(getMemDC(), 0, 0);
		shopBuyMenuDraw();
	}

	if (_selectMenu[BUTTON_SELL].Selected) //팔러가기 버튼 선택시
	{
		IMAGEMANAGER->findImage("상점메인")->render(getMemDC(), 0, 0);
	}

	if (_selectMenu[BUTTON_CANCEL].Selected) //취소버튼 선택시
	{
		SCENEMANAGER->changeScene("오프닝씬");
	}
}

void shopScene::shopBuyMenuDraw() //상점 사러가기 Menu 그려주는 함수
{
	

	for (int i = 0; i <INDEX_BUTTON_END; i++)
	{
		if (_selectItem[i].isSelect == true)
		{
			IMAGEMANAGER->findImage("상점사러가기선택")->render(getMemDC(), _selectItem[i].pt.x, _selectItem[i].pt.y);
		}
	}

	if (_selectItem[INDEX_BUTTON_0].Selected) //1번째 아이템 
	{
		IMAGEMANAGER->findImage("상점메인")->render(getMemDC(), 0, 0);
	}
	if (_selectItem[INDEX_BUTTON_1].Selected) //2번째 아이템 
	{
		IMAGEMANAGER->findImage("상점메인")->render(getMemDC(), 0, 0);
	}
	if (_selectItem[INDEX_BUTTON_2].Selected) //3번째 아이템 
	{
		IMAGEMANAGER->findImage("상점메인")->render(getMemDC(), 0, 0);
	}
	if (_selectItem[INDEX_BUTTON_3].Selected) //4번째 아이템 
	{
		IMAGEMANAGER->findImage("상점메인")->render(getMemDC(), 0, 0);
	}
	if (_selectItem[INDEX_BUTTON_4].Selected) //5번째 아이템 
	{
		IMAGEMANAGER->findImage("상점메인")->render(getMemDC(), 0, 0);
	}
	if (_selectItem[INDEX_BUTTON_5].Selected) //6번째 아이템 
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
				//_isClear[i] = true;


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
	if (KEYMANAGER->isOnceKeyDown(VK_RIGHT))
	{
		IndexSelectNum = (IndexSelectNum + (INDEX_BUTTON_END - 1)) % INDEX_BUTTON_END;
		for (int i = 0; i < INDEX_BUTTON_END; i++)
		{
			if (IndexSelectNum == i)
			{
				_selectItem[i].isSelect = true;

			}
			else
			{
				_selectItem[i].isSelect = false;


			}
		}
	}

	if (KEYMANAGER->isOnceKeyDown(VK_LEFT))
	{
		IndexSelectNum = (IndexSelectNum + 1) % INDEX_BUTTON_END;
		for (int i = 0; i < INDEX_BUTTON_END; i++)
		{
			if (IndexSelectNum == i)
			{
				_selectItem[i].isSelect = true;

			}
			else
			{
				_selectMenu[i].isSelect = false;

			}
		}
	}
	if (KEYMANAGER->isOnceKeyDown('A'))
	{
		_selectItem[IndexSelectNum].Selected = true;
	}
}