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
	
	IMAGEMANAGER->addImage("���", "worldmap1.bmp", WINSIZEX, WINSIZEY, true, true, RGB(255, 0, 255));

	SCENEMANAGER->addScene("����ʾ�", new worldMapScene);
	IMAGEMANAGER->addImage("ǥ��", "select.bmp", 50, 78, true, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("clear", "clear.bmp", 101, 42, true, true, RGB(255, 0, 255));


	return S_OK;
}

//�޸� ���� ����
void playGround::release(void)
{
	gameNode::release();

}

//����
void playGround::update(void)
{
	gameNode::update();

	SCENEMANAGER->update();
	if (KEYMANAGER->isOnceKeyDown(VK_F2)) SCENEMANAGER->changeScene("����ʾ�");
}

//�׸��°�.......
void playGround::render(void)
{
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//================== �� ���� �մ��� ���ÿ� =========================

	SCENEMANAGER->render();

	//================== �� �Ʒ��� �մ��� ���ÿ� ========================
	this->getBackBuffer()->render(getHDC(), 0, 0);//hdc������ �׷��ش� 
}
