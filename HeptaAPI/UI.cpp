#include "stdafx.h"
#include "UI.h"



UI::UI()
{

}


UI::~UI()
{

}


HRESULT UI::init()
{
	IMAGEMANAGER->addImage("PlayerUi", ".\\bmps\\UI\\PlayerUi.bmp", WINSIZEX, WINSIZEY, false, true, MAGENTA);
	IMAGEMANAGER->addImage("MedalUi", ".\\bmps\\UI\\medalUi.bmp", 260, 78, false, true, MAGENTA);
	IMAGEMANAGER->addImage("PlayerBag", ".\\bmps\\UI\\PlayerBag.bmp", 90, 90, false, true, MAGENTA);
	IMAGEMANAGER->addImage("PlayerName", ".\\bmps\\UI\\PlayerName.bmp", 90, 90, false, true, MAGENTA);
	IMAGEMANAGER->addImage("PlayerPokeMon", ".\\bmps\\UI\\PlayerPokeMon.bmp", 90, 90, false, true, MAGENTA);
	IMAGEMANAGER->addImage("PlayerSave", ".\\bmps\\UI\\PlayerSave.bmp", 90, 90, false, true, MAGENTA);
	IMAGEMANAGER->addImage("PlayerUiBak", ".\\bmps\\UI\\PlayerUiBak.bmp", 90, 90, false, true, MAGENTA);
	IMAGEMANAGER->addImage("PlayerMedalUi", ".\\bmps\\UI\\medalUi.bmp", 480, 100, false, true, MAGENTA);
	IMAGEMANAGER->addImage("PlayerMedalUi2", ".\\bmps\\UI\\PlayerName2.bmp", 480, 260, false, true, MAGENTA);
	IMAGEMANAGER->addImage("bage1", ".\\bmps\\UI\\bage1.bmp", 35, 35, false, true, MAGENTA);
	IMAGEMANAGER->addImage("bage2", ".\\bmps\\UI\\bage2.bmp", 35, 35, false, true, MAGENTA);
	IMAGEMANAGER->addImage("bage3", ".\\bmps\\UI\\bage3.bmp", 35, 35, false, true, MAGENTA);
	IMAGEMANAGER->addImage("bage4", ".\\bmps\\UI\\bage4.bmp", 35, 35, false, true, MAGENTA);
	IMAGEMANAGER->addImage("bage5", ".\\bmps\\UI\\bage5.bmp", 35, 35, false, true, MAGENTA);
	IMAGEMANAGER->addImage("bage6", ".\\bmps\\UI\\bage6.bmp", 35, 35, false, true, MAGENTA);
	IMAGEMANAGER->addImage("bage7", ".\\bmps\\UI\\bage7.bmp", 35, 35, false, true, MAGENTA);
	IMAGEMANAGER->addImage("bage8", ".\\bmps\\UI\\bage8.bmp", 35, 35, false, true, MAGENTA);
	IMAGEMANAGER->addImage("kingbage", ".\\bmps\\UI\\대왕뱃지.bmp", 92, 50, false, true, MAGENTA);


	//==============UI 구조체 초기화======================//
	_Info[0].rc = RectMakeCenter(120, 90, 90, 90);
	_Info[1].rc = RectMakeCenter(360, 90, 90, 90);
	_Info[2].rc = RectMakeCenter(120, 180, 90, 90);
	_Info[3].rc = RectMakeCenter(360, 180, 90, 90);
	_Info[4].rc = RectMakeCenter(120, 270, 90, 90);

	_NameExit = RectMakeCenter(403, 325, 116, 43);
	_UiExit = RectMakeCenter(403, 318, 116, 43);

	_PlayerBage.rc1 = RectMakeCenter(200, 30, 35, 35);
	_PlayerBage.rc2 = RectMakeCenter(290, 30, 35, 35);
	_PlayerBage.rc3 = RectMakeCenter(380, 30, 35, 35);
	_PlayerBage.rc4 = RectMakeCenter(470, 30, 35, 35);
	_PlayerBage.rc5 = RectMakeCenter(200, 80, 35, 35);
	_PlayerBage.rc6 = RectMakeCenter(290, 80, 35, 35);
	_PlayerBage.rc7 = RectMakeCenter(380, 80, 35, 35);
	_PlayerBage.rc8 = RectMakeCenter(470, 80, 35, 35);

	for (int i = 0 ; i < 8; i++)
	{
		_PlayerBage.bage[i] = false;
	}


	//======= 불값~========
	_isName = false;


	return S_OK;
}
void UI::release(void)
{

}
void UI::update(void) 
{
	if(!_isName)
	{
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
		{
			if (PtInRect(&_Info[0].rc, _ptMouse))
			{
				if (!_isName) SCENEMANAGER->changeScene("인벤토리씬");
			}
		
			else if (PtInRect(&_Info[1].rc, _ptMouse))
			{
				_isName = true;
			}
		
			else if (PtInRect(&_Info[2].rc, _ptMouse))
			{
				if (!_isName)
				{
					SCENEMANAGER->init("PokeInfo");
					SCENEMANAGER->changeScene("PokeInfo");
				}
			}
			else if (PtInRect(&_Info[3].rc, _ptMouse))
			{
				
			}	
			else if (PtInRect(&_Info[4].rc, _ptMouse))
			{
				
			}
			else if (PtInRect(&_Info[5].rc, _ptMouse))
			{
				
			}

			else if (PtInRect(&_UiExit, _ptMouse))
			{
				SCENEMANAGER->changeScene(_destScene);
			}
		
		}
	}

	if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
	{
		if(PtInRect(&_NameExit, _ptMouse))
		{
			_isName = false;
			_isMonBak = false;
		}
	}

	for (int i = 0 ;i < 8; i++)
	{
		if (DATABASE->getIsStageClear(i + 1) == true)
		{
			_PlayerBage.bage[i] = true;
		}

	}
}
void UI::render(void) 
{


	IMAGEMANAGER->findImage("PlayerUi")->render(getMemDC());

	//for (int i = 0; i < 6; i++)
	//{
	//	Rectangle(getMemDC(), _rect[i].left, _rect[i].top, _rect[i].right, _rect[i].bottom);
	//}

	IMAGEMANAGER->findImage("PlayerBag")->render(getMemDC(), _Info[0].rc.left, _Info[0].rc.top);
	IMAGEMANAGER->findImage("PlayerName")->render(getMemDC(), _Info[1].rc.left, _Info[1].rc.top);
	IMAGEMANAGER->findImage("PlayerPokeMon")->render(getMemDC(), _Info[2].rc.left, _Info[2].rc.top);
	IMAGEMANAGER->findImage("PlayerSave")->render(getMemDC(), _Info[3].rc.left, _Info[3].rc.top);
	IMAGEMANAGER->findImage("PlayerUiBak")->render(getMemDC(), _Info[4].rc.left, _Info[4].rc.top);
	//Rectangle(getMemDC(), _UiExit.left, _UiExit.top, _UiExit.right, _UiExit.bottom);
	if (_isName)
	{

		SetBkMode(getMemDC(), TRANSPARENT);
		IMAGEMANAGER->findImage("PlayerMedalUi")->render(getMemDC(), 0, 0);
		IMAGEMANAGER->findImage("PlayerMedalUi2")->render(getMemDC(), 0, 100);
		
		char currentMoney[32];
		sprintf(currentMoney, "%d", 1000);
		TextOut(getMemDC(), 220, 180, currentMoney, strlen(currentMoney));
		//Retanle(getMemDC(),_NameExit.left, _NameExit.top, _NameExit.right, _NameExit.bottom);
		



		
			if (_PlayerBage.bage[0])
			{
				IMAGEMANAGER->findImage("bage1")->render(getMemDC(), _PlayerBage.rc1.left, _PlayerBage.rc1.top);
			}

			if (_PlayerBage.bage[1])
			{
			IMAGEMANAGER->findImage("bage2")->render(getMemDC(), _PlayerBage.rc2.left, _PlayerBage.rc2.top);
			}

			if (_PlayerBage.bage[2])
			{
			IMAGEMANAGER->findImage("bage3")->render(getMemDC(), _PlayerBage.rc3.left, _PlayerBage.rc3.top);
			}

			if (_PlayerBage.bage[3])
			{
			IMAGEMANAGER->findImage("bage4")->render(getMemDC(), _PlayerBage.rc4.left, _PlayerBage.rc4.top);
			}

			if (_PlayerBage.bage[4])
			{
			IMAGEMANAGER->findImage("bage5")->render(getMemDC(), _PlayerBage.rc5.left, _PlayerBage.rc5.top);
			}

			if (_PlayerBage.bage[5])
			{
			IMAGEMANAGER->findImage("bage6")->render(getMemDC(), _PlayerBage.rc6.left, _PlayerBage.rc6.top);
			}

			if (_PlayerBage.bage[6])
			{
			IMAGEMANAGER->findImage("bage7")->render(getMemDC(), _PlayerBage.rc7.left, _PlayerBage.rc7.top);
			}

			if (_PlayerBage.bage[7])
			{
		 	IMAGEMANAGER->findImage("bage8")->render(getMemDC(), _PlayerBage.rc8.left, _PlayerBage.rc8.top);
			}


	

			if (_PlayerBage.bage[0] == true && _PlayerBage.bage[1] == true && _PlayerBage.bage[2] == true && _PlayerBage.bage[3] == true && _PlayerBage.bage[4] == true &&
				_PlayerBage.bage[5] == true && _PlayerBage.bage[6] == true && _PlayerBage.bage[7] == true)
			{
				IMAGEMANAGER->findImage("kingbage")->render(getMemDC(), 15, 25);
			}

		
	}

}