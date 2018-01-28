#include "stdafx.h"
#include "MonsterBack.h"
#include "pokemon.h"
#include "battleSceneUI.h"


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
	 IMAGEMANAGER->addImage("pokeChange", ".\\bmps\\PokeBack\\pokeChange.bmp", WINSIZEX, WINSIZEY, false, true, MAGENTA);

	 for (int i = 0; i < 6; i++)
	 {
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
	 
		
		 _isChange = false;

		 if (i < (*DATABASE->getVPlayerPokemon()).size())
		 {
			 _PokeInfo[i]._playerHpBar = new progressBar;
			 _PokeInfo[i]._playerHpBar->init("hpBar", _PokeInfo[i].rc.left + 118, _PokeInfo[i].rc.top + 47, 95, 8, ((*DATABASE->getVPlayerPokemon())[i]->getCurrentHP()) , ((*DATABASE->getVPlayerPokemon())[i]->getMaxHP()));
		 }

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
				 
				 if (_PokeInfo[i].count % 10 == 0)
				 {
					 _PokeInfo[i].currentFrameX++;
					 
					 if (_PokeInfo[i].currentFrameX >= 2) _PokeInfo[i].currentFrameX = 0;
					 _PokeInfo[i].count = 0;
				 }
	
	
				 _PokeInfo[i]._playerHpBar->setGauge(((*DATABASE->getVPlayerPokemon())[i]->getCurrentHP()), ((*DATABASE->getVPlayerPokemon())[i]->getMaxHP()));
	
		 }
	 if (!_isChange)
	 {
		 if(SCENEMANAGER->getLastSceneName() != "battleScene")
		 {
			 for (int i = 0; i < DATABASE->getVPlayerPokemon()->size(); i++)
			 {

				 
				if(PtInRect(&_PokeInfo[i].rc, _ptMouse))
				{
						if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
						{
							if (_PokeInfo[0].Catch == true) _PokeInfo[0].Catch = false;
							else if (_PokeInfo[1].Catch == true) _PokeInfo[1].Catch = false;
							else if (_PokeInfo[2].Catch == true) _PokeInfo[2].Catch = false;
							else if (_PokeInfo[3].Catch == true) _PokeInfo[3].Catch = false;
							else if (_PokeInfo[4].Catch == true) _PokeInfo[4].Catch = false;
							else if (_PokeInfo[5].Catch == true) _PokeInfo[5].Catch = false;
							_PokeInfo[i].Catch = true;
						}

						

				 }

			 }
		 }
	 // 마지막 신이 배틀 씬 일때 ~~
		 if(SCENEMANAGER->getLastSceneName() == "battleScene")
		 {

				 //마우스로 키를 눌렀을 경우~
				 if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
				 {
					 // 취소키를 눌렀을때!
					 if (PtInRect(&_CancleRc, _ptMouse))
					 {
						 SCENEMANAGER->changeScene(SCENEMANAGER->getLastSceneName());
						 _battleSceneUI->selectReset();
					 }
					 for (int i = 0; i < DATABASE->getVPlayerPokemon()->size(); i++)
					 {
						 if (PtInRect(&_PokeInfo[i].rc, _ptMouse))
						 {
							 _isChange = true;
						 }

					 }
			 }
			 //키로 취소를 눌렀을 경우
			 if (KEYMANAGER->isOnceKeyDown(PLAYER_CANCLE_KEY))
			 {
				 SCENEMANAGER->changeScene(SCENEMANAGER->getLastSceneName());
				 _battleSceneUI->selectReset();
			 }
		 }
	 }









	 // 마지막 씬이 UI였을때~
	 if (SCENEMANAGER->getLastSceneName() == "UI")
	 {
		 //마우스로 취소 키를 눌렀을 경우~
		 if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
		 {
			 if (PtInRect(&_CancleRc, _ptMouse))
			 {
				 SCENEMANAGER->changeScene(SCENEMANAGER->getLastSceneName());
			 }
		 }

		 //키로 취소를 눌렀을 경우
		 if (KEYMANAGER->isOnceKeyDown(PLAYER_CANCLE_KEY))
		 {
			 SCENEMANAGER->changeScene(SCENEMANAGER->getLastSceneName());

		 }
	 }




}


 void MonsterBack::render(void)
 {	

		 IMAGEMANAGER->findImage("MonsterBackGround")->render(getMemDC());


		 //Rectangle(getMemDC(), _CancleRc.left, _CancleRc.top, _CancleRc.right, _CancleRc.bottom);

		 IMAGEMANAGER->findImage("cancle")->render(getMemDC(), _CancleRc.left, _CancleRc.top);


		 for (int i = 0; i < DATABASE->getVPlayerPokemon()->size(); i++)
		 {

			 if (!_isChange)
			 {
				 if (!_PokeInfo[i].Catch)
				 {
					 IMAGEMANAGER->findImage("PokeMonCatch")->render(getMemDC(), _PokeInfo[i].rc.left, _PokeInfo[i].rc.top);
				 }
				 if (_PokeInfo[i].Catch)
				 {
					 IMAGEMANAGER->findImage("PokeSelect")->render(getMemDC(), _PokeInfo[i].rc.left, _PokeInfo[i].rc.top);
				 }

		 
		
					 IMAGEMANAGER->findImage((*DATABASE->getVPlayerPokemon())[i]->getName() + "s")->frameRender(getMemDC(), _PokeInfo[i].PokeImageRc.left, _PokeInfo[i].PokeImageRc.top, _PokeInfo[i].currentFrameX, 0);
					 SetBkMode(getMemDC(), TRANSPARENT);
					 TextOut(getMemDC(), _PokeInfo[i].HpTxt.x, _PokeInfo[i].HpTxt.y, (*DATABASE->getVPlayerPokemon())[i]->getName().c_str(), strlen((*DATABASE->getVPlayerPokemon())[i]->getName().c_str()));
					 _PokeInfo[i]._playerHpBar->render();
					 
					 char temp[32];
					 sprintf(temp, "%d", (*DATABASE->getVPlayerPokemon())[i]->getLevel());
					 TextOut(getMemDC(), _PokeInfo[i].rc.left + 40, _PokeInfo[i].rc.top + 65, temp, strlen(temp));
					 
					 char currentHP[32];
					 sprintf(currentHP, "%d", (*DATABASE->getVPlayerPokemon())[i]->getCurrentHP());
					 TextOut(getMemDC(), _PokeInfo[i].rc.left + 130, _PokeInfo[i].rc.top + 65, currentHP, strlen(currentHP));

					 char maxHP[32];
					 sprintf(maxHP, "%d", (*DATABASE->getVPlayerPokemon())[i]->getMaxHP());
					 TextOut(getMemDC(), _PokeInfo[i].rc.left + 180, _PokeInfo[i].rc.top + 65, maxHP, strlen(maxHP));
					 
				 //==== 포켓몬 조그만한 이미지 출력 박스===///
				 //Rectangle(getMemDC(), _PokeInfo[0].PokeImageRc.left, _PokeInfo[0].PokeImageRc.top, _PokeInfo[0].PokeImageRc.right, _PokeInfo[0].PokeImageRc.bottom);
			}
			 if (_isChange)
	     	{
				 IMAGEMANAGER->findImage("pokeChange")->render(getMemDC(), 0, 0);
			}

	 }

 }