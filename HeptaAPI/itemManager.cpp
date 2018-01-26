#include "stdafx.h"
#include "itemManager.h"


itemManager::itemManager()
{
}


itemManager::~itemManager()
{

}

HRESULT itemManager::init(void)
{


	return S_OK;
}
void itemManager::release(void)
{
	deleteAll();
}

item* itemManager::addItem(string strKey, int itemNum, ITEM_TYPE type, string name, string ds, int ability, int price)
{
	item* itm = findItem(strKey);

	if (itm) return itm;
	itm = new item;

	if (FAILED(itm->init(itemNum, type, name, ds, ability, price)))
	{
		SAFE_DELETE(itm);

		return NULL;
	}

	_mItemList.insert(make_pair(strKey, itm));
	return itm;
}

item* itemManager::addItem(string strKey, image* img, int itemNum, ITEM_TYPE type, string name, string ds, int ability, int price)
{
	item* itm = findItem(strKey);

	if (itm) return itm;
	itm = new item;

	if (FAILED(itm->init(itemNum, img, type, name, ds, ability, price)))
	{
		SAFE_DELETE(itm);

		return NULL;
	}

	_mItemList.insert(make_pair(strKey, itm));
	return itm;
}

item* itemManager::findItem(string strKey)
{
	mapItemIter key = _mItemList.find(strKey);

	if (key != _mItemList.end())
	{
		return key->second;
	}

	return NULL;
}

BOOL itemManager::deleteItem(string strKey)
{
	mapItemIter key = _mItemList.find(strKey);

	if (key != _mItemList.end())
	{
		key->second->release();
		SAFE_DELETE(key->second);
		_mItemList.erase(key);

		return true;
	}
	return false;
}
BOOL itemManager::deleteAll(void)
{
	mapItemIter iter = _mItemList.begin();

	for (; iter != _mItemList.end();)
	{
		if (iter->second != NULL)
		{
			SAFE_DELETE(iter->second);
			iter = _mItemList.erase(iter);
		}
		else ++iter;

	}
	_mItemList.clear();

	return TRUE;

}

void itemManager::render(string strKey, HDC hdc)
{
	item* itm = findItem(strKey);
	if (itm) itm->render(hdc);
}

void itemManager::render(string strKey, HDC hdc, int destX, int destY, int itemNum)
{
	item* itm = findItem(strKey);
	if (itm) itm->render(hdc, destX, destY, itemNum);
}

void itemManager::render(string strKey, image* img, HDC hdc, int destX, int destY, int itemNum)
{
	item* itm = findItem(strKey);
	if (itm) itm->render(hdc, img, destX, destY, itemNum);
}