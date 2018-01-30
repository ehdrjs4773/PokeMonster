#pragma once
#include "gameNode.h"
#include <string>

enum ITEM_TYPE 
{
	ITEM_NULL,	//�ʱ�ȭ��
	ITEM_UTILS,	//item_kind_1 
	ITEM_POTION,	//item_kind_2
	ITEM_BALL,	//item_kinde_4
	ITEM_MACHINE,	//item_kind_4
	ITEM_END

};


class item : public gameNode
{
private:
	image* _image;
	RECT _rc;
	ITEM_TYPE	_itemKind;		//������ ����
	string	_name;			//������ �̸�
	string	_description;	//������ ����
	int		_ability;		//������ �ɷ�
	int		_price;			//������ ����
	int		_itemNum;		//������ ����




public:
	item();
	~item();

	HRESULT init(int itemNum, ITEM_TYPE type, string name, string ds, int ability, int price);
	HRESULT init(int itemNum, image* img, ITEM_TYPE type, string name, string ds, int ability, int price);
	void release(void);
	void update(void);
	void render(HDC hdc);
	void render(HDC hdc, int destX, int destY, int itemNum);
	void render(HDC hdc, image* img, int destX, int destY, int itemNum);
	void InvenRender(HDC hdc, image* img, int destX, int destY);


	//item's getter setter
	int getItemNum() { return _itemNum; } // ������ ���� �������� �Լ�
	void setItemNum(int num) { _itemNum = num; } // ������ ���� �����ϴ� �Լ�

	image* getImg() { return _image; } // �̹��� �������� �Լ�

	int getItemAbility() { return _ability; } // ������ �ɷ�ġ �������� �Լ�
	ITEM_TYPE getType() { return _itemKind; } //������ ���� �������� �Լ�
	string getName() { return _name; }


};

