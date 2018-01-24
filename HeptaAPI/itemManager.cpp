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

item* itemManager::addItem(string strKey)
{
	item* itm = findItem(strKey);

	if (itm) return itm;
	itm = new item;

	if (FAILED(itm->init()))
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

void itemManager::render(string strKey, HDC hdc, int destX, int destY)
{
	item* itm = findItem(strKey);
	if (itm) itm->render(hdc, destX, destY);
}