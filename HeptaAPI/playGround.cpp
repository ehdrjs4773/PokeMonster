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

	SCENEMANAGER->addScene("����ʾ�", new worldMapScene);
	SCENEMANAGER->addScene("battleScene", new battleScene);
	SCENEMANAGER->addScene("�����׾�", new Opening);
	SCENEMANAGER->addScene("SelectScene", new SelectScene);
	SCENEMANAGER->addScene("DR5", new drHouseScene);
	SCENEMANAGER->addScene("������", new shopScene);
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
	if (KEYMANAGER->isOnceKeyDown(VK_F2)) SCENEMANAGER->changeScene("������");

	// ��Ʋ�� �׽�Ʈ
	if (KEYMANAGER->isOnceKeyDown(VK_F1))
	{
		vector<pokemon*> vPokemon;
		vector<pokemon*> vPokemon2;

		pokemon* pika = new pokemon;
		vPokemon.push_back(pika);
		vPokemon2.push_back(pika);

		DATABASE->setVPlayerPokemon(&vPokemon);
		DATABASE->setVEnemyPokemon(&vPokemon2);

		SCENEMANAGER->changeScene("battleScene");
	}



	if (KEYMANAGER->isOnceKeyDown(VK_F3))
	{
		SCENEMANAGER->changeScene("�����׾�");
	}

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
