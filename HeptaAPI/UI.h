#pragma once
#include "gameNode.h"


struct InfoRect
{
	RECT rc;				// ��Ʈ �ڽ�
	image rcImage;			// ��Ʈ �̹���
	image imageName;		// ���ϸ� �̹���
	BOOL isCatch;			// ���ϸ��� ��ҳ�?
	
};


struct PlayerBage
{
	bool bage1, bage2, bage3, bage4, bage5, bage6, bage7, bage8;
	image* bage1image, bage2image, bage3image, bage4image, bage5image, bage6image, bage7image, bage8image;
	RECT rc1, rc2, rc3, rc4, rc5, rc6, rc7, rc8;
};



class UI : public gameNode
{

private:

	RECT _NameExit;


	InfoRect _Info[5];
	PlayerBage _PlayerBage;



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

