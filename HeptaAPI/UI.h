#pragma once
#include "gameNode.h"


struct InfoRect
{
	RECT rc;				// ��Ʈ �ڽ�
	image rcImage;			// ��Ʈ �̹���
	image imageName;		// ���ϸ� �̹���
	BOOL isCatch;			// ���ϸ��� ��ҳ�?
	
};

class UI : public gameNode
{

private:


	InfoRect _Info[5];

	bool _isName;		 // �̸�ĭ�� ����
	bool _isMonBak;		 //���� ���濡 ����
	bool _isBak;		 // ������ ���濡 ����
	bool _isSave;	     // ���̺� â�� ������?
	bool _isDogam;		 // ���� â�� ������?



public:
	UI();
	~UI();


	virtual HRESULT init();
	virtual void release(void);
	virtual void update(void);
	virtual void render(void);

};

