#include "stdafx.h"
#include "playGround.h"

playGround::playGround()
{

}


playGround::~playGround()
{

}

HRESULT playGround::init()
{
	gameNode::init(true);
	
	IMAGEMANAGER->addImage("배경", "worldmap1.bmp", WINSIZEX, WINSIZEY, true, true, RGB(255, 0, 255));

	SCENEMANAGER->addScene("월드맵씬", new worldMapScene);
	IMAGEMANAGER->addImage("표시", "select.bmp", 50, 78, true, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("clear", "clear.bmp", 101, 42, true, true, RGB(255, 0, 255));


	return S_OK;
}

//메모리 관련 삭제
void playGround::release(void)
{
	gameNode::release();

}

//연산
void playGround::update(void)
{
	gameNode::update();

	SCENEMANAGER->update();
	if (KEYMANAGER->isOnceKeyDown(VK_F2)) SCENEMANAGER->changeScene("월드맵씬");
}

//그리는거.......
void playGround::render(void)
{
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//================== 이 위는 손대지 마시오 =========================

	SCENEMANAGER->render();

	//================== 이 아래는 손대지 마시오 ========================
	this->getBackBuffer()->render(getHDC(), 0, 0);//hdc영역에 그려준다 
}
