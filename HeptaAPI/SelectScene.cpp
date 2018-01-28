#include "stdafx.h"
#include "SelectScene.h"



SelectScene::SelectScene()
{
}


SelectScene::~SelectScene()
{

}




HRESULT SelectScene::init(void)
{
	//==== 셀렉트 씬 이미지 확인=====================================================================================================================//
	IMAGEMANAGER->addImage("openingBackGround4", ".\\bmps\\SelectScene\\openingBackGround4.bmp", WINSIZEX, WINSIZEY, true, true, MAGENTA);
	IMAGEMANAGER->addImage("openingBackGroudn4BackDarkNees", ".\\bmps\\SelectScene\\openingBackGround4DarkNess.bmp", WINSIZEX, WINSIZEY, false, false, MAGENTA);
	IMAGEMANAGER->addImage("openingDr5", ".\\bmps\\SelectScene\\Dr5.bmp", 62, 122, true, true, MAGENTA);
	IMAGEMANAGER->addImage("openingPokeBall", ".\\bmps\\SelectScene\\MonsterBall.bmp", 15, 15, true, true, MAGENTA);
	IMAGEMANAGER->addFrameImage("openingNpc", ".\\bmps\\SelectScene\\openingNpc.bmp",98, 37, 2, 1, true, true , MAGENTA);
	IMAGEMANAGER->addImage("openingRect", ".\\bmps\\SelectScene\\openingDr5Can.bmp", 320, 58, false, true, MAGENTA);
	IMAGEMANAGER->addFrameImage("openingPlayer", ".\\bmps\\SelectScene\\PlayerSin.bmp", 160, 97, 4, 1, false, true, MAGENTA);


	//=============================================================================================================================================//

	_SelectScene = SelectScene_one;
	_alpha = 0;
	_alphaBall = 0;
	_npcAlpha = 0;

	_currentFrameX = 0;


	_dr5x = WINSIZEX / 2 - 34;
	_dr5y = WINSIZEY / 2 - 66;


	return S_OK;
}
void SelectScene::release(void)
{
		
}


void SelectScene::update(void) 
{
	if (KEYMANAGER->isOnceKeyDown(VK_RETURN))
	{
		if(DIALOGUE->getCurrentLine() <= 32) DIALOGUE->setCurrentLine(DIALOGUE->getCurrentLine() + 2);
	}



	switch (_SelectScene)
	{
	case SelectScene_one :
		if(DIALOGUE->getCurrentLine() >= 3)
		{
			if (_alpha <= 254) _alpha += 1;
			
			else
			{
				_SelectScene = SelectScene_Two;

			}
		}
		break;

	case SelectScene_Two :
		if(DIALOGUE->getCurrentLine() >= 14)
		{
			if (_dr5x <= WINSIZEX - 180) _dr5x += 3;

			else if( _alphaBall <= 254) _alphaBall += 5;

			else _SelectScene = SelectScene_Three;
		}
		break;


	case SelectScene_Three:
		if (DIALOGUE->getCurrentLine() >= 16)
		{
			_alphaBall = 0;
			_npcAlpha = 255;

			if (_npcAlpha == 255)
			{
				_count++;
				if (_count % 50 == 0)
				{
					_currentFrameX++;
					if (_currentFrameX >= 2)
					{
						_currentFrameX = 0;
						if(DIALOGUE->getCurrentLine() >= 34)
						{
						 	_SelectScene = SelectScene_Four;
						}
					}
					_count = 0;
				}
			}
		}
		break;

	case SelectScene_Four:

			_count++;
			if (_count % 50 == 0)
			{
				_currentFrameX++;
				if (_currentFrameX >= 5) SCENEMANAGER->changeScene("스테이지0");
				_count = 0;
			}

		break;


	}

	DIALOGUE->update();
}



void SelectScene::render(void)
{


	switch (_SelectScene)
	{
	case SelectScene_one : 	case SelectScene_Two:	case SelectScene_Three:

		IMAGEMANAGER->findImage("openingBackGroudn4BackDarkNees")->render(getMemDC());
		IMAGEMANAGER->findImage("openingBackGround4")->alphaRender(getMemDC(), _alpha);
		IMAGEMANAGER->findImage("openingDr5")->alphaRender(getMemDC(), _dr5x, _dr5y, _alpha);
		IMAGEMANAGER->findImage("openingPokeBall")->alphaRender(getMemDC(), WINSIZEX - 180, WINSIZEY / 2- 15, _alphaBall);
		IMAGEMANAGER->findImage("openingNpc")->alphaFrameRender(getMemDC(), WINSIZEX / 2, WINSIZEY / 2 + 37, _currentFrameX, 0,  _npcAlpha);
		IMAGEMANAGER->findImage("openingRect")->render(getMemDC(), WINSIZEX / 2 - 160, WINSIZEY - 58);
		DIALOGUE->render(getMemDC());
		break;

	case SelectScene_Four :

		IMAGEMANAGER->findImage("openingBackGroudn4BackDarkNees")->render(getMemDC());
		IMAGEMANAGER->findImage("openingPlayer")->frameRender(getMemDC(), WINSIZEX / 2- 20, WINSIZEY / 2 - 43, _currentFrameX, 0);

		break;



	}




}
