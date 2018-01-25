#pragma once
#include "gameNode.h"


struct InfoRect
{
	RECT rc;				// 렉트 박스
	image rcImage;			// 렉트 이미지
	image imageName;		// 포켓몬 이미지
	BOOL isCatch;			// 포켓몬을 잡았냐?
	
};

class UI : public gameNode
{

private:


	InfoRect _Info[5];

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

