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


	//�κ��丮 �޴� �̹������
	IMAGEMANAGER->addImage("�κ��丮_��ƿ", ".\\bmps\\inventoryScene\\inventory_1.bmp", WINSIZEX, WINSIZEY, false, true, MAGENTA);
	IMAGEMANAGER->addImage("�κ��丮_����", ".\\bmps\\inventoryScene\\inventory_2.bmp", WINSIZEX, WINSIZEY, false, true, MAGENTA);
	IMAGEMANAGER->addImage("�κ��丮_��", ".\\bmps\\inventoryScene\\inventory_3.bmp", WINSIZEX, WINSIZEY, false, true, MAGENTA);
	IMAGEMANAGER->addImage("�κ��丮_�ӽ�", ".\\bmps\\inventoryScene\\inventory_4.bmp", WINSIZEX, WINSIZEY, false, true, MAGENTA);
	IMAGEMANAGER->addImage("�κ��丮����", ".\\bmps\\inventoryScene\\inventory_main_select.bmp", 232, 69, false, true, MAGENTA);
	IMAGEMANAGER->addImage("�κ��丮���", ".\\bmps\\inventoryScene\\exit_box.bmp", 116, 43, false, true, MAGENTA);
	IMAGEMANAGER->addImage("�κ��丮��Ҽ���", ".\\bmps\\inventoryScene\\exit_box_select.bmp", 116, 43, false, true, MAGENTA);

	//�κ��丮 ������ �̹��� ���
	IMAGEMANAGER->addFrameImage("������_��ƿ", ".\\bmps\\inventoryScene\\item_kind_1.bmp", 50, 100, 1, 2, false, true, MAGENTA);
	IMAGEMANAGER->addFrameImage("������_����", ".\\bmps\\inventoryScene\\item_kind_2.bmp", 50, 100, 1, 2, false, true, MAGENTA);
	IMAGEMANAGER->addFrameImage("������_��", ".\\bmps\\inventoryScene\\item_kind_3.bmp", 50, 100, 1, 2, false, true, MAGENTA);
	IMAGEMANAGER->addFrameImage("������_�ӽ�", ".\\bmps\\inventoryScene\\item_kind_4.bmp", 50, 100, 1, 2, false, true, MAGENTA);
	IMAGEMANAGER->addImage("�����ܼ���", ".\\bmps\\inventoryScene\\select_item_kind_box.bmp", 50, 50, false, true, MAGENTA);

	////MENU BUTTON ��ǥ
	//_selectMenu[BUTTONS_BUY].pt.x = 110;
	//_selectMenu[BUTTONS_BUY].pt.y = 100;

	//_selectMenu[BUTTONS_SELL].pt.x = 110;
	//_selectMenu[BUTTONS_SELL].pt.y = 180;

	//_selectMenu[BUTTONS_CANCEL].pt.x = 110;
	//_selectMenu[BUTTONS_CANCEL].pt.y = 260;

	//ITEM INDEX BUTTON ��ǥ
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
		//����������θ޴�
	}
}

void inventory::buyItem(vector<item*>::iterator buyingItem)
{
	_vInventory.push_back(*buyingItem);
}

//void inventory::shopMainMenuDraw() //���� ����� Main Menu �׷��ִ� �Լ�
//{
//	IMAGEMANAGER->findImage("��������")->render(getMemDC(), 0, 0);
//	IMAGEMANAGER->findImage("�������¹�ư_BUY")->render(getMemDC(), _selectMenu[BUTTONS_BUY].pt.x, _selectMenu[BUTTONS_BUY].pt.y);
//	IMAGEMANAGER->findImage("�������¹�ư_SELL")->render(getMemDC(), _selectMenu[BUTTONS_SELL].pt.x, _selectMenu[BUTTONS_SELL].pt.y);
//	IMAGEMANAGER->findImage("�������¹�ư_CANCEL")->render(getMemDC(), _selectMenu[BUTTONS_CANCEL].pt.x, _selectMenu[BUTTONS_CANCEL].pt.y);
//
//	TextOut(IMAGEMANAGER->findImage("�������¹�ư_BUY")->getMemDC(), 80, 15, "�� �� �� ��", strlen("�� �� �� ��"));
//	TextOut(IMAGEMANAGER->findImage("�������¹�ư_SELL")->getMemDC(), 80, 15, "�� �� �� ��", strlen("�� �� �� ��"));
//	TextOut(IMAGEMANAGER->findImage("�������¹�ư_CANCEL")->getMemDC(), 100, 15, "�� ��", strlen("�� ��"));
//
//
//
//
//	for (int i = 0; i <BUTTONS_END; i++)
//	{
//		if (_selectMenu[i].isSelect == true)
//		{
//			IMAGEMANAGER->findImage("��������")->render(getMemDC(), _selectMenu[i].pt.x, _selectMenu[i].pt.y);
//		}
//	}
//
//	if (_selectMenu[BUTTONS_BUY].Selected) //�緯���� ��ư ���ý� 
//	{
//		IMAGEMANAGER->findImage("��������")->render(getMemDC(), 0, 0);
//		shopBuyMenuDraw();
//		_WS = WSS_BUY;
//	}
//
//	if (_selectMenu[BUTTONS_SELL].Selected) //�ȷ����� ��ư ���ý�
//	{
//		IMAGEMANAGER->findImage("��������")->render(getMemDC(), 0, 0);
//		shopBuyMenuDraw();
//		_WS = WSS_SELL;
//	}
//
//	if (_selectMenu[BUTTONS_CANCEL].Selected) //��ҹ�ư ���ý�
//	{
//		SCENEMANAGER->changeScene("�����׾�");
//	}
//}

void inventory::UtilMenuDraw() //���� �緯���� Menu �׷��ִ� �Լ�
{
	IMAGEMANAGER->findImage("�κ��丮_��ƿ")->render(getMemDC(), 0, 0);
	IMAGEMANAGER->findImage("�κ��丮���")->render(getMemDC(), 360, 310);

	//����BUY ���� �̵� ���� �κ�
	for (int i = 0; i <6; i++)
	{
		if (_selectItem[i].isSelect == true)
		{
			IMAGEMANAGER->findImage("�κ��丮����")->render(getMemDC(), _selectItem[i].pt.x, _selectItem[i].pt.y);
		}
	}
	//��� ��ư ���� ����
	if (_selectItem[INDEXS_BUTTON_CANCEL].isSelect == true)
	{
		IMAGEMANAGER->findImage("�κ��丮��Ҽ���")->render(getMemDC(), _selectItem[6].pt.x, _selectItem[6].pt.y);
	}

	//�� �κ� ���ý� �߻��ϴ� �̺�Ʈ ����
	if (_selectItem[INDEXS_BUTTON_0].Selected) //1��° ������ 
	{
		//_inven->buyItem(_item->findItem("���ͺ�")->getItem());
	}
	if (_selectItem[INDEXS_BUTTON_1].Selected) //2��° ������ 
	{
		//IMAGEMANAGER->findImage("�κ��丮_��ƿ")->render(getMemDC(), 0, 0);
	}
	if (_selectItem[INDEXS_BUTTON_2].Selected) //3��° ������ 
	{
		//IMAGEMANAGER->findImage("��������")->render(getMemDC(), 0, 0);
	}
	if (_selectItem[INDEXS_BUTTON_3].Selected) //4��° ������ 
	{
		//IMAGEMANAGER->findImage("��������")->render(getMemDC(), 0, 0);
	}
	if (_selectItem[INDEXS_BUTTON_4].Selected) //5��° ������ 
	{
		//IMAGEMANAGER->findImage("��������")->render(getMemDC(), 0, 0);
	}
	if (_selectItem[INDEXS_BUTTON_5].Selected) //6��° ������ 
	{
		//IMAGEMANAGER->findImage("��������")->render(getMemDC(), 0, 0);
	}
	if (_selectItem[INDEXS_BUTTON_CANCEL].Selected) //��� ��ư
	{
		SCENEMANAGER->changeScene("�����׾�");
	}
}

void inventory::PotionMenuDraw() //���� �緯���� Menu �׷��ִ� �Լ�
{
	IMAGEMANAGER->findImage("�κ��丮_����")->render(getMemDC(), 0, 0);
	IMAGEMANAGER->findImage("�κ��丮���")->render(getMemDC(), 360, 310);
	//����BUY ���� �̵� ���� �κ�
	for (int i = 0; i <6; i++)
	{
		if (_selectItem[i].isSelect == true)
		{
			IMAGEMANAGER->findImage("�κ��丮����")->render(getMemDC(), _selectItem[i].pt.x, _selectItem[i].pt.y);
		}
	}
	//��� ��ư ���� ����
	if (_selectItem[INDEXS_BUTTON_CANCEL].isSelect == true)
	{
		IMAGEMANAGER->findImage("�κ��丮��Ҽ���")->render(getMemDC(), _selectItem[6].pt.x, _selectItem[6].pt.y);
	}

	//�� �κ� ���ý� �߻��ϴ� �̺�Ʈ ����
	if (_selectItem[INDEXS_BUTTON_0].Selected) //1��° ������ 
	{
		//_inven->buyItem(_item->findItem("���ͺ�")->getItem());
	}
	if (_selectItem[INDEXS_BUTTON_1].Selected) //2��° ������ 
	{
		//IMAGEMANAGER->findImage("��������")->render(getMemDC(), 0, 0);
	}
	if (_selectItem[INDEXS_BUTTON_2].Selected) //3��° ������ 
	{
		//IMAGEMANAGER->findImage("��������")->render(getMemDC(), 0, 0);
	}
	if (_selectItem[INDEXS_BUTTON_3].Selected) //4��° ������ 
	{
		//IMAGEMANAGER->findImage("��������")->render(getMemDC(), 0, 0);
	}
	if (_selectItem[INDEXS_BUTTON_4].Selected) //5��° ������ 
	{
		//IMAGEMANAGER->findImage("��������")->render(getMemDC(), 0, 0);
	}
	if (_selectItem[INDEXS_BUTTON_5].Selected) //6��° ������ 
	{
		//IMAGEMANAGER->findImage("��������")->render(getMemDC(), 0, 0);
	}
	if (_selectItem[INDEXS_BUTTON_CANCEL].Selected) //��� ��ư
	{
		SCENEMANAGER->changeScene("�����׾�");
	}
}

void inventory::BallMenuDraw() //���� �緯���� Menu �׷��ִ� �Լ�
{
	IMAGEMANAGER->findImage("�κ��丮_��")->render(getMemDC(), 0, 0);
	IMAGEMANAGER->findImage("�κ��丮���")->render(getMemDC(), 360, 310);

	//����BUY ���� �̵� ���� �κ�
	for (int i = 0; i <6; i++)
	{
		if (_selectItem[i].isSelect == true)
		{
			IMAGEMANAGER->findImage("�κ��丮����")->render(getMemDC(), _selectItem[i].pt.x, _selectItem[i].pt.y);
		}
	}
	//��� ��ư ���� ����
	if (_selectItem[INDEXS_BUTTON_CANCEL].isSelect == true)
	{
		IMAGEMANAGER->findImage("�κ��丮��Ҽ���")->render(getMemDC(), _selectItem[6].pt.x, _selectItem[6].pt.y);
	}

	//�� �κ� ���ý� �߻��ϴ� �̺�Ʈ ����
	if (_selectItem[INDEXS_BUTTON_0].Selected) //1��° ������ 
	{
		//_inven->buyItem(_item->findItem("���ͺ�")->getItem());
	}
	if (_selectItem[INDEXS_BUTTON_1].Selected) //2��° ������ 
	{
		//IMAGEMANAGER->findImage("��������")->render(getMemDC(), 0, 0);
	}
	if (_selectItem[INDEXS_BUTTON_2].Selected) //3��° ������ 
	{
		//IMAGEMANAGER->findImage("��������")->render(getMemDC(), 0, 0);
	}
	if (_selectItem[INDEXS_BUTTON_3].Selected) //4��° ������ 
	{
		//IMAGEMANAGER->findImage("��������")->render(getMemDC(), 0, 0);
	}
	if (_selectItem[INDEXS_BUTTON_4].Selected) //5��° ������ 
	{
		//IMAGEMANAGER->findImage("��������")->render(getMemDC(), 0, 0);
	}
	if (_selectItem[INDEXS_BUTTON_5].Selected) //6��° ������ 
	{
		//IMAGEMANAGER->findImage("��������")->render(getMemDC(), 0, 0);
	}
	if (_selectItem[INDEXS_BUTTON_CANCEL].Selected) //��� ��ư
	{
		SCENEMANAGER->changeScene("�����׾�");
	}
	
}

void inventory::MachineMenuDraw() //���� �緯���� Menu �׷��ִ� �Լ�
{
	IMAGEMANAGER->findImage("�κ��丮_�ӽ�")->render(getMemDC(), 0, 0);
	IMAGEMANAGER->findImage("�κ��丮���")->render(getMemDC(), 360, 310);

	//����BUY ���� �̵� ���� �κ�
	for (int i = 0; i <6; i++)
	{
		if (_selectItem[i].isSelect == true)
		{
			IMAGEMANAGER->findImage("�κ��丮����")->render(getMemDC(), _selectItem[i].pt.x, _selectItem[i].pt.y);
		}
	}
	//��� ��ư ���� ����
	if (_selectItem[INDEXS_BUTTON_CANCEL].isSelect == true)
	{
		IMAGEMANAGER->findImage("�κ��丮��Ҽ���")->render(getMemDC(), _selectItem[6].pt.x, _selectItem[6].pt.y);
	}

	//�� �κ� ���ý� �߻��ϴ� �̺�Ʈ ����
	if (_selectItem[INDEXS_BUTTON_0].Selected) //1��° ������ 
	{
		//_inven->buyItem(_item->findItem("���ͺ�")->getItem());
	}
	if (_selectItem[INDEXS_BUTTON_1].Selected) //2��° ������ 
	{
		//IMAGEMANAGER->findImage("��������")->render(getMemDC(), 0, 0);
	}
	if (_selectItem[INDEXS_BUTTON_2].Selected) //3��° ������ 
	{
		//IMAGEMANAGER->findImage("��������")->render(getMemDC(), 0, 0);
	}
	if (_selectItem[INDEXS_BUTTON_3].Selected) //4��° ������ 
	{
		//IMAGEMANAGER->findImage("��������")->render(getMemDC(), 0, 0);
	}
	if (_selectItem[INDEXS_BUTTON_4].Selected) //5��° ������ 
	{
		//IMAGEMANAGER->findImage("��������")->render(getMemDC(), 0, 0);
	}
	if (_selectItem[INDEXS_BUTTON_5].Selected) //6��° ������ 
	{
		//IMAGEMANAGER->findImage("��������")->render(getMemDC(), 0, 0);
	}
	if (_selectItem[INDEXS_BUTTON_CANCEL].Selected) //��� ��ư
	{
		SCENEMANAGER->changeScene("�����׾�");
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

