#include "stdafx.h"
#include "inventory.h"
#include "battleScene.h"


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
	_selectMenu[BUTTONS_UTIL].pt.x = 80;
	_selectMenu[BUTTONS_UTIL].pt.y = 0;

	_selectMenu[BUTTONS_POTION].pt.x = 170;
	_selectMenu[BUTTONS_POTION].pt.y = 0;

	_selectMenu[BUTTONS_BALL].pt.x = 260;
	_selectMenu[BUTTONS_BALL].pt.y = 0;

	_selectMenu[BUTTONS_MACHINE].pt.x = 350;
	_selectMenu[BUTTONS_MACHINE].pt.y = 0;

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

	//for (int i = 0; i < SLOT_MAX; i++)
	//{
	//	_invenSlot_UTIL[i].slotUse = false;
	//	_invenSlot_POTION[i].slotUse = false;
	//	_invenSlot_BALL[i].slotUse = false;
	//	_invenSlot_MACHINE[i].slotUse = false;
	//}

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

	}
}


void inventory::buyItems(string strKey, item* itm)
{
	mapItemIter key = _mInvenList.find(strKey);

	if (key != _mInvenList.end()) //key값이 있으면
	{
		int i = key->second->getItemNum();
		key->second->setItemNum(i + 1);
	}
	else //없으면 insert해라
	{
		_mInvenList.insert(make_pair(strKey, itm));
		itm->setItemNum(1);
	}
}

void inventory::renderItem(string strKey, WINDOWSTATUSS ws, int num)
{
	mapItemIter key = _mInvenList.find(strKey);

	if (key != _mInvenList.end()) //key값이 있으면
	{
		if (ws == WSS_UTIL)
		{
			if (_mInvenList.find(strKey)->second->getType() != ITEM_UTILS) return;

			for (int i = 0; i < SLOT_MAX; ++i)
			{
				_invenSlot_UTIL[i].slotUse = false;
			}
			_invenSlot_UTIL[num].slotUse = true;
			if (_invenSlot_UTIL[0].slotUse)
			{
				_invenSlot_UTIL[0].itm = key->second;
				key->second->InvenRender(getMemDC(), _mInvenList.find(strKey)->second->getImg(), ITEMSLOT_FIRSTX, ITEMSLOT_FIRSTY);
			}
			else 	if (_invenSlot_UTIL[1].slotUse)
			{
				_invenSlot_UTIL[1].itm = key->second;
				key->second->InvenRender(getMemDC(), _mInvenList.find(strKey)->second->getImg(), ITEMSLOT_SECONDX, ITEMSLOT_SECONDY);
			}
			else if (_invenSlot_UTIL[2].slotUse)
			{
				_invenSlot_UTIL[2].itm = key->second;
				key->second->InvenRender(getMemDC(), _mInvenList.find(strKey)->second->getImg(), ITEMSLOT_THIRDX, ITEMSLOT_THIRDY);
			}
			else if (_invenSlot_UTIL[3].slotUse)
			{
				_invenSlot_UTIL[3].itm = key->second;
				key->second->InvenRender(getMemDC(), _mInvenList.find(strKey)->second->getImg(), ITEMSLOT_FORTHX, ITEMSLOT_FORTHY);
			}
			else if (_invenSlot_UTIL[4].slotUse)
			{
				_invenSlot_UTIL[4].itm = key->second;
				key->second->InvenRender(getMemDC(), _mInvenList.find(strKey)->second->getImg(), ITEMSLOT_FIFTHX, ITEMSLOT_FIFTHY);
			}
			else if (_invenSlot_UTIL[5].slotUse)
			{
				_invenSlot_UTIL[5].itm = key->second;
				key->second->InvenRender(getMemDC(), _mInvenList.find(strKey)->second->getImg(), ITEMSLOT_SIXTHX, ITEMSLOT_SIXTHY);
			}
			else if (_invenSlot_UTIL[1].slotUse &&_invenSlot_UTIL[2].slotUse &&_invenSlot_UTIL[3].slotUse &&_invenSlot_UTIL[4].slotUse &&_invenSlot_UTIL[5].slotUse &&_invenSlot_UTIL[6].slotUse)
			{
				TextOut(getMemDC(), 200, 200, "아이템 슬롯이 꽉 찼습니다.", strlen("아이템 슬롯이 꽉 찼습니다."));
			}
		}
		else if (ws == WSS_POTION)
		{
			if (_mInvenList.find(strKey)->second->getType() != ITEM_POTION) return;

			for (int i = 0; i < SLOT_MAX; ++i)
			{
				_invenSlot_POTION[i].slotUse = false;
			}
			_invenSlot_POTION[num].slotUse = true;
			if (_invenSlot_POTION[0].slotUse)
			{
				_invenSlot_POTION[0].itm = key->second;
				key->second->InvenRender(getMemDC(), _mInvenList.find(strKey)->second->getImg(), ITEMSLOT_FIRSTX, ITEMSLOT_FIRSTY);
			}
			else 	if (_invenSlot_POTION[1].slotUse)
			{
				_invenSlot_POTION[1].itm = key->second;
				key->second->InvenRender(getMemDC(), _mInvenList.find(strKey)->second->getImg(), ITEMSLOT_SECONDX, ITEMSLOT_SECONDY);
			}
			else if (_invenSlot_POTION[2].slotUse)
			{
				_invenSlot_POTION[2].itm = key->second;
				key->second->InvenRender(getMemDC(), _mInvenList.find(strKey)->second->getImg(), ITEMSLOT_THIRDX, ITEMSLOT_THIRDY);
			}
			else if (_invenSlot_POTION[3].slotUse)
			{
				_invenSlot_POTION[3].itm = key->second;
				key->second->InvenRender(getMemDC(), _mInvenList.find(strKey)->second->getImg(), ITEMSLOT_FORTHX, ITEMSLOT_FORTHY);
			}
			else if (_invenSlot_POTION[4].slotUse)
			{
				_invenSlot_POTION[4].itm = key->second;
				key->second->InvenRender(getMemDC(), _mInvenList.find(strKey)->second->getImg(), ITEMSLOT_FIFTHX, ITEMSLOT_FIFTHY);
			}
			else if (_invenSlot_POTION[5].slotUse)
			{
				_invenSlot_POTION[5].itm = key->second;
				key->second->InvenRender(getMemDC(), _mInvenList.find(strKey)->second->getImg(), ITEMSLOT_SIXTHX, ITEMSLOT_SIXTHY);
			}
			else if (_invenSlot_POTION[0].slotUse &&_invenSlot_POTION[1].slotUse &&_invenSlot_POTION[2].slotUse &&_invenSlot_POTION[3].slotUse &&_invenSlot_POTION[4].slotUse &&_invenSlot_POTION[5].slotUse)
			{
				TextOut(IMAGEMANAGER->findImage("인벤토리_포션")->getMemDC(), 200, 200, "아이템 슬롯이 꽉 찼습니다.", strlen("아이템 슬롯이 꽉 찼습니다."));
			}
		}
		else if (ws == WSS_BALL)
		{
			if (_mInvenList.find(strKey)->second->getType() != ITEM_BALL) return;

			for (int i = 0; i < SLOT_MAX; ++i)
			{
				_invenSlot_BALL[i].slotUse = false;
			}
			_invenSlot_BALL[num].slotUse = true;
			if (_invenSlot_BALL[0].slotUse)
			{
				_invenSlot_BALL[0].itm = key->second;
				key->second->InvenRender(getMemDC(), _mInvenList.find(strKey)->second->getImg(), ITEMSLOT_FIRSTX, ITEMSLOT_FIRSTY);
			}
			else 	if (_invenSlot_BALL[1].slotUse)
			{
				_invenSlot_BALL[1].itm = key->second;
				key->second->InvenRender(getMemDC(), _mInvenList.find(strKey)->second->getImg(), ITEMSLOT_SECONDX, ITEMSLOT_SECONDY);
			}
			else if (_invenSlot_BALL[2].slotUse)
			{
				_invenSlot_BALL[2].itm = key->second;
				key->second->InvenRender(getMemDC(), _mInvenList.find(strKey)->second->getImg(), ITEMSLOT_THIRDX, ITEMSLOT_THIRDY);
			}
			else if (_invenSlot_BALL[3].slotUse)
			{
				_invenSlot_BALL[3].itm = key->second;
				key->second->InvenRender(getMemDC(), _mInvenList.find(strKey)->second->getImg(), ITEMSLOT_FORTHX, ITEMSLOT_FORTHY);
			}
			else if (_invenSlot_BALL[4].slotUse)
			{
				_invenSlot_BALL[4].itm = key->second;
				key->second->InvenRender(getMemDC(), _mInvenList.find(strKey)->second->getImg(), ITEMSLOT_FIFTHX, ITEMSLOT_FIFTHY);
			}
			else if (_invenSlot_BALL[5].slotUse)
			{
				_invenSlot_BALL[5].itm = key->second;
				key->second->InvenRender(getMemDC(), _mInvenList.find(strKey)->second->getImg(), ITEMSLOT_SIXTHX, ITEMSLOT_SIXTHY);
			}
			else if (_invenSlot_BALL[0].slotUse &&_invenSlot_BALL[1].slotUse &&_invenSlot_BALL[2].slotUse &&_invenSlot_BALL[3].slotUse &&_invenSlot_BALL[4].slotUse &&_invenSlot_BALL[5].slotUse)
			{
				TextOut(getMemDC(), 200, 200, "아이템 슬롯이 꽉 찼습니다.", strlen("아이템 슬롯이 꽉 찼습니다."));
			}
		}
		else if (ws == WSS_MACHINE)
		{
			if (_mInvenList.find(strKey)->second->getType() != ITEM_MACHINE) return;

			for (int i = 0; i < SLOT_MAX; ++i)
			{
				_invenSlot_MACHINE[i].slotUse = false;
			}
			_invenSlot_MACHINE[num].slotUse = true;
			if (_invenSlot_MACHINE[0].slotUse)
			{
				key->second->InvenRender(getMemDC(), _mInvenList.find(strKey)->second->getImg(), ITEMSLOT_FIRSTX, ITEMSLOT_FIRSTY);
			}
			else 	if (_invenSlot_MACHINE[1].slotUse)
			{
				key->second->InvenRender(getMemDC(), _mInvenList.find(strKey)->second->getImg(), ITEMSLOT_SECONDX, ITEMSLOT_SECONDY);
			}
			else if (_invenSlot_MACHINE[2].slotUse)
			{
				key->second->InvenRender(getMemDC(), _mInvenList.find(strKey)->second->getImg(), ITEMSLOT_THIRDX, ITEMSLOT_THIRDY);
			}
			else if (_invenSlot_MACHINE[3].slotUse)
			{
				key->second->InvenRender(getMemDC(), _mInvenList.find(strKey)->second->getImg(), ITEMSLOT_FORTHX, ITEMSLOT_FORTHY);
			}
			else if (_invenSlot_MACHINE[4].slotUse)
			{
				key->second->InvenRender(getMemDC(), _mInvenList.find(strKey)->second->getImg(), ITEMSLOT_FIFTHX, ITEMSLOT_FIFTHY);
			}
			else if (_invenSlot_MACHINE[5].slotUse)
			{
				key->second->InvenRender(getMemDC(), _mInvenList.find(strKey)->second->getImg(), ITEMSLOT_SIXTHX, ITEMSLOT_SIXTHY);
			}
			else if (_invenSlot_MACHINE[0].slotUse &&_invenSlot_MACHINE[1].slotUse &&_invenSlot_MACHINE[2].slotUse &&_invenSlot_MACHINE[3].slotUse &&_invenSlot_MACHINE[4].slotUse &&_invenSlot_MACHINE[5].slotUse)
			{
				TextOut(getMemDC(), 200, 200, "아이템 슬롯이 꽉 찼습니다.", strlen("아이템 슬롯이 꽉 찼습니다."));
			}
		}
		else //없으면
		{
			//TextOut(getMemDC(), 100, 100, "gkgk2", strlen("gkgk2"));
		}
	}
}


void inventory::UtilMenuDraw() //인벤토리 유틸 Menu 그려주는 함수
{
	IMAGEMANAGER->findImage("인벤토리_유틸")->render(getMemDC(), 0, 0);
	IMAGEMANAGER->findImage("인벤토리취소")->render(getMemDC(), 360, 310);

	IMAGEMANAGER->findImage("아이콘_유틸")->frameRender(getMemDC(), _selectMenu[BUTTONS_UTIL].pt.x, _selectMenu[BUTTONS_UTIL].pt.y, 0, 1);
	IMAGEMANAGER->findImage("아이콘선택")->render(getMemDC(), _selectMenu[BUTTONS_UTIL].pt.x, _selectMenu[BUTTONS_UTIL].pt.y);

	IMAGEMANAGER->findImage("아이콘_포션")->frameRender(getMemDC(), _selectMenu[BUTTONS_POTION].pt.x, _selectMenu[BUTTONS_POTION].pt.y, 0, 0);
	IMAGEMANAGER->findImage("아이콘_볼")->frameRender(getMemDC(), _selectMenu[BUTTONS_BALL].pt.x, _selectMenu[BUTTONS_BALL].pt.y, 0, 0);
	IMAGEMANAGER->findImage("아이콘_머신")->frameRender(getMemDC(), _selectMenu[BUTTONS_MACHINE].pt.x, _selectMenu[BUTTONS_MACHINE].pt.y, 0, 0);



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

	mapItemIter iter = _mInvenList.begin();
	for (int i = 0; iter != _mInvenList.end(); ++iter, ++i)
	{
		if (iter->second->getType() != ITEM_UTILS)
		{
			--i;
		}
		else
			renderItem(iter->first, WSS_UTIL, i);
	}

	//각 부분 선택시 발생하는 이벤트 제어
	if (_selectItem[INDEXS_BUTTON_0].Selected) //1번째 아이템 
	{
		if (_invenSlot_UTIL[0].slotUse == true)
		{
			_currentItem = _invenSlot_UTIL[0].itm;
			SCENEMANAGER->changeScene("PokeInfo");
		}

		_selectItem[INDEXS_BUTTON_0].Selected = false;
	}
	if (_selectItem[INDEXS_BUTTON_1].Selected) //2번째 아이템 
	{
		if (_invenSlot_UTIL[1].slotUse == true)
		{
			_currentItem = _invenSlot_UTIL[1].itm;
			SCENEMANAGER->changeScene("PokeInfo");
		}

		_selectItem[INDEXS_BUTTON_1].Selected = false;
	}
	if (_selectItem[INDEXS_BUTTON_2].Selected) //3번째 아이템 
	{
		if (_invenSlot_UTIL[2].slotUse == true)
		{
			_currentItem = _invenSlot_UTIL[2].itm;
			SCENEMANAGER->changeScene("PokeInfo");
		}

		_selectItem[INDEXS_BUTTON_2].Selected = false;
	}
	if (_selectItem[INDEXS_BUTTON_3].Selected) //4번째 아이템 
	{
		if (_invenSlot_UTIL[3].slotUse == true)
		{
			_currentItem = _invenSlot_UTIL[3].itm;
			SCENEMANAGER->changeScene("PokeInfo");
		}

		_selectItem[INDEXS_BUTTON_3].Selected = false;
	}
	if (_selectItem[INDEXS_BUTTON_4].Selected) //5번째 아이템 
	{
		if (_invenSlot_UTIL[4].slotUse == true)
		{
			_currentItem = _invenSlot_UTIL[4].itm;
			SCENEMANAGER->changeScene("PokeInfo");
		}

		_selectItem[INDEXS_BUTTON_4].Selected = false;
	}
	if (_selectItem[INDEXS_BUTTON_5].Selected) //6번째 아이템 
	{
		if (_invenSlot_UTIL[5].slotUse == true)
		{
			_currentItem = _invenSlot_UTIL[5].itm;
			SCENEMANAGER->changeScene("PokeInfo");
		}
	
		_selectItem[INDEXS_BUTTON_5].Selected = false;
	}
	if (_selectItem[INDEXS_BUTTON_CANCEL].Selected) //취소 버튼
	{
		SCENEMANAGER->changeScene(SCENEMANAGER->getLastSceneName());
		_selectItem[INDEXS_BUTTON_CANCEL].Selected = false;
	}
}

void inventory::PotionMenuDraw() // 인벤토리 포션 Menu 그려주는 함수
{
	IMAGEMANAGER->findImage("인벤토리_포션")->render(getMemDC(), 0, 0);
	IMAGEMANAGER->findImage("인벤토리취소")->render(getMemDC(), 360, 310);

	IMAGEMANAGER->findImage("아이콘_유틸")->frameRender(getMemDC(), _selectMenu[BUTTONS_UTIL].pt.x, _selectMenu[BUTTONS_UTIL].pt.y, 0, 0);


	IMAGEMANAGER->findImage("아이콘_포션")->frameRender(getMemDC(), _selectMenu[BUTTONS_POTION].pt.x, _selectMenu[BUTTONS_POTION].pt.y, 0, 1);
	IMAGEMANAGER->findImage("아이콘_볼")->frameRender(getMemDC(), _selectMenu[BUTTONS_BALL].pt.x, _selectMenu[BUTTONS_BALL].pt.y, 0, 0);
	IMAGEMANAGER->findImage("아이콘_머신")->frameRender(getMemDC(), _selectMenu[BUTTONS_MACHINE].pt.x, _selectMenu[BUTTONS_MACHINE].pt.y, 0, 0);
	IMAGEMANAGER->findImage("아이콘선택")->render(getMemDC(), _selectMenu[BUTTONS_POTION].pt.x, _selectMenu[BUTTONS_POTION].pt.y);
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

	mapItemIter iter = _mInvenList.begin();
	for (int i = 0; iter != _mInvenList.end(); ++iter, ++i)
	{
		if (iter->second->getType() != ITEM_POTION)
		{
			--i;
		}

		renderItem(iter->first, WSS_POTION, i);
	}

	//각 부분 선택시 발생하는 이벤트 제어
	if (_selectItem[INDEXS_BUTTON_0].Selected) //1번째 아이템 
	{
		if (_invenSlot_POTION[0].slotUse == true)
		{
			_currentItem = _invenSlot_POTION[0].itm;
			SCENEMANAGER->changeScene("PokeInfo");
		}

		_selectItem[INDEXS_BUTTON_0].Selected = false;
	}
	if (_selectItem[INDEXS_BUTTON_1].Selected) //2번째 아이템 
	{
		if (_invenSlot_POTION[1].slotUse == true)
		{
			_currentItem = _invenSlot_POTION[1].itm;
			SCENEMANAGER->changeScene("PokeInfo");
		}
		_selectItem[INDEXS_BUTTON_1].Selected = false;
	}
	if (_selectItem[INDEXS_BUTTON_2].Selected) //3번째 아이템 
	{
		if (_invenSlot_POTION[2].slotUse == true)
		{
			_currentItem = _invenSlot_POTION[2].itm;
			SCENEMANAGER->changeScene("PokeInfo");
		}
		_selectItem[INDEXS_BUTTON_2].Selected = false;
	}
	if (_selectItem[INDEXS_BUTTON_3].Selected) //4번째 아이템 
	{
		if (_invenSlot_POTION[3].slotUse == true)
		{
			_currentItem = _invenSlot_POTION[3].itm;
			SCENEMANAGER->changeScene("PokeInfo");
		}
		_selectItem[INDEXS_BUTTON_3].Selected = false;
	}
	if (_selectItem[INDEXS_BUTTON_4].Selected) //5번째 아이템 
	{
		if (_invenSlot_POTION[4].slotUse == true)
		{
			_currentItem = _invenSlot_POTION[4].itm;
			SCENEMANAGER->changeScene("PokeInfo");
		}
		_selectItem[INDEXS_BUTTON_4].Selected = false;
	}
	if (_selectItem[INDEXS_BUTTON_5].Selected) //6번째 아이템 
	{
		if (_invenSlot_POTION[5].slotUse == true)
		{
			_currentItem = _invenSlot_POTION[5].itm;
			SCENEMANAGER->changeScene("PokeInfo");
		}
		_selectItem[INDEXS_BUTTON_5].Selected = false;
	}
	if (_selectItem[INDEXS_BUTTON_CANCEL].Selected) //취소 버튼
	{
		SCENEMANAGER->changeScene(SCENEMANAGER->getLastSceneName());
		_selectItem[INDEXS_BUTTON_CANCEL].Selected = false;
	}
}

void inventory::BallMenuDraw() //인벤토리 볼 Menu 그려주는 함수
{
	IMAGEMANAGER->findImage("인벤토리_볼")->render(getMemDC(), 0, 0);
	IMAGEMANAGER->findImage("인벤토리취소")->render(getMemDC(), 360, 310);

	IMAGEMANAGER->findImage("아이콘_유틸")->frameRender(getMemDC(), _selectMenu[BUTTONS_UTIL].pt.x, _selectMenu[BUTTONS_UTIL].pt.y, 0, 0);
	IMAGEMANAGER->findImage("아이콘_포션")->frameRender(getMemDC(), _selectMenu[BUTTONS_POTION].pt.x, _selectMenu[BUTTONS_POTION].pt.y, 0, 0);

	IMAGEMANAGER->findImage("아이콘_볼")->frameRender(getMemDC(), _selectMenu[BUTTONS_BALL].pt.x, _selectMenu[BUTTONS_BALL].pt.y, 0, 1);
	IMAGEMANAGER->findImage("아이콘선택")->render(getMemDC(), _selectMenu[BUTTONS_BALL].pt.x, _selectMenu[BUTTONS_BALL].pt.y);

	IMAGEMANAGER->findImage("아이콘_머신")->frameRender(getMemDC(), _selectMenu[BUTTONS_MACHINE].pt.x, _selectMenu[BUTTONS_MACHINE].pt.y, 0, 0);

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

	mapItemIter iter = _mInvenList.begin();
	for (int i = 0; iter != _mInvenList.end(); ++iter, ++i)
	{
		if (iter->second->getType() != ITEM_BALL)
		{
			i--;
		}

		renderItem(iter->first, WSS_BALL, i);
	}

	_battleScene = (battleScene*)SCENEMANAGER->findScene("battleScene");

	//각 부분 선택시 발생하는 이벤트 제어
	if (_selectItem[INDEXS_BUTTON_0].Selected) //1번째 아이템 
	{
		if (_invenSlot_BALL[0].slotUse == true)
		{
			if (_battleScene->getCurrentEnemyType() != ENEMY_WILD)
			{
				_currentItem = _invenSlot_BALL[0].itm;
				_battleScene->setSequenceCatch();
				SCENEMANAGER->changeScene("battleScene");
			}
		}
		_selectItem[INDEXS_BUTTON_0].Selected = false;
	}
	if (_selectItem[INDEXS_BUTTON_1].Selected) //2번째 아이템 
	{
		if (_invenSlot_BALL[1].slotUse == true)
		{
			if (_battleScene->getCurrentEnemyType() != ENEMY_WILD)
			{
				_currentItem = _invenSlot_BALL[1].itm;
				_battleScene->setSequenceCatch();
				SCENEMANAGER->changeScene("battleScene");
			}
		}
		_selectItem[INDEXS_BUTTON_1].Selected = false;
	}
	if (_selectItem[INDEXS_BUTTON_2].Selected) //3번째 아이템 
	{
		if (_invenSlot_BALL[2].slotUse == true)
		{
			if (_battleScene->getCurrentEnemyType() != ENEMY_WILD)
			{
				_currentItem = _invenSlot_BALL[2].itm;
				_battleScene->setSequenceCatch();
				SCENEMANAGER->changeScene("battleScene");
			}
		}
		_selectItem[INDEXS_BUTTON_2].Selected = false;
	}
	if (_selectItem[INDEXS_BUTTON_3].Selected) //4번째 아이템 
	{
		if (_invenSlot_BALL[3].slotUse == true)
		{
			if (_battleScene->getCurrentEnemyType() != ENEMY_WILD)
			{
				_currentItem = _invenSlot_BALL[3].itm;
				_battleScene->setSequenceCatch();
				SCENEMANAGER->changeScene("battleScene");
			}
		}
		_selectItem[INDEXS_BUTTON_3].Selected = false;
	}
	if (_selectItem[INDEXS_BUTTON_4].Selected) //5번째 아이템 
	{
		if (_invenSlot_BALL[4].slotUse == true)
		{
			if (_battleScene->getCurrentEnemyType() != ENEMY_WILD)
			{
				_currentItem = _invenSlot_BALL[4].itm;
				_battleScene->setSequenceCatch();
				SCENEMANAGER->changeScene("battleScene");
			}
		}
		_selectItem[INDEXS_BUTTON_4].Selected = false;
	}
	if (_selectItem[INDEXS_BUTTON_5].Selected) //6번째 아이템 
	{
		if (_invenSlot_BALL[5].slotUse == true)
		{
			if (_battleScene->getCurrentEnemyType() != ENEMY_WILD)
			{
				_currentItem = _invenSlot_BALL[5].itm;
				_battleScene->setSequenceCatch();
				SCENEMANAGER->changeScene("battleScene");
			}
		}
		_selectItem[INDEXS_BUTTON_5].Selected = false;
	}
	if (_selectItem[INDEXS_BUTTON_CANCEL].Selected) //취소 버튼
	{
		SCENEMANAGER->changeScene(SCENEMANAGER->getLastSceneName());
		_selectItem[INDEXS_BUTTON_CANCEL].Selected = false;
	}

}

void inventory::MachineMenuDraw() //인벤토리 머신 Menu 그려주는 함수
{
	IMAGEMANAGER->findImage("인벤토리_머신")->render(getMemDC(), 0, 0);
	IMAGEMANAGER->findImage("인벤토리취소")->render(getMemDC(), 360, 310);

	IMAGEMANAGER->findImage("아이콘_유틸")->frameRender(getMemDC(), _selectMenu[BUTTONS_UTIL].pt.x, _selectMenu[BUTTONS_UTIL].pt.y, 0, 0);
	IMAGEMANAGER->findImage("아이콘_포션")->frameRender(getMemDC(), _selectMenu[BUTTONS_POTION].pt.x, _selectMenu[BUTTONS_POTION].pt.y, 0, 0);
	IMAGEMANAGER->findImage("아이콘_볼")->frameRender(getMemDC(), _selectMenu[BUTTONS_BALL].pt.x, _selectMenu[BUTTONS_BALL].pt.y, 0, 0);

	IMAGEMANAGER->findImage("아이콘_머신")->frameRender(getMemDC(), _selectMenu[BUTTONS_MACHINE].pt.x, _selectMenu[BUTTONS_MACHINE].pt.y, 0, 1);
	IMAGEMANAGER->findImage("아이콘선택")->render(getMemDC(), _selectMenu[BUTTONS_MACHINE].pt.x, _selectMenu[BUTTONS_MACHINE].pt.y);
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

	mapItemIter iter = _mInvenList.begin();
	for (int i = 0; iter != _mInvenList.end(); ++iter, ++i)
	{
		if (iter->second->getType() != ITEM_MACHINE)
		{
			--i;
		}

		renderItem(iter->first, WSS_MACHINE, i);
	}

	//각 부분 선택시 발생하는 이벤트 제어
	if (_selectItem[INDEXS_BUTTON_0].Selected) //1번째 아이템 
	{
		if (_invenSlot_MACHINE[0].slotUse == true)
		{
			_currentItem = _invenSlot_MACHINE[0].itm;
			SCENEMANAGER->changeScene("PokeInfo");
		}
		_selectItem[INDEXS_BUTTON_0].Selected = false;
	}
	if (_selectItem[INDEXS_BUTTON_1].Selected) //2번째 아이템 
	{
		if (_invenSlot_MACHINE[1].slotUse == true)
		{
			_currentItem = _invenSlot_MACHINE[1].itm;
			SCENEMANAGER->changeScene("PokeInfo");
		}
		_selectItem[INDEXS_BUTTON_1].Selected = false;
	}
	if (_selectItem[INDEXS_BUTTON_2].Selected) //3번째 아이템 
	{
		if (_invenSlot_MACHINE[2].slotUse == true)
		{
			_currentItem = _invenSlot_MACHINE[2].itm;
			SCENEMANAGER->changeScene("PokeInfo");
		}
		_selectItem[INDEXS_BUTTON_2].Selected = false;
	}
	if (_selectItem[INDEXS_BUTTON_3].Selected) //4번째 아이템 
	{
		if (_invenSlot_MACHINE[3].slotUse == true)
		{
			_currentItem = _invenSlot_MACHINE[3].itm;
			SCENEMANAGER->changeScene("PokeInfo");
		}
		_selectItem[INDEXS_BUTTON_3].Selected = false;
	}
	if (_selectItem[INDEXS_BUTTON_4].Selected) //5번째 아이템 
	{
		if (_invenSlot_MACHINE[4].slotUse == true)
		{
			_currentItem = _invenSlot_MACHINE[4].itm;
			SCENEMANAGER->changeScene("PokeInfo");
		}
		_selectItem[INDEXS_BUTTON_4].Selected = false;
	}
	if (_selectItem[INDEXS_BUTTON_5].Selected) //6번째 아이템 
	{
		if (_invenSlot_MACHINE[5].slotUse == true)
		{
			_currentItem = _invenSlot_MACHINE[5].itm;
			SCENEMANAGER->changeScene("PokeInfo");
		}
		_selectItem[INDEXS_BUTTON_5].Selected = false;
	}
	if (_selectItem[INDEXS_BUTTON_CANCEL].Selected) //취소 버튼
	{
		SCENEMANAGER->changeScene(SCENEMANAGER->getLastSceneName());
		_selectItem[INDEXS_BUTTON_CANCEL].Selected = false;
	}

}

void inventory::KeyControl()
{

	if (KEYMANAGER->isOnceKeyDown(VK_UP))
	{
		switch (_WS)
		{
		case WSS_UTIL:
			changeWS(WSS_MACHINE);
			break;
		case WSS_POTION:
			changeWS(WSS_UTIL);
			break;
		case WSS_BALL:
			changeWS(WSS_POTION);
			break;
		case WSS_MACHINE:
			changeWS(WSS_BALL);
			break;
		}
	}

	if (KEYMANAGER->isOnceKeyDown(VK_DOWN))
	{
		switch (_WS)
		{
		case WSS_UTIL:
			changeWS(WSS_POTION);
			break;
		case WSS_POTION:
			changeWS(WSS_BALL);
			break;
		case WSS_BALL:
			changeWS(WSS_MACHINE);
			break;
		case WSS_MACHINE:
			changeWS(WSS_UTIL);
			break;
		}
	}

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

	if (KEYMANAGER->isOnceKeyDown(PLAYER_SELECT_KEY))
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

	if (KEYMANAGER->isOnceKeyDown(PLAYER_CANCLE_KEY))
	{
		SCENEMANAGER->changeScene(SCENEMANAGER->getLastSceneName());
	}

}

//void inventory::itemPrint(string strKey, image* img, HDC hdc, int destX, int destY, int itemNum)
//{
//	for (_viInventory = _vInventory.begin(); _viInventory != _vInventory.end(); ++_viInventory)
//	{
//		(*_viInventory)->render(hdc, img, destX, destY, itemNum);
//	}
//
//}


map<string, item*>::iterator inventory::findNum(int arrNum)
{
	mapItemIter iter = _mInvenList.begin();
	for (int i = 0; i < arrNum; arrNum)
		++iter;

	return iter;
}


