#include "stdafx.h"
#include "shopScene.h"
#include "inventory.h"



shopScene::shopScene()
{
}


shopScene::~shopScene()
{
}

HRESULT shopScene::init()
{
	_item = new itemManager;

	//ITEM IMAGE ADD
	IMAGEMANAGER->addImage("마스터볼", ".\\bmps\\shopScene\\item_masterball.bmp", 20, 20, false, true, MAGENTA);
	IMAGEMANAGER->addImage("몬스터볼", ".\\bmps\\shopScene\\item_monsterball.bmp", 20, 20, false, true, MAGENTA);
	IMAGEMANAGER->addImage("하이퍼볼", ".\\bmps\\shopScene\\item_hyperball.bmp", 20, 20, false, true, MAGENTA);
	IMAGEMANAGER->addImage("슈퍼볼", ".\\bmps\\shopScene\\item_superball.bmp", 20, 20, false, true, MAGENTA);
	IMAGEMANAGER->addImage("hp포션", ".\\bmps\\shopScene\\item_potion1.bmp", 16, 28, false, true, MAGENTA);
	IMAGEMANAGER->addImage("pp포션", ".\\bmps\\shopScene\\item_potion2.bmp", 16, 28, false, true, MAGENTA);
	IMAGEMANAGER->addImage("자전거", ".\\bmps\\shopScene\\item_util_bicycle.bmp", 30, 30, false, true, MAGENTA);
	IMAGEMANAGER->addImage("낚시대", ".\\bmps\\shopScene\\item_util_fishinglod.bmp", 30, 30, false, true, MAGENTA);
	IMAGEMANAGER->addImage("머신1", ".\\bmps\\shopScene\\item_machine1.bmp", 17, 27, false, true, MAGENTA);
	IMAGEMANAGER->addImage("머신2", ".\\bmps\\shopScene\\item_machine2.bmp", 17, 27, false, true, MAGENTA);
	IMAGEMANAGER->addImage("머신3", ".\\bmps\\shopScene\\item_machine3.bmp", 17, 27, false, true, MAGENTA);
	IMAGEMANAGER->addImage("머신4", ".\\bmps\\shopScene\\item_machine4.bmp", 17, 27, false, true, MAGENTA);

	//ITEM ADD
	_item->addItem("몬스터볼", IMAGEMANAGER->findImage("몬스터볼"),1, ITEM_BALL, "몬스터볼", "몬스터볼입니다", 50, 500);
	_item->addItem("마스터볼", IMAGEMANAGER->findImage("마스터볼"), 4, ITEM_BALL, "마스터볼", "마스터볼입니다", 100, 5000);
	_item->addItem("hp포션", IMAGEMANAGER->findImage("hp포션") ,2, ITEM_POTION, "hp포션", "hp 채우는 포션입니다", 150, 5000);
	_item->addItem("pp포션", IMAGEMANAGER->findImage("pp포션"), 2, ITEM_POTION, "pp포션", "pp를 채우는 포션입니다", 150, 5000);
	_item->addItem("머신4", IMAGEMANAGER->findImage("머신4"), 2, ITEM_MACHINE, "기술머신4", "머신4입니다", 150, 5000);
	_item->addItem("자전거", IMAGEMANAGER->findImage("자전거"), 3, ITEM_UTILS, "자전거", "자전거입니다", 200, 1000);
	

	//상점입장시메인메뉴 이미지 등록
	IMAGEMANAGER->addImage("상점오픈", ".\\bmps\\shopScene\\shop_open.bmp", WINSIZEX, WINSIZEY, false, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("상점오픈버튼_BUY", ".\\bmps\\shopScene\\shop_button_buy.bmp", 252, 46, false, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("상점오픈버튼_SELL", ".\\bmps\\shopScene\\shop_button_sell.bmp", 252, 46, false, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("상점오픈버튼_CANCEL", ".\\bmps\\shopScene\\shop_button_cancel.bmp", 252, 46, false, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("상점선택", ".\\bmps\\shopScene\\shop_button_select.bmp", 252, 46, false, true, RGB(255, 0, 255));

	//사러가기 선택시 이미지등록
	IMAGEMANAGER->addImage("상점메인", ".\\bmps\\shopScene\\shop_main.bmp", WINSIZEX, WINSIZEY, false, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("상점사러가기선택", ".\\bmps\\shopScene\\shop_main_select.bmp", 232, 69, false, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("상점사러가기취소", ".\\bmps\\shopScene\\exit_box.bmp", 116, 43, false, true, MAGENTA);
	IMAGEMANAGER->addImage("상점사러가기취소선택", ".\\bmps\\shopScene\\exit_box_select.bmp", 116, 43, false, true, MAGENTA);

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

	_selectItem[INDEX_BUTTON_1].pt.x = 245;
	_selectItem[INDEX_BUTTON_1].pt.y = 75;

	_selectItem[INDEX_BUTTON_2].pt.x = 5;
	_selectItem[INDEX_BUTTON_2].pt.y = 150;

	_selectItem[INDEX_BUTTON_3].pt.x = 245;
	_selectItem[INDEX_BUTTON_3].pt.y = 150;

	_selectItem[INDEX_BUTTON_4].pt.x = 5;
	_selectItem[INDEX_BUTTON_4].pt.y = 225;

	_selectItem[INDEX_BUTTON_5].pt.x = 245;
	_selectItem[INDEX_BUTTON_5].pt.y = 225;

	_selectItem[INDEX_BUTTON_CANCEL].pt.x = 360;
	_selectItem[INDEX_BUTTON_CANCEL].pt.y = 310;

	for (int i = 0; i < BUTTON_END; i++)
	{
	_selectMenu[i].Selected = false;
	}

	for (int i = 0; i < INDEX_BUTTON_END; i++)
	{
		_selectItem[i].Selected = false;
	}

	_WS = WS_MAIN;

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
	KeyControl();
}

void shopScene::render()
{
	switch (_WS)
	{
	case WS_MAIN:
			shopMainMenuDraw();
		break;
	case WS_BUY:
			shopBuyMenuDraw();
		break;
	case WS_SELL:
			shopBuyMenuDraw();
		break;
	case WS_CANCEL:
		break;

	}
	

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

	_item->findItem("몬스터볼")->render(IMAGEMANAGER->findImage("상점메인")->getMemDC(), IMAGEMANAGER->findImage("몬스터볼"), ITEMSLOT_FIRSTX, ITEMSLOT_FIRSTY, 3);
	_item->findItem("마스터볼")->render(IMAGEMANAGER->findImage("상점메인")->getMemDC(), IMAGEMANAGER->findImage("마스터볼"), ITEMSLOT_SECONDX, ITEMSLOT_SECONDY, 3);
	_item->findItem("hp포션")->render(IMAGEMANAGER->findImage("상점메인")->getMemDC(), IMAGEMANAGER->findImage("hp포션"), ITEMSLOT_THIRDX, ITEMSLOT_THIRDY, 3);
	_item->findItem("pp포션")->render( IMAGEMANAGER->findImage("상점메인")->getMemDC(), IMAGEMANAGER->findImage("pp포션"), ITEMSLOT_FORTHX, ITEMSLOT_FORTHY, 2);
	_item->findItem("자전거")->render(IMAGEMANAGER->findImage("상점메인")->getMemDC(), IMAGEMANAGER->findImage("자전거"), ITEMSLOT_FIFTHX, ITEMSLOT_FIFTHY, 2);
	_item->findItem("머신4")->render(IMAGEMANAGER->findImage("상점메인")->getMemDC(), IMAGEMANAGER->findImage("머신4"), ITEMSLOT_SIXTHX, ITEMSLOT_SIXTHY, 2);

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
		_WS = WS_BUY;
		_selectMenu[BUTTON_BUY].Selected = false;
	}

	if (_selectMenu[BUTTON_SELL].Selected) //팔러가기 버튼 선택시
	{
		IMAGEMANAGER->findImage("상점메인")->render(getMemDC(), 0, 0);
		shopBuyMenuDraw();
		_WS = WS_SELL;
		_selectMenu[BUTTON_SELL].Selected = false;
	}

	if (_selectMenu[BUTTON_CANCEL].Selected) //취소버튼 선택시
	{
		SCENEMANAGER->changeScene(SCENEMANAGER->getLastSceneName());
		_selectMenu[BUTTON_CANCEL].Selected = false;
	}
}

void shopScene::shopBuyMenuDraw() //상점 사러가기 Menu 그려주는 함수
{
	IMAGEMANAGER->findImage("상점메인")->render(getMemDC(), 0, 0);
	IMAGEMANAGER->findImage("상점사러가기취소")->render(getMemDC(), 360, 310);

	//상점BUY 선택 이동 렌더 부분
	for (int i = 0; i <6; i++)
	{
		if (_selectItem[i].isSelect == true)
		{
			IMAGEMANAGER->findImage("상점사러가기선택")->render(getMemDC(), _selectItem[i].pt.x, _selectItem[i].pt.y);
		}
	}
	//취소 버튼 선택 랜더
	if (_selectItem[INDEX_BUTTON_CANCEL] .isSelect == true)
	{
		IMAGEMANAGER->findImage("상점사러가기취소선택")->render(getMemDC(), _selectItem[6].pt.x, _selectItem[6].pt.y);
	}

	//각 부분 선택시 발생하는 이벤트 제어
	if (_selectItem[INDEX_BUTTON_0].Selected) //1번째 아이템 
	{
		_inven->buyItems("몬스터볼", _item->findItem("몬스터볼"));	
		_selectItem[INDEX_BUTTON_0].Selected = false;
	}
	if (_selectItem[INDEX_BUTTON_1].Selected) //2번째 아이템 
	{
		_inven->buyItems("마스터볼", _item->findItem("마스터볼"));
		_selectItem[INDEX_BUTTON_1].Selected = false;
	}
	if (_selectItem[INDEX_BUTTON_2].Selected) //3번째 아이템 
	{
		_inven->buyItems("hp포션", _item->findItem("hp포션"));
		_selectItem[INDEX_BUTTON_2].Selected = false;
	}
	if (_selectItem[INDEX_BUTTON_3].Selected) //4번째 아이템 
	{
		_inven->buyItems("pp포션", _item->findItem("pp포션"));
		_selectItem[INDEX_BUTTON_3].Selected = false;
	}
	if (_selectItem[INDEX_BUTTON_4].Selected) //5번째 아이템 
	{
		_inven->buyItems("자전거", _item->findItem("자전거"));
		_selectItem[INDEX_BUTTON_4].Selected = false;
	}
	if (_selectItem[INDEX_BUTTON_5].Selected) //6번째 아이템 
	{
		_inven->buyItems("머신4", _item->findItem("머신4"));
		_selectItem[INDEX_BUTTON_5].Selected = false;
	}
	if (_selectItem[INDEX_BUTTON_CANCEL].Selected) //취소 버튼
	{
		SCENEMANAGER->changeScene("인벤토리씬");
		SCENEMANAGER->init("인벤토리씬");
		_selectItem[INDEX_BUTTON_CANCEL].Selected = false;
	}
	
}

void shopScene::KeyControl()
{
	if (KEYMANAGER->isOnceKeyDown(VK_UP))
	{
		switch (_WS)
		{
		case WS_MAIN:
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
				break;
		case WS_BUY:
			break;
		case WS_SELL:
			break;
		case WS_CANCEL:
			break;
		}
	}

	if (KEYMANAGER->isOnceKeyDown(VK_DOWN))
	{
		switch (_WS)
		{
		case WS_MAIN:
			SelectNum = (SelectNum + 1) % BUTTON_END;
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
			break;
		case WS_BUY:
	
			break;
		case WS_SELL:
			break;
		case WS_CANCEL:
			break;
		
		}
	}

	if (KEYMANAGER->isOnceKeyDown(VK_LEFT))
	{
		switch (_WS)
		{
		case WS_MAIN:
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
			break;
		case WS_BUY:
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
			break;
		case WS_SELL:
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
			break;
		case WS_CANCEL:
			break;

		}
	}

	if (KEYMANAGER->isOnceKeyDown(VK_RIGHT))
	{
		switch (_WS)
		{
		case WS_MAIN:
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
			break;
		case WS_BUY:
			IndexSelectNum = (IndexSelectNum + 1) % INDEX_BUTTON_END;
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
			break;
		case WS_SELL:
			IndexSelectNum = (IndexSelectNum + 1) % INDEX_BUTTON_END;
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
			break;
		case WS_CANCEL:
			break;

		}

	}

	if (KEYMANAGER->isOnceKeyDown(PLAYER_SELECT_KEY))
	{

		switch (_WS)
		{
		case WS_MAIN:
			_selectMenu[SelectNum].Selected = true;
			break;
		case WS_BUY:
			_selectItem[IndexSelectNum].Selected = true;
			break;
		case WS_SELL:
			_selectItem[IndexSelectNum].Selected = true;
			break;
		case WS_CANCEL:
			break;

		}
	
	}

	if (KEYMANAGER->isOnceKeyDown(PLAYER_CANCLE_KEY))
	{
		SCENEMANAGER->changeScene(SCENEMANAGER->getLastSceneName());
	}


}



