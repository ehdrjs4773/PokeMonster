#pragma once
#include "gameNode.h"


enum ITEMKIND
{
	ITEM_TOOL,
	ITEM_POSITON,
	ITEM_BALL,
	ITEM_MACHINE
};

struct tagItem
{
	image* image;		//�̹���
	ITEMKIND kind;		//����
	string itemName;	//�̸�
	string dis;			//����
	RECT rc;
	float x, y;
	int ability;		//�ɷ�
	int price;			//����
	int itemNum;		//���� ��ȣ
};

class items : public gameNode
{
protected:
	tagItem _item;
	float _x, _y;

public:
	items();
	~items();

	virtual HRESULT init();
	//�̹����̸�, ���������� , �������̸� , �����ۼ��� , �����۴ɷ� , �����۰��� , �����۹�ȣ
	virtual HRESULT init(string imageName , ITEMKIND itemKind , string itemName , string itemDis, int ability , int price , int itemNum);
	virtual void release();
	virtual void update();
	virtual void render();

	virtual void rectDraw(float x, float y , float width , float height);
	
	void setRect(RECT item) { _item.rc = item; }

	tagItem getItemInfo() { return _item; }
	RECT getItemRect() { return _item.rc; }
};

