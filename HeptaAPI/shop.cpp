#include "stdafx.h"
#include "shop.h"
#include "jm_itemManager.h"

shop::shop()
{
}


shop::~shop()
{
}



HRESULT shop::init()
{
	IMAGEMANAGER->addImage("shop_menu", ".\\bmps\\shop\\shop_menu.bmp", WINSIZEX, WINSIZEY);
	IMAGEMANAGER->addImage("shop_main", ".\\bmps\\shop\\shop_main.bmp", WINSIZEX, WINSIZEY);
	IMAGEMANAGER->addImage("shop_menu_box", ".\\bmps\\shop\\shop_menu_box.bmp", 200, 61 ,false, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("shop_select_box", ".\\bmps\\shop\\shop_select_box_1.bmp", 200, 61, false, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("shop_select_box_2", ".\\bmps\\shop\\shop_select_box_2.bmp", 50, 50, false, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("shop_select_box_3", ".\\bmps\\shop\\shop_select_box_3.bmp", 230, 68, false, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("shop_select_box_4", ".\\bmps\\shop\\shop_select_box_4.bmp", 116, 43, false, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("shop_exit_box", ".\\bmps\\shop\\shop_exit_box.bmp", 116, 43, false, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("shop_tool_box", ".\\bmps\\shop\\item_kind_1.bmp", 0, 0, 50, 100, 1, 2, false, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("shop_postion_box", ".\\bmps\\shop\\item_kind_2.bmp", 0, 0, 50, 100, 1, 2, false, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("shop_ball_box", ".\\bmps\\shop\\item_kind_3.bmp", 0, 0, 50, 100, 1, 2, false, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("shop_machine_box", ".\\bmps\\shop\\item_kind_4.bmp", 0, 0, 50, 100, 1, 2, false, true, RGB(255, 0, 255));

	_state = SHOP_MENU;

	_im = new jm_itemManager;
	_im->init();
	_im->addItem_ball();
	_im->addItem_postion();
	_im->addItem_tool();
	_im->addItem_machine();
	

	//눌럿을때 이미지 전환
	_currentFrameY_1 = 1;
	_currentFrameY_2 = _currentFrameY_3 = _currentFrameY_4 = 0;

	_x = 150;
	_y = 80;
	_width = 200;
	_height = 61;
	_selectBox = RectMake(_x, _y, _width, _height);

	return S_OK;
}
void shop::release()
{

}

void shop::update()
{
	select_rect_move();
	shopUpdate();
}

void shop::render()
{
	drawScreen();
	drawRect_shop();
	drawRect_select();

	_im->render();
}


void shop::drawRect_shop()
{
	switch (_state)
	{
	// ## 메뉴화면 ## 
	case SHOP_MENU:
		for (int i = 0; i < 3; i++)
		{
			_select_menu[i].rc.left = 150;
			_select_menu[i].rc.top = 80 + i * 90;
			_select_menu[i].width = 200;
			_select_menu[i].height = 61;
			
			IMAGEMANAGER->findImage("shop_menu_box")->render(getMemDC(), _select_menu[i].rc.left, _select_menu[i].rc.top);

			_select_menu[i].rc = RectMake(_select_menu[i].rc.left, _select_menu[i].rc.top,
				_select_menu[i].width, _select_menu[i].height);

			if (KEYMANAGER->isToggleKey(VK_TAB))
			Rectangle(getMemDC(), _select_menu[i].rc.left, _select_menu[i].rc.top, _select_menu[i].rc.right, _select_menu[i].rc.bottom);
		}

		SetBkMode(getMemDC(), TRANSPARENT);
		TextOut(getMemDC(), 200, 100, "사  러  간  다", strlen("사  러  간  다"));
		TextOut(getMemDC(), 200, 190, "팔  러  간  다", strlen("팔  러  간  다"));
		TextOut(getMemDC(), 210, 280, "나  간  다", strlen("나  간  다"));
		break;

	// ## 쇼핑중 ## 
	case SHOP_SHOPPING:
		for (int i = 0; i < 4; ++i)
		{
			_select_item_kind[i].rc.left = 40 + i * 120;
			_select_item_kind[i].rc.top = 0;
			_select_item_kind[i].width = 50;
			_select_item_kind[i].height = 50;

			_select_item_kind[i].rc = RectMake(_select_item_kind[i].rc.left, _select_item_kind[i].rc.top,
				_select_item_kind[i].width, _select_item_kind[i].height);


			if (i == 0)
			{
				IMAGEMANAGER->findImage("shop_tool_box")->frameRender(getMemDC(), _select_item_kind[i].rc.left,
					_select_item_kind[i].rc.top, 0, _currentFrameY_1);
			}
			if (i == 1)
			{
				IMAGEMANAGER->findImage("shop_postion_box")->frameRender(getMemDC(), _select_item_kind[i].rc.left,
					_select_item_kind[i].rc.top, 0, _currentFrameY_2);
			}
			if (i == 2)
			{
				IMAGEMANAGER->findImage("shop_ball_box")->frameRender(getMemDC(), _select_item_kind[i].rc.left,
					_select_item_kind[i].rc.top, 0, _currentFrameY_3);
			}
			if (i == 3)
			{
				IMAGEMANAGER->findImage("shop_machine_box")->frameRender(getMemDC(), _select_item_kind[i].rc.left,
					_select_item_kind[i].rc.top, 0, _currentFrameY_4);
			}
		}
		switch (_kind)
		{
		case SHOP_ITEM_TOOL:
			_im->imageDraw_tool(40, 90);
			break;
		case SHOP_ITEM_POSTION:
			_im->imageDraw_postion(40, 90);
			break;
		case SHOP_ITEM_BALL:
			_im->imageDraw_ball(40, 90);
			break;
		case SHOP_ITEM_MACHINE:
			_im->imageDraw_machine(40, 90);
			break;
		default:
			break;
		}

		IMAGEMANAGER->findImage("shop_exit_box")->render(getMemDC(), 340, 305);
		break;
	case SHOP_SELL:
		break;
	// ## 아이템 살거니? ##
	case SHOP_BUYITEM:
		break;
	default:
		break;
	}

	
}

void shop::drawRect_select()
{
	_selectBox = RectMake(_x, _y, _width, _height);

	switch (_state)
	{
	case SHOP_MENU:
		IMAGEMANAGER->findImage("shop_select_box")->render(getMemDC(), _selectBox.left, _selectBox.top);	
		break;
	case SHOP_SHOPPING:
		switch (_pos)
		{
		case SHOP_UP:
			IMAGEMANAGER->findImage("shop_select_box_2")->render(getMemDC(), _selectBox.left, _selectBox.top);
			break;
		case SHOP_MIDDLE:
			IMAGEMANAGER->findImage("shop_select_box_3")->render(getMemDC(), _selectBox.left, _selectBox.top);
			break;
		case SHOP_DOWN:
			IMAGEMANAGER->findImage("shop_select_box_4")->render(getMemDC(), _selectBox.left, _selectBox.top);
			break;
		default:
			break;
		}	
		break;
	case SHOP_SELL:
		break;
	case SHOP_BUYITEM:
		break;
	default:
		break;
	}

	
}


void shop::drawScreen()
{
	switch (_state)
	{
	case SHOP_MENU:
		IMAGEMANAGER->findImage("shop_menu")->render(getMemDC(), 0, 0);
		break;
	case SHOP_SHOPPING:
		IMAGEMANAGER->findImage("shop_main")->render(getMemDC(), 0, 0);
		break;
	case SHOP_SELL:
		break;
	case SHOP_BUYITEM:
		break;
	default:
		break;
	}
}

void shop::select_rect_move()
{
	switch (_state)
	{
	case SHOP_MENU:
		//									더 못내려가게 하려는 임의의값
		if (KEYMANAGER->isOnceKeyDown(VK_DOWN) && _y <= 200)
		{
			_y += 90;
		}
		if (KEYMANAGER->isOnceKeyDown(VK_UP) && _y >= 100)
		{
			_y -= 90;
		}
		break;
	case SHOP_SHOPPING:
		switch (_pos)
		{
		case SHOP_UP:
			if (KEYMANAGER->isOnceKeyDown(VK_RIGHT) && _x < 300)
			{
				_x += 120;
			}
			if (KEYMANAGER->isOnceKeyDown(VK_LEFT) && _x > 40)
			{
				_x -= 120;
			}
			if (KEYMANAGER->isOnceKeyDown(VK_DOWN))
			{
				_pos = SHOP_MIDDLE;
				selectBoxInit(5, 75, 230, 68);
			}
			break;
		case SHOP_MIDDLE:
			if (KEYMANAGER->isOnceKeyDown(VK_RIGHT) && _x < 150)
			{
				_x += 240;
			}
			if (KEYMANAGER->isOnceKeyDown(VK_LEFT) && _x > 50)
			{
				_x -= 240;
			}
			if (KEYMANAGER->isOnceKeyDown(VK_UP))
			{
				if (_y <= 100)
				{
					_pos = SHOP_UP;
					selectBoxInit(40, 0, 50, 50);
				}
				else
				{
					_y -= 74;
				}
			}
			if (KEYMANAGER->isOnceKeyDown(VK_DOWN))
			{
				if (_y >= 200)
				{
					_pos = SHOP_DOWN;
					selectBoxInit(340, 305, 116, 43);
				}
				else
				{
					_y += 74;
				}
			}
			break;
		case SHOP_DOWN:
			if (KEYMANAGER->isOnceKeyDown(VK_UP))
			{
				_pos = SHOP_MIDDLE;
				selectBoxInit(245, 222, 230, 68);
			}
			if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
			{
				_state = SHOP_MENU;
				selectBoxInit(150, 80, 200, 61);
			}
			break;
		default:
			break;
		}
		break;
	case SHOP_SELL:
		break;
	case SHOP_BUYITEM:
		break;
	default:
		break;
	}
}

void shop::shopUpdate()
{
	switch (_state)
	{
	case SHOP_MENU:
		for (int i = 0; i < 3; ++i)
		{		
			RECT temp;
			if (IntersectRect(&temp, &_select_menu[i].rc, &_selectBox))
			{
				//선택할때마다 선택박스 위치 초기화
				if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
				{
					switch (i)
					{
					case 0:
						_state = SHOP_SHOPPING;
						selectBoxInit(40, 0, 50, 50);
						_pos = SHOP_UP;
						_kind = SHOP_ITEM_TOOL;
						break;
					case 1:
						break;
					case 2:
						exit(0);
						break;
					default:
						break;
					}
				}
			}
		}
		break;
	case SHOP_SHOPPING:
		for (int i = 0; i < 4; ++i)
		{
			RECT temp;
			if (IntersectRect(&temp, &_select_item_kind[i].rc, &_selectBox))
			{
				if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
				{
					switch (i)
					{
					case 0:
						_currentFrameY_1 = 1;
						_currentFrameY_2 = _currentFrameY_3 = _currentFrameY_4 = 0;
						_kind = SHOP_ITEM_TOOL;
						break;
					case 1:
						_currentFrameY_2 = 1;
						_currentFrameY_1 = _currentFrameY_3 = _currentFrameY_4 = 0;
						_kind = SHOP_ITEM_POSTION;
						break;
					case 2:
						_currentFrameY_3 = 1;
						_currentFrameY_2 = _currentFrameY_1 = _currentFrameY_4 = 0;
						_kind = SHOP_ITEM_BALL;
						break;
					case 3:
						_currentFrameY_4 = 1;
						_currentFrameY_2 = _currentFrameY_3 = _currentFrameY_1 = 0;
						_kind = SHOP_ITEM_MACHINE;
						break;
					default:
						break;
					}
				}
			}
		}	
		
		switch (_kind)
		{
		case SHOP_ITEM_TOOL:
			for (int i=0; i < _im->getVItem_tool().size(); ++i)
			{ 
				RECT temp;
				if (IntersectRect(&temp, &_im->getVItem_tool()[i]->getItemRect(), &_selectBox))
				{
					if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
					{
						exit(0);
					}
				}
			}	
			break;
		case SHOP_ITEM_POSTION:
			break;
		case SHOP_ITEM_BALL:
			break;
		case SHOP_ITEM_MACHINE:
			break;
		default:
			break;
		}
		
		break;
	case SHOP_BUYITEM:
		break;
	default:
		break;
	}
}

void shop::selectBoxInit(float x, float y, int width, int height)
{
	_x = x;
	_y = y;
	_width = width;
	_height = height;
}

