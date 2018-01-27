#include "stdafx.h"
#include "MonsterBack.h"
#include "pokemon.h"


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
	 IMAGEMANAGER->addFrameImage("이상해씨", ".\\bmps\\MonsterBag\\이상해씨s.bmp", 80, 40, 2, 1, false, true, MAGENTA);

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
		 _PokeInfo[i].PokeImageRc = RectMake(_PokeInfo[i].rc.left + 40, _PokeInfo[i].rc.top + 20, 40, 40);
		 _PokeInfo[i].currentFrameX = 0;
		 _PokeInfo[i].count = 0;
		 _PokeInfo[i].HpTxt.x = _PokeInfo[i].rc.left + 130;
		 _PokeInfo[i].HpTxt.y = _PokeInfo[i].rc.top + 20;
	 }

	 _CancleRc = RectMakeCenter(WINSIZEX - 55, WINSIZEY - 25, 104, 45);



	 return S_OK;

}
 void MonsterBack::release(void)
 {



 }


 void MonsterBack::update(void)	
{
	 for(int i = 0 ; i < DATABASE->getVPlayerPokemon()->size(); i++)
	 { 

			 _PokeInfo[i].count++;
			 
			 if (_PokeInfo[i].count % 50 == 0)
			 {
				 _PokeInfo[i].currentFrameX++;

				 if (_PokeInfo[i].currentFrameX >= 2) _PokeInfo[i].currentFrameX = 0;
				 _PokeInfo[i].count = 0;
			 }


	 }



	 if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
	 {
		 if (PtInRect(&_CancleRc, _ptMouse))
		 {
			 SCENEMANAGER->changeScene("UI");
		 }
	 }

	 if (KEYMANAGER->isOnceKeyDown('C'))
	 {
		 SCENEMANAGER->changeScene("UI");
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

	 
	 for (int i = 0; i < DATABASE->getVPlayerPokemon()->size(); i++)
	 {
		
			 IMAGEMANAGER->findImage("PokeMonCatch")->render(getMemDC(), _PokeInfo[i].rc.left, _PokeInfo[i].rc.top);
			 IMAGEMANAGER->findImage((*DATABASE->getVPlayerPokemon())[i]->getName() + "s")->frameRender(getMemDC(), _PokeInfo[i].PokeImageRc.left, _PokeInfo[i].PokeImageRc.top, _PokeInfo[i].currentFrameX, 0);

		 //==== 포켓몬 조그만한 이미지 출력 박스===///
		 //Rectangle(getMemDC(), _PokeInfo[0].PokeImageRc.left, _PokeInfo[0].PokeImageRc.top, _PokeInfo[0].PokeImageRc.right, _PokeInfo[0].PokeImageRc.bottom);
	 }


	 for (int i = 0; i < DATABASE->getVPlayerPokemon()->size(); i++)
	 {
		 SetBkMode(getMemDC(), TRANSPARENT);
		 TextOut(getMemDC(), _PokeInfo[i].HpTxt.x, _PokeInfo[i].HpTxt.y, (*DATABASE->getVPlayerPokemon())[i]->getName().c_str(), strlen((*DATABASE->getVPlayerPokemon())[i]->getName().c_str()));
	 }


 }