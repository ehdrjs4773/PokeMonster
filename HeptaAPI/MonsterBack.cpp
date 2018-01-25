#include "stdafx.h"
#include "MonsterBack.h"



MonsterBack::MonsterBack()
{
}


MonsterBack::~MonsterBack()
{
}



 HRESULT MonsterBack::init(void)
{
	 IMAGEMANAGER->addImage("MonsterBackGround", ".\\bmps\\PokeBack\\PokeBackGround.bmp", WINSIZEX, WINSIZEY, false, true, MAGENTA);
	 IMAGEMANAGER->addImage("cancle", ".\\bmps\\PokeBack\\cancle.bmp", 104, 45, false, true, MAGENTA);
	 IMAGEMANAGER->addImage("PokeSelect", ".\\bmps\\PokeBack\\DogamSelect.bmp", 239, 92, false, true, MAGENTA);
	 IMAGEMANAGER->addImage("PokeMonCatch", ".\\bmps\\PokeBack\\DogamMonsterIn.bmp", 239, 92, false, true, MAGENTA);


	 for (int i = 0; i < 6; i++)
	 {
		 _PokeInfo[i].HP = 0;
		 _PokeInfo[i].Level = 0;
		 _PokeInfo[i].RectImage = IMAGEMANAGER->findImage("PokeSelect");
		 _PokeInfo[i].Catch = false;
		 _PokeInfo[i].PoketImage = NULL;
		 _PokeInfo[0].rc = RectMakeCenter(120, 46, 239, 92);
		 _PokeInfo[1].rc = RectMakeCenter(359, 59, 239, 92);
		 _PokeInfo[2].rc = RectMakeCenter(120, 142, 239, 92);
		 _PokeInfo[3].rc = RectMakeCenter(359, 151, 239, 92);
		 _PokeInfo[4].rc = RectMakeCenter(120, 234, 239, 92);
		 _PokeInfo[5].rc = RectMakeCenter(359, 243, 239, 92);
		 _PokeInfo[0].PokeImageRc = RectMake(_PokeInfo[0].rc.left + 40, _PokeInfo[0].rc.top + 20, 40, 40);
		 _PokeInfo[1].PokeImageRc = RectMake(_PokeInfo[1].rc.left + 40, _PokeInfo[1].rc.top + 20, 40, 40);
		 _PokeInfo[2].PokeImageRc = RectMake(_PokeInfo[2].rc.left + 40, _PokeInfo[2].rc.top + 20, 40, 40);
		 _PokeInfo[3].PokeImageRc = RectMake(_PokeInfo[3].rc.left + 40, _PokeInfo[3].rc.top + 20, 40, 40);
		 _PokeInfo[4].PokeImageRc = RectMake(_PokeInfo[4].rc.left + 40, _PokeInfo[4].rc.top + 20, 40, 40);
		 _PokeInfo[5].PokeImageRc = RectMake(_PokeInfo[5].rc.left + 40, _PokeInfo[5].rc.top + 20, 40, 40);
	 }

	

	 _CancleRc = RectMakeCenter(WINSIZEX - 55, WINSIZEY - 25, 104, 45);
	 return S_OK;

}
 void MonsterBack::release(void)
 {



 }


 void MonsterBack::update(void)	
{
	 if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
	 {
		 if (PtInRect(&_CancleRc, _ptMouse))
		 {
			 SCENEMANAGER->changeScene("UI");
		 }
	 }


	 if (KEYMANAGER->isOnceKeyDown(VK_LEFT))
	 {
		 if (_PokeInfo[0].Catch)
		 {
			 _PokeInfo[0].Catch = false;
		 }
		 else _PokeInfo[0].Catch = true;
	 }

}


 void MonsterBack::render(void)
 {

	 IMAGEMANAGER->findImage("MonsterBackGround")->render(getMemDC());


	//Rectangle(getMemDC(), _CancleRc.left, _CancleRc.top, _CancleRc.right, _CancleRc.bottom);

	 IMAGEMANAGER->findImage("cancle")->render(getMemDC(), _CancleRc.left, _CancleRc.top);

	 
	 for (int i = 0; i < 6; i++)
	 {
		 if (_PokeInfo[i].Catch) // ==== 포켓몬 잡혔을때 출력!===//
		 {//Rectangle(getMemDC(), _PokeInfo[i].rc.left, _PokeInfo[i].rc.top, _PokeInfo[i].rc.right, _PokeInfo[i].rc.bottom);
			 IMAGEMANAGER->findImage("PokeSelect")->render(getMemDC(), _PokeInfo[i].rc.left, _PokeInfo[i].rc.top);
		 }
		 //==== 포켓몬 조그만한 이미지 출력 박스===///
		 //Rectangle(getMemDC(), _PokeInfo[0].PokeImageRc.left, _PokeInfo[0].PokeImageRc.top, _PokeInfo[0].PokeImageRc.right, _PokeInfo[0].PokeImageRc.bottom);
	 }

	
 }