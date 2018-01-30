#include "stdafx.h"
#include "MonsterBack.h"
#include "pokemon.h"
#include "battleSceneUI.h"
#include "battleScene.h"
#include "inventory.h"
#include "item.h"

MonsterBack::MonsterBack()
{//생성맨~
}


MonsterBack::~MonsterBack()
{//소멸맨~
}



 HRESULT MonsterBack::init(void)
{
	 IMAGEMANAGER->addImage("MonsterBackGround", ".\\bmps\\PokeBack\\PokeBackGround.bmp", WINSIZEX, WINSIZEY, false, true, MAGENTA);
	 IMAGEMANAGER->addImage("cancle", ".\\bmps\\PokeBack\\cancle.bmp", 104, 45, false, true, MAGENTA);
	 IMAGEMANAGER->addImage("PokeSelect", ".\\bmps\\PokeBack\\DogamSelect.bmp", 239, 92, false, true, MAGENTA);
	 IMAGEMANAGER->addImage("PokeMonCatch", ".\\bmps\\PokeBack\\DogamMonsterIn.bmp", 239, 92, false, true, MAGENTA);
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
		 _SelectPokeMonNum = 0;

		 if (i < (*DATABASE->getVPlayerPokemon()).size())
		 {
			 _PokeInfo[i]._playerHpBar = new progressBar;
			 _PokeInfo[i]._playerHpBar->init("hpBar", _PokeInfo[i].rc.left + 118, _PokeInfo[i].rc.top + 47, 95, 8, ((*DATABASE->getVPlayerPokemon())[i]->getCurrentHP()) , ((*DATABASE->getVPlayerPokemon())[i]->getMaxHP()));
		 }
		


	 }


	 _PokeChage.rc = RectMakeCenter(WINSIZEX  / 2 , 208, 449, 118);
	 _PokeChage.rc1 = RectMakeCenter(WINSIZEX - 38, WINSIZEY - 36, 71, 73);

	 _CancleRc = RectMakeCenter(WINSIZEX - 55, WINSIZEY - 25, 104, 45);

	 _inventory = (inventory*)SCENEMANAGER->findScene("인벤토리씬");

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
	
	
				 _PokeInfo[i]._playerHpBar->setGauge(((*DATABASE->getVPlayerPokemon())[i]->getCurrentHP()), ((*DATABASE->getVPlayerPokemon())[i]->getMaxHP()), (int)true);
	
		 }
	 if (!_isChange)
	 {
		 if(SCENEMANAGER->getLastSceneName() != "battleScene")
		 {
			 for (int i = 0; i < DATABASE->getVPlayerPokemon()->size(); i++)
			 {

				 
				if(PtInRect(&_PokeInfo[i].rc, _ptMouse))
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
	 // 마지막 신이 배틀 씬 일때 ~~
		 if(SCENEMANAGER->getLastSceneName() == "battleScene")
		 {
			 
			 if (_isChange == false)
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
							 _SelectPokeMonNum = i;
							 _isChange = true;
						 }

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

	 //============배틀 쒼 전환 =======================//
	 if (_isChange == true)
	 {
		 if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
		 {
			 if (_battleSceneUI->getBattleScene()->getCurrentPlayerPokemon() != (*DATABASE->getVPlayerPokemon())[_SelectPokeMonNum])
			 {
				 if (PtInRect(&_PokeChage.rc, _ptMouse))
				 {
					 _battleSceneUI->getBattleScene()->setPlayerChangeNum(_SelectPokeMonNum);
					 _battleSceneUI->getBattleScene()->setSequence(BATTLE_FIGHT);
					 SCENEMANAGER->changeScene(SCENEMANAGER->getLastSceneName());
					 _isChange = false;
				 }
			 }
			if (PtInRect(&_PokeChage.rc1, _ptMouse))
			{
				_isChange = false;
			}
		 }
	 }
	 //====================================================//







	// ================= 인벤토리에서 회복약 사용했을때! ===============================//

	 if (SCENEMANAGER->getLastSceneName() == "인벤토리씬")
	 {
		 if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
		 {		 //마우스로 취소 키를 눌렀을 경우~

			 string temp = SCENEMANAGER->getLastSceneName();
			 if (PtInRect(&_CancleRc, _ptMouse))
			 {
				 SCENEMANAGER->changeScene(SCENEMANAGER->getLastSceneName());
			 }

			 //아이템 사용~ 하는거
			 for (int i = 0; i < DATABASE->getVPlayerPokemon()->size(); i++)
			 {
				if (PtInRect(&_PokeInfo[i].rc, _ptMouse))
				{
					if (_inventory->getCurrentItem()->getType() == ITEM_POTION)
					{
						if(_inventory->getCurrentItem()->getName() == "hp포션")
						{
							(*DATABASE->getVPlayerPokemon())[i]->setCurrentHP((*DATABASE->getVPlayerPokemon())[i]->getCurrentHP() + _inventory->getCurrentItem()->getItemAbility());
							_PokeInfo[i]._playerHpBar->setGauge((*DATABASE->getVPlayerPokemon())[i]->getCurrentHP(), (*DATABASE->getVPlayerPokemon())[i]->getMaxHP(), (int)true);
							//SCENEMANAGER->changeScene(SCENEMANAGER->getLastSceneName());
						}

						if (_inventory->getCurrentItem()->getName() == "pp포션")
						{
							(*DATABASE->getVPlayerPokemon())[i]->getVSkill()[0]->setCurrentPP((*DATABASE->getVPlayerPokemon())[i]->getVSkill()[0]->getMaxPP());
							(*DATABASE->getVPlayerPokemon())[i]->getVSkill()[1]->setCurrentPP((*DATABASE->getVPlayerPokemon())[i]->getVSkill()[1]->getMaxPP());
							(*DATABASE->getVPlayerPokemon())[i]->getVSkill()[2]->setCurrentPP((*DATABASE->getVPlayerPokemon())[i]->getVSkill()[2]->getMaxPP());
							(*DATABASE->getVPlayerPokemon())[i]->getVSkill()[3]->setCurrentPP((*DATABASE->getVPlayerPokemon())[i]->getVSkill()[3]->getMaxPP());
						}

					}

				}
			 }
		 }
		 //키로 취소를 눌렀을 경우
		 if (KEYMANAGER->isOnceKeyDown(PLAYER_CANCLE_KEY))
		 {
			 SCENEMANAGER->changeScene(SCENEMANAGER->getLastSceneName());
		 }
	 }


	 if (SCENEMANAGER->getLastSceneName() == "UI")
	 {
		 //마우스로 취소 키를 눌렀을 경우~
		 if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
		 {
			 if (PtInRect(&_CancleRc, _ptMouse))
			 {
				 SCENEMANAGER->changeScene("UI");
			 }
		 }

		 //키로 취소를 눌렀을 경우
		 if (KEYMANAGER->isOnceKeyDown(PLAYER_CANCLE_KEY))
		 {
			 SCENEMANAGER->changeScene("UI");

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
	 }
		 if (_isChange)
		 {
			 IMAGEMANAGER->findImage("pokeChange")->render(getMemDC(), 0, 0);
			// Rectangle(getMemDC(), _PokeChage.rc.left, _PokeChage.rc.top, _PokeChage.rc.right, _PokeChage.rc.bottom);
			// Rectangle(getMemDC(), _PokeChage.rc1.left, _PokeChage.rc1.top, _PokeChage.rc1.right, _PokeChage.rc1.bottom);

			 IMAGEMANAGER->findImage((*DATABASE->getVPlayerPokemon())[_SelectPokeMonNum]->getName() + "s")->frameRender(getMemDC(), WINSIZEX / 2 - 35, WINSIZEY / 2 - 80, _PokeInfo[_SelectPokeMonNum].currentFrameX, 0);
			 
			 SetBkMode(getMemDC(), TRANSPARENT);
			 TextOut(getMemDC(),WINSIZEX / 2 - 40, 80, (*DATABASE->getVPlayerPokemon())[_SelectPokeMonNum]->getName().c_str(), strlen((*DATABASE->getVPlayerPokemon())[_SelectPokeMonNum]->getName().c_str()));
		 }
		// _battleSceneUI->getBattleScene()->setPlayerChangeNum(_SelectPokeMonNum);

 }