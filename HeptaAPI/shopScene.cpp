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

	_item->addItem("���ͺ�", 1, ITEM_BALL, "���ͺ�", "���ͺ��Դϴ�", 50, 500);
	_item->addItem("����",2, ITEM_POTION, "ȸ����", "ȸ�����Դϴ�", 150, 500);
	_item->addItem("�ƹ��ų�", 3, ITEM_UTILS, "�ƹ��ų�", "�ƹ��ų��Դϴ�", 200, 1000);

	IMAGEMANAGER->addImage("������", ".\\bmps\\shopScene\\item_masterball.bmp", 20, 20, false, true, MAGENTA);

	_item->addItem("�����ͺ�", IMAGEMANAGER->findImage("������"), 4, ITEM_BALL, "�����ͺ�", "�����ͺ��Դϴ�", 100, 5000);

	//��������ø��θ޴� �̹��� ���
	IMAGEMANAGER->addImage("��������", ".\\bmps\\shopScene\\shop_open.bmp", WINSIZEX, WINSIZEY, false, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("�������¹�ư_BUY", ".\\bmps\\shopScene\\shop_button_buy.bmp", 252, 46, false, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("�������¹�ư_SELL", ".\\bmps\\shopScene\\shop_button_sell.bmp", 252, 46, false, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("�������¹�ư_CANCEL", ".\\bmps\\shopScene\\shop_button_cancel.bmp", 252, 46, false, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("��������", ".\\bmps\\shopScene\\shop_button_select.bmp", 252, 46, false, true, RGB(255, 0, 255));

	//�緯���� ���ý� �̹������
	IMAGEMANAGER->addImage("��������", ".\\bmps\\shopScene\\shop_main.bmp", WINSIZEX, WINSIZEY, false, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("�����緯���⼱��", ".\\bmps\\shopScene\\shop_main_select.bmp", 232, 69, false, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("�����緯�������", ".\\bmps\\shopScene\\exit_box.bmp", 116, 43, false, true, MAGENTA);
	IMAGEMANAGER->addImage("�����緯������Ҽ���", ".\\bmps\\shopScene\\exit_box_select.bmp", 116, 43, false, true, MAGENTA);

	//MENU BUTTON ��ǥ
	_selectMenu[BUTTON_BUY].pt.x = 110;
	_selectMenu[BUTTON_BUY].pt.y = 100;

	_selectMenu[BUTTON_SELL].pt.x = 110;
	_selectMenu[BUTTON_SELL].pt.y = 180;

	_selectMenu[BUTTON_CANCEL].pt.x = 110;
	_selectMenu[BUTTON_CANCEL].pt.y = 260;

	//ITEM INDEX BUTTON ��ǥ
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

	//ó�� �ʱ�ȭ
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

void shopScene::shopMainMenuDraw() //���� ����� Main Menu �׷��ִ� �Լ�
{
	IMAGEMANAGER->findImage("��������")->render(getMemDC(), 0, 0);
	IMAGEMANAGER->findImage("�������¹�ư_BUY")->render(getMemDC(), _selectMenu[BUTTON_BUY].pt.x, _selectMenu[BUTTON_BUY].pt.y);
	IMAGEMANAGER->findImage("�������¹�ư_SELL")->render(getMemDC(), _selectMenu[BUTTON_SELL].pt.x, _selectMenu[BUTTON_SELL].pt.y);
	IMAGEMANAGER->findImage("�������¹�ư_CANCEL")->render(getMemDC(), _selectMenu[BUTTON_CANCEL].pt.x, _selectMenu[BUTTON_CANCEL].pt.y);

	TextOut(IMAGEMANAGER->findImage("�������¹�ư_BUY")->getMemDC(), 80, 15, "�� �� �� ��", strlen("�� �� �� ��"));
	TextOut(IMAGEMANAGER->findImage("�������¹�ư_SELL")->getMemDC(), 80, 15, "�� �� �� ��", strlen("�� �� �� ��"));
	TextOut(IMAGEMANAGER->findImage("�������¹�ư_CANCEL")->getMemDC(), 100, 15, "�� ��", strlen("�� ��"));


	//_item->findItem("���ͺ�")->render( IMAGEMANAGER->findImage("��������")->getMemDC(), ITEMSLOT_FIRSTX, ITEMSLOT_FIRSTY, 1);
	_item->findItem("����")->render( IMAGEMANAGER->findImage("��������")->getMemDC(), ITEMSLOT_THIRDX, ITEMSLOT_THIRDY, 2);
	_item->findItem("�ƹ��ų�")->render(IMAGEMANAGER->findImage("��������")->getMemDC(), ITEMSLOT_SECONDX, ITEMSLOT_SECONDY, 3);
	_item->findItem("�����ͺ�")->render(IMAGEMANAGER->findImage("��������")->getMemDC(), IMAGEMANAGER->findImage("������"), ITEMSLOT_FIRSTX, ITEMSLOT_FIRSTY, 3);

	for (int i = 0; i <BUTTON_END; i++)
	{
		if (_selectMenu[i].isSelect == true)
		{
			IMAGEMANAGER->findImage("��������")->render(getMemDC(), _selectMenu[i].pt.x, _selectMenu[i].pt.y);
		}
	}

	if (_selectMenu[BUTTON_BUY].Selected) //�緯���� ��ư ���ý� 
	{
		IMAGEMANAGER->findImage("��������")->render(getMemDC(), 0, 0);
		shopBuyMenuDraw();
		_WS = WS_BUY;
	}

	if (_selectMenu[BUTTON_SELL].Selected) //�ȷ����� ��ư ���ý�
	{
		IMAGEMANAGER->findImage("��������")->render(getMemDC(), 0, 0);
		shopBuyMenuDraw();
		_WS = WS_SELL;
	}

	if (_selectMenu[BUTTON_CANCEL].Selected) //��ҹ�ư ���ý�
	{
		SCENEMANAGER->changeScene("�����׾�");
	}
}

void shopScene::shopBuyMenuDraw() //���� �緯���� Menu �׷��ִ� �Լ�
{
	IMAGEMANAGER->findImage("��������")->render(getMemDC(), 0, 0);
	IMAGEMANAGER->findImage("�����緯�������")->render(getMemDC(), 360, 310);

	//����BUY ���� �̵� ���� �κ�
	for (int i = 0; i <6; i++)
	{
		if (_selectItem[i].isSelect == true)
		{
			IMAGEMANAGER->findImage("�����緯���⼱��")->render(getMemDC(), _selectItem[i].pt.x, _selectItem[i].pt.y);
		}
	}
	//��� ��ư ���� ����
	if (_selectItem[INDEX_BUTTON_CANCEL] .isSelect == true)
	{
		IMAGEMANAGER->findImage("�����緯������Ҽ���")->render(getMemDC(), _selectItem[6].pt.x, _selectItem[6].pt.y);
	}

	//�� �κ� ���ý� �߻��ϴ� �̺�Ʈ ����
	if (_selectItem[INDEX_BUTTON_0].Selected) //1��° ������ 
	{
		//vItem temp;
		//temp.push_back(_item->findItem("���ͺ�"));
		//_inven->buyItem(temp.begin());

		_inven->buyItems("���ͺ�", _item->findItem("���ͺ�"));
	}
	if (_selectItem[INDEX_BUTTON_1].Selected) //2��° ������ 
	{
		_inven->buyItems("�����ͺ�", _item->findItem("�����ͺ�"));
	}
	if (_selectItem[INDEX_BUTTON_2].Selected) //3��° ������ 
	{
		_inven->buyItems("���ͺ�", _item->findItem("���ͺ�"));
	}
	if (_selectItem[INDEX_BUTTON_3].Selected) //4��° ������ 
	{
		_inven->buyItems("���ͺ�", _item->findItem("���ͺ�"));
	}
	if (_selectItem[INDEX_BUTTON_4].Selected) //5��° ������ 
	{
		_inven->buyItems("���ͺ�", _item->findItem("���ͺ�"));
	}
	if (_selectItem[INDEX_BUTTON_5].Selected) //6��° ������ 
	{
		_inven->buyItems("���ͺ�", _item->findItem("���ͺ�"));
	}
	if (_selectItem[INDEX_BUTTON_CANCEL].Selected) //��� ��ư
	{
		SCENEMANAGER->changeScene("�κ��丮��");
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

	if (KEYMANAGER->isOnceKeyDown('A'))
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

}



