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
	_selectMenu[BUTTONS_UTIL].pt.x = 80;
	_selectMenu[BUTTONS_UTIL].pt.y = 0;

	_selectMenu[BUTTONS_POTION].pt.x = 170;
	_selectMenu[BUTTONS_POTION].pt.y = 0;

	_selectMenu[BUTTONS_BALL].pt.x = 260;
	_selectMenu[BUTTONS_BALL].pt.y = 0;

	_selectMenu[BUTTONS_MACHINE].pt.x = 350;
	_selectMenu[BUTTONS_MACHINE].pt.y = 0;

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

	if (key != _mInvenList.end()) //key���� ������
	{
		//TextOut(getMemDC(), 100, 100, "gkgk", strlen("gkgk")); //tagItem����ü ����->item*�� �������� ��Ƽ� 
	}
	else //������ insert�ض�
	{
		if (itm->getType() == ITEM_UTILS)
		{
			_mInvenList.insert(make_pair(strKey, itm));

			//if (!_invenSlot_UTIL[0].slotUse)
			//{
			//	_invenSlot_UTIL[0].key = strKey;
			//	_invenSlot_UTIL[0].number = 1;
			//	//_invenSlot_UTIL[0].slotUse = true;
			//}
			//else 	if (_invenSlot_UTIL[0].slotUse)
			//{
			//	_invenSlot_UTIL[1].key = strKey;
			//	_invenSlot_UTIL[1].number = 1;
			//	//_invenSlot_UTIL[1].slotUse = true;
			//}else if (_invenSlot_UTIL[1].slotUse)
			//{
			//	_invenSlot_UTIL[2].key = strKey;
			//	_invenSlot_UTIL[2].number = 1;
			//	//_invenSlot_UTIL[2].slotUse = true;
			//}else if (_invenSlot_UTIL[2].slotUse)
			//{
			//	_invenSlot_UTIL[3].key = strKey;
			//	_invenSlot_UTIL[3].number = 1;
			//	//_invenSlot_UTIL[3].slotUse = true;
			//}else if (_invenSlot_UTIL[3].slotUse)
			//{
			//	_invenSlot_UTIL[4].key = strKey;
			//	_invenSlot_UTIL[4].number = 1;
			//	//_invenSlot_UTIL[4].slotUse = true;
			//}else if (_invenSlot_UTIL[4].slotUse)
			//{
			//	_invenSlot_UTIL[5].key = strKey;
			//	_invenSlot_UTIL[5].number = 1;
			//	//_invenSlot_UTIL[5].slotUse = true;
			//}
			//else if (_invenSlot_UTIL[0].slotUse &&_invenSlot_UTIL[1].slotUse &&_invenSlot_UTIL[2].slotUse &&_invenSlot_UTIL[3].slotUse &&_invenSlot_UTIL[4].slotUse &&_invenSlot_UTIL[5].slotUse)
			//{
			//	TextOut(getMemDC(), 200, 200, "������ ������ �� á���ϴ�.", strlen("������ ������ �� á���ϴ�."));
			//}
			
		
		}
		else if (itm->getType() == ITEM_POTION)
		{
			_mInvenList.insert(make_pair(strKey, itm));
		}
		else if (itm->getType() == ITEM_BALL)
		{
			_mInvenList.insert(make_pair(strKey, itm));
		}
		else if (itm->getType() == ITEM_MACHINE)
		{
			_mInvenList.insert(make_pair(strKey, itm));
		}
		
	}
}

void inventory::renderItem(string strKey, WINDOWSTATUSS ws, int num)
{
	for (int i = 0; i < SLOT_MAX; ++i)
	{
			_invenSlot_UTIL[i].slotUse = false;
			_invenSlot_UTIL[num].slotUse = true;
	}


	for (int i = 0; i < SLOT_MAX; ++i)
	{
		_invenSlot_POTION[i].slotUse = false;
		_invenSlot_POTION[num].slotUse = true;
	}


	for (int i = 0; i < SLOT_MAX; ++i)
	{
		_invenSlot_BALL[i].slotUse = false;
		_invenSlot_BALL[num].slotUse = true;
	}


	for (int i = 0; i < SLOT_MAX; ++i)
	{
		_invenSlot_MACHINE[i].slotUse = false;
		_invenSlot_MACHINE[num].slotUse = true;
	}

	mapItemIter key = _mInvenList.find(strKey);

	if (key != _mInvenList.end()) //key���� ������
	{
		if (ws == WSS_UTIL)
		{
			if (_invenSlot_UTIL[1].slotUse)
			{
				key->second->InvenRender(IMAGEMANAGER->findImage("�κ��丮_��ƿ")->getMemDC(), _mInvenList[strKey]->getImg(), ITEMSLOT_FIRSTX, ITEMSLOT_FIRSTY);
			}
			else 	if (_invenSlot_UTIL[2].slotUse)
			{
				key->second->InvenRender(IMAGEMANAGER->findImage("�κ��丮_��ƿ")->getMemDC(), _mInvenList[strKey]->getImg(), ITEMSLOT_SECONDX, ITEMSLOT_SECONDY);
			}
			else if (_invenSlot_UTIL[3].slotUse)
			{
				key->second->InvenRender(IMAGEMANAGER->findImage("�κ��丮_��ƿ")->getMemDC(), _mInvenList[strKey]->getImg(), ITEMSLOT_THIRDX, ITEMSLOT_THIRDY);
			}
			else if (_invenSlot_UTIL[4].slotUse)
			{
				key->second->InvenRender(IMAGEMANAGER->findImage("�κ��丮_��ƿ")->getMemDC(), _mInvenList[strKey]->getImg(), ITEMSLOT_FORTHX, ITEMSLOT_FORTHY);
			}
			else if (_invenSlot_UTIL[5].slotUse)
			{
				key->second->InvenRender(IMAGEMANAGER->findImage("�κ��丮_��ƿ")->getMemDC(), _mInvenList[strKey]->getImg(), ITEMSLOT_FIFTHX, ITEMSLOT_FIFTHY);
			}
			else if (_invenSlot_UTIL[6].slotUse)
			{
				key->second->InvenRender(IMAGEMANAGER->findImage("�κ��丮_��ƿ")->getMemDC(), _mInvenList[strKey]->getImg(), ITEMSLOT_SIXTHX, ITEMSLOT_SIXTHY);
			}
			else if (_invenSlot_UTIL[1].slotUse &&_invenSlot_UTIL[2].slotUse &&_invenSlot_UTIL[3].slotUse &&_invenSlot_UTIL[4].slotUse &&_invenSlot_UTIL[5].slotUse &&_invenSlot_UTIL[6].slotUse)
			{
				TextOut(getMemDC(), 200, 200, "������ ������ �� á���ϴ�.", strlen("������ ������ �� á���ϴ�."));
			}
		}
		else if (ws == WSS_POTION)
		{
			if (_invenSlot_POTION[0].slotUse)
			{
				key->second->InvenRender(IMAGEMANAGER->findImage("�κ��丮_����")->getMemDC(), _mInvenList[strKey]->getImg(), ITEMSLOT_FIRSTX, ITEMSLOT_FIRSTY);
			}
			else 	if (_invenSlot_POTION[1].slotUse)
			{
				key->second->InvenRender(IMAGEMANAGER->findImage("�κ��丮_����")->getMemDC(), _mInvenList[strKey]->getImg(), ITEMSLOT_SECONDX, ITEMSLOT_SECONDY);
			}
			else if (_invenSlot_POTION[2].slotUse)
			{
				key->second->InvenRender(IMAGEMANAGER->findImage("�κ��丮_����")->getMemDC(), _mInvenList[strKey]->getImg(), ITEMSLOT_THIRDX, ITEMSLOT_THIRDY);
			}
			else if (_invenSlot_POTION[3].slotUse)
			{
				key->second->InvenRender(IMAGEMANAGER->findImage("�κ��丮_����")->getMemDC(), _mInvenList[strKey]->getImg(), ITEMSLOT_FORTHX, ITEMSLOT_FORTHY);
			}
			else if (_invenSlot_POTION[4].slotUse)
			{
				key->second->InvenRender(IMAGEMANAGER->findImage("�κ��丮_����")->getMemDC(), _mInvenList[strKey]->getImg(), ITEMSLOT_FIFTHX, ITEMSLOT_FIFTHY);
			}
			else if (_invenSlot_POTION[5].slotUse)
			{
				key->second->InvenRender(IMAGEMANAGER->findImage("�κ��丮_����")->getMemDC(), _mInvenList[strKey]->getImg(), ITEMSLOT_SIXTHX, ITEMSLOT_SIXTHY);
			}
			else if (_invenSlot_POTION[0].slotUse &&_invenSlot_POTION[1].slotUse &&_invenSlot_POTION[2].slotUse &&_invenSlot_POTION[3].slotUse &&_invenSlot_POTION[4].slotUse &&_invenSlot_POTION[5].slotUse)
			{
				TextOut(IMAGEMANAGER->findImage("�κ��丮_����")->getMemDC(), 200, 200, "������ ������ �� á���ϴ�.", strlen("������ ������ �� á���ϴ�."));
			}
		}
		else if (ws == WSS_BALL)
		{
			if (_invenSlot_BALL[0].slotUse)
			{
				key->second->InvenRender(IMAGEMANAGER->findImage("�κ��丮_��")->getMemDC(), _mInvenList[strKey]->getImg(), ITEMSLOT_FIRSTX, ITEMSLOT_FIRSTY);
			}
			else 	if (_invenSlot_BALL[1].slotUse)
			{
				key->second->InvenRender(IMAGEMANAGER->findImage("�κ��丮_��")->getMemDC(), _mInvenList[strKey]->getImg(), ITEMSLOT_SECONDX, ITEMSLOT_SECONDY);
			}
			else if (_invenSlot_BALL[2].slotUse)
			{
				key->second->InvenRender(IMAGEMANAGER->findImage("�κ��丮_��")->getMemDC(), _mInvenList[strKey]->getImg(), ITEMSLOT_THIRDX, ITEMSLOT_THIRDY);
			}
			else if (_invenSlot_BALL[3].slotUse)
			{
				key->second->InvenRender(IMAGEMANAGER->findImage("�κ��丮_��")->getMemDC(), _mInvenList[strKey]->getImg(), ITEMSLOT_FORTHX, ITEMSLOT_FORTHY);
			}
			else if (_invenSlot_BALL[4].slotUse)
			{
				key->second->InvenRender(IMAGEMANAGER->findImage("�κ��丮_��")->getMemDC(), _mInvenList[strKey]->getImg(), ITEMSLOT_FIFTHX, ITEMSLOT_FIFTHY);
			}
			else if (_invenSlot_BALL[5].slotUse)
			{
				key->second->InvenRender(IMAGEMANAGER->findImage("�κ��丮_��")->getMemDC(), _mInvenList[strKey]->getImg(), ITEMSLOT_SIXTHX, ITEMSLOT_SIXTHY);
			}
			else if (_invenSlot_BALL[0].slotUse &&_invenSlot_BALL[1].slotUse &&_invenSlot_BALL[2].slotUse &&_invenSlot_BALL[3].slotUse &&_invenSlot_BALL[4].slotUse &&_invenSlot_BALL[5].slotUse)
			{
				TextOut(getMemDC(), 200, 200, "������ ������ �� á���ϴ�.", strlen("������ ������ �� á���ϴ�."));
			}
		}
		else if (ws == WSS_MACHINE)
		{
			if (_invenSlot_MACHINE[0].slotUse)
			{
				key->second->InvenRender(IMAGEMANAGER->findImage("�κ��丮_�ӽ�")->getMemDC(), _mInvenList[strKey]->getImg(), ITEMSLOT_FIRSTX, ITEMSLOT_FIRSTY);
			}
			else 	if (_invenSlot_MACHINE[1].slotUse)
			{
				key->second->InvenRender(IMAGEMANAGER->findImage("�κ��丮_�ӽ�")->getMemDC(), _mInvenList[strKey]->getImg(), ITEMSLOT_SECONDX, ITEMSLOT_SECONDY);
			}
			else if (_invenSlot_MACHINE[2].slotUse)
			{
				key->second->InvenRender(IMAGEMANAGER->findImage("�κ��丮_�ӽ�")->getMemDC(), _mInvenList[strKey]->getImg(), ITEMSLOT_THIRDX, ITEMSLOT_THIRDY);
			}
			else if (_invenSlot_MACHINE[3].slotUse)
			{
				key->second->InvenRender(IMAGEMANAGER->findImage("�κ��丮_�ӽ�")->getMemDC(), _mInvenList[strKey]->getImg(), ITEMSLOT_FORTHX, ITEMSLOT_FORTHY);
			}
			else if (_invenSlot_MACHINE[4].slotUse)
			{
				key->second->InvenRender(IMAGEMANAGER->findImage("�κ��丮_�ӽ�")->getMemDC(), _mInvenList[strKey]->getImg(), ITEMSLOT_FIFTHX, ITEMSLOT_FIFTHY);
			}
			else if (_invenSlot_MACHINE[5].slotUse)
			{
				key->second->InvenRender(IMAGEMANAGER->findImage("�κ��丮_�ӽ�")->getMemDC(), _mInvenList[strKey]->getImg(), ITEMSLOT_SIXTHX, ITEMSLOT_SIXTHY);
			}
			else if (_invenSlot_MACHINE[0].slotUse &&_invenSlot_MACHINE[1].slotUse &&_invenSlot_MACHINE[2].slotUse &&_invenSlot_MACHINE[3].slotUse &&_invenSlot_MACHINE[4].slotUse &&_invenSlot_MACHINE[5].slotUse)
			{
				TextOut(getMemDC(), 200, 200, "������ ������ �� á���ϴ�.", strlen("������ ������ �� á���ϴ�."));
			}
		}
		else //������
		{
			//TextOut(getMemDC(), 100, 100, "gkgk2", strlen("gkgk2"));
		}
	}
}


void inventory::UtilMenuDraw() //�κ��丮 ��ƿ Menu �׷��ִ� �Լ�
{
	IMAGEMANAGER->findImage("�κ��丮_��ƿ")->render(getMemDC(), 0, 0);
	IMAGEMANAGER->findImage("�κ��丮���")->render(getMemDC(), 360, 310);

	IMAGEMANAGER->findImage("������_��ƿ")->frameRender(getMemDC(), _selectMenu[BUTTONS_UTIL].pt.x, _selectMenu[BUTTONS_UTIL].pt.y, 0, 1);
	IMAGEMANAGER->findImage("�����ܼ���")->render(getMemDC(), _selectMenu[BUTTONS_UTIL].pt.x, _selectMenu[BUTTONS_UTIL].pt.y);

	IMAGEMANAGER->findImage("������_����")->frameRender(getMemDC(), _selectMenu[BUTTONS_POTION].pt.x, _selectMenu[BUTTONS_POTION].pt.y, 0, 0);
	IMAGEMANAGER->findImage("������_��")->frameRender(getMemDC(), _selectMenu[BUTTONS_BALL].pt.x, _selectMenu[BUTTONS_BALL].pt.y, 0, 0);
	IMAGEMANAGER->findImage("������_�ӽ�")->frameRender(getMemDC(), _selectMenu[BUTTONS_MACHINE].pt.x, _selectMenu[BUTTONS_MACHINE].pt.y, 0, 0);



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

	//renderItem("�ƹ��ų�", WSS_UTIL);
	//renderItem("�ӽ�2", WSS_UTIL);
	//renderItem("�ӽ�3", WSS_UTIL);
	//renderItem("�ӽ�4", WSS_UTIL);

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

void inventory::PotionMenuDraw() // �κ��丮 ���� Menu �׷��ִ� �Լ�
{
	IMAGEMANAGER->findImage("�κ��丮_����")->render(getMemDC(), 0, 0);
	IMAGEMANAGER->findImage("�κ��丮���")->render(getMemDC(), 360, 310);

	IMAGEMANAGER->findImage("������_��ƿ")->frameRender(getMemDC(), _selectMenu[BUTTONS_UTIL].pt.x, _selectMenu[BUTTONS_UTIL].pt.y, 0, 0);
	

	IMAGEMANAGER->findImage("������_����")->frameRender(getMemDC(), _selectMenu[BUTTONS_POTION].pt.x, _selectMenu[BUTTONS_POTION].pt.y, 0, 1);
	IMAGEMANAGER->findImage("������_��")->frameRender(getMemDC(), _selectMenu[BUTTONS_BALL].pt.x, _selectMenu[BUTTONS_BALL].pt.y, 0, 0);
	IMAGEMANAGER->findImage("������_�ӽ�")->frameRender(getMemDC(), _selectMenu[BUTTONS_MACHINE].pt.x, _selectMenu[BUTTONS_MACHINE].pt.y, 0, 0);
	IMAGEMANAGER->findImage("�����ܼ���")->render(getMemDC(), _selectMenu[BUTTONS_POTION].pt.x, _selectMenu[BUTTONS_POTION].pt.y);
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

	mapItemIter iter = _mInvenList.begin();
	for (int i = 0; iter != _mInvenList.end(); ++iter, ++i)
	{
		if (iter->second->getType() != ITEM_POTION)
		{
			--i;
		}

		renderItem(iter->first, WSS_POTION, i);
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

void inventory::BallMenuDraw() //�κ��丮 �� Menu �׷��ִ� �Լ�
{
	IMAGEMANAGER->findImage("�κ��丮_��")->render(getMemDC(), 0, 0);
	IMAGEMANAGER->findImage("�κ��丮���")->render(getMemDC(), 360, 310);

	IMAGEMANAGER->findImage("������_��ƿ")->frameRender(getMemDC(), _selectMenu[BUTTONS_UTIL].pt.x, _selectMenu[BUTTONS_UTIL].pt.y, 0, 0);
	IMAGEMANAGER->findImage("������_����")->frameRender(getMemDC(), _selectMenu[BUTTONS_POTION].pt.x, _selectMenu[BUTTONS_POTION].pt.y, 0, 0);

	IMAGEMANAGER->findImage("������_��")->frameRender(getMemDC(), _selectMenu[BUTTONS_BALL].pt.x, _selectMenu[BUTTONS_BALL].pt.y, 0, 1);
	IMAGEMANAGER->findImage("�����ܼ���")->render(getMemDC(), _selectMenu[BUTTONS_BALL].pt.x, _selectMenu[BUTTONS_BALL].pt.y);

	IMAGEMANAGER->findImage("������_�ӽ�")->frameRender(getMemDC(), _selectMenu[BUTTONS_MACHINE].pt.x, _selectMenu[BUTTONS_MACHINE].pt.y, 0, 0);

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

	mapItemIter iter = _mInvenList.begin();
	for (int i = 0; iter != _mInvenList.end(); ++iter, ++i)
	{
		if (iter->second->getType() != ITEM_BALL)
		{
			i--;
		}

		renderItem(iter->first, WSS_BALL, i);
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

void inventory::MachineMenuDraw() //�κ��丮 �ӽ� Menu �׷��ִ� �Լ�
{
	IMAGEMANAGER->findImage("�κ��丮_�ӽ�")->render(getMemDC(), 0, 0);
	IMAGEMANAGER->findImage("�κ��丮���")->render(getMemDC(), 360, 310);

	IMAGEMANAGER->findImage("������_��ƿ")->frameRender(getMemDC(), _selectMenu[BUTTONS_UTIL].pt.x, _selectMenu[BUTTONS_UTIL].pt.y, 0, 0);
	IMAGEMANAGER->findImage("������_����")->frameRender(getMemDC(), _selectMenu[BUTTONS_POTION].pt.x, _selectMenu[BUTTONS_POTION].pt.y, 0, 0);
	IMAGEMANAGER->findImage("������_��")->frameRender(getMemDC(), _selectMenu[BUTTONS_BALL].pt.x, _selectMenu[BUTTONS_BALL].pt.y, 0, 0);

	IMAGEMANAGER->findImage("������_�ӽ�")->frameRender(getMemDC(), _selectMenu[BUTTONS_MACHINE].pt.x, _selectMenu[BUTTONS_MACHINE].pt.y, 0, 1);
	IMAGEMANAGER->findImage("�����ܼ���")->render(getMemDC(), _selectMenu[BUTTONS_MACHINE].pt.x, _selectMenu[BUTTONS_MACHINE].pt.y);
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

	mapItemIter iter = _mInvenList.begin();
	for (int i = 0; iter != _mInvenList.end(); ++iter, ++i)
	{
		if (iter->second->getType() != ITEM_MACHINE)
		{
			--i;
		}

		renderItem(iter->first, WSS_MACHINE, i);
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

	if(KEYMANAGER->isOnceKeyDown(PLAYER_CANCLE_KEY))
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