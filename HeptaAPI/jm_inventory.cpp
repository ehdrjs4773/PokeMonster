#include "stdafx.h"
#include "jm_inventory.h"
#include "jm_itemManager.h"

jm_inventory::jm_inventory()
{
}


jm_inventory::~jm_inventory()
{
}

HRESULT jm_inventory::init()
{
	IMAGEMANAGER->addImage("inven_tool", ".\\bmps\\inventory\\inventory_1.bmp", 480, 360, false, false, RGB(0, 0, 0));
	IMAGEMANAGER->addImage("inven_postion", ".\\bmps\\inventory\\inventory_2.bmp", 480, 360 , false , false , RGB(0,0,0));
	IMAGEMANAGER->addImage("inven_ball", ".\\bmps\\inventory\\inventory_3.bmp", 480, 360, false, false, RGB(0, 0, 0));
	IMAGEMANAGER->addImage("inven_machine", ".\\bmps\\inventory\\inventory_4.bmp", 480, 360, false, false, RGB(0, 0, 0));

	IMAGEMANAGER->addFrameImage("inven_kind_box_tool", ".\\bmps\\inventory\\item_kind_1.bmp", 0, 0, 50, 100, 1, 2, false, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("inven_kind_box_postion", ".\\bmps\\inventory\\item_kind_2.bmp", 0, 0, 50, 100, 1, 2, false, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("inven_kind_box_ball", ".\\bmps\\inventory\\item_kind_3.bmp", 0, 0, 50, 100, 1, 2, false, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("inven_kind_box_machine", ".\\bmps\\inventory\\item_kind_4.bmp", 0, 0, 50, 100, 1, 2, false, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("inven_exit_box", ".\\bmps\\inventory\\exit_box.bmp", 116, 43, false, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("select_inven_kind_box", ".\\bmps\\inventory\\select_item_kind_box.bmp", 50, 50, false, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("select_item_box", ".\\bmps\\inventory\\select_item_box.bmp", 228, 67, false, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("select_exit_box", ".\\bmps\\inventory\\select_exit_box.bmp", 116, 43, false, true, RGB(255, 0, 255));

	_invenState = INVEN_TOOL;
	_selectBox = INVEN_UP;

	_currentFrameY_1 = 1;
	_currentFrameY_2 = _currentFrameY_3 = _currentFrameY_4 = 0;

	for (int i = 0; i < ITEM_KIND; ++i)
	{
		_item_kind_box[i].x = 60 + i * 120;
		_item_kind_box[i].y = 25;

		_item_kind_box[i].rc = RectMakeCenter(_item_kind_box[i].x, _item_kind_box[i].y, 50, 50);
	}
	_x = INVEN_MENU_START_X;
	_y = INVEN_MENU_START_Y;
	_width = INVEN_MENU_WITDH;
	_height = INVEN_MENU_HEIGHT;

	_select_item_kind_box.rc = RectMakeCenter(_x, _y, _width, _height);

	return S_OK;
}

void jm_inventory::release()
{
}

void jm_inventory::update()
{
	keykontrol();
	selectKind();
}

void jm_inventory::render()
{
	draw();
}

void jm_inventory::draw()
{

	switch (_invenState)
	{
	case INVEN_TOOL:
		IMAGEMANAGER->findImage("inven_tool")->render(getMemDC(), 0, 0);
		break;
	case INVEN_POSTION:
		IMAGEMANAGER->findImage("inven_postion")->render(getMemDC(), 0, 0);
		break;
	case INVEN_BALL:
		IMAGEMANAGER->findImage("inven_ball")->render(getMemDC(), 0, 0);
		break;
	case INVEN_MACHINE:
		IMAGEMANAGER->findImage("inven_machine")->render(getMemDC(), 0, 0);
		break;
	default:
		break;
	}

	for (int i = 0; i < ITEM_KIND; i++)
	{
		if (i == 0)
		{
			IMAGEMANAGER->findImage("inven_kind_box_tool")->frameRender(getMemDC(), _item_kind_box[i].rc.left,
				_item_kind_box[i].rc.top, 0, _currentFrameY_1);
		}
		if (i == 1)
		{
			IMAGEMANAGER->findImage("inven_kind_box_postion")->frameRender(getMemDC(), _item_kind_box[i].rc.left,
				_item_kind_box[i].rc.top, 0, _currentFrameY_2);
		}
		if (i == 2)
		{
			IMAGEMANAGER->findImage("inven_kind_box_ball")->frameRender(getMemDC(), _item_kind_box[i].rc.left,
				_item_kind_box[i].rc.top, 0, _currentFrameY_3);
		}
		if (i == 3)
		{
			IMAGEMANAGER->findImage("inven_kind_box_machine")->frameRender(getMemDC(), _item_kind_box[i].rc.left,
				_item_kind_box[i].rc.top, 0, _currentFrameY_4);
		}
	}

	// cancel ¸Þ´º
	IMAGEMANAGER->findImage("inven_exit_box")->render(getMemDC(), 362, 308);

	switch (_selectBox)
	{
	case INVEN_UP:
		IMAGEMANAGER->findImage("select_inven_kind_box")->render(getMemDC(), _select_item_kind_box.rc.left, _select_item_kind_box.rc.top);
		break;
	case INVEN_MIDDLE:
		IMAGEMANAGER->findImage("select_item_box")->render(getMemDC(), _select_item_kind_box.rc.left, _select_item_kind_box.rc.top);
		break;
	case INVEN_DOWN:
		IMAGEMANAGER->findImage("select_exit_box")->render(getMemDC(), _select_item_kind_box.rc.left, _select_item_kind_box.rc.top);
		break;
	default:
		break;
	}

	if (_isDebug)
	{
		Rectangle(getMemDC(), _select_item_kind_box.rc.left, _select_item_kind_box.rc.top,
			_select_item_kind_box.rc.right, _select_item_kind_box.rc.bottom);
	}


	
}

void jm_inventory::keykontrol()
{
	switch (_selectBox)
	{
	case INVEN_UP:

		_width = INVEN_MENU_WITDH;
		_height = INVEN_MENU_HEIGHT;

		//ÁÂ¿ì
		if (KEYMANAGER->isOnceKeyDown(VK_RIGHT))
		{
			if (_x >= INVEN_MENU_START_X + (3 * INVEN_MENU_MOVE))
			{
				_x = INVEN_MENU_START_X;
			}
			else
			{
				_x += INVEN_MENU_MOVE;
			}
		}
		if (KEYMANAGER->isOnceKeyDown(VK_LEFT))
		{
			if (_x <= INVEN_MENU_START_X) _x = INVEN_MENU_START_X + (3 * INVEN_MENU_MOVE);
			else
				_x -= INVEN_MENU_MOVE;
		}
		//¹Ø
		if (KEYMANAGER->isOnceKeyDown(VK_DOWN))
		{
			_selectBox = INVEN_MIDDLE;

			_x = INVEN_MIDDLE_START_X;
			_y = INVEN_MIDDLE_START_Y;
			_width = INVEN_MIDDLE_WITDH;
			_height = INVEN_MIDDLE_HEIGHT;
			
			_select_item_kind_box.rc = RectMakeCenter(_x, _y, _width, _height);
			return;
		}

		break;
	case INVEN_MIDDLE:

		_width = INVEN_MIDDLE_WITDH;
		_height = INVEN_MIDDLE_HEIGHT;

		if (KEYMANAGER->isOnceKeyDown(VK_UP))
		{
			if (_y <= INVEN_MIDDLE_START_Y)
			{
				_selectBox = INVEN_UP;
				_x = INVEN_MENU_START_X;
				_y = INVEN_MENU_START_Y;
				_width = INVEN_MENU_WITDH;
				_height = INVEN_MENU_HEIGHT;

				_select_item_kind_box.rc = RectMakeCenter(_x, _y, _width, _height);
				return;
			}
			else
			{
				_y -= INVEN_MIDDLE_UPANDDOWN_MOVE;
			}
		}

		//ÁÂ¿ì
		if (KEYMANAGER->isOnceKeyDown(VK_RIGHT))
		{
			if (_x >= INVEN_MIDDLE_START_X + INVEN_MIDDLE_LEFTANDRIGHT_MOVE) return;
			else _x += INVEN_MIDDLE_LEFTANDRIGHT_MOVE;
		}
		if (KEYMANAGER->isOnceKeyDown(VK_LEFT))
		{
			if (_x <= INVEN_MIDDLE_START_X) return;
			else _x -= INVEN_MIDDLE_LEFTANDRIGHT_MOVE;
		}
		
		if (KEYMANAGER->isOnceKeyDown(VK_DOWN))
		{
			//¸Þ´º·Î?
			if (_x == INVEN_MIDDLE_START_X && _y >= INVEN_MIDDLE_START_Y + 2 * INVEN_MIDDLE_UPANDDOWN_MOVE)
			{
				_selectBox = INVEN_UP;
				_x = INVEN_MENU_START_X;
				_y = INVEN_MENU_START_Y;
				_width = INVEN_MENU_WITDH;
				_height = INVEN_MENU_HEIGHT;

				_select_item_kind_box.rc = RectMakeCenter(_x, _y, _width, _height);
				return;
			}
			//Äµ½½·Î
			else if (_x == INVEN_MIDDLE_START_X + INVEN_MIDDLE_LEFTANDRIGHT_MOVE && 
				_y >= INVEN_MIDDLE_START_Y + 2 * INVEN_MIDDLE_UPANDDOWN_MOVE)
			{
				_selectBox = INVEN_DOWN;
				_x = INVEN_DOWN_START_X;
				_y = INVEN_DOWN_START_Y;
				_width = INVEN_DOWN_WITDH;
				_height = INVEN_DOWN_HEIGHT;

				_select_item_kind_box.rc = RectMakeCenter(_x, _y, _width, _height);
				return;
			}
			else
			_y += INVEN_MIDDLE_UPANDDOWN_MOVE;
		}

		break;
	case INVEN_DOWN:

		_width = INVEN_DOWN_WITDH;
		_height = INVEN_DOWN_HEIGHT;

		if (KEYMANAGER->isOnceKeyDown(VK_UP))
		{
			_selectBox = INVEN_MIDDLE;
			_x = INVEN_MIDDLE_START_X + INVEN_MIDDLE_LEFTANDRIGHT_MOVE;
			_y = INVEN_MIDDLE_START_Y + 2 * INVEN_MIDDLE_UPANDDOWN_MOVE;
			_width = INVEN_MIDDLE_WITDH;
			_height = INVEN_MIDDLE_HEIGHT;

			_select_item_kind_box.rc = RectMakeCenter(_x, _y, _width, _height);
			return;
		}
		if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
		{
			exit(0);
		}
		break;
	default:
		break;
	}

	_select_item_kind_box.rc = RectMakeCenter(_x, _y, _width, _height);
}

void jm_inventory::selectKind()
{
	if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
	{
		for (int i = 0; i < ITEM_KIND; ++i)
		{
			RECT temp;
			if (IntersectRect(&temp, &_item_kind_box[0].rc, &_select_item_kind_box.rc))
			{
				_invenState = INVEN_TOOL;
				_select_item_kind_box.kind = INVEN_ITEM_TOOL;
				_currentFrameY_1 = 1;
				_currentFrameY_2 = _currentFrameY_3 = _currentFrameY_4 = 0;
				break;
			}
			if (IntersectRect(&temp, &_item_kind_box[1].rc, &_select_item_kind_box.rc))
			{
				_invenState = INVEN_POSTION;
				_select_item_kind_box.kind = INVEN_ITEM_POSTION;
				_currentFrameY_2 = 1;
				_currentFrameY_1 = _currentFrameY_3 = _currentFrameY_4 = 0;
				break;
			}
			if (IntersectRect(&temp, &_item_kind_box[2].rc, &_select_item_kind_box.rc))
			{
				_invenState = INVEN_BALL;
				_select_item_kind_box.kind = INVEN_ITEM_BALL;
				_currentFrameY_3 = 1;
				_currentFrameY_1 = _currentFrameY_2 = _currentFrameY_4 = 0;
				break;
			}
			if (IntersectRect(&temp, &_item_kind_box[3].rc, &_select_item_kind_box.rc))
			{
				_invenState = INVEN_MACHINE;
				_select_item_kind_box.kind = INVEN_ITEM_MACHINE;
				_currentFrameY_4 = 1;
				_currentFrameY_1 = _currentFrameY_2 = _currentFrameY_3 = 0;
				break;
			}
		}
	}
}
