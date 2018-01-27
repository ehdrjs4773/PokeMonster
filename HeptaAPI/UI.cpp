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


	//==============UI 구조체 초기화======================//
	_Info[0].rc = RectMakeCenter(120, 90, 90, 90);
	_Info[1].rc = RectMakeCenter(360, 90, 90, 90);
	_Info[2].rc = RectMakeCenter(120, 180, 90, 90);
	_Info[3].rc = RectMakeCenter(360, 180, 90, 90);
	_Info[4].rc = RectMakeCenter(120, 270, 90, 90);
		


	//======= 불값~========
	_isName = false;


	return S_OK;
}
void UI::release(void)
{

}
void UI::update(void) 
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
			if (!_isName) SCENEMANAGER->changeScene("PokeInfo");
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
	
	}

	// 취솟! //
	if (KEYMANAGER->isOnceKeyDown('C'))
	{
		_isName = false;
		_isMonBak = false;
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

	if (_isName)

	{
		IMAGEMANAGER->findImage("PlayerMedalUi")->render(getMemDC(), 0, 0);
		IMAGEMANAGER->findImage("PlayerMedalUi2")->render(getMemDC(), 0, 100);
	}

}