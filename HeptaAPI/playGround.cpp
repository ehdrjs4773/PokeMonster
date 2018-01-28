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
	SCENEMANAGER->addScene("DR5", new stageScene);
	shopScene* shop = new shopScene;
	SCENEMANAGER->addScene("������", shop);
	SCENEMANAGER->addScene("�κ��丮��", new inventory);
	SCENEMANAGER->init("�κ��丮��");

	SCENEMANAGER->addScene("PokeInfo", new MonsterBack);
	SCENEMANAGER->addScene("UI", new UI);
	//--------�������� �׽�Ʈ----------
	SCENEMANAGER->addScene("flyMap", new flyMap);
	SCENEMANAGER->addScene("fighterMap", new fighterMap);



	shop->invenMemoryAdressLink((inventory*)SCENEMANAGER->findScene("�κ��丮��"));

	// ��Ʋ�� �׽�Ʈ��
	vector<pokemon*>* vPokemon = new vector<pokemon*>;
	vector<pokemon*>* vPokemon2 = new vector<pokemon*>;

	skill* _temp = new skill;
	_temp->init("�����ġ��");
	skill* _temp2 = new skill;
	_temp2->init("������");
	skill* _temp3 = new skill;
	_temp3->init("�����ġ��");
	skill* _temp4 = new skill;
	_temp4->init("�����ġ��");

	pokemon* isang = new pokemon;
	isang->init("�̻��ؾ�", 24);
	isang->addSkill(_temp);
	isang->addSkill(_temp2);
	pokemon* tuttleKing = new pokemon;
	tuttleKing->init("�źϿ�", 36);
	tuttleKing->addSkill(_temp4);
	pokemon* dandaegi = new pokemon;
	dandaegi->init("���α�", 20);
	dandaegi->addSkill(_temp3);
	vPokemon->push_back(isang);
	vPokemon->push_back(tuttleKing);
	vPokemon2->push_back(dandaegi);

	DATABASE->setVPlayerPokemon(vPokemon);
	DATABASE->setVEnemyPokemon(vPokemon2);

	SCENEMANAGER->init("PokeInfo");
	SCENEMANAGER->init("UI");

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
	if (KEYMANAGER->isOnceKeyDown(VK_F2))
	{
		SCENEMANAGER->changeScene("����ʾ�");
		SCENEMANAGER->init("����ʾ�");
	}

	// ��Ʋ�� �׽�Ʈ
	if (KEYMANAGER->isOnceKeyDown(VK_F1))
	{
		SCENEMANAGER->changeScene("battleScene");
		SCENEMANAGER->init("battleScene");
	}

	if (KEYMANAGER->isOnceKeyDown(VK_F3))
	{
		SCENEMANAGER->changeScene("�����׾�");
		SCENEMANAGER->init("�����׾�");
	}
	if (KEYMANAGER->isOnceKeyDown(VK_F4))
	{
		SCENEMANAGER->changeScene("DR5");
		SCENEMANAGER->init("DR5");
	}

	if (KEYMANAGER->isOnceKeyDown(VK_F12))
	{
		SCENEMANAGER->changeScene(SCENEMANAGER->getLastSceneName());
	}

	//if (KEYMANAGER->isOnceKeyDown(VK_F5))
	//{
	//	SCENEMANAGER->changeScene("UI");
	//}
	//--------�������� �׽�Ʈ----------
	if (KEYMANAGER->isOnceKeyDown(VK_NUMPAD0))
	{
		SCENEMANAGER->changeScene("flyMap");
		SCENEMANAGER->init("flyMap");
	}
	if (KEYMANAGER->isOnceKeyDown(VK_NUMPAD1))
	{
		SCENEMANAGER->changeScene("fighterMap");
		SCENEMANAGER->init("fighterMap");
	}

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
