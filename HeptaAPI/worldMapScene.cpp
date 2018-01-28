#include "stdafx.h"
#include "worldMapScene.h"


worldMapScene::worldMapScene()
{

}


worldMapScene::~worldMapScene()
{
}


HRESULT worldMapScene::init()
{
	IMAGEMANAGER->addImage("¹è°æ", ".\\bmps\\worldMapScene\\worldmap1.bmp", WINSIZEX, WINSIZEY, true, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("Ç¥½Ã", ".\\bmps\\worldMapScene\\select.bmp", 50, 78, true, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("clear", ".\\bmps\\worldMapScene\\clear.bmp", 101, 42, true, true, RGB(255, 0, 255));

	//Ã¼À°°ü ÁÂÇ¥ ÃÊ±âÈ­
	_select[GYM_0].pt.x = 70;
	_select[GYM_0].pt.y = 5;

	_select[GYM_1].pt.x = 35;
	_select[GYM_1].pt.y = 70;

	_select[GYM_2].pt.x = 60;
	_select[GYM_2].pt.y = 170;

	_select[GYM_3].pt.x = 205;
	_select[GYM_3].pt.y = 165;

	_select[GYM_4].pt.x = 265;
	_select[GYM_4].pt.y = 155;

	_select[GYM_5].pt.x = 360;
	_select[GYM_5].pt.y = 155;


	_select[GYM_6].pt.x = 400;
	_select[GYM_6].pt.y = 250;

	_select[GYM_7].pt.x = 300;
	_select[GYM_7].pt.y = 20;

	_select[GYM_8].pt.x = 230;
	_select[GYM_8].pt.y = 90;

	//Ã³À½Ã¼À°°ü ÃÊ±âÈ­
	SelectNum = 0;
	_select[0].isSelect = true;

	for (int i = 0; i < GYM_END; i++)
	{
		_select[i].Selected = false;
	}

	return S_OK;
}
void worldMapScene::release()
{

}
void worldMapScene::update()
{
	selectMove();

	if (_select[GYM_0].Selected) //1¹øÂ° Ã¼À°°ü 
	{
		SCENEMANAGER->changeScene("ÀÎº¥Åä¸®¾À");
		SCENEMANAGER->init("ÀÎº¥Åä¸®¾À");
		_select[GYM_0].Selected = false;
	}
	if (_select[GYM_1].Selected) //2¹øÂ° Ã¼À°°ü
	{
		SCENEMANAGER->changeScene("»óÁ¡¾À");
		SCENEMANAGER->init("»óÁ¡¾À");
		_select[GYM_1].Selected = false;
	}
	if (_select[GYM_2].Selected) //3¹øÂ° Ã¼À°°ü 
	{
		SCENEMANAGER->changeScene("½ºÅ×ÀÌÁö7");
		SCENEMANAGER->init("½ºÅ×ÀÌÁö7");
		_select[GYM_2].Selected = false;
	}
	if (_select[GYM_3].Selected) //4¹øÂ° Ã¼À°°ü 
	{
		SCENEMANAGER->changeScene("¿ÀÇÁ´×¾À");
		_select[GYM_3].Selected = false;
	}
	if (_select[GYM_4].Selected) //5¹øÂ° Ã¼À°°ü 
	{
		SCENEMANAGER->changeScene("¿ÀÇÁ´×¾À");
		_select[GYM_4].Selected = false;
	}
	if (_select[GYM_5].Selected) //6¹øÂ° Ã¼À°°ü
	{
		SCENEMANAGER->changeScene("¿ÀÇÁ´×¾À");
		_select[GYM_5].Selected = false;
	}
	if (_select[GYM_6].Selected) //7¹øÂ° Ã¼À°°ü 
	{
		SCENEMANAGER->changeScene("¿ÀÇÁ´×¾À");
		_select[GYM_6].Selected = false;
	}
	if (_select[GYM_7].Selected) //8¹øÂ° Ã¼À°°ü 
	{
		SCENEMANAGER->changeScene("¿ÀÇÁ´×¾À");
		_select[GYM_7].Selected = false;
	}
	if (_select[GYM_8].Selected) //9¹øÂ° Ã¼À°°ü 
	{
		SCENEMANAGER->changeScene("¿ÀÇÁ´×¾À");
		_select[GYM_8].Selected = false;
	}



}
void worldMapScene::render()
{
	IMAGEMANAGER->findImage("¹è°æ")->render(getMemDC(), 0, 0);

	for (int i = 0; i < GYM_MAX; i++)
	{
		if (_select[i].isSelect == true)
		{
			IMAGEMANAGER->findImage("Ç¥½Ã")->render(getMemDC(), _select[i].pt.x, _select[i].pt.y);
		}
	}

	for (int i = 0; i < GYM_MAX; i++)
	{
		if (_isClear[i] == true)
		{
			IMAGEMANAGER->findImage("clear")->render(getMemDC(), _select[i].pt.x, _select[i].pt.y + 50);
		}
	}


}

void worldMapScene::selectMove()
{
	if (KEYMANAGER->isOnceKeyDown(VK_UP))
	{
		SelectNum = (SelectNum + (GYM_MAX - 1)) % GYM_MAX;
		for (int i = 0; i < GYM_MAX; i++)
		{
			if (SelectNum == i)
			{
				_select[i].isSelect = true;
			}
			else
			{
				_select[i].isSelect = false;
			}
		}
	}

	if (KEYMANAGER->isOnceKeyDown(VK_DOWN))
	{
		SelectNum = (SelectNum + 1) % GYM_MAX;
		for (int i = 0; i < GYM_MAX; i++)
		{
			if (SelectNum == i)
			{
				_select[i].isSelect = true;


			}
			else
			{
				_select[i].isSelect = false;

			}
		}
	}

	if (KEYMANAGER->isOnceKeyDown(PLAYER_SELECT_KEY))
	{
		_select[SelectNum].Selected = true;
	}

	if (KEYMANAGER->isOnceKeyDown(PLAYER_CANCLE_KEY))
	{
		SCENEMANAGER->changeScene(SCENEMANAGER->getLastSceneName());
	}

}