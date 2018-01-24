#pragma once
#include "singletonBase.h"
#include "item.h"
#include <map>

class itemManager : public singletonBase<itemManager>
{

private:
	typedef map<string, item*> mapItemList;
	typedef map<string, item*>::iterator mapItemIter;


private:
	mapItemList _mItemList;

public:

	HRESULT init(void);
	void release(void);

	item* addItem(string strKey);
	item* findItem(string strKey);

	BOOL deleteItem(string strKey);
	BOOL deleteAll(void);

	void render(string strKey, HDC hdc);
	void render(string strKey, HDC hdc, int destX, int destY);


	itemManager();
	~itemManager();
};

