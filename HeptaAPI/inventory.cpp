#include "stdafx.h"
#include "inventory.h"



inventory::inventory()
{
}


inventory::~inventory()
{

}

HRESULT inventory::init()
{


	//인벤토리 메뉴 이미지등록
	IMAGEMANAGER->addImage("인벤토리_유틸", ".\\bmps\\inventoryScene\\inventory_1.bmp", WINSIZEX, WINSIZEY, false, true, MAGENTA);
	IMAGEMANAGER->addImage("인벤토리_포션", ".\\bmps\\inventoryScene\\inventory_2.bmp", WINSIZEX, WINSIZEY, false, true, MAGENTA);
	IMAGEMANAGER->addImage("인벤토리_볼", ".\\bmps\\inventoryScene\\inventory_3.bmp", WINSIZEX, WINSIZEY, false, true, MAGENTA);
	IMAGEMANAGER->addImage("인벤토리_머신", ".\\bmps\\inventoryScene\\inventory_4.bmp", WINSIZEX, WINSIZEY, false, true, MAGENTA);
	IMAGEMANAGER->addImage("인벤토리선택", ".\\bmps\\inventoryScene\\inventory_main_select.bmp", 232, 69, false, true, MAGENTA);
	IMAGEMANAGER->addImage("인벤토리취소", ".\\bmps\\inventoryScene\\exit_box.bmp", 116, 43, false, true, MAGENTA);
	IMAGEMANAGER->addImage("인벤토리취소선택", ".\\bmps\\inventoryScene\\exit_box_select.bmp", 116, 43, false, true, MAGENTA);

	//인벤토리 아이콘 이미지 등록
	IMAGEMANAGER->addFrameImage("아이콘_유틸", ".\\bmps\\inventoryScene\\item_kind_1.bmp", 50, 100, 1, 2, false, true, MAGENTA);
	IMAGEMANAGER->addFrameImage("아이콘_포션", ".\\bmps\\inventoryScene\\item_kind_2.bmp", 50, 100, 1, 2, false, true, MAGENTA);
	IMAGEMANAGER->addFrameImage("아이콘_볼", ".\\bmps\\inventoryScene\\item_kind_3.bmp", 50, 100, 1, 2, false, true, MAGENTA);
	IMAGEMANAGER->addFrameImage("아이콘_머신", ".\\bmps\\inventoryScene\\item_kind_4.bmp", 50, 100, 1, 2, false, true, MAGENTA);
	IMAGEMANAGER->addImage("아이콘선택", ".\\bmps\\inventoryScene\\select_item_kind_box.bmp", 50, 50, false, true, MAGENTA);

	////MENU BUTTON 좌표
	//_selectMenu[BUTTONS_BUY].pt.x = 110;
	//_selectMenu[BUTTONS_BUY].pt.y = 100;

	//_selectMenu[BUTTONS_SELL].pt.x = 110;
	//_selectMenu[BUTTONS_SELL].pt.y = 180;

	//_selectMenu[BUTTONS_CANCEL].pt.x = 110;
	//_selectMenu[BUTTONS_CANCEL].pt.y = 260;

	//ITEM INDEX BUTTON 좌표
	_selectItem[INDEXS_BUTTON_0].pt.x = 5;
	_selectItem[INDEXS_BUTTON_0].pt.y = 75;

	_selectItem[INDEXS_BUTTON_1].pt.x = 245;
	_selectItem[INDEXS_BUTTON_1].pt.y = 75;

	_selectItem[INDEXS_BUTTON_2].pt.x = 5;
	_selectItem[INDEXS_BUTTON_2].pt.y = 150;

	_selectItem[INDEXS_BUTTON_3].pt.x = 245;
	_selectItem[INDEXS_BUTTON_3].pt.y = 150;

	_selectItem[INDEXS_BUTTON_4].pt.x = 5;
	_selectItem[INDEXS_BUTTON_4].pt.y = 225;

	_selectItem[INDEXS_BUTTON_5].pt.x = 245;
	_selectItem[INDEXS_BUTTON_5].pt.y = 225;

	_selectItem[INDEXS_BUTTON_CANCEL].pt.x = 360;
	_selectItem[INDEXS_BUTTON_CANCEL].pt.y = 310;

	for (int i = 0; i < BUTTONS_END; i++)
	{
		_selectMenu[i].Selected = false;
	}

	for (int i = 0; i < INDEXS_BUTTON_END; i++)
	{
		_selectItem[i].Selected = false;
	}

	_WS = WSS_UTIL;



	IndexSelectNum = 0;
	_selectItem[0].isSelect = true;

	return S_OK;
}

void inventory::update()	 
{
	KeyControl();
}

void inventory::release()	  
{

}

void inventory::render()	  
{
	switch (_WS)
	{
	case WSS_UTIL:
		UtilMenuDraw();
		break;
	case WSS_POTION:
		PotionMenuDraw();
		break;
	case WSS_BALL:
		BallMenuDraw();
		break;
	case WSS_MACHINE:
		MachineMenuDraw();
		break;
		//상점입장메인메뉴
	}
}

void inventory::buyItem(vector<item*>::iterator buyingItem)
{
	_vInventory.push_back(*buyingItem);
}

//void inventory::shopMainMenuDraw() //상점 입장시 Main Menu 그려주는 함수
//{
//	IMAGEMANAGER->findImage("상점오픈")->render(getMemDC(), 0, 0);
//	IMAGEMANAGER->findImage("상점오픈버튼_BUY")->render(getMemDC(), _selectMenu[BUTTONS_BUY].pt.x, _selectMenu[BUTTONS_BUY].pt.y);
//	IMAGEMANAGER->findImage("상점오픈버튼_SELL")->render(getMemDC(), _selectMenu[BUTTONS_SELL].pt.x, _selectMenu[BUTTONS_SELL].pt.y);
//	IMAGEMANAGER->findImage("상점오픈버튼_CANCEL")->render(getMemDC(), _selectMenu[BUTTONS_CANCEL].pt.x, _selectMenu[BUTTONS_CANCEL].pt.y);
//
//	TextOut(IMAGEMANAGER->findImage("상점오픈버튼_BUY")->getMemDC(), 80, 15, "사 러 간 다", strlen("사 러 간 다"));
//	TextOut(IMAGEMANAGER->findImage("상점오픈버튼_SELL")->getMemDC(), 80, 15, "팔 러 간 다", strlen("팔 러 간 다"));
//	TextOut(IMAGEMANAGER->findImage("상점오픈버튼_CANCEL")->getMemDC(), 100, 15, "취 소", strlen("취 소"));
//
//
//
//
//	for (int i = 0; i <BUTTONS_END; i++)
//	{
//		if (_selectMenu[i].isSelect == true)
//		{
//			IMAGEMANAGER->findImage("상점선택")->render(getMemDC(), _selectMenu[i].pt.x, _selectMenu[i].pt.y);
//		}
//	}
//
//	if (_selectMenu[BUTTONS_BUY].Selected) //사러가기 버튼 선택시 
//	{
//		IMAGEMANAGER->findImage("상점메인")->render(getMemDC(), 0, 0);
//		shopBuyMenuDraw();
//		_WS = WSS_BUY;
//	}
//
//	if (_selectMenu[BUTTONS_SELL].Selected) //팔러가기 버튼 선택시
//	{
//		IMAGEMANAGER->findImage("상점메인")->render(getMemDC(), 0, 0);
//		shopBuyMenuDraw();
//		_WS = WSS_SELL;
//	}
//
//	if (_selectMenu[BUTTONS_CANCEL].Selected) //취소버튼 선택시
//	{
//		SCENEMANAGER->changeScene("오프닝씬");
//	}
//}

void inventory::UtilMenuDraw() //상점 사러가기 Menu 그려주는 함수
{
	IMAGEMANAGER->findImage("인벤토리_유틸")->render(getMemDC(), 0, 0);
	IMAGEMANAGER->findImage("인벤토리취소")->render(getMemDC(), 360, 310);

	//상점BUY 선택 이동 렌더 부분
	for (int i = 0; i <6; i++)
	{
		if (_selectItem[i].isSelect == true)
		{
			IMAGEMANAGER->findImage("인벤토리선택")->render(getMemDC(), _selectItem[i].pt.x, _selectItem[i].pt.y);
		}
	}
	//취소 버튼 선택 랜더
	if (_selectItem[INDEXS_BUTTON_CANCEL].isSelect == true)
	{
		IMAGEMANAGER->findImage("인벤토리취소선택")->render(getMemDC(), _selectItem[6].pt.x, _selectItem[6].pt.y);
	}

	//각 부분 선택시 발생하는 이벤트 제어
	if (_selectItem[INDEXS_BUTTON_0].Selected) //1번째 아이템 
	{
		//_inven->buyItem(_item->findItem("몬스터볼")->getItem());
	}
	if (_selectItem[INDEXS_BUTTON_1].Selected) //2번째 아이템 
	{
		//IMAGEMANAGER->findImage("인벤토리_유틸")->render(getMemDC(), 0, 0);
	}
	if (_selectItem[INDEXS_BUTTON_2].Selected) //3번째 아이템 
	{
		//IMAGEMANAGER->findImage("상점메인")->render(getMemDC(), 0, 0);
	}
	if (_selectItem[INDEXS_BUTTON_3].Selected) //4번째 아이템 
	{
		//IMAGEMANAGER->findImage("상점메인")->render(getMemDC(), 0, 0);
	}
	if (_selectItem[INDEXS_BUTTON_4].Selected) //5번째 아이템 
	{
		//IMAGEMANAGER->findImage("상점메인")->render(getMemDC(), 0, 0);
	}
	if (_selectItem[INDEXS_BUTTON_5].Selected) //6번째 아이템 
	{
		//IMAGEMANAGER->findImage("상점메인")->render(getMemDC(), 0, 0);
	}
	if (_selectItem[INDEXS_BUTTON_CANCEL].Selected) //취소 버튼
	{
		SCENEMANAGER->changeScene("오프닝씬");
	}
}

void inventory::PotionMenuDraw() //상점 사러가기 Menu 그려주는 함수
{
	IMAGEMANAGER->findImage("인벤토리_포션")->render(getMemDC(), 0, 0);
	IMAGEMANAGER->findImage("인벤토리취소")->render(getMemDC(), 360, 310);
	//상점BUY 선택 이동 렌더 부분
	for (int i = 0; i <6; i++)
	{
		if (_selectItem[i].isSelect == true)
		{
			IMAGEMANAGER->findImage("인벤토리선택")->render(getMemDC(), _selectItem[i].pt.x, _selectItem[i].pt.y);
		}
	}
	//취소 버튼 선택 랜더
	if (_selectItem[INDEXS_BUTTON_CANCEL].isSelect == true)
	{
		IMAGEMANAGER->findImage("인벤토리취소선택")->render(getMemDC(), _selectItem[6].pt.x, _selectItem[6].pt.y);
	}

	//각 부분 선택시 발생하는 이벤트 제어
	if (_selectItem[INDEXS_BUTTON_0].Selected) //1번째 아이템 
	{
		//_inven->buyItem(_item->findItem("몬스터볼")->getItem());
	}
	if (_selectItem[INDEXS_BUTTON_1].Selected) //2번째 아이템 
	{
		//IMAGEMANAGER->findImage("상점메인")->render(getMemDC(), 0, 0);
	}
	if (_selectItem[INDEXS_BUTTON_2].Selected) //3번째 아이템 
	{
		//IMAGEMANAGER->findImage("상점메인")->render(getMemDC(), 0, 0);
	}
	if (_selectItem[INDEXS_BUTTON_3].Selected) //4번째 아이템 
	{
		//IMAGEMANAGER->findImage("상점메인")->render(getMemDC(), 0, 0);
	}
	if (_selectItem[INDEXS_BUTTON_4].Selected) //5번째 아이템 
	{
		//IMAGEMANAGER->findImage("상점메인")->render(getMemDC(), 0, 0);
	}
	if (_selectItem[INDEXS_BUTTON_5].Selected) //6번째 아이템 
	{
		//IMAGEMANAGER->findImage("상점메인")->render(getMemDC(), 0, 0);
	}
	if (_selectItem[INDEXS_BUTTON_CANCEL].Selected) //취소 버튼
	{
		SCENEMANAGER->changeScene("오프닝씬");
	}
}

void inventory::BallMenuDraw() //상점 사러가기 Menu 그려주는 함수
{
	IMAGEMANAGER->findImage("인벤토리_볼")->render(getMemDC(), 0, 0);
	IMAGEMANAGER->findImage("인벤토리취소")->render(getMemDC(), 360, 310);

	//상점BUY 선택 이동 렌더 부분
	for (int i = 0; i <6; i++)
	{
		if (_selectItem[i].isSelect == true)
		{
			IMAGEMANAGER->findImage("인벤토리선택")->render(getMemDC(), _selectItem[i].pt.x, _selectItem[i].pt.y);
		}
	}
	//취소 버튼 선택 랜더
	if (_selectItem[INDEXS_BUTTON_CANCEL].isSelect == true)
	{
		IMAGEMANAGER->findImage("인벤토리취소선택")->render(getMemDC(), _selectItem[6].pt.x, _selectItem[6].pt.y);
	}

	//각 부분 선택시 발생하는 이벤트 제어
	if (_selectItem[INDEXS_BUTTON_0].Selected) //1번째 아이템 
	{
		//_inven->buyItem(_item->findItem("몬스터볼")->getItem());
	}
	if (_selectItem[INDEXS_BUTTON_1].Selected) //2번째 아이템 
	{
		//IMAGEMANAGER->findImage("상점메인")->render(getMemDC(), 0, 0);
	}
	if (_selectItem[INDEXS_BUTTON_2].Selected) //3번째 아이템 
	{
		//IMAGEMANAGER->findImage("상점메인")->render(getMemDC(), 0, 0);
	}
	if (_selectItem[INDEXS_BUTTON_3].Selected) //4번째 아이템 
	{
		//IMAGEMANAGER->findImage("상점메인")->render(getMemDC(), 0, 0);
	}
	if (_selectItem[INDEXS_BUTTON_4].Selected) //5번째 아이템 
	{
		//IMAGEMANAGER->findImage("상점메인")->render(getMemDC(), 0, 0);
	}
	if (_selectItem[INDEXS_BUTTON_5].Selected) //6번째 아이템 
	{
		//IMAGEMANAGER->findImage("상점메인")->render(getMemDC(), 0, 0);
	}
	if (_selectItem[INDEXS_BUTTON_CANCEL].Selected) //취소 버튼
	{
		SCENEMANAGER->changeScene("오프닝씬");
	}
	
}

void inventory::MachineMenuDraw() //상점 사러가기 Menu 그려주는 함수
{
	IMAGEMANAGER->findImage("인벤토리_머신")->render(getMemDC(), 0, 0);
	IMAGEMANAGER->findImage("인벤토리취소")->render(getMemDC(), 360, 310);

	//상점BUY 선택 이동 렌더 부분
	for (int i = 0; i <6; i++)
	{
		if (_selectItem[i].isSelect == true)
		{
			IMAGEMANAGER->findImage("인벤토리선택")->render(getMemDC(), _selectItem[i].pt.x, _selectItem[i].pt.y);
		}
	}
	//취소 버튼 선택 랜더
	if (_selectItem[INDEXS_BUTTON_CANCEL].isSelect == true)
	{
		IMAGEMANAGER->findImage("인벤토리취소선택")->render(getMemDC(), _selectItem[6].pt.x, _selectItem[6].pt.y);
	}

	//각 부분 선택시 발생하는 이벤트 제어
	if (_selectItem[INDEXS_BUTTON_0].Selected) //1번째 아이템 
	{
		//_inven->buyItem(_item->findItem("몬스터볼")->getItem());
	}
	if (_selectItem[INDEXS_BUTTON_1].Selected) //2번째 아이템 
	{
		//IMAGEMANAGER->findImage("상점메인")->render(getMemDC(), 0, 0);
	}
	if (_selectItem[INDEXS_BUTTON_2].Selected) //3번째 아이템 
	{
		//IMAGEMANAGER->findImage("상점메인")->render(getMemDC(), 0, 0);
	}
	if (_selectItem[INDEXS_BUTTON_3].Selected) //4번째 아이템 
	{
		//IMAGEMANAGER->findImage("상점메인")->render(getMemDC(), 0, 0);
	}
	if (_selectItem[INDEXS_BUTTON_4].Selected) //5번째 아이템 
	{
		//IMAGEMANAGER->findImage("상점메인")->render(getMemDC(), 0, 0);
	}
	if (_selectItem[INDEXS_BUTTON_5].Selected) //6번째 아이템 
	{
		//IMAGEMANAGER->findImage("상점메인")->render(getMemDC(), 0, 0);
	}
	if (_selectItem[INDEXS_BUTTON_CANCEL].Selected) //취소 버튼
	{
		SCENEMANAGER->changeScene("오프닝씬");
	}
	
}

void inventory::KeyControl()
{
	
	if (KEYMANAGER->isOnceKeyDown(VK_LEFT))
	{
		switch (_WS)
		{
		case WSS_UTIL: case WSS_POTION: case WSS_BALL: case WSS_MACHINE:
			IndexSelectNum = (IndexSelectNum + (INDEXS_BUTTON_END - 1)) % INDEXS_BUTTON_END;
			for (int i = 0; i < INDEXS_BUTTON_END; i++)
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
			break;

		case WSS_CANCEL:
			break;

		}
	}

	if (KEYMANAGER->isOnceKeyDown(VK_RIGHT))
	{
		switch (_WS)
		{

		case WSS_UTIL: case WSS_POTION: case WSS_BALL: case WSS_MACHINE:
			IndexSelectNum = (IndexSelectNum + 1) % INDEXS_BUTTON_END;
			for (int i = 0; i < INDEXS_BUTTON_END; i++)
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
			break;
	
		case WSS_CANCEL:
			break;

		}

	}

	if (KEYMANAGER->isOnceKeyDown('A'))
	{

		switch (_WS)
		{
		case WSS_UTIL: case WSS_POTION: case WSS_BALL: case WSS_MACHINE:
			_selectItem[IndexSelectNum].Selected = true;
			break;
		case WSS_CANCEL:
			break;

		}

	}

}

void inventory::itemPrint()
{
	for (_viInventory = _vInventory.begin(); _viInventory != _vInventory.end(); ++_viInventory)
	{
		cout << *_viInventory << endl;
	}

}

