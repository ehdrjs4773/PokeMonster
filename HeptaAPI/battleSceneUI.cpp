#include "stdafx.h"
#include "battleSceneUI.h"



battleSceneUI::battleSceneUI()
{
}


battleSceneUI::~battleSceneUI()
{
}

HRESULT battleSceneUI::init()
{
	IMAGEMANAGER->addImage("battleFrame", ".\\bmps\\battleScene\\UI\\battleFrame.bmp", WINSIZEX, WINSIZEY, false, true, MAGENTA);

	return S_OK;
}

void battleSceneUI::release()
{

}

void battleSceneUI::update() 
{

}

void battleSceneUI::render() 
{
	IMAGEMANAGER->findImage("battleFrame")->render(getMemDC());
}

