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

	//���� 
	SOUNDMANAGER->addSound("��Ʋ�� �׸���", "battleBgm.mp3", true, true);
	SOUNDMANAGER->addSound("������ �׸���", ".//bossBgm.mp3", true, true);
	SOUNDMANAGER->addSound("���ڻ� �׸���", "drOBgm.mp3", true, true);
	SOUNDMANAGER->addSound("����� �׸���", "worldBgm.mp3", true, true);


	_player = new player;
	_player->init();
	DATABASE->setPlayerMemory(_player);

	this->imageInit();

	SCENEMANAGER->addScene("����ʾ�", new worldMapScene);
	SCENEMANAGER->addScene("battleScene", new battleScene);

	SCENEMANAGER->addScene("�����׾�", new Opening);
	SCENEMANAGER->addScene("SelectScene", new SelectScene);
	shopScene* shop = new shopScene;
	SCENEMANAGER->addScene("������", shop);
	SCENEMANAGER->addScene("�κ��丮��", new inventory);
	SCENEMANAGER->addScene("PokeInfo", new MonsterBack);
	SCENEMANAGER->addScene("UI", new UI);
	SCENEMANAGER->init("�κ��丮��");
	SCENEMANAGER->addScene("ending", new Ending);
	//--------�������� �׽�Ʈ----------
	SCENEMANAGER->addScene("��������0", new drOHouse);
	SCENEMANAGER->addScene("��������1", new steelMap);
	SCENEMANAGER->addScene("��������2", new fighterMap);
	SCENEMANAGER->addScene("��������3", new ghostMap);
	SCENEMANAGER->addScene("��������4", new normalMap);
	SCENEMANAGER->addScene("��������5", new dragonMap);
	SCENEMANAGER->addScene("��������6", new bugMap);
	SCENEMANAGER->addScene("��������7", new flyMap);
	SCENEMANAGER->addScene("��������8", new iceMap);
	SCENEMANAGER->addScene("��������9", new guardian1);
	SCENEMANAGER->addScene("��������10", new guardian2);
	SCENEMANAGER->addScene("��������11", new guardian3);
	SCENEMANAGER->addScene("��������12", new guardian4);
	SCENEMANAGER->addScene("��������13", new champion);

	shop->invenMemoryAdressLink((inventory*)SCENEMANAGER->findScene("�κ��丮��"));

	SCENEMANAGER->init("PokeInfo");
	SCENEMANAGER->init("UI");
	SCENEMANAGER->init("�����׾�");
	SCENEMANAGER->init("ending");
	
	SCENEMANAGER->changeScene("�����׾�");

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
	
}

//�׸��°�.......
void playGround::render(void)
{
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//================== �� ���� �մ��� ���ÿ� =========================

	SetBkMode(getMemDC(), TRANSPARENT);
	SCENEMANAGER->render();

	//================== �� �Ʒ��� �մ��� ���ÿ� ========================
	this->getBackBuffer()->render(getHDC(), 0, 0);//hdc������ �׷��ش� 
}
