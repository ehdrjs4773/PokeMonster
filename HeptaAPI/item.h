#pragma once



enum ITEM_TYPE 
{
	ITEM_NORMAL,
	ITEM_LASER,
	ITEM_CHAIN,
	ITEM_SPEED,
	ITEM_BOMB,
	ITEM_PACMAN,
	ITEM_DUMMY2,
	ITEM_END
};


class item 
{
	ITEM_TYPE _item;


public:
	item();
	~item();

	HRESULT init(void);
	void release(void);
	void update(void);
	void render(HDC hdc);
	void render(HDC hdc, int destX, int destY);

	inline ITEM_TYPE getItem(void) { return _item; }
};

