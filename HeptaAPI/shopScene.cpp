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
	//��������ø��θ޴� �̹��� ���
	IMAGEMANAGER->addImage("��������", ".\\bmps\\shopScene\\shop_open.bmp", WINSIZEX, WINSIZEY, false, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("�������¹�ư_BUY", ".\\bmps\\shopScene\\shop_button_buy.bmp", 252, 46, false, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("�������¹�ư_SELL", ".\\bmps\\shopScene\\shop_button_sell.bmp", 252, 46, false, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("�������¹�ư_CANCEL", ".\\bmps\\shopScene\\shop_button_cancel.bmp", 252, 46, false, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("��������", ".\\bmps\\shopScene\\shop_button_select.bmp", 252, 46, false, true, RGB(255, 0, 255));

	//�緯���� ���ý� �̹������
	IMAGEMANAGER->addImage("��������", ".\\bmps\\shopScene\\shop_main.bmp", WINSIZEX, WINSIZEY, false, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("�����緯���⼱��", ".\\bmps\\shopScene\\shop_main_select.bmp", 232, 69, false, true, RGB(255, 0, 255));
	ITEMMANAGER->addItem("���ͺ�");

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
	MenuSelectMove(); //����������θ޴� ���� ȭ�� �����Լ�
	ShopelectMove();
}

void shopScene::render()
{
	
	shopMainMenuDraw(); //����������θ޴�
	//shopBuyMenuDraw();
	ITEMMANAGER->findItem("���ͺ�")->render(IMAGEMANAGER->findImage("��������")->getMemDC(), 100, 100);

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
	}

	if (_selectMenu[BUTTON_SELL].Selected) //�ȷ����� ��ư ���ý�
	{
		IMAGEMANAGER->findImage("��������")->render(getMemDC(), 0, 0);
	}

	if (_selectMenu[BUTTON_CANCEL].Selected) //��ҹ�ư ���ý�
	{
		SCENEMANAGER->changeScene("�����׾�");
	}
}

void shopScene::shopBuyMenuDraw() //���� �緯���� Menu �׷��ִ� �Լ�
{
	

	for (int i = 0; i <INDEX_BUTTON_END; i++)
	{
		if (_selectItem[i].isSelect == true)
		{
			IMAGEMANAGER->findImage("�����緯���⼱��")->render(getMemDC(), _selectItem[i].pt.x, _selectItem[i].pt.y);
		}
	}

	if (_selectItem[INDEX_BUTTON_0].Selected) //1��° ������ 
	{
		IMAGEMANAGER->findImage("��������")->render(getMemDC(), 0, 0);
	}
	if (_selectItem[INDEX_BUTTON_1].Selected) //2��° ������ 
	{
		IMAGEMANAGER->findImage("��������")->render(getMemDC(), 0, 0);
	}
	if (_selectItem[INDEX_BUTTON_2].Selected) //3��° ������ 
	{
		IMAGEMANAGER->findImage("��������")->render(getMemDC(), 0, 0);
	}
	if (_selectItem[INDEX_BUTTON_3].Selected) //4��° ������ 
	{
		IMAGEMANAGER->findImage("��������")->render(getMemDC(), 0, 0);
	}
	if (_selectItem[INDEX_BUTTON_4].Selected) //5��° ������ 
	{
		IMAGEMANAGER->findImage("��������")->render(getMemDC(), 0, 0);
	}
	if (_selectItem[INDEX_BUTTON_5].Selected) //6��° ������ 
	{
		IMAGEMANAGER->findImage("��������")->render(getMemDC(), 0, 0);
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