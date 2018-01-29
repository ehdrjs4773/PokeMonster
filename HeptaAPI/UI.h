#pragma once
#include "gameNode.h"


struct InfoRect
{
	RECT rc;				// 렉트 박스
	image rcImage;			// 렉트 이미지
	image imageName;		// 포켓몬 이미지
	BOOL isCatch;			// 포켓몬을 잡았냐?
	
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



	bool _isName;		 // 이름칸에 들어갔냐
	bool _isMonBak;		 //몬스터 가방에 들어갔냐
	bool _isBak;		 // 아이템 가방에 들어갔냐
	bool _isSave;	     // 세이브 창을 눌렀냐?
	bool _isDogam;		 // 도감 창을 눌럿냐?



public:
	UI();
	~UI();


	virtual HRESULT init();
	virtual void release(void);
	virtual void update(void);
	virtual void render(void);

};

