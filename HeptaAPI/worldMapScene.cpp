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
	IMAGEMANAGER->addImage("���", ".\\bmps\\worldMapScene\\worldmap1.bmp", WINSIZEX, WINSIZEY, true, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("ǥ��", ".\\bmps\\worldMapScene\\select.bmp", 50, 78, true, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("clear", ".\\bmps\\worldMapScene\\clear.bmp", 101, 42, true, true, RGB(255, 0, 255));

	//ü���� ��ǥ �ʱ�ȭ
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


	_select[GYM_6].pt.x =400;
	_select[GYM_6].pt.y = 250;

	_select[GYM_7].pt.x = 300;
	_select[GYM_7].pt.y = 20;

	_select[GYM_8].pt.x = 230;
	_select[GYM_8].pt.y = 90;


	
	for (int i = 0; i < GYM_END; i++)
	{
		_select[i].Selected = false;
	}

	//ó��ü���� �ʱ�ȭ
	SelectNum = 0;
	_select[0].isSelect = true;

	return S_OK;
}
void worldMapScene::release()	  
{

}
void worldMapScene::update()	 
{
	selectMove();

	if (_select[GYM_0].Selected) //1��° ü���� 
	{
		SCENEMANAGER->changeScene("�κ��丮��");
		SCENEMANAGER->init("�κ��丮��");
	}
	if (_select[GYM_1].Selected) //2��° ü����
	{
		SCENEMANAGER->changeScene("������");
		SCENEMANAGER->init("������");
	}
	if (_select[GYM_2].Selected) //3��° ü���� 
	{
		SCENEMANAGER->changeScene("�����׾�");
	}
	if (_select[GYM_3].Selected) //4��° ü���� 
	{
		SCENEMANAGER->changeScene("�����׾�");
	}
	if (_select[GYM_4].Selected) //5��° ü���� 
	{
		SCENEMANAGER->changeScene("�����׾�");
	}
	if (_select[GYM_5].Selected) //6��° ü����
	{
		SCENEMANAGER->changeScene("�����׾�");
	}
	if (_select[GYM_6].Selected) //7��° ü���� 
	{
		SCENEMANAGER->changeScene("�����׾�");
	}
	if (_select[GYM_7].Selected) //8��° ü���� 
	{
		SCENEMANAGER->changeScene("�����׾�");
	}
	if (_select[GYM_8].Selected) //9��° ü���� 
	{
		SCENEMANAGER->changeScene("�����׾�");
	}



}
void worldMapScene::render()	
{
	IMAGEMANAGER->findImage("���")->render(getMemDC(), 0, 0);

	for (int i = 0; i < GYM_MAX; i++)
	{
		if (_select[i].isSelect == true)
		{
			IMAGEMANAGER->findImage("ǥ��")->render(getMemDC(), _select[i].pt.x, _select[i].pt.y);
		}
	}

	for (int i = 0; i < GYM_MAX; i++)
	{
		if (_isClear[i] == true)
		{
			IMAGEMANAGER->findImage("clear")->render(getMemDC(), _select[i].pt.x, _select[i].pt.y+50);
		}
	}


}

void worldMapScene::selectMove()
{
	if (KEYMANAGER->isOnceKeyDown(VK_UP))
	{
		SelectNum = (SelectNum + (GYM_MAX-1)) % GYM_MAX;
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

	if (KEYMANAGER->isOnceKeyDown('A'))
	{
		_select[SelectNum].Selected = true;
	}

}